package com.github.axet.protonet.test.client;

import java.net.InetAddress;
import java.net.UnknownHostException;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;

import com.github.axet.protonet.ProtoNetHandler;
import com.github.axet.protonet.ProtoNetHandlerDelegate;
import com.github.axet.protonet.test.client.R;
import com.github.axet.protonet.test.common.ExampleProto.SeatTakeRequest;
import com.github.axet.protonet.test.common.ExampleProto.SeatTakeRespond;
import com.google.protobuf.GeneratedMessage;

@SuppressLint("InlinedApi")
public class ConnectActivity extends Activity {

    int selectedSeatId;
    PokerApplication app;

    Handler handler = new Handler();

    ProtoNetHandler map = new ProtoNetHandler();

    {
        PokerApplication app = (PokerApplication) getApplication();

        map.install(SeatTakeRespond.class, new ProtoNetHandlerDelegate() {
            @Override
            public void process(final GeneratedMessage request) {
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        SeatTakeRespond t = (SeatTakeRespond) request;
                    }
                });
            }
        });

        app.socket.addListener(map);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_connect);

        SeatView v = (SeatView) findViewById(R.id.seat);
        v.setDownListener(new SeatView.DownListener() {
            @Override
            public void up(SeatView v) {
                PokerApplication app = (PokerApplication) getApplication();
                app.socket.send(SeatTakeRequest.newBuilder().setTake(false).build());
            }

            @Override
            public void down(SeatView v) {
                PokerApplication app = (PokerApplication) getApplication();
                app.socket.send(SeatTakeRequest.newBuilder().setTake(true).build());
            }
        });

        InetAddress addr;
        int port;

        try {
            addr = InetAddress.getByName(getIntent().getExtras().getString("addr"));
            port = getIntent().getExtras().getInt("port");
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }

        app = (PokerApplication) getApplication();
        app.connect(addr, port);
    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    public void finish() {
        super.finish();
    }

    public void cancelClick(View v) {
        finish();
    }

    public void joinClick(View v) {
    }
}
