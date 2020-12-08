package com.example.Project3;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.SearchView;
import androidx.appcompat.widget.Toolbar;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.Manifest;
import android.content.ContentValues;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class HomeActivity extends AppCompatActivity {

    private FirebaseAuth mAuth;
    private FirebaseUser currentUser;
    private static final int REQUEST_FOR_CAMERA=0011;
    private static final int OPEN_FILE=0012;
    private Uri imageUri=null;
    RecyclerView recyclerView;
    List<MessageRecyclerAdapter.PostModel> postsList;
    MessageRecyclerAdapter myRecyclerAdapter;
    int num = 0;
    MovieData movieData = new MovieData();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        Toolbar myToolbar = (Toolbar) findViewById(R.id.my_toolbar);
        setSupportActionBar(myToolbar);
        // Initialize Firebase Auth
        mAuth = FirebaseAuth.getInstance();
        currentUser = mAuth.getCurrentUser();
        recyclerView=findViewById(R.id.recylcer_view);

        final FirebaseDatabase database = FirebaseDatabase.getInstance();
        DatabaseReference ref = database.getReference("Movies");

        Map<String, MessageRecyclerAdapter.PostModel> mov_dat= new HashMap<>();
//        for (int i =0;i<movieData.getSize();i++) {
//                        mov_dat.put(movieData.getItem(num).get("name").toString(), new MessageRecyclerAdapter.PostModel(
//                                movieData.getItem(num).get("name").toString(),
//                                movieData.getItem(num).get("description").toString(),
//                                movieData.getItem(num).get("url").toString(),
//                                movieData.getItem(num).get("year").toString(),
//                                movieData.getItem(num).get("stars").toString(),
//                                movieData.getItem(num).get("rating").toString()));
//
//                        ref.setValue(mov_dat);
//        }

        LinearLayoutManager layoutManager=new LinearLayoutManager(this);
        layoutManager.setOrientation(RecyclerView.VERTICAL);
        layoutManager.scrollToPosition(0);
        recyclerView.setLayoutManager(layoutManager);
//        myRecyclerAdapter=new MessageRecyclerAdapter(recyclerView);
        MovieData md=new MovieData();
         myRecyclerAdapter = new MessageRecyclerAdapter(postsList);
        myRecyclerAdapter.setOnItemClickListener(new OnListItemClickListener(){
            @Override
            public void onItemClick(View v, int position) {
//                Map hashMap = myRecyclerAdapter.getItem(position);
//                FragmentManager fragmentManager = getSupportFragmentManager();
//                FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
//
//                MovieDetailFragment movieDetailFragment=MovieDetailFragment.newInstance((int)hashMap.get("image"),
//                        hashMap.get("name").toString(),hashMap.get("year").toString(),
//                        Float.parseFloat(hashMap.get("rating").toString()),hashMap.get("description").toString());
//
//                fragmentTransaction.replace(R.id.detailFragment,movieDetailFragment);
//                fragmentTransaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
//                fragmentTransaction.commit();
//                Toast toast = Toast.makeText(getApplicationContext(), "" + hashMap.get("name") + "-" + position, Toast.LENGTH_SHORT);
//                toast.show();
            }
            @Override
            public void onItemLongClick(View v, int position){
                Toast toast = Toast.makeText(getApplicationContext(), "Position: " + position, Toast.LENGTH_SHORT);
                toast.show();
            }
        });
        recyclerView.setAdapter(myRecyclerAdapter);



    }
//    @Override
//    public boolean onCreateOptionsMenu(Menu menu){
//       getMenuInflater().inflate(R.menu.actionbar_menu, menu);
//      return super.onCreateOptionsMenu(menu);
//    }
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

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle item selection
        switch (item.getItemId()) {
            case R.id.signout:
                mAuth.signOut();
                finish();
                return true;
            case R.id.newUser:
                createTestEntry();
                return true;
            case R.id.edit_profile:
                startActivity(new Intent(this, EditProfile.class));
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
    private void createTestEntry(){
        FirebaseDatabase database = FirebaseDatabase.getInstance();
        DatabaseReference usersRef = database.getReference("Users");
        String pushKey=usersRef.push().getKey();
        usersRef.child(pushKey).setValue(new User("Test Display Name",
                "Test Email", "Test Phone"));
    }
    public void uploadNewPhoto(View view){
        checkPermissions();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        myRecyclerAdapter.removeListener();
    }

    private void takePhoto(){
        ContentValues values = new ContentValues();
        values.put(MediaStore.Images.Media.TITLE, "New Picture");
        values.put(MediaStore.Images.Media.DESCRIPTION, "From your Camera");
        imageUri = getContentResolver().insert(
                MediaStore.Images.Media.EXTERNAL_CONTENT_URI, values);
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        intent.putExtra(MediaStore.EXTRA_OUTPUT, imageUri);
        Intent chooser=Intent.createChooser(intent,"Select a Camera App.");
        if (intent.resolveActivity(getPackageManager()) != null) {
            startActivityForResult(chooser, REQUEST_FOR_CAMERA);}
    }
    private void checkPermissions(){

        if (ContextCompat.checkSelfPermission(getBaseContext(),
                android.Manifest.permission.CAMERA)
                != PackageManager.PERMISSION_GRANTED || ContextCompat.checkSelfPermission(getBaseContext(),
                Manifest.permission.WRITE_EXTERNAL_STORAGE)
                != PackageManager.PERMISSION_GRANTED) {

            Toast.makeText(this, "We need permission to access your camera and photo.", Toast.LENGTH_SHORT).show();
            ActivityCompat.requestPermissions(this,
                    new String[]{android.Manifest.permission.CAMERA, android.Manifest.permission.WRITE_EXTERNAL_STORAGE},
                    REQUEST_FOR_CAMERA);
        }
        else
        {
            takePhoto();
        }
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_FOR_CAMERA && resultCode == RESULT_OK) {
            if(imageUri==null)
            {
                Toast.makeText(this, "Error taking photo.", Toast.LENGTH_SHORT).show();
                return;
            }
            Intent intent=new Intent(this, PhotoPreview.class);
            intent.putExtra("uri",imageUri.toString());
            startActivity(intent);

            return;
        }
    }

}
