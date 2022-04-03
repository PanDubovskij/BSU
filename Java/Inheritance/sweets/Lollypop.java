package com.company.sweets;

public class Lollypop extends Sweet {
    private String form;
    private String taste;


    public Lollypop(String name, double weight, double sugar, double price,String form, String taste) {
        super(name, weight, sugar, price);
        this.form = form;
        this.taste = taste;
    }

    public String getForm() {
        return form;
    }

    public void setForm(String form) {
        this.form = form;
    }

    public String getTaste() {
        return taste;
    }

    public void setTaste(String taste) {
        this.taste = taste;
    }
    @Override
    public String toString() {
        return "l " +super.toString() +
                " " + form +
                " " + taste + '\n';
    }
}
