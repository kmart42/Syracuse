package com.example.project2;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.core.view.ViewCompat;
import androidx.fragment.app.Fragment;

public class DetailFragment extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        View rootView=inflater.inflate(R.layout.fragment_layout, container, false);
        ImageView imageView=(ImageView)rootView.findViewById(R.id.large_image);
        TextView title=(TextView)rootView.findViewById(R.id.title_text);
        TextView year=(TextView)rootView.findViewById(R.id.year_text);
        TextView actor=(TextView)rootView.findViewById(R.id.actor_text);
        TextView des=(TextView)rootView.findViewById(R.id.description);
        RatingBar ratingBar=rootView.findViewById(R.id.movie_rating);
        Bundle args=getArguments();
        imageView.setImageResource(args.getInt("img_id"));
        title.setText(args.getString("mtitle"));
        ViewCompat.setTransitionName(imageView,args.getString("mtitle"));
        year.setText(args.getString("myear"));
        actor.setText(args.getString("mactor"));
        des.setText(args.getString("mdes"));
        ratingBar.setNumStars(args.getInt("mrating"));
        return rootView;
    }
}
