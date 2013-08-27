// hi

#import "ProtoNetDiscoveryService.h"

@implementation ProtoNetDiscoveryService

@synthesize address  =_address;
@synthesize port = _port;

- (id)initWithAddress:(NSString *)address port:(int)port
{
    if (self = [super init])
    {
        _address = address;
        _port = port;
    }
    return self;
}

@end
