package com.example.project32;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Filter;
import android.widget.Filterable;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.view.ViewCompat;
import androidx.recyclerview.widget.RecyclerView;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class MyRecyclerAdapter extends RecyclerView.Adapter<MyRecyclerAdapter.ViewHolder> implements Filterable {
    private RecyclerView r;
    private List<PostModel> md;
    private List<PostModel> md_filtered;
    private FirebaseAuth mAuth;
    private FirebaseUser currentUser;
    FirebaseDatabase database = FirebaseDatabase.getInstance();
    DatabaseReference allPostsRef = database.getReference("Movie");
   // private HashMap<String, PostModel> movieHash;
    private ListFragment.OnItemSelectedListener onListItemClickListener = null;

    public void setRecyclerView(RecyclerView recyclerView){
        r=recyclerView;
    }
    //ListFragment.OnItemSelectedListener clickListener;
    public MyRecyclerAdapter() {
        md = new ArrayList<>();

        mAuth = FirebaseAuth.getInstance();
        currentUser = mAuth.getCurrentUser();
        allPostsRef.addChildEventListener(new ChildEventListener() {
            @Override
            public void onChildAdded(@NonNull DataSnapshot dataSnapshot, @Nullable String previousChildName) {
                PostModel userModel=new PostModel(dataSnapshot.child("name").getValue().toString(),
                        dataSnapshot.child("description").getValue().toString(),
                        dataSnapshot.child("url").getValue().toString(),
                        dataSnapshot.child("rating").getValue().toString(), dataSnapshot.getKey(),
                        dataSnapshot.child("year").getValue().toString(),
                        dataSnapshot.child("length").getValue().toString(),
                        dataSnapshot.child("director").getValue().toString(), dataSnapshot.child("stars").getValue().toString());


                md.add(userModel);
                MyRecyclerAdapter.this.notifyItemInserted(md.size()-1);
                if(r != null){
                r.scrollToPosition(md.size()-1);
            }}

            @Override
            public void onChildChanged(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {

            }

            @Override
            public void onChildRemoved(@NonNull DataSnapshot snapshot) {
                String key = snapshot.getKey();

                int index = -1;
                PostModel pmToRemove = null;
                for(PostModel pm : md){

                    if(key.equals(pm.key)){
                        index = md.indexOf(pm);
                        pmToRemove = pm;

                    }
                }
                if(index > -1 && pmToRemove != null) {
                    md.remove(index);
                    //postsList.remove(pmToRemove);
                    notifyItemRemoved(index);
                }

            }


            @Override
            public void onChildMoved(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {

            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

    }

    @Override
    public Filter getFilter() {
        return new Filter() {
            @Override
            protected FilterResults performFiltering(CharSequence charSequence) {
                String charString = charSequence.toString();

                if (charString.isEmpty()) {
                    md_filtered = md;
                } else {
//                    List<Map<String, ?>> filteredList = new ArrayList<>();
                    List<PostModel> filteredList = new ArrayList<>();
                    for (PostModel movie : md) {
                        if (Float.parseFloat(movie.rating)>= Float.parseFloat(charString.toLowerCase())) {
                            filteredList.add(movie);
                            System.out.println(movie.name);
                        }
                    }
                    md_filtered = filteredList;
                }
                FilterResults filterResults = new FilterResults();
                filterResults.values = md_filtered;
                return filterResults;
//            return null;
            }

            @Override
            protected void publishResults(CharSequence charSequence, FilterResults filterResults) {
                //md_filtered = (ArrayList<Map<String, ?>>) filterResults.values;
                md_filtered = (ArrayList<PostModel>) filterResults.values;
                notifyDataSetChanged();
            }
        };
    }

    public static class ViewHolder extends RecyclerView.ViewHolder implements Filterable {
        public TextView movie_name;
        public TextView movie_year;
        public ImageView poster_img;
        public ImageButton button;

        public ViewHolder(View view) {
            super(view);
            movie_name = view.findViewById(R.id.movie_name);
            movie_year = view.findViewById(R.id.movie_year);
            poster_img = view.findViewById(R.id.poster_photo);
            button = view.findViewById(R.id.button);
        }

        @Override
        public Filter getFilter() {
            return null;
        }
    }

    public PostModel getItem(int i) {
        return md.get(i);
    }

    public void setOnItemClickListener(ListFragment.OnItemSelectedListener listener) {
        onListItemClickListener = listener;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.recycler, parent, false);

        final ViewHolder view_holder = new ViewHolder(v);
        return view_holder;
    }

    @Override
    public void onBindViewHolder(final ViewHolder holder, final int position) {
        Picasso.get().load(md.get(position).url).into(holder.poster_img);
        holder.movie_name.setText(md.get(position).name);
        holder.movie_year.setText(md.get(position).description);
       // holder.poster_img.setImageResource(Integer.parseInt(md_filtered.get(position).get("image").toString()));
        ViewCompat.setTransitionName(holder.itemView, md.get(position).name);
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (onListItemClickListener != null)
                    onListItemClickListener.onListItemSelected(view,md.get(position));

            }
        });

        holder.button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                PopupMenu popup = new PopupMenu((Context) onListItemClickListener, holder.button);
                popup.inflate(R.menu.options_menu);
                popup.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                    @Override
                    public boolean onMenuItemClick(MenuItem menuItem) {
                        switch(menuItem.getItemId()){
                            case R.id.more:

                                database.getReference("Movie").child(md.get(position).key).setValue(null);
                                return true;
                            case R.id.duplicate:
                                Toast.makeText((Context) onListItemClickListener, "duplicate click", Toast.LENGTH_SHORT).show();
                                database.getReference("Movie").push().setValue(md.get(position));
                                return true;
                            default:
                                return false;
                        }

                    }
                });
                popup.show();
            }
        });


    }

    @Override
    public int getItemCount() {
        return md.size();
    }
}


