package com.example.lab6;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class MyRecyclerAdapter extends RecyclerView.Adapter<MyRecyclerAdapter.ViewHolder> {
    private List<Contact> mContactList;
    private Context mContext;
    private RecyclerView mRecyclerView;

    private EditText mNameEditText;
    private EditText mLastname;
    private EditText mPhoneEditText;
    private Button mUpdateBtn;
    private MyDBHelper dbHelper;
    private long contactId;

    public MyRecyclerAdapter(List<Contact> myDataset, Context context, RecyclerView recyclerView){
        mContactList=myDataset;
        mContext = context;
        mRecyclerView = recyclerView;
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        public TextView name_v;
        public TextView lastname_v;
        public TextView phone_v;
        public ViewHolder(View view) {
            super(view);
            name_v = (TextView)view.findViewById(R.id.name_view);
            lastname_v = (TextView)view.findViewById(R.id.lastname_view);
            phone_v = (TextView)view.findViewById(R.id.phone_number);
        }
    }

    @Override
    public  MyRecyclerAdapter.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_view_layout, parent, false);
        final ViewHolder view_holder = new ViewHolder(v);
        return  view_holder;
    }
    public void updateList(List<Contact> myDataset){
        mContactList = myDataset;
        notifyDataSetChanged();
    }

    public void onBindViewHolder(final ViewHolder holder, final int position){
        final Contact c = mContactList.get(position);
        holder.name_v.setText("Name: " + c.getName());
        holder.lastname_v.setText("Last Name: " + c.getLastname());
        holder.phone_v.setText("Phone: " + c.getPhone_number());
        holder.itemView.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(mContext);
                builder.setTitle("Choose option");
                builder.setMessage("Update or delete user?");

                builder.setPositiveButton("Update", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface arg0, int arg1) {
                        goToUpdateActivity(c.getId());
                    }
                });


            builder.setNeutralButton("Delete", new DialogInterface.OnClickListener(){
                @Override
                public void onClick(DialogInterface arg0, int arg1) {
                    MyDBHelper dbHelper = new MyDBHelper(mContext);
                    dbHelper.deleteContact(c.getId(), mContext);
                    mContactList.remove(position);
                    mRecyclerView.removeViewAt(position);
                    notifyItemRemoved(position);
                    notifyItemRangeChanged(position, mContactList.size());
                    notifyDataSetChanged();
                }
            });
            builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener(){
                @Override
                public void onClick(DialogInterface arg0, int arg1) {
                    arg0.dismiss();
                }
            });
            builder.create().show();

            }
    });
        }



    private void goToUpdateActivity(long personId){
        Intent intent = new Intent(mContext, UpdateContact.class);
        intent.putExtra("CONTACT_ID", personId);
//        mContext.startActivity(intent);

        final Dialog dialog = new Dialog(mContext);
        dialog.setContentView(R.layout.activity_update_contact);
        dialog.setTitle("Lab 6");
        mNameEditText = (EditText)dialog.findViewById(R.id.contactName);
        mLastname = (EditText)dialog.findViewById(R.id.contactLastname);
        mPhoneEditText = (EditText)dialog.findViewById(R.id.contactPhone);
        mUpdateBtn = (Button)dialog.findViewById(R.id.updateButton);
        dbHelper = new MyDBHelper(mContext.getApplicationContext());
        try{
            contactId = intent.getLongExtra("CONTACT_ID", 1);
        } catch (Exception e) {
            e.printStackTrace();
        }
        Contact c = dbHelper.getContact(contactId);
        mNameEditText.setText(c.getName());
        mLastname.setText(c.getLastname());
        mPhoneEditText.setText(c.getPhone_number());
        mUpdateBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                updateContact(dialog);
            }
        });
        dialog.show();
    }

    public void updateContact(Dialog dialog){
        String name = mNameEditText.getText().toString().trim();
        String lastname = mLastname.getText().toString().trim();
        String phone = mPhoneEditText.getText().toString().trim(); if(name.isEmpty()){
            Toast.makeText(mContext, "You must enter a name", Toast.LENGTH_SHORT).show();
        }
        if(lastname.isEmpty()){
            Toast.makeText(mContext, "You must enter a last name", Toast.LENGTH_SHORT).show();
        }
        if(phone.isEmpty()){
            Toast.makeText(mContext, "You must enter a phone number", Toast.LENGTH_SHORT).show();
        }
        Contact updatedContact = new Contact(name, lastname, phone);
        dbHelper.updateContact(contactId, mContext, updatedContact);
        dialog.dismiss();
        Intent intent2 = new Intent(mContext, MainActivity.class);
        mContext.startActivity(intent2);
    }

    @Override
    public int getItemCount() {
        return mContactList.size();
    }


            }

