package com.company;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.function.Predicate;

public class Course implements Iterable<Student>{
    private Set<Student> students;
    private String name;

    public Course(Set<Student> students, String name) {
        this.students = students;
        this.name = name;
    }

    public Set<Postgraduate> getPostgraduates(String nameOfSupervisor){
        Set<Postgraduate> studentsBySupervisor= new HashSet<>();
        for(Student student:students){
            try {
                if (student.getClass() == Postgraduate.class && ((Postgraduate) student).getSupervisor().getName()==nameOfSupervisor) {
                    studentsBySupervisor.add((Postgraduate) student);
                }
            } catch (NullPointerException ex){
                continue;
            }
        }
        return studentsBySupervisor;
    }
    public Set<Student> studentsByCondition (Predicate<Student> condition){
        Set<Student> studentsByCondition=new HashSet<>();
        for(Student student:students){
            if(condition.test(student)){
                studentsByCondition.add(student);
            }
        }
        return studentsByCondition;
    }
    public void addStudent(Student student){
        students.add(student);
    }

    @Override
    public Iterator iterator() {
        return students.iterator();
    }

    public Set<Student> getStudents() {
        return students;
    }

    public void setStudents(Set<Student> students) {
        this.students = students;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Course{" +
                "students=" + students +
                ", name='" + name + '\'' +
                '}';
    }
}
