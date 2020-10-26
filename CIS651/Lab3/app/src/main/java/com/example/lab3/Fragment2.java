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

public class Fragment2 extends Fragment {
    private FragmentTracker ft;
    private View v;
    public static final String fragmentTitle="Address Info";
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        ft.fragmentVisible(fragmentTitle);
        v=inflater.inflate(R.layout.second_fragment, container, false);
        Button b_prev=v.findViewById(R.id.prev_button2);
        Button b_next=v.findViewById(R.id.next_button2);
        b_next.setOnClickListener((view) -> {ft.goNext();});
        b_prev.setOnClickListener((view) -> {ft.goBack();});
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
       EditText ucity=v.findViewById(R.id.u_city);
       EditText uzip=v.findViewById(R.id.u_zip);
       ft.saveCityAndZip(ucity.getText().toString(),uzip.getText().toString());
       v=null;
   }
}
