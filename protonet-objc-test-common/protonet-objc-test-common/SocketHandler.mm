//
//  AppDelegate.m
//  poker-hand
//
//  Created by Alexey Kuznetsov on 25/06/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "SocketHandler.h"

@implementation SocketHandler

-(id)init
{
    if (self = [super init])
    {
        [self install: new ::com::github::axet::protonet::test::HandRequest()];
        [self install: new ::com::github::axet::protonet::test::HandRespond()];
        [self install: new ::com::github::axet::protonet::test::SeatTakeRequest()];
        [self install: new ::com::github::axet::protonet::test::SeatTakeRespond()];
    }
    return self;
}

@end
