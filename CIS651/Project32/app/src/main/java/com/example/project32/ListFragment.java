package com.example.project32;

import android.content.Context;
import android.os.Bundle;
import android.transition.Slide;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ListFragment extends Fragment implements QueryListener{


    @Override
    public void Filter(String query) {
        myRecyclerAdapter.getFilter().filter(query);
    }

    public interface OnItemSelectedListener{
        public void onListItemSelected(View sharedView, PostModel movie);
    }
    OnItemSelectedListener clickListener;

    private MovieData md = new MovieData();
    private MyRecyclerAdapter myRecyclerAdapter = new MyRecyclerAdapter();


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View rooView = inflater.inflate(R.layout.list_fragment, container,false);
        RecyclerView rv = rooView.findViewById(R.id.mainRecyclerView);
        myRecyclerAdapter.setRecyclerView(rv);
        LinearLayoutManager layoutManager = new LinearLayoutManager(getActivity());
        layoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        layoutManager.scrollToPosition(0);
        rv.setLayoutManager(layoutManager);
        rv.setAdapter(myRecyclerAdapter);
        rv.setItemAnimator(new DefaultItemAnimator());
//        loadMovies();
        return rooView;
    }

    @Override
    public void onAttach(Context context){
        super.onAttach(context);
        try{
            clickListener=(OnItemSelectedListener)context;
            myRecyclerAdapter.setOnItemClickListener(clickListener);


        }
        catch (ClassCastException ex)
        {
            throw new ClassCastException(context.toString()+"must implement EventTrack");
        }
    }

  private void loadMovies () {
        DatabaseReference movieRef = FirebaseDatabase.getInstance().getReference();
        List<Map<String, ?>> movieList = md.getMoviesList();
        for (Map movie : movieList){
            HashMap<String, String> regMap = new HashMap<>();

            regMap.put("title", movie.get("name").toString());
            regMap.put("year", movie.get("year").toString());
            regMap.put("director", movie.get("director").toString());
            regMap.put("length", movie.get("length").toString());
            regMap.put("cast", movie.get("stars").toString());
            regMap.put("rating", movie.get("rating").toString());
            regMap.put("description", movie.get("description").toString());
            regMap.put("imageUrl", movie.get("url").toString());
            movieRef.child("Movie").push().setValue(movie);
        }
    }
}
