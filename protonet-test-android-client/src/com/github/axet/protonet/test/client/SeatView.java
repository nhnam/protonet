package com.github.axet.protonet.test.client;

import android.content.Context;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.FrameLayout;
import android.widget.ImageView;

import com.github.axet.protonet.test.client.R;

public class SeatView extends FrameLayout {

    public boolean down;

    DownListener downListener;

    public static interface DownListener {
        void down(SeatView v);

        void up(SeatView v);
    }

    public SeatView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getAction()) {
        case MotionEvent.ACTION_DOWN:
            down = true;
            update();
            return true;
        case MotionEvent.ACTION_CANCEL:
        case MotionEvent.ACTION_UP:
            down = false;
            update();
            return true;
        }

        return super.onTouchEvent(event);
    }

    public void setDownListener(DownListener l) {
        downListener = l;
    }

    void update() {
        ImageView v = (ImageView) findViewById(R.id.seat_image);
        v.setImageResource(down ? R.drawable.seat_light : R.drawable.seat);

        if (downListener != null) {
            if (down)
                downListener.down(this);
            else
                downListener.up(this);
        }
    }
}
