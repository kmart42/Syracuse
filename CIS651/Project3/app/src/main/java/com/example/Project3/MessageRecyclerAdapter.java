package com.example.Project3;

import android.content.Intent;
import android.os.Bundle;
import android.os.Parcelable;
import android.transition.Slide;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Filter;
import android.widget.Filterable;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.recyclerview.widget.RecyclerView;

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
import com.squareup.picasso.Picasso;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.sql.DataSource;

public class MessageRecyclerAdapter
        extends RecyclerView.Adapter<MessageRecyclerAdapter.ViewHolder> implements Filterable
        {
            SimpleDateFormat localDateFormat= new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
            static class PostModel{
//                public String postKey;
                public String title;
                public String description;
                public String image;
                public String year;
                public String rating;
                public String stars;
                public PostModel(String title, String description, String image, String year, String stars, String rating) {
                    this.year=year;
                    this.rating=rating;
                    this.stars=stars;
                    this.description=description;
                    this.image=image;
                   this.title=title;
//                   this.postKey=key;
                }
            }
            int num = 0;
//            private List<Map<String, ?>> md;
//            private List<Map<String, ?>> md_filtered;
            MovieData movieData = new MovieData();
            FirebaseDatabase database = FirebaseDatabase.getInstance();
            DatabaseReference allPostsRef = database.getReference("Movies");
            ChildEventListener usersRefListener;
            private FirebaseAuth mAuth;
            private FirebaseUser currentUser;
            private List<PostModel> postsList;
            private List<PostModel> posts_filtered;
            private OnListItemClickListener onListItemClickListener=null;
            private RecyclerView r;

//            public MessageRecyclerAdapter(RecyclerView recyclerView){
        public MessageRecyclerAdapter(List<PostModel> list)
        {
            postsList = new ArrayList<>();


//                r=recyclerView;
            mAuth = FirebaseAuth.getInstance();
            currentUser = mAuth.getCurrentUser();

//            postsList = list;
            allPostsRef.addChildEventListener(new ChildEventListener() {
                @Override
                public void onChildAdded(@NonNull DataSnapshot dataSnapshot, @Nullable String previousChildName) {
//                    System.out.println(num);

                    final FirebaseDatabase database = FirebaseDatabase.getInstance();
                    DatabaseReference ref = database.getReference("Movies");

                    Map<String, PostModel> mov_dat= new HashMap<>();
                    for (int i =0;i<movieData.getSize() ;i++) {
                        if(movieData.getItem(num)!=null) {
                            mov_dat.put(movieData.getItem(num).get("name").toString(), new PostModel(
                                    movieData.getItem(num).get("name").toString(),
                                    movieData.getItem(num).get("description").toString(),
                                    movieData.getItem(num).get("url").toString(),
                                    movieData.getItem(num).get("year").toString(),
                                    movieData.getItem(num).get("stars").toString(),
                                    movieData.getItem(num).get("rating").toString()));
                            ref.setValue(mov_dat);
                        }
                        PostModel userModel = new PostModel(
                                movieData.getItem(i).get("name").toString(),
                                movieData.getItem(i).get("description").toString(),
                                movieData.getItem(i).get("url").toString(),
                                movieData.getItem(i).get("year").toString(),
                                movieData.getItem(i).get("stars").toString(),
                                movieData.getItem(i).get("rating").toString()
                        );
                        postsList.add(userModel);
//                        if (num < 30) {
                            num = num + 1;
//                        }
                    }
                    if(postsList!=null) {
                        MessageRecyclerAdapter.this.notifyItemInserted(postsList.size() - 1);
                    }
//                        r.scrollToPosition(postsList.size()-1);
                }


                @Override
                public void onChildChanged(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {
                    String id = snapshot.child("title").getValue().toString();
                    int position = -1;
                    for (int i = 0; i < postsList.size(); i++) {
                        if (postsList.get(i).title.equals(id)) {
                            position = i;
                            break;
                        }
                    }
                    if (position != -1) {
                        PostModel userModel = new PostModel(snapshot.child("title").getValue().toString(),
                                snapshot.child("description").getValue().toString(),
                                snapshot.child("image").getValue().toString(),
                                snapshot.child("year").getValue().toString(),
                                snapshot.child("stars").getValue().toString(),
                                snapshot.child("rating").getValue().toString());
                        postsList.add(position, userModel);
                        MessageRecyclerAdapter.this.notifyItemRemoved(position);
//                            r.scrollToPosition(position);
                    }

                }

                @Override
                public void onChildRemoved(@NonNull DataSnapshot snapshot) {
                    String id = snapshot.child("title").getValue().toString();
                    int position = -1;
                    for (int i = 0; i < postsList.size(); i++) {
                        if (postsList.get(i).title.equals(id)) {
                            position = i;
                            break;
                        }
                    }
                    if (position != -1) {
                        postsList.remove(position);
                        MessageRecyclerAdapter.this.notifyItemRemoved(position);
//                            r.scrollToPosition(position);
                    }

                }

                @Override
                public void onChildMoved(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {

                }

                @Override
                public void onCancelled(@NonNull DatabaseError error) {

                }
            });

//            list=new ArrayList<>();
//            postsList=posts_filtered=list;
//            postsList = posts_filtered;

        }
            @Override
            public Filter getFilter() {
                return new Filter() {
                    @Override
                    protected FilterResults performFiltering(CharSequence charSequence) {
                        String charString = charSequence.toString();
                        if (charString.isEmpty()) {
                            posts_filtered = postsList;
                        } else {
                            List<PostModel> filteredList = new ArrayList<>();
                            for (MessageRecyclerAdapter.PostModel movie : postsList) {
                                if (Float.parseFloat(movie.rating)>Integer.parseInt(charString)){
//                                if ((Float.parseFloat(movie.rating)>Integer.parseInt(charString))) {
                                    filteredList.add(movie);
                                    System.out.println(movie.title);
                                }
                            }
                            posts_filtered = filteredList;
                        }
                        FilterResults filterResults = new FilterResults();
                        filterResults.values = posts_filtered;
                        return filterResults;
                    }

                    @Override
                    protected void publishResults(CharSequence charSequence, FilterResults filterResults) {
                        posts_filtered = (ArrayList<PostModel>) filterResults.values;
                        notifyDataSetChanged();

                    }
                };
            }


            @NonNull
            @Override
            public ViewHolder onCreateViewHolder(@NonNull final ViewGroup parent, final int viewType) {
                View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_view, parent,false);
                final ViewHolder vh = new ViewHolder(v);

                return vh;
            }


            @Override
            public void onBindViewHolder(@NonNull final ViewHolder holder, final int position) {
                final PostModel u =postsList.get(position);
                String title=u.title;
            holder.more_menu.setOnClickListener(new View.OnClickListener() {
                                                    @Override
                                                    public void onClick(final View v) {
                                                        PopupMenu popupMenu = new PopupMenu(v.getContext(), holder.imageView, Gravity.END);
                                                        popupMenu.getMenu().add("Duplicate");
                                                        popupMenu.getMenu().addSubMenu("Delete");
                                                        popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                                                            @Override
                                                            public boolean onMenuItemClick(MenuItem item) {
                                                                if("Delete".equals(item.toString())) {
                                                                    holder.uref = database.getReference("Movies/"+u.title);
                                                                    holder.uref.removeValue();
                                                                    return false;
                                                                } else {
                                                                    DatabaseReference ref = database.getReference("Movies/");

                                                                    Map<String, PostModel> mov_dat= new HashMap<>();
                                                                    mov_dat.put(movieData.getItem(position).get("name").toString(), new PostModel(
                                                                    movieData.getItem(position).get("name").toString(),
                                                                    movieData.getItem(position).get("description").toString(),
                                                                    movieData.getItem(position).get("url").toString(),
                                                                    movieData.getItem(position).get("year").toString(),
                                                                    movieData.getItem(position).get("stars").toString(),
                                                                    movieData.getItem(position).get("rating").toString()));
                                                                    ref.child(movieData.getItem(position).get("name").toString()+'2').setValue(mov_dat);

                                                                    PostModel userModel = new PostModel(

                                                                    database.getReference("Movies/"+u.title).toString(),
                                                                            database.getReference("Movies/"+u.title+"/description").toString(),
                                                                            database.getReference("Movies/"+u.title+"/image").toString(),
                                                                            database.getReference("Movies/"+u.title+"/year").toString(),
                                                                            database.getReference("Movies/"+u.title+"/stars").toString(),
                                                                            database.getReference("Movies/"+u.title+"/rating").toString()
                                                                    );
                                                                    postsList.add(userModel);
                                                                    notifyDataSetChanged();
                                                                    return false;
                                                                }
                                                            }

                                                        });
                                                        popupMenu.show();

                                                    }
                                                });

            holder.imageView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Intent intent=new Intent(holder.imageView.getContext(), LaunchMovie.class);
                    intent.putExtra("picture",  movieData.getItem(position).get("url").toString());
                    intent.putExtra("title_text", movieData.getItem(position).get("name").toString());
                    intent.putExtra("year_text", movieData.getItem(position).get("year").toString());
                    intent.putExtra("description", movieData.getItem(position).get("description").toString());
                    intent.putExtra("movie_rating", movieData.getItem(position).get("rating").toString());
                    holder.imageView.getContext().startActivity(intent);
                }
            });


                if(holder.uref!=null && holder.urefListener!=null)
                {
                    holder.uref.removeEventListener(holder.urefListener);
                }
                Picasso.get().load(u.image).into(holder.imageView);
                final FirebaseDatabase database = FirebaseDatabase.getInstance();
                holder.uref = database.getReference("Movies").child(title);
                holder.uref.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        holder.title_v.setText(movieData.getItem(position).get("name").toString());
                        holder.description_v.setText(movieData.getItem(position).get("description").toString());

//                        holder.fname_v.setText("First Name: " +dataSnapshot.child("displayname").getValue().toString());
//                        holder.email_v.setText("Email:  " + dataSnapshot.child("email").getValue().toString());
//                        holder.phone_v.setText("Phone Num:  " + dataSnapshot.child("phone").getValue().toString());
//                        holder.title_v.setText("Date Created: "+u.title);
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {

                    }
                });


                holder.description_v.setText(u.description);


            }
            public MessageRecyclerAdapter.PostModel getItem(int i){
                return posts_filtered.get(i);
            }
            public void setOnItemClickListener(OnListItemClickListener listener){
                onListItemClickListener=listener;
            }
            public void removeListener(){
                if(allPostsRef !=null && usersRefListener!=null)
                    allPostsRef.removeEventListener(usersRefListener);
            }
            @Override
            public int getItemCount() {
                if (postsList == null) {
                    return 0;
                } else {
                    return postsList.size();
                }
            }
            public static class ViewHolder extends RecyclerView.ViewHolder{
//                public TextView fname_v;
                public TextView email_v;
                public TextView phone_v;
                public TextView title_v;
                public TextView description_v;
                public ImageView imageView;
                public RatingBar ratingBar;
                public ImageButton more_menu;
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
//                    fname_v = (TextView) v.findViewById(R.id.fname_view);
//                    email_v = (TextView) v.findViewById(R.id.email_view);
//                    phone_v = (TextView) v.findViewById(R.id.phone_view);
                   title_v = (TextView) v.findViewById(R.id.title_view);
                   description_v=v.findViewById(R.id.description);
                   imageView=v.findViewById(R.id.postImg);
                   ratingBar=v.findViewById(R.id.movie_rating);
                    more_menu=v.findViewById(R.id.more_menu);
                }
            }

}
