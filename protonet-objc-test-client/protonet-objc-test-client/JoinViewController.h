//
//  JoinViewController.h
//  poker-hand
//
//  Created by Alexey Kuznetsov on 10/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "ProtoNetSocketDelegate.h"
#import "ExampleProto.pb.h"
#import "ProtoNetHandler.h"

@interface JoinViewController : UIViewController<ProtoNetSocketDelegate> {
    ProtoNetHandler *_commands;
}

@property (nonatomic, strong) NSString *host;

@property (nonatomic) int port;

- (IBAction)joinDown:(id)sender;

- (IBAction)joinUp:(id)sender;

- (void)processSeatTaken:(::com::github::axet::protonet::test::SeatTakeRespond*) m;

@end
