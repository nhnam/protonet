//
//  AppDelegate.h
//  poker-hand
//
//  Created by Alexey Kuznetsov on 25/06/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ProtoNetDiscovery.h"

@class SocketHandler;

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) SocketHandler *socket;

@property ProtoNetDiscovery *discovery;

- (id)init;

@end
