package com.example.project2;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

public class MovieDetailFragment extends Fragment {
    public static MovieDetailFragment newInstance(int i, String t, String y, float r, String d)
    {
        MovieDetailFragment movieDetailFragment=new MovieDetailFragment();
        Bundle args=new Bundle();
        args.putInt("id",i);
        args.putString("title",t);
        args.putString("year",y);
        args.putFloat("rating",r);
        args.putString("description",d);
        movieDetailFragment.setArguments(args);
        return movieDetailFragment;
    }
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        Bundle args = getArguments();
        final View v = inflater.inflate(R.layout.fragment_layout, container, false);
        ImageView imageView=v.findViewById(R.id.large_image);
        imageView.setImageResource(args.getInt("id"));
        TextView editText=v.findViewById(R.id.title_text);
        editText.setText(args.getString("title"));
        TextView yearText=v.findViewById(R.id.year_text);
        yearText.setText(args.getString("year"));
        RatingBar ratingBar=v.findViewById(R.id.movie_rating);
        ratingBar.setRating(args.getFloat("rating"));
        TextView descriptionText=v.findViewById(R.id.description);
        descriptionText.setText(args.getString("description"));
        TextView actorText=v.findViewById(R.id.actor_text);
        actorText.setText(args.getString("stars"));
        return v;
    }
}