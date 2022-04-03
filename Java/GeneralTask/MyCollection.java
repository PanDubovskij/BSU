package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.Collectors;

public class MyCollection<T extends Lamp> {
    private ArrayList<T> collection=new ArrayList<>();

    public void add(T elem){
        collection.add(elem);
    }

    public ArrayList<T> sortCollection(){
        ArrayList<T> sortedCollection=new ArrayList<>(collection);
        sortedCollection.sort(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return Double.compare(o2.countPrice(),o1.countPrice());
            }
        });
        return sortedCollection;
    }
    public ArrayList<T> sortCollectionByPriceAndPower(){
        ArrayList<T> sortedCollection=new ArrayList<>(collection);
        sortedCollection.sort(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return Double.compare(o2.countPrice()/o2.getPower(),o1.countPrice()/o1.getPower());
            }
        });
        return sortedCollection;
    }

    public Set<String> getProducers() throws MyException{
        if (collection.isEmpty()) {
            throw new MyException("Empty collection");
        }
        Set<String> producers=collection
                .stream()
                .collect(Collectors.groupingBy(l->l.getProducer()))
                .entrySet()
                .stream()
                .map(Map.Entry::getKey)
                .collect(Collectors.toSet());
        return producers;
    }

    public double countAverage(String name) throws MyException {
        if (collection.isEmpty()) {
            throw new MyException("Empty collection");
        }
        OptionalDouble average = collection
                .stream()
                .filter(p -> p.getProducer().equals(name))
                .mapToDouble(p -> p.countPrice())
                .average();
        if (!average.isEmpty()) {
            return average.getAsDouble();
        } else throw new MyException("Nothing find");
    }

    public void readIncandescentLamp(String filename) throws FileNotFoundException{
        File file = new File(filename);
        try (Scanner sc = new Scanner(file)) {
            while (sc.hasNextLine()) {
                try {
                    String lines = sc.nextLine();
                    Scanner scLine = new Scanner(lines);
                    add((T) new IncandescentLamp(scLine.next(), scLine.nextInt(), scLine.nextDouble()));
                } catch (InputMismatchException ex) {
                    continue;
                }
            }
        }
    }
    public void readLedLamp(String filename) throws FileNotFoundException{
        File file = new File(filename);
        try (Scanner sc = new Scanner(file)) {
            while (sc.hasNextLine()) {
                try {
                    String lines = sc.nextLine();
                    Scanner scLine = new Scanner(lines);
                    add((T) new LedLamp(scLine.next(), scLine.nextInt(), scLine.nextInt()));
                } catch (InputMismatchException ex) {
                    continue;
                }
            }
        }
    }

    @Override
    public String toString() {
        String str=new String();
        for(T elem: collection){
            str+=elem+"\n";
        }
        return str;
    }
}
