package com.github.axet.protonet.test.server;

import com.github.axet.protonet.ProtoNetSocket;

public class ServerStateMachine {

    ServerSockets server;

    ServerApplication app;

    public ServerStateMachine(ServerApplication app, TableActivity mainActivity) {
        this.app = app;
        this.server = app.getServer();

        server.addListener(new ServerSockets.ClientServerHandler() {
            @Override
            public void process(ProtoNetSocket t, Object request) {
            }

            @Override
            public void clientConnected(ProtoNetSocket t) {
            }

            @Override
            public void clientDisconnected(ProtoNetSocket t) {
            }
        });
    }

}
