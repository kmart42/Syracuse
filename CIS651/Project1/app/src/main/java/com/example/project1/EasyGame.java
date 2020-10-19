package com.example.project1;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;


import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Arrays;
import java.util.Collections;


public class EasyGame extends AppCompatActivity {
    ImageView tile11, tile12, tile13, tile14,
    tile21, tile22, tile23, tile24,
    tile31, tile32, tile33, tile34;

    int image11, image12, image13, image14, image15, image16,
    image21, image22, image23, image24, image25, image26;

    Integer[] tileArray = {11, 12, 13, 14, 15, 16, 21, 22, 23, 24, 25, 26};

    int firstTile, secondTile;
    int clickedFirst, clickedSecond;
    int tileNumber = 1;

    int mCounter = 0;
    TextView score;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.easy_grid);
        score = (TextView) findViewById(R.id.score_count);
        score.setText("Number of clicks: " + 0);

        tile11 = (ImageView) findViewById(R.id.tile11);
        tile12 = (ImageView) findViewById(R.id.tile12);
        tile13 = (ImageView) findViewById(R.id.tile13);
        tile14 = (ImageView) findViewById(R.id.tile14);
        tile21 = (ImageView) findViewById(R.id.tile21);
        tile22 = (ImageView) findViewById(R.id.tile22);
        tile23 = (ImageView) findViewById(R.id.tile23);
        tile24 = (ImageView) findViewById(R.id.tile24);
        tile31 = (ImageView) findViewById(R.id.tile31);
        tile32 = (ImageView) findViewById(R.id.tile32);
        tile33 = (ImageView) findViewById(R.id.tile33);
        tile34 = (ImageView) findViewById(R.id.tile34);

        tile11.setTag("0");
        tile12.setTag("1");
        tile13.setTag("2");
        tile14.setTag("3");
        tile21.setTag("4");
        tile22.setTag("5");
        tile23.setTag("6");
        tile24.setTag("7");
        tile31.setTag("8");
        tile32.setTag("9");
        tile33.setTag("10");
        tile34.setTag("11");

        frontOfTilesResources();

        Collections.shuffle(Arrays.asList(tileArray));

        tile11.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile11, theTile);
            }
        });
        tile12.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile12, theTile);
            }
        });
        tile13.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile13, theTile);
            }
        });
        tile14.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile14, theTile);
            }
        });
        tile21.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile21, theTile);
            }
        });
        tile22.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile22, theTile);
            }
        });
        tile23.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile23, theTile);
            }
        });
        tile24.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile24, theTile);
            }
        });
        tile31.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile31, theTile);
            }
        });
        tile32.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile32, theTile);
            }
        });
        tile33.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile33, theTile);
            }
        });
        tile34.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile34, theTile);
            }
        });
    }

    private void flipCheck(ImageView img, int tile){
        mCounter++;
        score.setText("Number of clicks: " + mCounter);
        if(tileArray[tile] == 11){
            img.setImageResource(image11);
        }else if(tileArray[tile] == 12){
            img.setImageResource(image12);
        }else if(tileArray[tile] == 13){
            img.setImageResource(image13);
        }else if(tileArray[tile] == 14){
            img.setImageResource(image14);
        }else if(tileArray[tile] == 15){
            img.setImageResource(image15);
        }else if(tileArray[tile] == 16){
            img.setImageResource(image16);
        }else if(tileArray[tile] == 21){
            img.setImageResource(image21);
        }else if(tileArray[tile] == 22){
            img.setImageResource(image22);
        }else if(tileArray[tile] == 23){
            img.setImageResource(image23);
        }else if(tileArray[tile] == 24){
            img.setImageResource(image24);
        }else if(tileArray[tile] == 25){
            img.setImageResource(image25);
        }else if(tileArray[tile] == 26){
            img.setImageResource(image26);
        }

        if(tileNumber == 1) {
            firstTile = tileArray[tile];
            if (firstTile > 20) {
                firstTile = firstTile - 10;
            }
            tileNumber = 2;
            clickedFirst = tile;

            img.setEnabled(false);
        }else if(tileNumber == 2){
            secondTile = tileArray[tile];
            if (secondTile > 20) {
                secondTile = secondTile - 10;
            }
            tileNumber = 1;
            clickedSecond = tile;

            tile11.setEnabled(false);
            tile12.setEnabled(false);
            tile13.setEnabled(false);
            tile14.setEnabled(false);
            tile21.setEnabled(false);
            tile22.setEnabled(false);
            tile23.setEnabled(false);
            tile24.setEnabled(false);
            tile31.setEnabled(false);
            tile32.setEnabled(false);
            tile33.setEnabled(false);
            tile34.setEnabled(false);

            Handler handler = new Handler();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    calculate();
                }
            }, 1000);
        }
    }

    private void calculate() {
        if (firstTile == secondTile) {
            if (clickedFirst == 0) {
                tile11.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 1) {
                tile12.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 2) {
                tile13.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 3) {
                tile14.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 4) {
                tile21.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 5) {
                tile22.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 6) {
                tile23.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 7) {
                tile24.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 8) {
                tile31.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 9) {
                tile32.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 10) {
                tile33.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 11) {
                tile34.setVisibility(View.INVISIBLE);
            }

            if (clickedSecond == 0) {
                tile11.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 1) {
                tile12.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 2) {
                tile13.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 3) {
                tile14.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 4) {
                tile21.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 5) {
                tile22.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 6) {
                tile23.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 7) {
                tile24.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 8) {
                tile31.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 9) {
                tile32.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 10) {
                tile33.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 11) {
                tile34.setVisibility(View.INVISIBLE);
            }
        }else {
            tile11.setImageResource(R.drawable.linux);
            tile12.setImageResource(R.drawable.linux);
            tile13.setImageResource(R.drawable.linux);
            tile14.setImageResource(R.drawable.linux);
            tile21.setImageResource(R.drawable.linux);
            tile22.setImageResource(R.drawable.linux);
            tile23.setImageResource(R.drawable.linux);
            tile24.setImageResource(R.drawable.linux);
            tile31.setImageResource(R.drawable.linux);
            tile32.setImageResource(R.drawable.linux);
            tile33.setImageResource(R.drawable.linux);
            tile34.setImageResource(R.drawable.linux);
        }

        tile11.setEnabled(true);
        tile12.setEnabled(true);
        tile13.setEnabled(true);
        tile14.setEnabled(true);
        tile21.setEnabled(true);
        tile22.setEnabled(true);
        tile23.setEnabled(true);
        tile24.setEnabled(true);
        tile31.setEnabled(true);
        tile32.setEnabled(true);
        tile33.setEnabled(true);
        tile34.setEnabled(true);

        checkEnd();
    }

    private void checkEnd(){
        if(tile11.getVisibility() == View.INVISIBLE &&
                tile12.getVisibility() == View.INVISIBLE &&
                tile13.getVisibility() == View.INVISIBLE &&
                tile14.getVisibility() == View.INVISIBLE &&
                tile21.getVisibility() == View.INVISIBLE &&
                tile22.getVisibility() == View.INVISIBLE &&
                tile23.getVisibility() == View.INVISIBLE &&
                tile24.getVisibility() == View.INVISIBLE &&
                tile31.getVisibility() == View.INVISIBLE &&
                tile32.getVisibility() == View.INVISIBLE &&
                tile33.getVisibility() == View.INVISIBLE &&
                tile34.getVisibility() == View.INVISIBLE){

            AlertDialog.Builder endGame = new AlertDialog.Builder(EasyGame.this);
            endGame.setMessage("GAME OVER\nNumber of clicks: "+mCounter).setCancelable(false)
                    .setPositiveButton("NEW GAME", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                            startActivity(intent);
                            finish();
                        }
                    });
            AlertDialog alertDialog = endGame.create();
            alertDialog.show();
        }

    }

    private void frontOfTilesResources(){
        image11 = R.drawable.red_hat;
        image12 = R.drawable.centos;
        image13 = R.drawable.debian;
        image14 = R.drawable.fedora;
        image15 = R.drawable.kali_linux;
        image16 = R.drawable.linux_mint;
        image21 = R.drawable.red_hat;
        image22 = R.drawable.centos;
        image23 = R.drawable.debian;
        image24 = R.drawable.fedora;
        image25 = R.drawable.kali_linux;
        image26 = R.drawable.linux_mint;

    }

}
