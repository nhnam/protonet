package com.github.axet.protonet.test.client;

import java.io.IOException;
import java.math.BigInteger;
import java.net.InetAddress;
import java.util.ArrayList;

import javax.jmdns.JmDNS;
import javax.jmdns.ServiceEvent;
import javax.jmdns.ServiceInfo;
import javax.jmdns.ServiceListener;

import org.apache.commons.lang.ArrayUtils;

import android.content.Context;
import android.database.DataSetObserver;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListAdapter;
import android.widget.TextView;

import com.github.axet.protonet.test.client.R;

public class DiscoveryAdapter implements ListAdapter {
    Handler handler = new Handler();

    ArrayList<ServiceInfo> list = new ArrayList<ServiceInfo>();

    final static String TAG = "tag";
    final static String SERVICE_TYPE = "_server._tcp.local.";
    String mServiceName = "Server";

    android.net.wifi.WifiManager.MulticastLock lock;

    JmDNS j;
    Thread thread;

    WifiManager wifi;

    ServiceListener res = new ServiceListener() {
        @Override
        public void serviceResolved(ServiceEvent event) {
            final ServiceInfo info = event.getInfo();

            if (!info.getName().contains(mServiceName))
                return;

            handler.post(new Runnable() {
                @Override
                public void run() {
                    add(info);
                    notifyDataChanged();
                }
            });
        }

        @Override
        public void serviceRemoved(ServiceEvent event) {
        }

        @Override
        public void serviceAdded(ServiceEvent event) {
            if (!event.getName().contains(mServiceName))
                return;

            j.requestServiceInfo(event.getType(), event.getName(), 1000);
        }
    };

    class RetreiveFeedTask implements Runnable {
        @Override
        public void run() {
            try {
                byte[] bytes = BigInteger.valueOf(wifi.getConnectionInfo().getIpAddress()).toByteArray();
                ArrayUtils.reverse(bytes);
                InetAddress addr = InetAddress.getByAddress(bytes);

                if (j != null)
                    j.close();

                j = JmDNS.create(addr);
                j.addServiceListener(SERVICE_TYPE, res);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public DiscoveryAdapter(WifiManager wifi) {
        this.wifi = wifi;

        lock = wifi.createMulticastLock("HeeereDnssdLock");
        lock.setReferenceCounted(true);
        lock.acquire();

        thread = new Thread(new RetreiveFeedTask(), "jmdns - refresh");
        thread.start();
    }

    public void close() {
        if (lock != null)
            lock.release();

        if (thread != null) {
            try {
                thread.interrupt();
                thread.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public Object getItem(int position) {
        return list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public int getItemViewType(int position) {
        return 1;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        final ServiceInfo w = list.get(position);
        if (convertView == null) {
            LayoutInflater inflater = (LayoutInflater) parent.getContext().getSystemService(
                    Context.LAYOUT_INFLATER_SERVICE);

            convertView = inflater.inflate(R.layout.activity_tables_list_item, parent, false);
        }

        TextView t = (TextView) convertView.findViewById(R.id.text_server);
        t.setText(w.getName() + " " + w.getHostAddresses()[0] + " " + w.getPort());

        convertView.setTag(w);

        return convertView;
    }

    @Override
    public int getViewTypeCount() {
        return 1;
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    ArrayList<DataSetObserver> servers = new ArrayList<DataSetObserver>();

    @Override
    public void registerDataSetObserver(DataSetObserver observer) {
        servers.add(observer);
    }

    @Override
    public void unregisterDataSetObserver(DataSetObserver observer) {
        servers.remove(observer);
    }

    public void notifyDataChanged() {
        for (DataSetObserver o : servers) {
            o.onChanged();
        }
    }

    @Override
    public boolean areAllItemsEnabled() {
        return true;
    }

    @Override
    public boolean isEnabled(int position) {
        return true;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    public void add(ServiceInfo s) {
        list.add(s);
    }

    public void removeAll() {
        list.clear();
    }
}
