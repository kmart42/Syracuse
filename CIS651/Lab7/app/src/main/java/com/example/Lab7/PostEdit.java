package com.example.Lab7;

import android.Manifest;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ServerValue;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class PostEdit extends AppCompatActivity {
//    TextView fname_v = (TextView) findViewById(R.id.fname_view);
//    TextView email_v = (TextView) findViewById(R.id.email_view);
//    TextView phone_v = (TextView) findViewById(R.id.phone_view);
//    TextView date_v = (TextView) findViewById(R.id.date_view);
//    TextView description_v= findViewById(R.id.description);

//    public static class Post {
//        public String uid;
//        public String url;
//        public Object timestamp;
//        public String description;
//        public int likeCount = 0;
//        public Map<String, Boolean> likes = new HashMap<>();
//        public Post(String uid, String url, String description)
//        {
//            this.uid=uid;
//            this.url=url;
//            this.description=description;
//            this.timestamp= ServerValue.TIMESTAMP; }
//        public Object getTimestamp(){
//            return timestamp;
//        }
//        public Post() {
//
//        }
//
//    }

    EditText description;
    private FirebaseAuth mAuth;
    private FirebaseUser currentUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.edit_post);
        TextView fname_v = (TextView) findViewById(R.id.editDescription);
//        String postKey= (String) savedInstanceState.getSerializable("postKey");
        description=findViewById(R.id.description);
        mAuth = FirebaseAuth.getInstance();
        currentUser = mAuth.getCurrentUser();
        final FirebaseDatabase database = FirebaseDatabase.getInstance();
        database.getReference("Posts/")
        System.out.println(database);
//        database.getReference("Posts/"+postKey);
//        System.out.println(database.getReference("Posts/"+postKey+"/description").toString());
//        fname_v.setText("First Name: " +database.getReference("Posts/"+postKey+"/description").toString());

    }

    private void editPost(){
//        final FirebaseDatabase database = FirebaseDatabase.getInstance();
//        DatabaseReference postsRef = database.getReference("Posts");
//        DatabaseReference newPostRef = postsRef.push();
//        newPostRef.setValue(new Post(currentUser.getUid(),uri.toString(),description.getText().toString()))
//                .addOnSuccessListener(new OnSuccessListener<Void>() {
//                    @Override public void onSuccess(Void aVoid) {
//                        Toast.makeText(PostEdit.this, "Success", Toast.LENGTH_SHORT).show();
//                    }
//                });

    }

//    private void editPost2(){
//        FirebaseStorage storage= FirebaseStorage.getInstance();
//        final String fileNameInStorage= UUID.randomUUID().toString(); String path="images/"+ fileNameInStorage+".jpg";
//        final StorageReference imageRef=storage.getReference(path);
//        imageRef.putFile(uri).addOnSuccessListener(new OnSuccessListener<UploadTask.TaskSnapshot>() {
//            @Override public void onSuccess(UploadTask.TaskSnapshot taskSnapshot) {
//                imageRef.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
//                    @Override public void onSuccess(final Uri uri) {
//                        final FirebaseDatabase database = FirebaseDatabase.getInstance();
//                        DatabaseReference postsRef = database.getReference("Posts");
//                        DatabaseReference newPostRef = postsRef.push();
//                        newPostRef.setValue(new Post(currentUser.getUid(),uri.toString(),description.getText().toString()))
//                                .addOnSuccessListener(new OnSuccessListener<Void>() {
//                                    @Override public void onSuccess(Void aVoid) {
//                                        Toast.makeText(PostEdit.this, "Success", Toast.LENGTH_SHORT).show();
//                                    }
//                                });
//                    }
//                }).addOnFailureListener(new OnFailureListener() {
//                    @Override public void onFailure(@NonNull Exception e) {
//                        Toast.makeText(PostEdit.this, e.getMessage(), Toast.LENGTH_SHORT).show();
//                    }
//                });
//            }
//        }).addOnFailureListener(new OnFailureListener() {
//            @Override public void onFailure(@NonNull Exception e) {
//                Toast.makeText(PostEdit.this, e.getMessage(), Toast.LENGTH_SHORT).show();
//            }
//        });


//    }
    public void Publish(View view){
        editPost();
       finish();
    }
}
