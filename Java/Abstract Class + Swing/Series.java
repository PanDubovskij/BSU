package com.company;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public abstract class Series {
    private int n=1;

    public void setN(int n_){
        n=n_;
    }
    public abstract double getElem(int j);
    public double getSum(){
        double sum=0;
        for (int i=1;i<=n;i++){
            sum+=getElem(i);
        }
        return sum;
    }
    public String toString(){
        StringBuilder str=new StringBuilder();
        for (int i=1;i<=n;i++){
            str.append(getElem(i));
            str.append(" ");
        }
        return new String(str);
    }
    public void save(String fileName) throws IOException{
        try(FileWriter fileWriter = new FileWriter(fileName);
        PrintWriter printWriter = new PrintWriter(fileWriter)){
        printWriter.print(this.toString()+"\nSum="+this.getSum());
        } catch (IOException ex){
            throw new IOException(ex.getMessage());
        }
    }
}
