//
//  ProtoNetHandler.m
//  protonet-objc
//
//  Created by Alexey Kuznetsov on 22.08.13.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "ProtoNetHandler.h"

#import <objc/message.h>

@interface NumberPair : NSObject
    @property (nonatomic, assign) id obj;
    @property (nonatomic, assign) SEL sel;
@end

@implementation NumberPair
    @synthesize obj, sel;
@end

@implementation ProtoNetHandler

- (void) install:(::google::protobuf::Message *)m id:(id)obj sel:(SEL)sel
{
    NumberPair *p = [[NumberPair alloc]init];
    p.sel = sel;
    p.obj = obj;
    
    [_commands setObject:p forKey: [NSNumber numberWithInt:m->GetDescriptor()->index()]];
    
    delete m;
}

-(void)process:(::google::protobuf::Message*) message
{
    NumberPair *p = [_commands objectForKey: [NSNumber numberWithInt: message->GetDescriptor()->index()]];

    if(p != nil)
        objc_msgSend(p.obj, p.sel, message);
}

- (void)disconnect
{
}

@end
