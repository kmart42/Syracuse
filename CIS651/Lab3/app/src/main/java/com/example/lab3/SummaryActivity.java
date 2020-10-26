package com.example.lab3;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class SummaryActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.final_view);

        PersonInfo pi = (PersonInfo) getIntent().getParcelableExtra("pi");
        TextView nl = findViewById(R.id.name_lastname);
        TextView cz = findViewById(R.id.city_zip);
        TextView lang = findViewById(R.id.lang1);
        nl.setText("Name : " + pi.getName() + " LastName : " + pi.getLastname());
        cz.setText("City : " + pi.getCity() + " Zip : " + pi.getZip());
        lang.setText("Language : " + pi.getLanguage());
    }
}

