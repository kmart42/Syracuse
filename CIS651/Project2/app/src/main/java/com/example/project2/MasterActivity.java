package com.example.project2;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;

import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import java.util.Map;

public class MasterActivity extends FragmentActivity {
    MovieData md = new MovieData();
    private int pages = md.getSize();
    private boolean twoPane;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mater_layout);
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction().replace(R.id.main_container, new ListFragment()).commit();
        }
        twoPane = false;
        if (findViewById(R.id.detail_container) != null) {
            twoPane = true;
        }

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
            final Button finalBtn = btn;
            btn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    LayoutInflater inflater = LayoutInflater
                            .from(getApplicationContext());
                    View newView = inflater.inflate(R.layout.fragment_layout, null);
                    FrameLayout frameLayout = new FrameLayout(MasterActivity.this);
                    frameLayout.addView(newView);
//                    FragmentManager fragmentManager = getSupportFragmentManager();
//                    FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
//
//                    MovieDetailFragment movieDetailFragment=MovieDetailFragment.newInstance((int)hashMap.get("image"),
//                            hashMap.get("name").toString(),hashMap.get("year").toString(),
//                            Float.parseFloat(hashMap.get("rating").toString()),hashMap.get("description").toString());
//
//                    fragmentTransaction.replace(R.id.main_container,movieDetailFragment);
//                    fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
//                    fragmentTransaction.commit();


                    Toast.makeText(view.getContext(),
                            "Button clicked index = " + finalI, Toast.LENGTH_SHORT)
                            .show();
                }
            });
        }
//        return rootView;
    }
}