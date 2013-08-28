package com.github.axet.protonet.test.server;

import java.util.TreeMap;

import android.app.Activity;
import android.graphics.Rect;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.MotionEvent.PointerCoords;
import android.view.View;
import android.view.ViewGroup;

import com.github.axet.protonet.test.server.R;

public class TableActivity extends Activity {

    ServerApplication app;
    TreeMap<Integer, ViewRotate> capture = new TreeMap<Integer, ViewRotate>();

    static class ViewRotate {
        public View v;
        public float r;

        public ViewRotate(View v, float r) {
            this.v = v;
            this.r = r;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_table);

        app = (ServerApplication) getApplication();

        app.setMachine(new ServerStateMachine(app, this));
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

    public void readyClick(View v) {
        v.setVisibility(View.INVISIBLE);
    }

}
