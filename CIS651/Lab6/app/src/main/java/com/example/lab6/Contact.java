package com.example.lab6;

public class Contact {
    private long id;
    private String name;
    private String lastname;
    private String phone_number;
    public Contact(){}
    public Contact(String name, String lastname, String phone_number){
        this.name = name;
        this.lastname = lastname;
        this.phone_number = phone_number;
    }

    public String getName() {
        return name;
    }

    public String getLastname() {
        return lastname;
    }

    public String getPhone_number() {
        return phone_number;
    }

    public long getId(){
        return id;
    }

    public void setId(long aLong) {
        this.id = aLong;
    }

    public void setName(String string) {
        this.name = string;
    }

    public void setLastname(String string) {
        this.lastname = string;
    }

    public void setPhone_number(String string) {
        this.phone_number = string;
    }
}
