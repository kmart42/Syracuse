package com.example.lab1;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.os.Bundle;
import android.text.Editable;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText btnName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void btnHorizontal(View view, LinearLayout ll){
        HorizontalScrollView horizontalScrollView= new HorizontalScrollView(this);
        LinearLayout.LayoutParams scrollViewParams = new
                LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT);
        horizontalScrollView.setLayoutParams(scrollViewParams);

        Button b = new Button(this);
        Integer count = ll.getChildCount()+1;
        b.setText(count.toString());
        ll.addView(b);

    }

    // Helper for horizontal view
    public void AddHorizontal(View view){
        // Create horizontal LL
        HorizontalScrollView horizontalScrollView= new HorizontalScrollView(this);
        LinearLayout.LayoutParams scrollViewParams = new
                LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT);
        horizontalScrollView.setLayoutParams(scrollViewParams);

        // Create ll view group
        final LinearLayout ll=new LinearLayout(this);
        ll.setOrientation(LinearLayout.HORIZONTAL);
        ll.setPadding(0,5,0,0);

        // Create new button and add to ll element
        Button b=new Button(this);
        Integer count=ll.getChildCount()+1;
        b.setText(count.toString());
        ll.addView(b);

        b.setOnClickListener(new View.OnClickListener() {
                                 @Override
                                 public void onClick(View v) {
                                     Button b = (Button) v;
                                     btnHorizontal(b, ll);
                                 }
                             });

        // Add new elements
        LinearLayout main_container= (LinearLayout) findViewById(R.id.mainContainer);
        horizontalScrollView.addView(ll);
        main_container.addView(horizontalScrollView);

    }

    //TODO Fix first line of portrait

    // Helper for regular/vertical view
    public void AddNew(View view) {
        // Create LinearLayout
        LinearLayout ll=new LinearLayout(this);
        ll.setOrientation(LinearLayout.HORIZONTAL);
        ll.setPadding(0,5,0,0);
        ll.setWeightSum(3);

        // Create view object EditText
        final EditText editText=new EditText(this);
        LinearLayout.LayoutParams params=new LinearLayout.LayoutParams(0,
                ViewGroup.LayoutParams.WRAP_CONTENT,2f);
        editText.setLayoutParams(params);

        // Create view object button
        Button b=new Button(this);
        LinearLayout.LayoutParams params2=new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT,1f);
        b.setLayoutParams(params2);
        // Get text for button, add to view
        btnName = findViewById(R.id.edittxtview);
        String inpt = btnName.getText().toString();
        b.setText(inpt);
        ll.addView(editText);
        ll.addView(b);

        // Handle button click
        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Implement the click handler here
                Button b = (Button)v;
                String btnCheck = editText.getText().toString();
                btnName.setText(btnCheck);
                if(!("h".equals(btnCheck))) {
                    AddNew(b);
                }
                else{
                    AddHorizontal(b);
                }
            }
        });

        // Show newly created elements
        LinearLayout main_container=findViewById(R.id.mainContainer);
        main_container.addView(ll);
    }

    public void AddNewInLandscape(View view){

        ImageView imageView=new ImageView(this);
        imageView.setImageResource(R.mipmap.su);

        Bitmap bMap = BitmapFactory.decodeResource(getResources(), R.mipmap.su_foreground);
        Bitmap bMapScaled = Bitmap.createScaledBitmap(bMap, 700, 700, true);
        imageView.setImageBitmap(bMapScaled);

        LinearLayout ll=findViewById(R.id.main_container);
        ll.addView(imageView);
    }


}