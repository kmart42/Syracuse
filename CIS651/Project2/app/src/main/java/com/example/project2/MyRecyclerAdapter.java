package com.example.project2;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Filter;
import android.widget.Filterable;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.core.view.ViewCompat;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class MyRecyclerAdapter extends RecyclerView.Adapter<MyRecyclerAdapter.ViewHolder> implements Filterable {
    private List<Map<String, ?>> md;
    private List<Map<String, ?>> md_filtered;
    private ListFragment.OnItemSelectedListener clickListener=null;

    @Override
    public MyRecyclerAdapter.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType){
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_view_layout, parent, false);
        final ViewHolder viewHolder = new ViewHolder(v);
        return viewHolder;
    }

    public MyRecyclerAdapter(List<Map<String, ?>> list)
    {
        md=md_filtered=list;
    }
    @Override
    public Filter getFilter(){
        return new Filter(){
            @Override
            protected FilterResults performFiltering(CharSequence charSequence){
                String charString = charSequence.toString();
                if(charString.isEmpty()) {
                    md_filtered = md;
                } else{
                    List<Map<String,?>> filteredList = new ArrayList<>();
                    for (Map movie : md) {
                        if(movie.get("name").toString().toLowerCase().contains(charString.toLowerCase())){
                            filteredList.add(movie);
                        }
                    }
                    md_filtered = filteredList;
                }
                FilterResults filterResults = new FilterResults();
                filterResults.values = md_filtered;
                return filterResults;
            }
            @Override
            protected void publishResults(CharSequence charSequence, FilterResults filterResults) {
                md_filtered = (ArrayList<Map<String,?>>) filterResults.values;
                notifyDataSetChanged();;
            }
        };

    }
    public static class ViewHolder extends RecyclerView.ViewHolder{
        public TextView movie_name;
        public TextView movie_year;
        public ImageView poster_img;
        public ViewHolder(View view){
            super(view);
            movie_name = (TextView)view.findViewById(R.id.movie_name);
            movie_year = (TextView)view.findViewById(R.id.movie_year);
            poster_img = (ImageView)view.findViewById(R.id.poster_photo);
        }

    }

    public Map getItem(int i){
        return md_filtered.get(i);
    }

    public void setOnItemClickListener(ListFragment.OnItemSelectedListener listener){
        clickListener=listener;
    }



    @Override
    public void onBindViewHolder(ViewHolder holder, final int position){
        holder.movie_name.setText(md_filtered.get(position).get("name").toString());
        holder.movie_year.setText(md_filtered.get(position).get("year").toString());
        holder.poster_img.setImageResource(Integer.parseInt(md_filtered.get(position).get("image").toString()));
        ViewCompat.setTransitionName(holder.poster_img,md_filtered.get(position).get("name").toString());
        holder.poster_img.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                if(clickListener!=null)
                    clickListener.onListItemSelected(view,Integer.parseInt(md_filtered.get(position).get("image").toString()),
                            md_filtered.get(position).get("name").toString(),
                            md_filtered.get(position).get("year").toString());
            }
        });
    }



    @Override
    public int getItemCount(){return md_filtered.size();}
    @Override
    public void onAttachedToRecyclerView(RecyclerView recyclerView){

    }





}


