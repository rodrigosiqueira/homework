package com.learn.android.simplePlayer;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class simplePlayer extends Activity
{
    private MediaPlayer mediaPlayer;
    private int playbackPostion = 0;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Button startPlayerBtn = (Button)findViewById(R.id.startPlayerBtn);
        Button pausePlayerBtn = (Button)findViewById(R.id.pausePlayerBtn);
        Button restartPlayerBtn = (Button)findViewById(R.id.restartPlayerBtn);

        startPlayerBtn.setOnClickListener(new OnClickListener(){
          @Override
          public void onClick(View view)
          {
            try
            {
              playLocalAudio();
            }
            catch(Exception e)
            {
              e.printStackTrace();
            }
          }
        });

      pausePlayerBtn.setOnClickListener(new OnClickListener(){
        @Override
        public void onClick(View view)
        {
          if (mediaPlayer != null)
          {
            playbackPostion = mediaPlayer.getCurrentPosition();
            mediaPlayer.pause();
          }
        }
      });

      restartPlayerBtn.setOnClickListener(new OnClickListener(){
        @Override
        public void onClick(View view)
        {
          if (mediaPlayer != null && !mediaPlayer.isPlaying())
          {
            mediaPlayer.seekTo(playbackPostion);
            mediaPlayer.start();
          }
        }
      });
    }

    private void playLocalAudio() throws Exception
    {
      mediaPlayer = MediaPlayer.create(this, R.raw.play);
      mediaPlayer.start();
    }

    @Override
    protected void onDestroy()
    {
      super.onDestroy();
      killMediaPlayer();
    }

    private void killMediaPlayer()
    {
      if (mediaPlayer != null)
      {
        try
        {
          mediaPlayer.release();
        }
        catch(Exception e)
        {
          e.printStackTrace();
        }
      }
    }
}
