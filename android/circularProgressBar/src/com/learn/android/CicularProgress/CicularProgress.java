package com.learn.android.CicularProgress;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ProgressBar;

import android.animation.ObjectAnimator;
import android.view.animation.DecelerateInterpolator;

public class CicularProgress extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        ProgressBar progressBar = (ProgressBar) findViewById(R.id.progressBar);
        // see this max value coming back here, we animale towards that value
        ObjectAnimator animation = ObjectAnimator.ofInt (progressBar, "progress", 0, 500); 
        animation.setDuration (5000); //in milliseconds
        animation.setInterpolator (new DecelerateInterpolator ());
        animation.start ();
    }
}
