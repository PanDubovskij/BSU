package com.company.sweets;

public abstract class Sweet implements Comparable<Sweet> {
    private String name;
    private double weight;
    private double sugar;
    private double price;

    public Sweet(String name, double weight, double sugar, double price) {
        this.name = name;
        this.weight = weight;
        this.sugar = sugar;
        this.price = price;
    }
    public int compareTo(Sweet sweet){
        return Double.compare(this.getPrice(),sweet.getPrice());
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getSugar() {
        return sugar;
    }

    public void setSugar(double sugar) {
        this.sugar = sugar;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return     name +
                " " + weight +
                " " + sugar +
                " " + price;
    }
}
