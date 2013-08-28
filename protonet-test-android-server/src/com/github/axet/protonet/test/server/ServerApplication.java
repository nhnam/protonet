package com.github.axet.protonet.test.server;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.HashMap;

import android.app.Application;
import android.os.Handler;
import android.util.Log;

import com.github.axet.protonet.test.server.ServerSockets.ClientServerHandler;
import com.github.axet.protonet.test.server.ServerSockets.ServerHandler;

public class ServerApplication extends Application {

    private ServerSockets server;

    private Discovery discovery;

    private ServerStateMachine machine;

    Handler handler;

    public static interface Listener {
    }

    public ServerApplication() {
    }

    @Override
    public void onCreate() {
        setServer(new ServerSockets());

        handler = new Handler();

        getServer().start();

        setDiscovery(new Discovery(
                (android.net.wifi.WifiManager) getSystemService(android.content.Context.WIFI_SERVICE), getServer()
                        .getLocalPort()));

        super.onCreate();
    }

    @Override
    public void onTerminate() {
        discovery.close();

        super.onTerminate();
    }

    public Discovery getDiscovery() {
        return discovery;
    }

    public void setDiscovery(Discovery discovery) {
        this.discovery = discovery;
    }

    public ServerSockets getServer() {
        return server;
    }

    public void setServer(ServerSockets server) {
        this.server = server;
    }

    public ServerStateMachine getMachine() {
        return machine;
    }

    public void setMachine(ServerStateMachine machine) {
        this.machine = machine;
    }
}