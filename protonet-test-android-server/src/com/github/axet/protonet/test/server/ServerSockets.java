package com.github.axet.protonet.test.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

import org.apache.http.HttpServerConnection;

import android.util.Log;

import com.github.axet.protonet.ProtoNetSocket;
import com.github.axet.protonet.ProtoNetSocketDelegate;
import com.google.protobuf.GeneratedMessage;

public class ServerSockets {
    ServerSocket serverSocket;

    HttpServerConnection d;

    ArrayList<ProtoNetSocket> threads = new ArrayList<ProtoNetSocket>();
    Thread main;

    ArrayList<ClientServerHandler> handler = new ArrayList<ServerSockets.ClientServerHandler>();

    public static interface ServerHandler {
        public void process(ProtoNetSocket t, Object request);
    }

    public static interface ClientServerHandler extends ServerHandler {
        public void clientConnected(ProtoNetSocket t);

        public void clientDisconnected(ProtoNetSocket t);
    }

    public ServerSockets() {
    }

    public void start() {
        if (main != null)
            stop();

        try {
            serverSocket = new ServerSocket(0);
        } catch (IOException e1) {
            throw new RuntimeException(e1);
        }

        main = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    while (!Thread.interrupted()) {
                        try {
                            final Socket clientSocket = serverSocket.accept();
                            Log.d("table", "new client " + clientSocket);
                            final ProtoNetSocket t = new ProtoNetSocket();

                            t.addListener(new ProtoNetSocketDelegate() {
                                @Override
                                public void process(GeneratedMessage request) {
                                }

                                @Override
                                public void disconnected() {
                                    for (ClientServerHandler c : handler) {
                                        c.clientDisconnected(t);
                                    }

                                    ServerSockets.this.disconnect(t);
                                }
                            });

                            synchronized (threads) {
                                threads.add(t);
                            }
                            t.connect(clientSocket);

                            clearThreads();
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    }

                    serverSocket.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }, "PokerServer");
        main.start();
    }

    public void disconnect(ProtoNetSocket t) {
        for (ClientServerHandler c : handler) {
            c.clientDisconnected(t);
        }
    }

    @SuppressWarnings("unchecked")
    public void stop() {
        if (main == null)
            return;

        main.interrupt();

        synchronized (threads) {
            for (ProtoNetSocket t : threads) {
                t.interrupt();
            }
        }

        ArrayList<ProtoNetSocket> tt;
        synchronized (threads) {
            tt = (ArrayList<ProtoNetSocket>) threads.clone();
        }

        for (ProtoNetSocket t : tt) {
            try {
                t.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }

        clearThreads();
    }

    @SuppressWarnings("unchecked")
    void clearThreads() {
        ArrayList<ProtoNetSocket> tt;
        synchronized (threads) {
            tt = (ArrayList<ProtoNetSocket>) threads.clone();
        }

        for (ProtoNetSocket t : tt) {
            if (!t.isAlive()) {
                t.close();
                threads.remove(t);
            }
        }
    }

    public int getLocalPort() {
        return serverSocket.getLocalPort();
    }

    public void addListener(ClientServerHandler h) {
        handler.add(h);
    }

    public void removeListener(ClientServerHandler h) {
        handler.remove(h);
    }
}