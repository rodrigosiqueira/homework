package com.android.learn.BaseList;

import android.view.View;

import android.app.ListActivity;
import android.os.Bundle;

import android.widget.TextView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class BaseList extends ListActivity
{
  TextView selection;
  String[] items = {"this", "is", "a", "simple", "test", "of", "using",
              "list", "view.", "called", "when", "the", "activity", "is",
              "created"};

  @Override
  public void onCreate(Bundle savedInstanceState)
  {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.main);

      setContentView(R.layout.main);
      setListAdapter(new ArrayAdapter<String>(this, R.layout.row, R.id.label,
                         items));

      selection = (TextView)findViewById(R.id.selection);
  }

  public void onListemClick(ListView parent, View v, int position, long id)
  {
    selection.setText(items[position]);
  }
}
