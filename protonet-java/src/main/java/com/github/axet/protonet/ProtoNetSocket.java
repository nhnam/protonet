package com.github.axet.protonet;

import java.io.IOException;
import java.io.InputStream;
import java.io.InterruptedIOException;
import java.io.OutputStream;
import java.lang.reflect.Method;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import com.google.protobuf.Descriptors.Descriptor;
import com.google.protobuf.GeneratedMessage;

public class ProtoNetSocket {
    Thread thread;

    Object sendReady = new Object();

    Socket socket;
    OutputStream oos;
    InputStream ois;

    interface ProtoNetSocketProcessor {
        public GeneratedMessage process(byte[] b);
    }

    HashMap<Integer, ProtoNetSocketProcessor> map = new HashMap<Integer, ProtoNetSocketProcessor>();
    List<ProtoNetSocketDelegate> listeners = new ArrayList<ProtoNetSocketDelegate>();

    public void install(Class<? extends GeneratedMessage> c) {
        try {
            final Method getDescriptor = c.getMethod("getDescriptor");
            final Method parseFrom = c.getMethod("parseFrom", (new byte[0]).getClass());

            Descriptor d = (Descriptor) getDescriptor.invoke(null);

            map.put(d.getIndex(), new ProtoNetSocketProcessor() {
                @Override
                public GeneratedMessage process(byte[] b) {
                    try {
                        return (GeneratedMessage) parseFrom.invoke(null, b);
                    } catch (RuntimeException e) {
                        throw e;
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                }
            });
        } catch (RuntimeException e) {
            throw e;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void addListener(ProtoNetSocketDelegate listener) {
        listeners.add(listener);
    }

    public void removeListener(ProtoNetSocketDelegate listener) {
        listeners.remove(listener);
    }
    
    public boolean isAlive() {
        return thread.isAlive();
    }
    
    public void interrupt() {
        thread.interrupt();
    }
    
    public void join() throws InterruptedException {
        thread.join();
    }

    public void connect(final InetAddress addr, final int port) {
        close();

        thread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    socket = new Socket(addr, port);
                    process();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }, "ProtoNetSocketConnect");
        thread.start();
    }

    public void connect(final Socket s) {
        close();

        thread = new Thread(new Runnable() {
            @Override
            public void run() {
                socket = s;
                process();
            }
        }, "ProtoNetSocketConnect");
        thread.start();
    }

    public void close() {
        if (thread != null) {
            thread.interrupt();

            listeners.clear();

            try {
                try {
                    synchronized (sendReady) {
                        if (oos == null)
                            sendReady.wait();
                    }
                    socket.close();
                    thread.join();

                    oos.close();
                    ois.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

                thread = null;
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    public void send(final GeneratedMessage o) {
        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    synchronized (sendReady) {
                        if (oos == null)
                            sendReady.wait();
                    }
                } catch (InterruptedException e) {
                    onDisconnect(e);
                }

                write(o, oos);

                try {
                    oos.flush();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

            }
        }, "ProtoNetSocketSend");
        t.start();
    }

    public GeneratedMessage read(InputStream is) {
        try {
            ByteBuffer typeBuf = ByteBuffer.allocate(Integer.SIZE / Byte.SIZE);
            if (!read(is, typeBuf.array()))
                throw new RuntimeException("unable to get type");
            int type = typeBuf.getInt();

            ByteBuffer sizeBuf = ByteBuffer.allocate(Long.SIZE / Byte.SIZE);
            if (!read(is, sizeBuf.array()))
                throw new RuntimeException("unable to get message");
            long size = sizeBuf.getLong();

            ByteBuffer dataBuf = ByteBuffer.allocate((int) size);
            if (!read(is, dataBuf.array()))
                throw new RuntimeException("unable to get message");

            return map.get(type).process(dataBuf.array());
        } catch (RuntimeException e) {
            throw e;
        }
    }

    public void write(GeneratedMessage o, OutputStream oos) {
        try {
            int type = o.getDescriptorForType().getIndex();
            ByteBuffer typeBuf = ByteBuffer.allocate(Integer.SIZE / Byte.SIZE);
            typeBuf.putInt(type);
            oos.write(typeBuf.array());

            long size = o.getSerializedSize();
            ByteBuffer sizeBuf = ByteBuffer.allocate(Long.SIZE / Byte.SIZE);
            sizeBuf.putLong(size);
            oos.write(sizeBuf.array());

            o.writeTo(oos);
            oos.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    //
    // protected
    //

    void process() {
        try {
            synchronized (sendReady) {
                oos = socket.getOutputStream();
                sendReady.notifyAll();
            }

            ois = socket.getInputStream();

            GeneratedMessage request;

            while ((request = read(ois)) != null) {
                for (ProtoNetSocketDelegate h : listeners) {
                    h.process(request);
                }
            }
        } catch (InterruptedIOException e) {
            Thread.currentThread().interrupt();
        } catch (RuntimeException e) {
            onDisconnect(e);
        } catch (Exception e) {
            onDisconnect(e);
        }
    }

    void onDisconnect(Throwable e) {
        for (ProtoNetSocketDelegate h : listeners) {
            h.disconnected();
        }
    }

    boolean read(InputStream ois, byte[] buffer) {
        try {
            int offset = 0;
            int r = 0;

            while (offset < buffer.length) {
                r = ois.read(buffer, offset, buffer.length - offset);

                if (r < 0)
                    return false;

                offset += r;
            }

            return true;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
