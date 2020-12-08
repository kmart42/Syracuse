package com.example.project32;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.SearchView;
import androidx.appcompat.widget.Toolbar;
import androidx.core.view.ViewCompat;
import androidx.fragment.app.Fragment;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.firebase.auth.FirebaseAuth;

public class HomeActivity extends AppCompatActivity implements ListFragment.OnItemSelectedListener{

    //private RecyclerView recycler_view;
    //private MovieData md=new MovieData();
    //private final MyRecyclerAdapter myRecyclerAdapter = new MyRecyclerAdapter(md.getMoviesList(), recycler_view);
    private FirebaseAuth mAuth;
    private QueryListener queryListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
//        setContentView(R.layout.activity_new);
        queryListener = new ListFragment();
        Toolbar myToolbar = findViewById(R.id.my_toolbar);
        setSupportActionBar(myToolbar);
        getSupportFragmentManager().beginTransaction().replace(R.id.main_container, (Fragment) queryListener).commit();
//        getSupportFragmentManager().beginTransaction().replace(R.id.recylcer_view, (Fragment) queryListener).commit();
        mAuth = FirebaseAuth.getInstance();
        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(HomeActivity.this, AddNewMovie.class);
                startActivity(intent);
            }
        });

    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu){
        getMenuInflater().inflate(R.menu.appbar_menu, menu);
        MenuItem myActionMenuItem = menu.findItem(R.id.search_action);
        SearchView searchView = (SearchView) myActionMenuItem.getActionView();
        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                Toast toast=Toast.makeText(getApplicationContext(),"Query Text="+query,Toast.LENGTH_SHORT);
                toast.show();
                queryListener.Filter(query);
                return true;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                queryListener.Filter(newText);
                return true;
            }

        });
        return  super.onCreateOptionsMenu(menu);

    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle item selection
        switch (item.getItemId()) {
            case R.id.signout:
                mAuth.signOut();
                finish();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public void onListItemSelected(View sharedView, PostModel movie) {
        Bundle args=new Bundle();
        args.putString("img_id",movie.url);
        args.putString("mtitle",movie.name);
        args.putString("myear",movie.year);
        args.putFloat("rating", Float.parseFloat(movie.rating));
        args.putString("description", movie.description);
        args.putString("director", movie.director);
        args.putString("length", movie.length);
        args.putString("cast", movie.stars);
        Fragment masterDetail=new DetailMaster();
        masterDetail.setArguments(args);

        getSupportFragmentManager().beginTransaction()
                .replace(R.id.main_container,masterDetail)
//                .replace(R.id.recylcer_view,masterDetail)
                .addToBackStack(null).commit();


    }
}

