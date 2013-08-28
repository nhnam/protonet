package com.github.axet.protonet;

import com.google.protobuf.GeneratedMessage;

public interface ProtoNetHandlerDelegate {
    public void process(GeneratedMessage request);
}
