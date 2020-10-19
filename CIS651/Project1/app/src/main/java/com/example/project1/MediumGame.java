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


public class MediumGame extends AppCompatActivity {
    ImageView tile11M, tile12M, tile13M, tile14M,
            tile21M, tile22M, tile23M, tile24M,
            tile31M, tile32M, tile33M, tile34M,
            tile41M, tile42M, tile43M, tile44M;

    int image11, image12, image13, image14, image15, image16, image17, image18,
            image21, image22, image23, image24, image25, image26, image27, image28;

    Integer[] tileArray = {11, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 25, 26, 27, 28};

    int firstTile, secondTile;
    int clickedFirst, clickedSecond;
    int tileNumber = 1;

    int mCounter = 0;
//    TextView score;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.medium_grid);
//        score = (TextView) findViewById(R.id.score_countM);
//        score.setText("Number of clicks: " + 0);

        tile11M = (ImageView) findViewById(R.id.tile11M);
        tile12M = (ImageView) findViewById(R.id.tile12M);
        tile13M = (ImageView) findViewById(R.id.tile13M);
        tile14M = (ImageView) findViewById(R.id.tile14M);
        tile21M = (ImageView) findViewById(R.id.tile21M);
        tile22M = (ImageView) findViewById(R.id.tile22M);
        tile23M = (ImageView) findViewById(R.id.tile23M);
        tile24M = (ImageView) findViewById(R.id.tile24M);
        tile31M = (ImageView) findViewById(R.id.tile31M);
        tile32M = (ImageView) findViewById(R.id.tile32M);
        tile33M = (ImageView) findViewById(R.id.tile33M);
        tile34M = (ImageView) findViewById(R.id.tile34M);
        tile41M = (ImageView) findViewById(R.id.tile41M);
        tile42M = (ImageView) findViewById(R.id.tile42M);
        tile43M = (ImageView) findViewById(R.id.tile43M);
        tile44M = (ImageView) findViewById(R.id.tile44M);

        tile11M.setTag("0");
        tile12M.setTag("1");
        tile13M.setTag("2");
        tile14M.setTag("3");
        tile21M.setTag("4");
        tile22M.setTag("5");
        tile23M.setTag("6");
        tile24M.setTag("7");
        tile31M.setTag("8");
        tile32M.setTag("9");
        tile33M.setTag("10");
        tile34M.setTag("11");
        tile41M.setTag("12");
        tile42M.setTag("13");
        tile43M.setTag("14");
        tile44M.setTag("15");

        frontOfTilesResources();

        Collections.shuffle(Arrays.asList(tileArray));

        tile11M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile11M, theTile);
            }
        });
        tile12M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile12M, theTile);
            }
        });
        tile13M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile13M, theTile);
            }
        });
        tile14M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile14M, theTile);
            }
        });
        tile21M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile21M, theTile);
            }
        });
        tile22M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile22M, theTile);
            }
        });
        tile23M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile23M, theTile);
            }
        });
        tile24M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile24M, theTile);
            }
        });
        tile31M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile31M, theTile);
            }
        });
        tile32M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile32M, theTile);
            }
        });
        tile33M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile33M, theTile);
            }
        });
        tile34M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile34M, theTile);
            }
        });
        tile41M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile41M, theTile);
            }
        });
        tile42M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile42M, theTile);
            }
        });
        tile43M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile43M, theTile);
            }
        });
        tile44M.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int theTile = Integer.parseInt((String) v.getTag());
                flipCheck(tile44M, theTile);
            }
        });
    }

    private void flipCheck(ImageView img, int tile){
        mCounter++;
//        score.setText("Number of clicks: " + mCounter);
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
        }else if(tileArray[tile] == 17){
            img.setImageResource(image17);
        }else if(tileArray[tile] == 18){
            img.setImageResource(image18);
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
        }else if(tileArray[tile] == 27){
            img.setImageResource(image27);
        }else if(tileArray[tile] == 28){
            img.setImageResource(image28);
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

            tile11M.setEnabled(false);
            tile12M.setEnabled(false);
            tile13M.setEnabled(false);
            tile14M.setEnabled(false);
            tile21M.setEnabled(false);
            tile22M.setEnabled(false);
            tile23M.setEnabled(false);
            tile24M.setEnabled(false);
            tile31M.setEnabled(false);
            tile32M.setEnabled(false);
            tile33M.setEnabled(false);
            tile34M.setEnabled(false);
            tile41M.setEnabled(false);
            tile42M.setEnabled(false);
            tile43M.setEnabled(false);
            tile44M.setEnabled(false);

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
                tile11M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 1) {
                tile12M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 2) {
                tile13M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 3) {
                tile14M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 4) {
                tile21M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 5) {
                tile22M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 6) {
                tile23M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 7) {
                tile24M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 8) {
                tile31M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 9) {
                tile32M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 10) {
                tile33M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 11) {
                tile34M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 12) {
                tile41M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 13) {
                tile42M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 14) {
                tile43M.setVisibility(View.INVISIBLE);
            } else if (clickedFirst == 15) {
                tile44M.setVisibility(View.INVISIBLE);
            }

            if (clickedSecond == 0) {
                tile11M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 1) {
                tile12M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 2) {
                tile13M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 3) {
                tile14M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 4) {
                tile21M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 5) {
                tile22M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 6) {
                tile23M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 7) {
                tile24M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 8) {
                tile31M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 9) {
                tile32M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 10) {
                tile33M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 11) {
                tile34M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 12) {
                tile41M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 13) {
                tile42M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 14) {
                tile43M.setVisibility(View.INVISIBLE);
            } else if (clickedSecond == 15) {
                tile44M.setVisibility(View.INVISIBLE);
            }

        }else {
            tile11M.setImageResource(R.drawable.linux);
            tile12M.setImageResource(R.drawable.linux);
            tile13M.setImageResource(R.drawable.linux);
            tile14M.setImageResource(R.drawable.linux);
            tile21M.setImageResource(R.drawable.linux);
            tile22M.setImageResource(R.drawable.linux);
            tile23M.setImageResource(R.drawable.linux);
            tile24M.setImageResource(R.drawable.linux);
            tile31M.setImageResource(R.drawable.linux);
            tile32M.setImageResource(R.drawable.linux);
            tile33M.setImageResource(R.drawable.linux);
            tile34M.setImageResource(R.drawable.linux);
            tile41M.setImageResource(R.drawable.linux);
            tile42M.setImageResource(R.drawable.linux);
            tile43M.setImageResource(R.drawable.linux);
            tile44M.setImageResource(R.drawable.linux);
        }

        tile11M.setEnabled(true);
        tile12M.setEnabled(true);
        tile13M.setEnabled(true);
        tile14M.setEnabled(true);
        tile21M.setEnabled(true);
        tile22M.setEnabled(true);
        tile23M.setEnabled(true);
        tile24M.setEnabled(true);
        tile31M.setEnabled(true);
        tile32M.setEnabled(true);
        tile33M.setEnabled(true);
        tile34M.setEnabled(true);
        tile41M.setEnabled(true);
        tile42M.setEnabled(true);
        tile43M.setEnabled(true);
        tile44M.setEnabled(true);

        checkEnd();
    }

    private void checkEnd(){
        if(tile11M.getVisibility() == View.INVISIBLE &&
                tile12M.getVisibility() == View.INVISIBLE &&
                tile13M.getVisibility() == View.INVISIBLE &&
                tile14M.getVisibility() == View.INVISIBLE &&
                tile21M.getVisibility() == View.INVISIBLE &&
                tile22M.getVisibility() == View.INVISIBLE &&
                tile23M.getVisibility() == View.INVISIBLE &&
                tile24M.getVisibility() == View.INVISIBLE &&
                tile31M.getVisibility() == View.INVISIBLE &&
                tile32M.getVisibility() == View.INVISIBLE &&
                tile33M.getVisibility() == View.INVISIBLE &&
                tile34M.getVisibility() == View.INVISIBLE &&
                tile41M.getVisibility() == View.INVISIBLE &&
                tile42M.getVisibility() == View.INVISIBLE &&
                tile43M.getVisibility() == View.INVISIBLE &&
                tile44M.getVisibility() == View.INVISIBLE){

            AlertDialog.Builder endGame = new AlertDialog.Builder(MediumGame.this);
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
        image17 = R.drawable.ubuntu;
        image18 = R.drawable.suse;
        image21 = R.drawable.red_hat;
        image22 = R.drawable.centos;
        image23 = R.drawable.debian;
        image24 = R.drawable.fedora;
        image25 = R.drawable.kali_linux;
        image26 = R.drawable.linux_mint;
        image27 = R.drawable.ubuntu;
        image28 = R.drawable.suse;

    }

}
