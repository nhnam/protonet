package com.github.axet.protonet.test.client;

import java.net.InetAddress;

import android.app.Application;
import android.content.Intent;
import android.os.Handler;

import com.github.axet.protonet.ProtoNetHandler;
import com.github.axet.protonet.ProtoNetSocket;
import com.github.axet.protonet.test.common.ExampleProto.HandRequest;
import com.github.axet.protonet.test.common.ExampleProto.HandRespond;
import com.github.axet.protonet.test.common.ExampleProto.SeatTakeRequest;
import com.github.axet.protonet.test.common.ExampleProto.SeatTakeRespond;
import com.google.protobuf.GeneratedMessage;

public class PokerApplication extends Application {

    public ProtoNetSocket socket = new ProtoNetSocket();

    Handler ah = new Handler();

    ProtoNetHandler handler = new ProtoNetHandler() {
        @Override
        public void disconnected() {
            ah.post(new Runnable() {
                @Override
                public void run() {
                    Intent intent1 = new Intent(PokerApplication.this, TablesActivity.class);
                    intent1.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    intent1.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    startActivity(intent1);
                }
            });
        };
    };

    {
        socket.install(HandRequest.class);
        socket.install(HandRespond.class);
        socket.install(SeatTakeRequest.class);
        socket.install(SeatTakeRespond.class);
    }

    {
        handler.install(HandRequest.class, new ProtoNetHandler() {
            @Override
            public void process(final GeneratedMessage request) {
                ah.post(new Runnable() {
                    @Override
                    public void run() {
                        HandRequest t = (HandRequest) request;
                        // work with t
                    }
                });
            }
        });

        socket.addListener(handler);
    }

    public PokerApplication() {
    }

    public void connect(InetAddress addr, int port) {
        socket.close();

        socket = new ProtoNetSocket();

        socket.connect(addr, port);
    }

    public void disconnect() {
        socket.close();
    }
}
