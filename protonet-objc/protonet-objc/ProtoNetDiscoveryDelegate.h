// hi

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/message.h>

#import "ProtoNetDiscoveryService.h"

@protocol ProtoNetDiscoveryDelegate <NSObject>

- (void)addService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;

- (void)removeService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;

@end
