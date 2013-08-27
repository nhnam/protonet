//
//  JoinViewController.m
//  poker-hand
//
//  Created by Alexey Kuznetsov on 10/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "JoinViewController.h"
#import "AppDelegate.h"
#import "../../protonet-objc-test-common/protonet-objc-test-common/SocketHandler.h"

#import <objc/message.h>

@interface JoinViewController ()

@end

@implementation JoinViewController

@synthesize host = _host;
@synthesize port = _port;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        _commands = [[ProtoNetHandler alloc] init];
        [_commands install:new ::com::github::axet::protonet::test::SeatTakeRespond() id:self sel:@selector(processSeatTaken:)];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
 
    _commands = [NSDictionary dictionaryWithObjectsAndKeys:
                 [NSValue valueWithPointer:@selector(processSeatTaken:)], [NSNumber numberWithInt: ::com::github::axet::protonet::test::SeatTakeRespond::descriptor()->index()],
                 nil];

    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    
    [[appDelegate socket] connect:[self host] port:[self port]];
    
    [[appDelegate socket] addListener: self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)joinDown:(id)sender
{
    AppDelegate *appDelegate= [[UIApplication sharedApplication] delegate];
    
    ::com::github::axet::protonet::test::SeatTakeRequest *m = new ::com::github::axet::protonet::test::SeatTakeRequest();
    m->set_take(true);
    
    [[appDelegate socket] writeMessage: m];
}

- (void)joinUp:(id)sender
{
    AppDelegate *appDelegate= [[UIApplication sharedApplication] delegate];
    
    ::com::github::axet::protonet::test::SeatTakeRequest *m = new ::com::github::axet::protonet::test::SeatTakeRequest();
    m->set_take(false);
    
    [[appDelegate socket] writeMessage: m];
}

- (void)disconnect
{
    //[self.navigationController popToRootViewControllerAnimated:YES];
}

- (void)processSeatTaken:(::com::github::axet::protonet::test::SeatTakeRespond*)m
{
}

@end
