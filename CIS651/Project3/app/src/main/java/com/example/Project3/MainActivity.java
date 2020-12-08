package com.example.Project3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.Toast;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    static class PostModel{
        //                public String postKey;
        public String title;
        public String description;
        public String image;
        public String year;
        public String rating;
        public String stars;
        public PostModel(String title, String description, String image, String year, String stars, String rating) {
            this.year=year;
            this.rating=rating;
            this.stars=stars;
            this.description=description;
            this.image=image;
            this.title=title;
//                   this.postKey=key;
        }
    }
    private List<PostModel> postsList;
    private MovieData movieData=new MovieData();
    private final MessageRecyclerAdapter myRecyclerAdapter = new MessageRecyclerAdapter(null);
    private FirebaseAuth mAuth;
    private FirebaseUser currentUser;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Initialize Firebase Auth
        mAuth = FirebaseAuth.getInstance();
        currentUser = mAuth.getCurrentUser();
    }


    @Override
    protected void onResume() {
        super.onResume();
        new CountDownTimer(3000, 1000) {

            public void onTick(long millisUntilFinished) {

            }

            public void onFinish() {
                if(currentUser==null){
                    Toast.makeText(MainActivity.this, "No user found", Toast.LENGTH_SHORT).show();
                    startActivity(new Intent(MainActivity.this,SignupLogin.class));
                    finish();
                }
                else{
                    if(currentUser.isEmailVerified()) {
                        postsList = new ArrayList<>();
                        //Toast.makeText(MainActivity.this, "User already signed in", Toast.LENGTH_SHORT).show();
                        startActivity(new Intent(MainActivity.this, HomeActivity.class));
                        finish();
                    }
                    else{
                        Toast.makeText(MainActivity.this, "Please verify your email and login.", Toast.LENGTH_SHORT).show();
                        startActivity(new Intent(MainActivity.this, SignupLogin.class));
                        finish();
                    }
                }

            }
        }.start();
    }

}
