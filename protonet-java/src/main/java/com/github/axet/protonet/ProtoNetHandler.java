package com.github.axet.protonet;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import com.google.protobuf.Descriptors.Descriptor;
import com.google.protobuf.GeneratedMessage;

public class ProtoNetHandler implements ProtoNetSocketDelegate {

    HashMap<Integer, ProtoNetHandlerDelegate> requestMap = new HashMap<Integer, ProtoNetHandlerDelegate>();
    List<ProtoNetHandlerDelegate> listeners = new ArrayList<ProtoNetHandlerDelegate>();

    public void install(Class<? extends GeneratedMessage> c, ProtoNetHandlerDelegate d) {
        try {
            final Method getDescriptor = c.getMethod("getDescriptor");

            Descriptor des = (Descriptor) getDescriptor.invoke(null);

            requestMap.put(des.getIndex(), d);
        } catch (RuntimeException e) {
            throw e;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void addListener(ProtoNetHandlerDelegate d) {
        listeners.add(d);
    }

    public void removeListener(ProtoNetHandlerDelegate d) {
        listeners.remove(d);
    }

    @Override
    public void process(GeneratedMessage request) {
        for (ProtoNetHandlerDelegate d : listeners) {
            d.process(request);
        }
    }

    @Override
    public void disconnected() {
    }
}
