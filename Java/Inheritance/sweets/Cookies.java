package com.company.sweets;

public class Cookies extends Sweet {
    private String filling;
    private String chocolate;

    public Cookies(String name, double weight, double sugar, double price, String chocolate,String filling) {
        super(name, weight, sugar, price);
        this.filling = filling;
        this.chocolate = chocolate;
    }

    public String getFilling() {
        return filling;
    }

    public void setFilling(String filling) {
        this.filling = filling;
    }

    public String isChocolate() {
        return chocolate;
    }

    public void setChocolate(String chocolate) {
        this.chocolate = chocolate;
    }

    @Override
    public String toString() {
        return "k " +super.toString() +
                " " + chocolate +
                " " + filling + '\n';
    }
}
