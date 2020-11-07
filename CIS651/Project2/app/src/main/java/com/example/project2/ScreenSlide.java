package com.example.project2;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import androidx.fragment.app.Fragment;

import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import java.util.Map;

public class ScreenSlide extends Fragment {
    private MovieData md=new MovieData();
    public int position;
    private final MyRecyclerAdapter myRecyclerAdapter = new MyRecyclerAdapter(md.getMoviesList());
    ImageView imageView;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        FragmentManager fragmentManager = getFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();

        Map hashMap = myRecyclerAdapter.getItem(position);
        MovieDetailFragment movieDetailFragment=MovieDetailFragment.newInstance((int)hashMap.get("image"),
                hashMap.get("name").toString(),hashMap.get("year").toString(),
                Float.parseFloat(hashMap.get("rating").toString()),hashMap.get("description").toString(), hashMap.get("stars").toString());

        fragmentTransaction.replace(R.id.pager,movieDetailFragment);
        fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
        fragmentTransaction.commit();


//        HashMap curr = md.getItem(position);
//        imageView = (ImageView) imageView.findViewById(R.id.large_image);
//        imageView.setImageResource(R.drawable.alice);

//        fragmentTransaction.replace(R.id.detailFragment,movieDetailFragment);
//        fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
//        fragmentTransaction.commit();

        ViewGroup rootView = (ViewGroup) inflater.inflate(
                R.layout.fragment_layout, container, false);

        return rootView;
    }

}
