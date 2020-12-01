package com.example.Lab8;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.MutableData;
import com.google.firebase.database.Transaction;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.squareup.picasso.Picasso;

import java.util.HashMap;
import java.util.List;

public class MyRecyclerAdapter
        extends RecyclerView.Adapter<MyRecyclerAdapter.ViewHolder>
        {


            FirebaseDatabase database = FirebaseDatabase.getInstance();
            DatabaseReference usersRef = database.getReference("Posts");
            ChildEventListener usersRefListener;
            private FirebaseAuth mAuth;
            private FirebaseUser currentUser;
            private List<String> keyList;
            private HashMap<String,PostModel> key_to_Post;
            ImageView profPic;
           // private RecyclerView r;
            private Marker currentMarker =null;
            private  ItemClickListener itemClickListener;
            public MyRecyclerAdapter(HashMap<String,PostModel> kp, List<String> kl, ItemClickListener _itemClickListener){
                keyList=kl;
                key_to_Post= kp;
                mAuth = FirebaseAuth.getInstance();
                currentUser = mAuth.getCurrentUser();
                itemClickListener =_itemClickListener;


            }
            @NonNull
            @Override
            public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
                View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_view, parent,false);
                final ViewHolder vh = new ViewHolder(v);
                return vh;
            }

            @Override
            public void onBindViewHolder(@NonNull final ViewHolder holder, int position) {
                final PostModel u =key_to_Post.get(keyList.get(position));
                String uid=u.uid;
                if(holder.uref!=null && holder.urefListener!=null)
                {
                    holder.uref.removeEventListener(holder.urefListener);
                }
                if(holder.likesRef!=null && holder.likesRefListener!=null)
                {
                    holder.likesRef.removeEventListener(holder.likesRefListener);
                }
                if(holder.likeCountRef!=null && holder.likeCountRefListener!=null)
                {
                    holder.likeCountRef.removeEventListener(holder.likeCountRefListener);
                }
                final FirebaseDatabase database = FirebaseDatabase.getInstance();
                holder.uref = database.getReference("Users").child(uid);
                holder.uref.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        profPic = holder.profPic.findViewById(R.id.profPic);
                        Picasso.get().load(String.valueOf(dataSnapshot.child("profilePicture").getValue())).into(profPic);
                        holder.fname_v.setText("First Name: " +dataSnapshot.child("displayname").getValue().toString());
                        holder.email_v.setText("Email:  " + dataSnapshot.child("email").getValue().toString());
                        holder.phone_v.setText("Phone Num:  " + dataSnapshot.child("phone").getValue().toString());
                        holder.date_v.setText("Date Created: "+u.date);
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {

                    }
                });
                holder.likeCountRef=
                database.getReference("Posts/"+u.postKey+"/likeCount");
                Log.d("LIKEC ", u.postKey);
               holder.likeCountRefListener=holder.likeCountRef.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        //Log.d("CRASH", dataSnapshot.toString());
                        if(dataSnapshot.getValue()!=null)
                         holder.likeCount.setText(dataSnapshot.getValue().toString()+" Likes");
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {

                    }
                });
                holder.likesRef=database.getReference("Posts/"+u.postKey+"/likes/"+currentUser.getUid());
                holder.likesRefListener=holder.likesRef.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        if(dataSnapshot.exists() && dataSnapshot.getValue().toString().equals("true"))
                        {
                            holder.likeBtn.setImageDrawable(ContextCompat.getDrawable(holder.likeBtn.getContext(), R.drawable.like_active));
                        }
                        else{
                            holder.likeBtn.setImageDrawable(ContextCompat.getDrawable(holder.likeBtn.getContext(), R.drawable.like_disabled));
                        }

                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {

                    }
                });
                holder.likeBtn.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        database.getReference("Posts/"+u.postKey).runTransaction(new Transaction.Handler() {
                            @NonNull
                            @Override
                            public Transaction.Result doTransaction(@NonNull MutableData mutableData) {
                                PhotoPreview.Post p = mutableData.getValue(PhotoPreview.Post.class);
                                if (p == null) {
                                    return Transaction.success(mutableData);
                                }

                                if (p.likes.containsKey(currentUser.getUid())) {
                                    // Unstar the post and remove self from stars
                                    p.likeCount = p.likeCount - 1;
                                    p.likes.remove(currentUser.getUid());
                                } else {
                                    // Star the post and add self to stars
                                    p.likeCount = p.likeCount + 1;
                                    p.likes.put(currentUser.getUid(), true);
                                }

                                // Set value and report transaction success
                                mutableData.setValue(p);
                                return Transaction.success(mutableData);
                            }

                            @Override
                            public void onComplete(@Nullable DatabaseError databaseError, boolean b, @Nullable DataSnapshot dataSnapshot) {

                            }
                        });
                    }
                });
                holder.imageView.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if (currentMarker!=null)
                            currentMarker.setIcon(BitmapDescriptorFactory.fromResource(R.drawable.marker_grey));

                        u.m.setIcon(BitmapDescriptorFactory.fromResource(R.drawable.marker_red));
                        currentMarker=u.m;
                        if (itemClickListener!=null)
                            itemClickListener.onItmeClick(currentMarker.getPosition());
                    }
                });


//                final FirebaseDatabase storage = FirebaseDatabase.getInstance();
//                String path= database.getReference("Users").child(uid).child("profilePicture").toString();
//                final DatabaseReference imageRef=storage.getReference(path);
                profPic = holder.profPic.findViewById(R.id.profPic);
                Picasso.get().load(String.valueOf(database.getReference("Users").child(uid).child("profilePicture"))).into(profPic);
//                profPic.setImageResource(R.drawable.profile_icon);
//                imageRef.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
//                    @Override
//                    public void onSuccess(Uri uri) {
//                        // Got the download URL for 'users/me/profile.png'
//                        // Pass it to Picasso to download, show in ImageView and caching
//                        Picasso.get().load(uri.toString()).into(profPic);
//                    }
//                }).addOnFailureListener(new OnFailureListener() {
//                    @Override
//                    public void onFailure(@NonNull Exception exception) {
//                        // Handle any errors
//                    }
//                });



//                System.out.println(database.getReference("Users").child(uid).child("profilePicture"));
//                Picasso.get().load(String.valueOf(database.getReference("Users").child(uid).child("profilePicture"))).into(profPic);

                holder.profPic.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Intent intent=new Intent(holder.imageView.getContext(), PostMessage.class);
                        intent.putExtra("postKey",u.postKey);
                        intent.putExtra("description", u.description);
                        holder.imageView.getContext().startActivity(intent);
                    }
                });

                holder.description_v.setText(u.description);
                StorageReference pathReference = FirebaseStorage.getInstance().getReference("images/"+u.url);
                pathReference.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
                    @Override
                    public void onSuccess(Uri uri) {
                        Picasso.get().load(uri).into(holder.imageView);
                    }
                });



            }

            public void removeListener(){
                if(usersRef!=null && usersRefListener!=null)
                    usersRef.removeEventListener(usersRefListener);
            }
            @Override
            public int getItemCount() {
                return keyList.size();
            }
            public static class ViewHolder extends RecyclerView.ViewHolder{
                public TextView fname_v;
                public TextView email_v;
                public TextView phone_v;
                public TextView date_v;
                public TextView description_v;
                public ImageView imageView;
                public ImageView profPic;
                public  ImageView likeBtn;
                public TextView likeCount;
                DatabaseReference uref;
                ValueEventListener urefListener;

                DatabaseReference likeCountRef;
                ValueEventListener likeCountRefListener;

                DatabaseReference likesRef;
                ValueEventListener likesRefListener;
                public ViewHolder(View v){
                    super(v);
                    fname_v = (TextView) v.findViewById(R.id.fname_view);
                    email_v = (TextView) v.findViewById(R.id.email_view);
                    phone_v = (TextView) v.findViewById(R.id.phone_view);
                   date_v = (TextView) v.findViewById(R.id.date_view);
                   description_v=v.findViewById(R.id.description);
                   imageView=v.findViewById(R.id.postImg);
                   profPic=v.findViewById(R.id.profPic);
                   likeBtn=v.findViewById(R.id.likeBtn);
                   likeCount=v.findViewById(R.id.likeCount);
                }
            }

}
