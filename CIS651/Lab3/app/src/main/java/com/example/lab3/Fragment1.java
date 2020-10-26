package com.example.lab3;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import java.util.Objects;

public class Fragment1 extends Fragment {
    private FragmentTracker ft;
    private View v;
    public static final String fragmentTitle="Personal Info";
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        ft.fragmentVisible(fragmentTitle);
        v=inflater.inflate(R.layout.first_fragment, container, false);
        Button b_next=v.findViewById(R.id.next_button1);
        b_next.setOnClickListener((view) -> {ft.goNext();});
        return v;
    }
    @Override
    public void onAttach(Context context){
        super.onAttach(context);
        try{
            ft=(FragmentTracker) context;
        }
        catch (ClassCastException ex)
        {
            throw new ClassCastException(context.toString()+"must implement EventTrack");
        }
    }
   @Override
   public void onDetach(){
        super.onDetach();
       EditText uname=v.findViewById(R.id.u_name);
       EditText ulname=v.findViewById(R.id.u_lastname);
       ft.saveNameAndLastName(uname.getText().toString(),ulname.getText().toString());
       v=null;
   }
}
