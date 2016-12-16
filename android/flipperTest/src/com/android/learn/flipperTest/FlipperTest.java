package com.android.learn.flipperTest;

import android.app.Activity;
import android.os.Bundle;

import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AnimationUtils;

import android.widget.Button;
import android.widget.ViewFlipper;

public class FlipperTest extends Activity
{
   String[] items = {"this", "is", "a", "simple", "test", "of", "using",
          "list", "view.", "called", "when", "the", "activity", "is",
          "created"};
    ViewFlipper flipper;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.main);

      flipper = (ViewFlipper)findViewById(R.id.details);

      flipper.setInAnimation(AnimationUtils.loadAnimation(this,
                                                       R.anim.push_left_in));
      flipper.setOutAnimation(AnimationUtils.loadAnimation(this,
                                                      R.anim.push_left_out));

      for (String item : items)
      {
        Button btn = new Button(this);

        btn.setText(item);

        flipper.addView(btn, new ViewGroup.LayoutParams(
                                        ViewGroup.LayoutParams.FILL_PARENT,
                                        ViewGroup.LayoutParams.FILL_PARENT));
      }
      flipper.setFlipInterval(2000);
      flipper.startFlipping();
    }
}
