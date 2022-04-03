package com.company;

public class Student implements Comparable<Student> {
    private String name;
    private int age;
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public int getAge() {
        return this.age;
    }
    public String getName() {
        return this.name;
    }
    @Override
    public String toString() {
        return name+" "+age+" ";
    }
    @Override
    public int compareTo(Student other) {
      //  return (age-other.age);
        return Integer.compare(age,other.age);
    }
}
