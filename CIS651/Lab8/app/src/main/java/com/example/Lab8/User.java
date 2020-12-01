package com.example.Lab8;

import android.net.Uri;

import com.google.firebase.database.ServerValue;

public class User {
    public String displayname;
    public String email;
    public String phone;
    public Object timestamp;
    public Uri photoUrl;
//    public int photoId;
    public User(String displayname, String email, Uri photoUrl, String phone) {
        this.displayname=displayname;
        this.email=email;
        this.phone=phone;
        this.photoUrl=photoUrl;
//        this.photoId=photoId;
        this.timestamp= ServerValue.TIMESTAMP;
    }
    public Object getTimestamp(){
        return timestamp;
    }
    public User() {

    }
}
