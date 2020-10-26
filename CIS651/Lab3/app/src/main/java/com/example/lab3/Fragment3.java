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

public class Fragment3 extends Fragment {
    private FragmentTracker ft;
    private View v;
    public static final String fragmentTitle="Details Info";
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        ft.fragmentVisible(fragmentTitle);
        v=inflater.inflate(R.layout.third_fragment, container, false);
        Button b_prev=v.findViewById(R.id.prev_button3);
        Button b_finished=v.findViewById(R.id.finish_button);
        b_finished.setOnClickListener((view) -> {ft.finished();});
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
       EditText ulang=v.findViewById(R.id.u_det1);
       ft.saveLanguage(ulang.getText().toString());
       v=null;
   }



}
