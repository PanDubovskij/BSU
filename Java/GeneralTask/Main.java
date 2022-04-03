package com.company;

import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
        //лампы накаливания
        MyCollection<Lamp> collection=new MyCollection<>();
        try {
            collection.readIncandescentLamp("inputIncandescentLamp.txt");
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
        System.out.println(collection);
        System.out.println("Sorted collection by price");
        System.out.println(collection.sortCollection());
        System.out.println("Sorted collection by price/power");
        System.out.println(collection.sortCollectionByPriceAndPower());
        System.out.println("Producers");
        try {
            System.out.println(collection.getProducers());
        } catch (MyException e) {
            System.out.println("Empty collection");
        }
        System.out.print("Average price=");
        try {
            System.out.printf("%.2f",collection.countAverage("Belarus"));
        } catch (MyException e) {
            System.out.println("Nothing is found with such name");
        }
        System.out.println();
        System.out.println();
        //светодиодные лампочки
        MyCollection<Lamp> collection2=new MyCollection<>();
        try {
            collection2.readLedLamp("inputLedLamp.txt");
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
        System.out.println(collection2);
        System.out.println("Sorted collection by price");
        System.out.println(collection2.sortCollection());
        System.out.println("Sorted collection by price/power");
        System.out.println(collection2.sortCollectionByPriceAndPower());
        System.out.println("Producers");
        try {
            System.out.println(collection2.getProducers());
        } catch (MyException e) {
            System.out.println("Empty collection");
        }
        System.out.print("Average price=");
        try {
            System.out.printf("%.2f",collection2.countAverage("France"));
        } catch (MyException e) {
            System.out.println("Nothing is found with such name");
        }
    }
}
