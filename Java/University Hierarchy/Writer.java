package com.company;

import java.io.FileWriter;
import java.io.IOException;

public class Writer {
    public void save(Course course){
        try(FileWriter writer = new FileWriter("output.txt"))
        {
            writer.write(course.toString());
        }
        catch(IOException ex){
            System.out.println(ex.getMessage());
        }
    }
}
