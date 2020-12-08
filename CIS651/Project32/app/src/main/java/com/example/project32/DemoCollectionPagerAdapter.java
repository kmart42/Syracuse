package com.example.project32;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentStatePagerAdapter;

import java.util.List;
import java.util.Map;

//public class DemoCollectionPagerAdapter extends FragmentStatePagerAdapter {
//    List<Map<String,?>> list_movie;
//    public DemoCollectionPagerAdapter(FragmentManager fm, List<Map<String,?>> list_m ) {
//        super(fm,BEHAVIOR_RESUME_ONLY_CURRENT_FRAGMENT);
//        this.list_movie=list_m;
//    }
//    @Override
//    public Fragment getItem(int i) {
//        Fragment fragment = new DemoObjectFragment();
//        Bundle args = new Bundle();
//        args.putString(DemoObjectFragment.ARG_TITLE, list_movie.get(i).get("name").toString());
//        args.putString(DemoObjectFragment.ARG_YEAR, list_movie.get(i).get("year").toString());
//        args.putInt(DemoObjectFragment.ARG_POSTER, Integer.parseInt(list_movie.get(i).get("image").toString()));
//        args.putFloat(DemoObjectFragment.ARG_RATING, Float.parseFloat(list_movie.get(i).get("rating").toString()));
//        args.putString(DemoObjectFragment.ARG_DESCRIPTION, list_movie.get(i).get("description").toString());
//        fragment.setArguments(args);
//        return fragment;
//    }
//    @Override
//    public int getCount() {
//        return list_movie.size();
//    }
//    @Override
//    public CharSequence getPageTitle(int position) {
//        return list_movie.get(position).get("name").toString();
//    }
//}
