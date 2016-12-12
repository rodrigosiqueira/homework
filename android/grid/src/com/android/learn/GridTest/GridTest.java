package com.android.learn.GridTest;

import android.content.Context;
import android.app.Activity;
import android.os.Bundle;

import android.view.View;
import android.view.ViewGroup;

import android.widget.TextView;
import android.widget.GridView;
import android.widget.ArrayAdapter;
import android.widget.AdapterView;
import android.widget.Button;

public class GridTest extends Activity
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
        selection=(TextView)findViewById(R.id.selection);

        GridView g = (GridView)findViewById(R.id.grid);
        g.setAdapter(new FunnyLookingAdapter(this,
          android.R.layout.simple_list_item_1, items));
        g.setOnItemSelectedListener(this);
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

    private class FunnyLookingAdapter extends ArrayAdapter
    {
      Context ctxt;

      FunnyLookingAdapter(Context ctxt, int resource, String[] items)
      {
        super(ctxt, resource, items);

        this.ctxt = ctxt;
      }

      public View getView(int position, View convertView, ViewGroup parent)
      {
        TextView label = (TextView)convertView;
        if (convertView == null)
        {
          convertView = new TextView(ctxt);
          label = (TextView)convertView;
        }
        label.setText(items[position]);
        return (convertView);
      }
    }
}
