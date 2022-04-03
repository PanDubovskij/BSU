package com.company.present;

import com.company.sweets.Chocolate;
import com.company.sweets.Cookies;
import com.company.sweets.Lollypop;
import com.company.sweets.Sweet;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Present {
    private ArrayList<Sweet> present;
    private double weight=0;
    public Present(){
        present=new ArrayList<Sweet>();
    }
    public void add(Sweet sweet){
        present.add(sweet);
        weight+=sweet.getWeight();
    }
    public double getWeight(){
        return weight;
    }
    public void sortByPrice(){
        Collections.sort(present);
    }

    public Sweet findSweet(double sugar1,double sugar2){
        for(Sweet sweet:present){
            if(sweet.getSugar()>=sugar1 && sweet.getSugar()<=sugar2){
                return sweet;
            }
        }
        return null;
    }

    public void save(String filename){
        try(FileWriter writer = new FileWriter(filename))
        {
            writer.write(this.toString());
        }
        catch(IOException ex){
            System.out.println(ex.getMessage());
        }
    }

    public void read(String filename){
        try {
            Scanner sc=new Scanner(new File(filename));
            while(sc.hasNext()){
                String next=sc.next();
                if(next.equals("l")){
                 this.add(new Lollypop(sc.next(),sc.nextDouble(),sc.nextDouble(),sc.nextDouble(),sc.next(),sc.next()));
                }else if(next.equals("c")){
                    this.add(new Chocolate(sc.next(),sc.nextDouble(),sc.nextDouble(),sc.nextDouble(),sc.nextDouble(),sc.next()));
                }else if(next.equals("k")){
                    this.add(new Cookies(sc.next(),sc.nextDouble(),sc.nextDouble(),sc.nextDouble(),sc.next(),sc.next()));
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public String toString() {
        String str=new String();
        for(Sweet sweet:present){
            str+=sweet.toString();
        }
        return str;
    }
}
