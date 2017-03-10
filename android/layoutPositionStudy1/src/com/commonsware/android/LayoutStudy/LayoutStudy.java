package com.commonsware.android.LayoutStudy;

import android.app.Activity;
import android.os.Bundle;

public class LayoutStudy extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }
}
