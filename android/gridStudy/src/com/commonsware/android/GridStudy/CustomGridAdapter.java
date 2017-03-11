package com.commonsware.android.GridStudy;

import android.content.Context;
import android.widget.BaseAdapter;
import android.widget.TextView;

import android.view.View;
import android.view.LayoutInflater;
import android.view.ViewGroup;


public class CustomGridAdapter extends BaseAdapter
{
  private Context context;
  private final String[] gridValues;

  //Constructor to initialize values
  public CustomGridAdapter(Context context, String[] gridValues)
  {
    this.context = context;
    this.gridValues = gridValues;
  }
   
  @Override
  public int getCount()
  {
    // Number of times getView method call depends upon gridValues.length
    return gridValues.length;
  }

  @Override
  public Object getItem(int position)
  {
      return null;
  }

  @Override
  public long getItemId(int position)
  {
    return 0;
  }

  // Number of times getView method call depends upon gridValues.length
  public View getView(int position, View convertView, ViewGroup parent)
  {
    LayoutInflater inflater = (LayoutInflater) context
              .getSystemService(Context.LAYOUT_INFLATER_SERVICE);

      View gridView;

      if (convertView == null)
      {
          gridView = new View(context);
          gridView = inflater.inflate( R.layout.grid_item , null);

          TextView textView = (TextView) gridView.findViewById(R.id.grid_label);
          textView.setText(gridValues[position]);
      }
      else
      {
         gridView = (View) convertView;
      }

      return gridView;
  }
}
