package com.company;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.TreeMap;
import java.util.TreeSet;

public class Student implements Comparable<Student> {
    private int number;
    private String surname;
    private int term;
    private TreeMap<String,Integer> exams;


    public Student(int number, String surname, int term) {
        this.number = number;
        this.surname = surname;
        this.term = term;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public int getTerm() {
        return term;
    }

    public void setTerm(int term) {
        this.term = term;
    }

    public TreeMap<String, Integer> getExams() {
        return exams;
    }

    public void setExams(TreeMap<String, Integer> exams) {
        this.exams = exams;
    }

    @Override
    public String toString() {
        return "Student{" +
                "number=" + number +
                ", surname='" + surname + '\'' +
                ", term=" + term +
                ", exams=" + exams +
                '}';
    }

    @Override
    public int compareTo(Student o) {
        return this.getNumber()-o.getNumber();
    }
}
