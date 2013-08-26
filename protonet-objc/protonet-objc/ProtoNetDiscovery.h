//
//  Application.h
//  poker-hand
//
//  Created by Alexey Kuznetsov on 04/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ProtoNetDiscoveryDelegate.h"

@interface ProtoNetDiscovery  : NSObject <NSNetServiceDelegate, NSNetServiceBrowserDelegate> {
    id<ProtoNetDiscoveryDelegate> delegate;
}

@property (strong, nonatomic) NSNetService *service;

@property (strong, nonatomic) NSNetServiceBrowser *serviceBrowser;

@property (strong, nonatomic) NSMutableArray *services;

@property (strong, nonatomic) NSString *serviceName;

- (id)init;

- (void)startBrowsing;

- (void)stopBrowsing;

- (void)setDelegate:(id < ProtoNetDiscoveryDelegate >)delegate;

- (void)netServiceBrowser:(NSNetServiceBrowser *)serviceBrowser didFindService:(NSNetService *)service moreComing:(BOOL)moreComing;

- (void)netServiceBrowser:(NSNetServiceBrowser *)serviceBrowser didRemoveService:(NSNetService *)service moreComing:(BOOL)moreComing;

@end
