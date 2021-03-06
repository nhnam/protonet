//
//  ProtoNetHandler.h
//  protonet-objc
//
//  Created by Alexey Kuznetsov on 22.08.13.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ProtoNetDelegate.h"

@interface ProtoNetHandler : NSObject<ProtoNetDelegate> {
    NSMutableDictionary* _commands;
}

- (void)install:(::google::protobuf::Message*)m id:(id)obj sel:(SEL)sel;

- (void)process:(::google::protobuf::Message*)message;

- (void)disconnect;

@end
