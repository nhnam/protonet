//
//  AppDelegate.m
//  poker-hand
//
//  Created by Alexey Kuznetsov on 25/06/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "ProtoNetSocket.h"

#define HEADER_TAG 1

#define BODY_TAG 10

@implementation ProtoNetSocket

-(id)init
{
    if (self = [super init])
    {
        _listneners = [[NSMutableArray alloc] init];

        _socket = [[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    }

    return self;
}

-(void)dealloc
{
    for(NSValue *v in _commands) {
        delete (::google::protobuf::Message *)[v pointerValue];
    }
    
    [super dealloc];
}

- (void)addListener:(id<ProtoNetDelegate>) delegate
{
    [_listneners addObject: delegate];
}

- (void)removeListener:(id<ProtoNetDelegate>) delegate
{
    [_listneners removeObject: delegate];
}

- (void) install:(::google::protobuf::Message *)m
{
    [_commands setObject:[NSValue valueWithPointer:m] forKey: [NSNumber numberWithInt:m->GetDescriptor()->index()]];
}

- (void)socket:(GCDAsyncSocket *)sender didConnectToHost:(NSString *)host port:(UInt16)port
{
    NSLog(@"connected");
}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)error
{
    NSLog(@"disconnected");

    for(id<ProtoNetDelegate> delegate in _listneners)
    {
        [delegate disconnect];
    }
}

- (void)disconnect
{
    [_socket disconnect];
}

- (void)connect:(NSString *) host port:(UInt16)port
{
    if([_socket isConnected]) {
        [_socket disconnect];
    }
    
    NSError *err = nil;

    if (![_socket connectToHost:host onPort:port error:&err]) // Asynchronous!
    {
        [NSException raise:@"protonet failed to connect" format:@"error %@", err];
    }
    
    [self readHeader];
}

- (void)write: (NSData*) data
{
    [_socket writeData:data withTimeout:-1 tag:1];
}

- (void)writeMessage:(::google::protobuf::Message *) msg
{
    int32_t type = msg->GetDescriptor()->index();
    int32_t typeSwap = CFSwapInt32HostToBig(type);
    NSData *typeBuf = [NSData dataWithBytes: &typeSwap length: sizeof(typeSwap)];
    [self write:typeBuf];

    int64_t size = msg->ByteSize();
    int64_t sizeSwap = CFSwapInt64HostToBig(size);
    NSData *sizeBuf = [NSData dataWithBytes: &sizeSwap length: sizeof(sizeSwap)];
    [self write:sizeBuf];
    
    NSMutableData *buf = [NSMutableData dataWithLength: size];
    
    msg->SerializeToArray([buf mutableBytes], size);
    
    [self write:buf];
}

- (::google::protobuf::Message *) read:(int) type data:(NSData*) data
{
    ::google::protobuf::Message *m = (::google::protobuf::Message *)[[_commands objectForKey: [NSNumber numberWithInt: type]] pointerValue];
    
    m = m->New();
    
    if(m->ParseFromArray([data bytes], [data length]))
        return m;
    
    [NSException raise:@"Invalid data buffer" format:@"data of %d bytes is invalid", [data length]];
    return nil;
}

- (void)socket:(GCDAsyncSocket *)sock didWriteDataWithTag:(long)tag
{
}

- (void)socket:(GCDAsyncSocket *)sender didReadData:(NSData *)data withTag:(long)tag
{
    switch(tag) {
        case HEADER_TAG:
        {
            int32_t type = *(int32_t*)((char*)[data bytes] + 0);
            int32_t typeSwap = CFSwapInt32HostToBig(type);

            int64_t size = *(int64_t*)((char*)[data bytes] + 4);
            int64_t sizeSwap = CFSwapInt64HostToBig(size);

            [self readBody:typeSwap length:sizeSwap];
            break;
        }
        default:
        {
            int type = tag - BODY_TAG;
            for(id<ProtoNetDelegate> delegate in _listneners) {
                ::google::protobuf::Message *msg = [self read: type data: data];
                [delegate process: msg];
            }
            break;
        }
    }
}

- (void)readHeader
{
    int headerLength = 4 + 8;

    [_socket readDataToLength:headerLength withTimeout:-1 tag:HEADER_TAG];
}

- (void)readBody:(int)type length:(long)size
{
    [_socket readDataToLength:size withTimeout:-1 tag:BODY_TAG + type];
    
    [self readHeader];
}

@end
