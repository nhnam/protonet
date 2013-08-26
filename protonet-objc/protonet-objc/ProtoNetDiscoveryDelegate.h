// hi

#include <google/protobuf/stubs/common.h>

#include <google/protobuf/message.h>

@protocol ProtoNetDiscoveryDelegate <NSObject>

- (void)addService:(NSString*)address port:(int)port moreComing:(bool)moreComing;

- (void)removeService:(NSString*)address port:(int)port moreComing:(bool)moreComing;

@end
