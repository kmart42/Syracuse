package com.example.project2;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentStatePagerAdapter;
import androidx.viewpager.widget.PagerAdapter;
import androidx.viewpager.widget.PagerTabStrip;
import androidx.viewpager.widget.ViewPager;

import java.util.Map;


public class SlideActivity extends FragmentActivity {
        MovieData md=new MovieData();
        private int pages = md.getSize();
        private ViewPager mPager;
        private PagerAdapter pagerAdapter;

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_screen);

            // Instantiate a ViewPager and a PagerAdapter.
            mPager = (ViewPager) findViewById(R.id.pager);
            pagerAdapter = new ScreenSlidePagerAdapter(getSupportFragmentManager());
            mPager.setAdapter(pagerAdapter);

        }

        @Override
        public void onBackPressed() {
            if (mPager.getCurrentItem() == 0) {
                // If the user is currently looking at the first step, allow the system to handle the
                // Back button. This calls finish() on this activity and pops the back stack.
                super.onBackPressed();
            } else {
                // Otherwise, select the previous step.
                mPager.setCurrentItem(mPager.getCurrentItem() - 1);
            }
        }


        private class ScreenSlidePagerAdapter extends FragmentStatePagerAdapter {
            MovieData md=new MovieData();

            public ScreenSlidePagerAdapter(FragmentManager fm) {
                super(fm);
            }
            @Override
            public Fragment getItem(int position) {
                Variables.setmPosition(position);
                System.out.println(position);
                return new ScreenSlide();
            }

            @Override
            public int getCount() {
                return pages;
            }

            @Override
            public CharSequence getPageTitle(int position) {
                Map hashMap = md.moviesList.get(position);
                return hashMap.get("name").toString();
        }
    }

}
