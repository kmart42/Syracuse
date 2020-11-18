package com.example.lab6;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class UpdateContact extends AppCompatActivity {
    private EditText mNameEditText;
    private EditText mLastname;
    private EditText mPhoneEditText;
    private Button mUpdateBtn;
    private MyDBHelper dbHelper;
    private long contactId;
    private LayoutInflater inflater;
    @Override
    protected void onCreate (Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update_contact);

        mNameEditText = (EditText)findViewById(R.id.contactName);
        mLastname = (EditText)findViewById(R.id.contactLastname);
        mPhoneEditText = (EditText)findViewById(R.id.contactPhone);
        mUpdateBtn = (Button)findViewById(R.id.updateButton);
        dbHelper = new MyDBHelper(this);
        try{
            contactId = getIntent().getLongExtra("CONTACT_ID", 1);
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
                updateContact();
            }
        });
    }




    public void updateContact(){
        String name = mNameEditText.getText().toString().trim();
        String lastname = mLastname.getText().toString().trim();
        String phone = mPhoneEditText.getText().toString().trim(); if(name.isEmpty()){
            Toast.makeText(this, "You must enter a name", Toast.LENGTH_SHORT).show();
        }
        if(lastname.isEmpty()){
            Toast.makeText(this, "You must enter a last name", Toast.LENGTH_SHORT).show();
        }
        if(phone.isEmpty()){
            Toast.makeText(this, "You must enter a phone number", Toast.LENGTH_SHORT).show();
        }
        Contact updatedContact = new Contact(name, lastname, phone);
        dbHelper.updateContact(contactId, this, updatedContact);
        finish();
    }

}
