package com.example.project2;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import java.util.Map;

public class ScreenSlide extends Fragment {
    private MovieData md=new MovieData();

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        int pos = Variables.getmPosition();
        Map hashMap = md.moviesList.get(pos);
        String img = hashMap.get("image").toString();
        float rtg = ((Double) hashMap.get("rating")).floatValue();
        ViewGroup rootView = (ViewGroup) inflater.inflate(
                R.layout.fragment_layout, container, false);
        ImageView imageView = (ImageView) rootView.findViewById(R.id.large_image);
        imageView.setImageResource((getResources().getIdentifier(img, "drawable", getContext().getPackageName())));
        TextView titleText=rootView.findViewById(R.id.title_text);
        titleText.setText(hashMap.get("name").toString());
        TextView yearText=rootView.findViewById(R.id.year_text);
        yearText.setText(hashMap.get("year").toString());
        RatingBar ratingBar=rootView.findViewById(R.id.movie_rating);
        ratingBar.setRating(rtg);
        TextView starText=rootView.findViewById(R.id.actor_text);
        starText.setText(hashMap.get("stars").toString());
        TextView descriptionText=rootView.findViewById(R.id.description);
        descriptionText.setText(hashMap.get("description").toString());


        return rootView;
    }

}
