package com.github.axet.protonet.test.client;

import javax.jmdns.ServiceInfo;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.github.axet.protonet.test.client.R;

@SuppressLint("InlinedApi")
public class TablesActivity extends Activity {

    DiscoveryAdapter list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_tables_list);

        list = new DiscoveryAdapter(
                (android.net.wifi.WifiManager) getSystemService(android.content.Context.WIFI_SERVICE));

        ListView l = (ListView) findViewById(R.id.activity_tables_list);
        l.setAdapter(list);
        l.setOnItemClickListener(new ListView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                Intent intent = new Intent(TablesActivity.this, ConnectActivity.class);

                ServiceInfo i = (ServiceInfo) arg1.getTag();

                intent.putExtra("addr", i.getHostAddresses()[0]);
                intent.putExtra("port", i.getPort());

                startActivity(intent);
            }
        });

        refreshClick(null);
    }

    @Override
    protected void onStart() {
        PokerApplication app = (PokerApplication) getApplication();
        app.disconnect();

        super.onStart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onDestroy() {
        list.close();

        super.onDestroy();
    }

    @Override
    public void finish() {
        super.finish();
    }

    public void refreshClick(View v) {
        list.close();

        list = new DiscoveryAdapter(
                (android.net.wifi.WifiManager) getSystemService(android.content.Context.WIFI_SERVICE));

        ListView l = (ListView) findViewById(R.id.activity_tables_list);
        l.setAdapter(list);
    }

}
