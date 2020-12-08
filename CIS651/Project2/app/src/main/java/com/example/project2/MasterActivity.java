package com.example.project2;

import android.content.Intent;
import android.os.Bundle;
import android.transition.Fade;
import android.transition.Slide;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;

import java.util.Map;

public class MasterActivity extends FragmentActivity {
    MovieData md = new MovieData();
    private int pages = md.getSize();
    private boolean twoPane;
    private int backCheck;

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mater_layout);
        twoPane = false;
        if (findViewById(R.id.detail_container) != null) {
            twoPane = true;
        }
        backCheck = 0;

            final LinearLayout layout = (LinearLayout) findViewById(R.id.content);
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                    LinearLayout.LayoutParams.MATCH_PARENT,
                    LinearLayout.LayoutParams.WRAP_CONTENT);

            for (int i = 0; i < pages; i++) {
                final Map hashMap = md.moviesList.get(i);
                Button btn = new Button(this);
                btn.setId(i);
                btn.setText(hashMap.get("name").toString());
                btn.setTextSize(12);
//            btn.setBackgroundColor(Color.rgb(70, 80, 90));
                btn.setLayoutParams(params);
                layout.addView(btn);
                btn = ((Button) findViewById(i));
                final int finalI = i;
                final int finalI1 = i;
                btn.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        int img_id = (int)hashMap.get("image");
                        String mtitle = hashMap.get("name").toString();
                        String myear = hashMap.get("year").toString();
                        String mdes = hashMap.get("description").toString();
                        String mactor = hashMap.get("stars").toString();
                        double mrating = (double)hashMap.get("rating");
                        onMovieStart(img_id, mtitle, myear, mdes, mactor, mrating, twoPane);
                    }
                });
        }
    }

    protected void onMovieStart(int img, String mtitle, String myear, String mdes, String mactor, double mrating, boolean twoPane) {

        backCheck = 1;
        Bundle args = new Bundle();
        args.putInt("img_id", img);
        args.putDouble("mrating", mrating);
        args.putString("mtitle", mtitle);
        args.putString("myear", myear);
        args.putString("mdes", mdes);
        args.putString("mactor", mactor);
        Fragment detailFragment = new DetailFragment();
        detailFragment.setArguments(args);

        if (twoPane) {
            detailFragment.setEnterTransition(new Slide(Gravity.TOP));
            detailFragment.setExitTransition(new Slide(Gravity.BOTTOM));
            getSupportFragmentManager().beginTransaction().replace(R.id.detail_container, detailFragment).addToBackStack(null).commit();
        } else {
            setContentView(R.layout.activity_new);
            detailFragment.setSharedElementEnterTransition(new DetailsTransition());
            detailFragment.setEnterTransition(new Fade());
            detailFragment.setExitTransition(new Fade());
            detailFragment.setSharedElementReturnTransition(new DetailsTransition());
            getSupportFragmentManager().beginTransaction().replace(R.id.main_container, detailFragment).addToBackStack(null).commit();
        }

    }
        @Override
        public void onBackPressed() {
            if (backCheck == 1) {
                Intent intent = new Intent(this, MasterActivity.class);
                startActivity(intent);
            }
            else {
                Intent intent2 = new Intent(this, MainActivity.class);
                startActivity(intent2);
            }
        }
        };


