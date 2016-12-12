package com.learn.android.ListViewTest;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;

import android.view.View;

import android.widget.AdapterView;
import android.widget.TextView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class ListViewTest extends ListActivity
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
        setListAdapter(new ArrayAdapter<String>(this,
                        android.R.layout.simple_list_item_1,
                        items));
        selection=(TextView)findViewById(R.id.selection);
    }

    public void onListItemClick(ListView parent, View v, int position, long id)
    {
      selection.setText(items[position]);
    }
}
