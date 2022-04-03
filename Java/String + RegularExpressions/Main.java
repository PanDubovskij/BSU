package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        String str=new String("a-000123+0000+bc+0000.000812+0+0001.07");
        String str1=str.replaceAll("(0*)(\\d\\.[\\d]*)","$2");
        String str2=str1.replaceAll("([^\\.0])(0*)([\\d])","$1$3");
        System.out.println(str2);
       /* for(int i=0;i<builder.length();i++){
            if(builder.charAt(i)=='0'){
                if(builder.charAt(i+1)=='.'){
                    int j=i+2;
                    new_str.append(builder.charAt(i));
                    new_str.append(builder.charAt(i+1));
                    for(;builder.charAt(j)=='0'&&j<builder.length();j++){
                        new_str.append(builder.charAt(j));
                    }
                    i=j+2;
                    while((builder.charAt(j)!='0'&&j<builder.length())||(builder.charAt(j-1)!='0'&&builder.charAt(j+1)!='0')){
                    new_str.append(builder.charAt(j));
                    j++;
                    i++;
                    }
                }else if(builder.charAt(i-1)=='.'){
                    new_str.append(builder.charAt(i));
                }else if(builder.charAt(i-1)!='0'&&builder.charAt(i+1)!='0'){
                    new_str.append(builder.charAt(i));
                }
            }else {
                new_str.append(builder.charAt(i));
            }
        }*/

    }
}
