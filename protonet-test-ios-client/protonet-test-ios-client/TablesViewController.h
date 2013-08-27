//
//  JoinViewController.h
//  poker-hand
//
//  Created by Alexey Kuznetsov on 08/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ProtoNetDiscoveryDelegate.h"

@class ProtoNetDiscovery;

@interface TablesViewController : UITableViewController<ProtoNetDiscoveryDelegate>

- (void)addService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;

- (void)removeService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;

@end
