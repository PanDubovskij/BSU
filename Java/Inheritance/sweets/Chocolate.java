package com.company.sweets;

public class Chocolate extends Sweet {
    private double cacao;
    private String filling;

    public Chocolate(String name, double weight, double sugar, double price,double cacao, String filling) {
        super(name, weight, sugar, price);
        this.cacao = cacao;
        this.filling = filling;
    }

    public double getCacao() {
        return cacao;
    }

    public void setCacao(double cacao) {
        this.cacao = cacao;
    }

    public String getFilling() {
        return filling;
    }

    public void setFilling(String filling) {
        this.filling = filling;
    }

    @Override
    public String toString() {
        return "c " + super.toString() +
                " " + cacao +
                " " + filling + '\n';
    }

}
