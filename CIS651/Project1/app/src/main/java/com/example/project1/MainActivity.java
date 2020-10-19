package com.example.project1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final String[] gameDifficulty = new String[1];
        final Spinner spinner = (Spinner) findViewById(R.id.welcome_spinner);
        final Button button = (Button) findViewById(R.id.start_button);
        final ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.difficulties, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if(parent.getSelectedItem().toString().matches("Easy")){
                    gameDifficulty[0] = "Easy";
                }
                else if(parent.getSelectedItem().toString().matches("Medium")){
                    gameDifficulty[0] = "Medium";
                }
                else if(parent.getSelectedItem().toString().matches("Hard")){
                    gameDifficulty[0] = "Hard";
                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(gameDifficulty[0].matches("Easy")){
                    startEasy();
                }else if(gameDifficulty[0].matches("Medium")){
                    startMedium();
                }else if(gameDifficulty[0].matches("Hard")){
                    startHard();
                }

            }
        });

    }

    public void startEasy(){
        Intent intent = new Intent(this, EasyGame.class);
        startActivity(intent);
    }

    public void startMedium(){
        Intent intent = new Intent(this, MediumGame.class);
        startActivity(intent);
    }
    public void startHard(){
        Intent intent = new Intent(this, HardGame.class);
        startActivity(intent);
    }
}