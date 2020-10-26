package com.example.lab3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.GestureDetectorCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.content.Intent;
import android.os.Bundle;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements FragmentTracker{
    private Fragment1 fragment1;
    private Fragment2 fragment2;
    private Fragment3 fragment3;
    private GestureDetectorCompat mDetector;
    private final PersonInfo pi=new PersonInfo();
    private int next=1;
    public TextView textView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        fragment1 = new Fragment1();
        fragment2 = new Fragment2();
        fragment3 = new Fragment3();
        loadTheFragment(fragment1);
        textView = (TextView) findViewById(R.id.title);
        textView.setText(Fragment1.fragmentTitle);
        mDetector = new GestureDetectorCompat(this, new MyGestureListener());
    }


    private class MyGestureListener extends GestureDetector.SimpleOnGestureListener{

        @Override
        public boolean onFling(MotionEvent event1, MotionEvent event2, float velocityX, float velocityY){
            if(event1.getX() < event2.getX()){
                Toast toast = Toast.makeText(MainActivity.this, "Fling right", Toast.LENGTH_SHORT);
                toast.show();
                nextFragment(1);
            }
            else
            {
                Toast toast = Toast.makeText(MainActivity.this, "Fling left", Toast.LENGTH_SHORT);
                toast.show();
                nextFragment(-1);
            }
            return true;
        }

    }

    @Override
    public boolean dispatchTouchEvent(MotionEvent ev){
        mDetector.onTouchEvent(ev);
        return super.dispatchTouchEvent(ev);
    }

    @Override
    public void fragmentVisible(String s) {

    }

    @Override
    public void goNext() {
        nextFragment(1);


    }

    @Override
    public void goBack() {
        nextFragment(-1);

    }

    @Override
    public void saveNameAndLastName(String name, String lname) {
//        PersonInfo pi = (PersonInfo) getIntent().getParcelableExtra("pi");
        pi.setName(name);
        pi.setLastname(lname);

    }

    @Override
    public void saveCityAndZip(String city, String zip) {
        pi.setCity(city);
        pi.setZip(zip);

    }

    @Override
    public void saveLanguage(String language) {
        pi.setLanguage(language);

    }

    @Override
    public void finished(){
        Intent i=new Intent(this, SummaryActivity.class);
        i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
        i.putExtra("pi",pi);
        startActivity(i);
    }

    private void loadTheFragment(Fragment f)
    {
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.replace(R.id.fragment_container,f);
        fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
        fragmentTransaction.commit();
    }


    public void nextFragment(Integer lr){
        next = next + lr;
        if(next==2){
            loadTheFragment(fragment2);
            textView.setText(Fragment2.fragmentTitle);
        }else if(next==0){
            next = 3;
            loadTheFragment(fragment3);
            textView.setText(Fragment3.fragmentTitle);
        }else if(next==3){
            loadTheFragment(fragment3);
            textView.setText(Fragment3.fragmentTitle);
        }else if(next==1){
            loadTheFragment(fragment1);
            textView.setText(Fragment1.fragmentTitle);
        }else if(next==4){
            next = 1;
            loadTheFragment(fragment1);
            textView.setText(Fragment1.fragmentTitle);
        }
    }

}


