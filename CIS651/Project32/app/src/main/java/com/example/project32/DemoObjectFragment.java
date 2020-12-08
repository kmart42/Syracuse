package com.example.project32;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import org.w3c.dom.Text;

//public class DemoObjectFragment extends Fragment {
//    public static final String ARG_TITLE = "title";
//    public static final String ARG_YEAR = "year";
//    public static final String ARG_POSTER = "poster";
//    public static final String ARG_RATING = "rating";
//    public static final String ARG_DESCRIPTION = "description";
//
//    @Override
//    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
//        // The last two arguments ensure LayoutParams are inflated
//        // properly.
//        View rootView = inflater.inflate(R.layout.fragment_collection_object, container, false);
//        Bundle args = getArguments();
//        ((TextView) rootView.findViewById(R.id.movie_title)).setText(args.getString(ARG_TITLE));
//        ((TextView) rootView.findViewById(R.id.movie_year)).setText(args.getString(ARG_YEAR));
//        ((ImageView) rootView.findViewById(R.id.movie_poster)).setImageResource(args.getInt(ARG_POSTER));
//        ((RatingBar)rootView.findViewById(R.id.movie_rating)).setRating(args.getFloat(ARG_RATING));
//        ((TextView)rootView.findViewById(R.id.description)).setText(args.getString(ARG_DESCRIPTION));
//        return rootView;
//    }
//}
