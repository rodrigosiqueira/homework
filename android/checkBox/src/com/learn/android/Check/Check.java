package com.learn.android.Check;

import android.app.Activity;
import android.os.Bundle;

import android.widget.CheckBox;
import android.widget.CompoundButton;

public class Check extends Activity
  implements CompoundButton.OnCheckedChangeListener
{
    CheckBox cb;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        cb=(CheckBox)findViewById(R.id.check);
        cb.setOnCheckedChangeListener(this);
    }

    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
    {
      if(isChecked)
      {
        cb.setText("This checkbox is: checked");
      }
      else
      {
        cb.setText("This checkbox is: unchecked");
      }
    }
}
