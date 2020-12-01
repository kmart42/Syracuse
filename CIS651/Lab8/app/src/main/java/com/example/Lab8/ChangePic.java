package com.example.Lab8;

import android.Manifest;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.MutableData;
import com.google.firebase.database.ServerValue;
import com.google.firebase.database.Transaction;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class ChangePic extends AppCompatActivity {
    private static final int REQUEST_FOR_LOCATION = 123 ;

    public static class Post {
        public String uid;
        public String url;
        public Object timestamp;
        public Uri photoUrl;
//        public String description;
        public int likeCount = 0;
        public Map<String, Boolean> likes = new HashMap<>();
        public Post(String uid, String url, String description)
        {
            this.uid=uid;
            this.url=url;
//            this.description=description;
            this.timestamp= ServerValue.TIMESTAMP; }
        public Object getTimestamp(){
            return timestamp;
        }
        public Post() {

        }

    }
    Uri uri;
//    EditText description;
    private FirebaseAuth mAuth;
    private FirebaseUser currentUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_photo_preview);
        uri= Uri.parse(getIntent().getStringExtra("uri"));
        ImageView imageView=findViewById(R.id.previewImage);
        imageView.setImageURI(uri);
//        description=findViewById(R.id.description);
        mAuth = FirebaseAuth.getInstance();
        currentUser = mAuth.getCurrentUser();
        Bundle extras = getIntent().getExtras();
        final String mKey = (String) extras.getString("postKey");
//        final Uri curr_pic = (Uri) extras.getString("profPic");
        currentUser = mAuth.getCurrentUser();
        final FirebaseDatabase database = FirebaseDatabase.getInstance();

        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED
                && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.ACCESS_FINE_LOCATION, Manifest.permission.ACCESS_COARSE_LOCATION},
                    REQUEST_FOR_LOCATION);

        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode==REQUEST_FOR_LOCATION && ((grantResults.length>0 && grantResults[0]!=PackageManager.PERMISSION_GRANTED) || (grantResults.length>1 && grantResults[1]!=PackageManager.PERMISSION_GRANTED))){
            Toast.makeText(this, "We need to access your location", Toast.LENGTH_SHORT).show();
        }
    }

    private void uploadImage(){
//        FirebaseStorage storage= FirebaseStorage.getInstance();
//        final String fileNameInStorage= UUID.randomUUID().toString(); String path="images/"+ fileNameInStorage+".jpg";
//        final StorageReference imageRef=storage.getReference(path);
//        imageRef.putFile(uri).addOnSuccessListener(new OnSuccessListener<UploadTask.TaskSnapshot>() {
//            @Override public void onSuccess(UploadTask.TaskSnapshot taskSnapshot) {
//                imageRef.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
//                    @Override public void onSuccess(final Uri uri) {
//                        database.getReference("Posts/" + mKey).runTransaction(new Transaction.Handler() {
//                            @NonNull
//                            @Override
//                            public Transaction.Result doTransaction(@NonNull MutableData mutableData) {
//                                PhotoPreview.Post p = mutableData.getValue(PhotoPreview.Post.class);
//                                if (p == null) {
//                                    return Transaction.success(mutableData);
//                                }
//                                p.description = fname_v.getText().toString();
//                                mutableData.setValue(p);
//                                return Transaction.success(mutableData);
//                            }
//                            @Override
//                            public void onComplete(@Nullable DatabaseError error, boolean committed, @Nullable DataSnapshot currentData) {
//
//                            }
//                        });
//                    }
//                }).addOnFailureListener(new OnFailureListener() {
//                    @Override public void onFailure(@NonNull Exception e) {
//                        Toast.makeText(ChangePic.this, e.getMessage(), Toast.LENGTH_SHORT).show();
//                    }
//                });
//            }
//        }).addOnFailureListener(new OnFailureListener() {
//            @Override public void onFailure(@NonNull Exception e) {
//                Toast.makeText(ChangePic.this, e.getMessage(), Toast.LENGTH_SHORT).show();
//            }
//        });


    }
    public void Publish(View view){
       uploadImage();
       finish();
    }
}
