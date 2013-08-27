//
//  Application.m
//  poker-hand
//
//  Created by Alexey Kuznetsov on 04/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "ProtoNetDiscovery.h"

#include <arpa/inet.h>

@implementation ProtoNetDiscovery

-(id)init
{
    if (self = [super init])
    {
        self.services = [[NSMutableArray alloc] init];
        
        [self startBrowsing ];
    }
    return self;
}

- (NSString*)address:(NSNetService*)s
{
    char addressBuffer[INET6_ADDRSTRLEN + 1] = {0};
    
    for (NSData *data in s.addresses)
    {
        memset(addressBuffer, 0, INET6_ADDRSTRLEN);
        
        typedef union {
            struct sockaddr sa;
            struct sockaddr_in ipv4;
            struct sockaddr_in6 ipv6;
        } ip_socket_address;
        
        ip_socket_address *socketAddress = (ip_socket_address *)[data bytes];
        
        if (socketAddress && (socketAddress->sa.sa_family == AF_INET || socketAddress->sa.sa_family == AF_INET6))
        {
            const char *addressStr = inet_ntop(
                                               socketAddress->sa.sa_family,
                                               (socketAddress->sa.sa_family == AF_INET ? (void *)&(socketAddress->ipv4.sin_addr) : (void *)&(socketAddress->ipv6.sin6_addr)),
                                               addressBuffer,
                                               sizeof(addressBuffer));
            
            int port = ntohs(socketAddress->sa.sa_family == AF_INET ? socketAddress->ipv4.sin_port : socketAddress->ipv6.sin6_port);
            
            if (addressStr && port)
            {
                NSLog(@"Found service at %s:%d", addressStr, port);
            }
        }
    }
    
    return [NSString stringWithCString:addressBuffer encoding:NSASCIIStringEncoding];
}

- (void)netServiceBrowser:(NSNetServiceBrowser *)serviceBrowser didFindService:(NSNetService *)service moreComing:(BOOL)moreComing {
    [service resolveWithTimeout: 1];

    ProtoNetDiscoveryService *s = [[ProtoNetDiscoveryService alloc] initWithAddress:[self address:service] port:service.port];
    
    [self.services addObject:service];
    if(!moreComing) {
        [self.services sortUsingDescriptors:@[[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]]];
    }
    
    if (delegate)
        [delegate addService:s moreComing:moreComing];
}

- (void)netServiceBrowser:(NSNetServiceBrowser *)serviceBrowser didRemoveService:(NSNetService *)service moreComing:(BOOL)moreComing {
    [self.services removeObject:service];
    
    ProtoNetDiscoveryService *s = [[ProtoNetDiscoveryService alloc] initWithAddress:[self address:service] port:service.port];

    if (delegate)
        [delegate removeService:s moreComing:moreComing];
}

- (void)netServiceBrowserDidStopSearch:(NSNetServiceBrowser *)serviceBrowser {
    [self stopBrowsing];
}

- (void)netServiceBrowser:(NSNetServiceBrowser *)aBrowser didNotSearch:(NSDictionary *)userInfo {
    [self stopBrowsing];
}

- (void)stopBrowsing {
    if (self.serviceBrowser) {
        [self.serviceBrowser stop];
        [self.serviceBrowser setDelegate:nil];
        [self setServiceBrowser:nil];
    }
}

- (void)startBrowsing {
    [self.services removeAllObjects];
    
    self.serviceBrowser = [[NSNetServiceBrowser alloc] init];
    
    [self.serviceBrowser setDelegate:  self];
    
    [self.serviceBrowser searchForServicesOfType:[NSString stringWithFormat:@"_%@._tcp.", [self serviceName]] inDomain:@"local."];
}

- (void)setDelegate:(id < ProtoNetDiscoveryDelegate >)d
{
    delegate = d;
}

@end
