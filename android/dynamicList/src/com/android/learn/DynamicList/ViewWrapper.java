package com.android.learn.DynamicList;

import android.view.View;
import android.widget.TextView;
import android.widget.ImageView;

public class ViewWrapper
{
  View base;
  TextView label = null;
  ImageView icon = null;

  ViewWrapper(View base)
  {
    this.base = base;
  }

  TextView getLabel()
  {
    if (label == null)
    {
      label = (TextView)base.findViewById(R.id.label);
    }
    return (label);
  }

  ImageView getIcon()
  {
    if (icon == null)
    {
      icon = (ImageView)base.findViewById(R.id.icon);
    }
    return (icon);
  }
}
