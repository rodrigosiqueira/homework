package com.learn.android.SpinnerTest;

import android.app.Activity;
import android.os.Bundle;

import android.view.View;

import android.widget.TextView;
import android.widget.ArrayAdapter;
import android.widget.AdapterView;
import android.widget.Spinner;

public class SpinnerTest extends Activity
  implements AdapterView.OnItemSelectedListener
{
    TextView selection;

    String[] items = {"this", "is", "a", "simple", "test", "of", "using",
              "list", "view.", "called", "when", "the", "activity", "is",
              "created"};
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        selection = (TextView)findViewById(R.id.selection);

        Spinner spin=(Spinner)findViewById(R.id.spinner);
        spin.setOnItemSelectedListener(this);
        ArrayAdapter<String> aa = new ArrayAdapter<String>(this,
            android.R.layout.simple_spinner_item, items);

        aa.setDropDownViewResource(
          android.R.layout.simple_spinner_dropdown_item);
        spin.setAdapter(aa);
    }

    public void onItemSelected(AdapterView<?> parent, View v, int position,
                               long id)
    {
      selection.setText(items[position]);
    }

    public void onNothingSelected(AdapterView<?> parent)
    {
      selection.setText("");
    }
}
