package com.example.lab4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import androidx.appcompat.widget.SearchView;

import android.view.View;
import android.widget.Toast;

import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.Map;

public class MainActivity extends AppCompatActivity {
    private RecyclerView recycler_view;
    private MovieData md=new MovieData();
    private final MyRecyclerAdapter myRecyclerAdapter = new MyRecyclerAdapter(md.getMoviesList());

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar myToolbar = (Toolbar) findViewById(R.id.my_toolbar);
        setSupportActionBar(myToolbar);
    }

    @Override
    protected void onStart() {
        super.onStart();
        recycler_view= (RecyclerView)findViewById(R.id.mainRecyclerView);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        layoutManager.setOrientation(LinearLayoutManager.HORIZONTAL);
        layoutManager.scrollToPosition(0);
        recycler_view.setLayoutManager(layoutManager);
        myRecyclerAdapter.setOnItemClickListener(new OnListItemClickListener(){
            @Override
            public void onItemClick(View v, int position) {
                Map hashMap = myRecyclerAdapter.getItem(position);
                FragmentManager fragmentManager = getSupportFragmentManager();
                FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();

                MovieDetailFragment movieDetailFragment=MovieDetailFragment.newInstance((int)hashMap.get("image"),
                        hashMap.get("name").toString(),hashMap.get("year").toString(),
                        Float.parseFloat(hashMap.get("rating").toString()),hashMap.get("description").toString());

                fragmentTransaction.replace(R.id.detailFragment,movieDetailFragment);
                fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
                fragmentTransaction.commit();
                Toast toast = Toast.makeText(getApplicationContext(), "" + hashMap.get("name") + "-" + position, Toast.LENGTH_SHORT);
                toast.show();
            }
            @Override
            public void onItemLongClick(View v, int position){
                Toast toast = Toast.makeText(getApplicationContext(), "Position: " + position, Toast.LENGTH_SHORT);
                toast.show();
            }
        });
        recycler_view.setAdapter(myRecyclerAdapter);
        recycler_view.setItemAnimator(new DefaultItemAnimator());
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu){
        getMenuInflater().inflate(R.menu.appbar_menu, menu);
        MenuItem myActionMenuItem = menu.findItem(R.id.search_action);
        SearchView searchView = (SearchView) myActionMenuItem.getActionView();
        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                Toast toast = Toast.makeText(getApplicationContext(), "Query Text=" + query, Toast.LENGTH_SHORT);
                toast.show();;
                myRecyclerAdapter.getFilter().filter(query);
                return true;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                myRecyclerAdapter.getFilter().filter(newText);
                return true;
            }
        });
        return super.onCreateOptionsMenu(menu);
    }
}