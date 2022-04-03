package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {


    public static void main(String[] args) {
	// write your code here
        MyApp app=new MyApp();
        /*try {
            Scanner sc=new Scanner(new File("input.txt"));
            TreeSet<Student> students=new TreeSet<>();
            while(sc.hasNext()){
                boolean flag=false;
                int id=sc.nextInt();
                String surname=sc.next();
                int term=sc.nextInt();
                String subject=sc.next();
                int mark=sc.nextInt();
                for(Student student:students){
                    if(student.getNumber()==id && student.getTerm()==term && student.getSurname().equals(surname)){
                        TreeMap<String,Integer> exams=student.getExams();
                        exams.put(subject,Integer.valueOf(mark));
                        student.setExams(exams);
                        flag=true;
                    }
                }
                if(!flag){
                    Student st=new Student(id,surname,term);
                TreeMap<String,Integer> exams=new TreeMap<>();
                exams.put(subject,Integer.valueOf(mark));
                st.setExams(exams);
                students.add(st);
                }
            }
            System.out.println(students);
            String str="1 Programming Maths English History";
            String[] subjects=str.split("\\s");
            int term=Integer.parseInt(subjects[0]);
            for(int i=1;i<subjects.length;i++){
                String subject=subjects[i];
                System.out.println(subject+": ");
                for(Student student: students){
                    if(student.getTerm()==term && student.getExams().get(subject)==2){
                        System.out.print(student);
                    }
                }

            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }*/
    }
}
