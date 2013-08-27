// hi

#include <google/protobuf/stubs/common.h>

#include <google/protobuf/message.h>

@interface ProtoNetDiscoveryService : NSObject

@property (strong, nonatomic) NSString* address;

@property (nonatomic) int port;

- (id) initWithAddress:(NSString*)address port:(int)port;

@end
