package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        BinaryTree<Student> bt = new BinaryTree<>();
        Student st1=new Student("Olga",6);
        Student st2=new Student("Victor",4);
        Student st3=new Student("Katya",8);
        Student st4=new Student("Liza",3);
        Student st5=new Student("Jan",5);
        Student st6=new Student("Ivan",7);
        Student st7=new Student("Artem",9);

        bt.add(st1);
        bt.add(st2);
        bt.add(st3);
        bt.add(st4);
        bt.add(st5);
        bt.add(st6);
        bt.add(st7);
        bt.traverseInOrder();
        bt.traversePostOrder();
        bt.traversePreOrder();
        System.out.println(bt.find(st1));
        System.out.println(bt.find(new Student("Olga",16)));

        BinaryTree<Integer> bt2=new BinaryTree<>();
        bt2.add(6);
        bt2.add(4);
        bt2.add(8);
        bt2.add(3);
        bt2.add(5);
        bt2.add(7);
        bt2.add(9);
        bt2.traverseInOrder();
        bt2.traversePostOrder();
        bt2.traversePreOrder();
        System.out.println(bt2.find(8));

    }
}
