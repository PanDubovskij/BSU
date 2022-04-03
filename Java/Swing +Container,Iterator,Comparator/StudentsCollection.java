package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class StudentsCollection {
    private TreeSet<Student> students;
    private ArrayList<Student> sortedStudents;

    public StudentsCollection() {
        students = new TreeSet<Student>(((s1,s2)->s2.getNumber()-s1.getNumber()));
        sortedStudents = new ArrayList<Student>();
    }

    public void read(String fileName) {
        try {
            Scanner sc = new Scanner(new File(fileName));
            while (sc.hasNext()) {
                boolean isExisted = false;
                int id = sc.nextInt();
                String surname = sc.next();
                int term = sc.nextInt();
                String subject = sc.next();
                int mark = sc.nextInt();
                for (Student student : students) {
                    if (student.getNumber() == id && student.getTerm() == term && student.getSurname().equals(surname)) {
                        TreeMap<String, Integer> exams = student.getExams();
                        exams.put(subject, Integer.valueOf(mark));
                        student.setExams(exams);
                        isExisted = true;
                    }else if(student.getNumber() == id && student.getTerm() != term && !student.getSurname().equals(surname)){
                        isExisted=true;
                    }
                }
                if (!isExisted) {
                    Student st = new Student(id, surname, term);
                    TreeMap<String, Integer> exams = new TreeMap<>();
                    exams.put(subject, Integer.valueOf(mark));
                    st.setExams(exams);
                    students.add(st);
                }

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    public void add(Student st){
        students.add(st);
    }
    public void findBadStudents(String str){
        String[] subjects=str.split("\\s");
        int term=Integer.parseInt(subjects[0]);
        for(Student student:students){
            boolean isBad=true;
            for(int i=1;i< subjects.length;i++){
                if(student.getTerm()==term && student.getExams().get(subjects[i])>2){
                    isBad=false;
                }
            }
            if(student.getTerm()==term && isBad){
                sortedStudents.add(student);
            }
        }
        sortedStudents.sort(Comparator.comparing(Student::getSurname));
    }

    public TreeSet<Student> getStudents() {
        return students;
    }

    public void setStudents(TreeSet<Student> students) {
        this.students = students;
    }

    public ArrayList<Student> getSortedStudents() {
        return sortedStudents;
    }

    public void setSortedStudents(ArrayList<Student> sortedStudents) {
        this.sortedStudents = sortedStudents;
    }
}
