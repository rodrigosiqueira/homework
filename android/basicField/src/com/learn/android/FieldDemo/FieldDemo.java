package com.learn.android.FieldDemo;

import android.app.Activity;
import android.os.Bundle;

import android.widget.EditText;

public class FieldDemo extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        EditText fld=(EditText)findViewById(R.id.field);
        fld.setText("lalalalallalalalalalalal lululululululululul");
    }
}
