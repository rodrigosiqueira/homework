package com.commonsware.android.GridStudy;

import android.content.Context;
import android.app.Activity;
import android.os.Bundle;

import android.view.View;
import android.view.ViewGroup;

import android.widget.TextView;
import android.widget.GridView;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.Toast;
import android.widget.AdapterView.OnItemClickListener;

public class GridStudy extends Activity
{
  GridView gridView;
  String[] items = {"this", "is", "a", "simple", "test", "of", "using",
            "list", "view.", "called", "when", "the", "activity", "is",
            "created", "this", "is", "a", "simple", "test", "of", "using",
            "list", "view.", "called", "when", "the", "activity", "is",
            "created"};


  /** Called when the activity is first created. */
  @Override
  public void onCreate(Bundle savedInstanceState)
  {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.main);

      // Grid basic setup
      gridView = (GridView)findViewById(R.id.grid);

      // Add adapter
      gridView.setAdapter(new CustomGridAdapter(this, items));
      gridView.setOnItemClickListener(new OnItemClickListener()
      {
        public void onItemClick(AdapterView<?> parent, View v, int position,
                                long id)
        {
          Toast.makeText(getApplicationContext(),
                         ((TextView) v.findViewById(R.id.grid_label))
                                      .getText(),
                          Toast.LENGTH_SHORT).show();
        }
      });
  }
}
