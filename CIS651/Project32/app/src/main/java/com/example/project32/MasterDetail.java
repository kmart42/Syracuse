package com.example.project32;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.ViewCompat;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.View;

public class MasterDetail extends AppCompatActivity implements ListFragment.OnItemSelectedListener {
    private boolean twoPane;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new);
        //setContentView(R.layout.activity_master_detail);
        if(savedInstanceState==null)
        {
            getSupportFragmentManager().beginTransaction().replace(R.id.main_container,new ListFragment()).commit();
//            getSupportFragmentManager().beginTransaction().replace(R.id.recylcer_view,new ListFragment()).commit();
        }
        twoPane=false;
//        if(findViewById(R.id.detail_container)!=null)
//        {
//            twoPane=true;
//        }
    }

    @Override
    public void onListItemSelected(View sharedView, PostModel movie) {
        Bundle args=new Bundle();
        args.putInt("img_id",Integer.parseInt(movie.url));
        args.putString("mtitle",movie.name);
        args.putString("myear",movie.year);
        args.putFloat("rating", Float.parseFloat(movie.rating));
        args.putString("description", movie.description);
        args.putString("director", movie.director);
        args.putString("length", movie.length);
        args.putString("cast", movie.stars);
        Fragment masterDetail=new DetailMaster();
        masterDetail.setArguments(args);

            getSupportFragmentManager().beginTransaction().addSharedElement(sharedView, ViewCompat.getTransitionName(sharedView))
//                    .replace(R.id.main_container,masterDetail)
                    .replace(R.id.recylcer_view,masterDetail)
                    .addToBackStack(null).commit();


    }

}