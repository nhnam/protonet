package com.github.axet.protonet.test.server;

import java.io.IOException;
import java.math.BigInteger;
import java.net.InetAddress;

import javax.jmdns.JmDNS;
import javax.jmdns.ServiceInfo;

import org.apache.commons.lang.ArrayUtils;

import android.net.wifi.WifiManager;
import android.net.wifi.WifiManager.MulticastLock;

public class Discovery {

    private String serviceName;

    JmDNS jmdns;
    ServiceInfo serviceInfo;
    Thread thread;
    WifiManager wifi;
    MulticastLock lock;

    public Discovery(final WifiManager wifi, final int port) {
        this.wifi = wifi;

        lock = wifi.createMulticastLock("HeeereDnssdLock");
        lock.setReferenceCounted(true);
        lock.acquire();

        thread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    byte[] bytes = BigInteger.valueOf(wifi.getConnectionInfo().getIpAddress()).toByteArray();
                    ArrayUtils.reverse(bytes);
                    InetAddress addr = InetAddress.getByAddress(bytes);

                    jmdns = JmDNS.create(addr);
                    serviceInfo = ServiceInfo.create("_server._tcp.local.", "Server", port, "Server");
                    jmdns.registerService(serviceInfo);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }, "Discovery");
        thread.start();
    }

    public String getServiceName() {
        return serviceName;
    }

    public void close() {
        if (thread != null) {
            thread.interrupt();
            try {
                thread.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            thread = null;
        }

        Thread t = new Thread(new Runnable() {

            @Override
            public void run() {
                jmdns.unregisterAllServices();
                try {
                    jmdns.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        });
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        if (lock != null)
            lock.release();
    }

    public void setServiceName(String mServiceName) {
        this.serviceName = mServiceName;
    }

}
