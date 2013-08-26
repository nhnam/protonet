// hi

#include <google/protobuf/stubs/common.h>

#include <google/protobuf/message.h>

@protocol ProtoNetHandlerDelegate <NSObject>

- (void)process:(::google::protobuf::Message*) message;

- (void)disconnect;

@end
