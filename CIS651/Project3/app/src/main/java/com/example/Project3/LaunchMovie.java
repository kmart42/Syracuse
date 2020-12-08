package com.example.Project3;

import android.os.Bundle;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.ViewCompat;

import com.squareup.picasso.Picasso;

public class LaunchMovie extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_layout);
        Bundle extras = getIntent().getExtras();
        final String pic = (String) extras.getString("picture");
        final String title_text = (String) extras.getString("title_text");
        final String description = (String) extras.getString("description");
        final String year_text = (String) extras.getString("year_text");
        final String movie_rating = (String) extras.getString("movie_rating");
        ImageView picture = (ImageView) findViewById(R.id.large_image);
        Picasso.get().load(pic).into(picture);
        TextView des=(TextView)findViewById(R.id.description);
        TextView title=(TextView)findViewById(R.id.title_text);
        TextView year=(TextView)findViewById(R.id.year_text);
        RatingBar rb = (RatingBar)findViewById(R.id.movie_rating);
        rb.setRating(Float.parseFloat(movie_rating));
        des.setText(description);
        title.setText(title_text);
        year.setText(year_text);
    }
}
