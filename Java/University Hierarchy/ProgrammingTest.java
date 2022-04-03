package com.company;

import java.util.HashSet;
import java.util.Set;

public class ProgrammingTest {

    public static void main(String[] args) {
        Undergraduate st1=new Undergraduate("Olga","gg4","olga@mail.ru");
        st1.setTutor(new Academic("Paul Deitel"));
        Undergraduate st2=new Undergraduate("Jan","pr3","jan@mail.ru");
        st2.setTutor(new Academic("Cay Horstmann"));
        Postgraduate st3=new Postgraduate("Victor","te2","victor@mail.ru");
        st3.setSupervisor(new Academic("Paul Deitel"));
        Postgraduate st4=new Postgraduate("Artem","yj34","artem@mail.ru");
        st4.setSupervisor(new Academic("Cay Horstmann"));
        Postgraduate st5=new Postgraduate("Nastya","jj8","nastya@mail.ru");
        st5.setSupervisor(new Academic("Cay Horstmann"));
        Postgraduate st6=new Postgraduate("Egor","kt8","egor@mail.ru");
        st6.setSupervisor(new Academic("Paul Deitel"));
        Set<Student> studentSet=new HashSet<>();
        studentSet.add(st1);
        studentSet.add(st2);
        studentSet.add(st3);
        studentSet.add(st4);
        studentSet.add(st5);
        Course course=new Course(studentSet,"course");
        course.addStudent(st6);
        Writer writer=new Writer();
        writer.save(course);
        Notifier notifier=new Notifier(studentSet);
        notifier.doNotifyAll("Hello,Students!");
        for(Postgraduate pg:course.getPostgraduates("Cay Horstmann")){
            System.out.println(pg.getName());
        }
    }
}
