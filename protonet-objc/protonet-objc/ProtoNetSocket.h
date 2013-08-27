//
//  AppDelegate.h
//  poker-hand
//
//  Created by Alexey Kuznetsov on 25/06/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GCDAsyncSocket.h"
#import "ProtoNetDelegate.h"

@interface ProtoNetSocket : NSObject {
    NSMutableDictionary* _commands;
    NSMutableArray *_listneners;
    GCDAsyncSocket *_socket;
}

// public

- (id)init;

- (void)addListener:(id<ProtoNetDelegate>) delegate;

- (void)removeListener:(id<ProtoNetDelegate>) delegate;

- (void)install:(::google::protobuf::Message *)m;

// protected

- (void)socket:(GCDAsyncSocket *)sender didConnectToHost:(NSString *)host port:(UInt16)port;

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)error;

- (void)socket:(GCDAsyncSocket *)sender didReadData:(NSData *)data withTag:(long)tag;

- (void)socket:(GCDAsyncSocket *)sock didWriteDataWithTag:(long)tag;

- (void)connect:(NSString *) host port:(UInt16)port;

- (void)disconnect;

- (void)readHeader;

- (void)readBody:(int) type length:(long) size;

- (void)write:(NSData*) data;

- (void)writeMessage:(::google::protobuf::Message*) message;

@end
