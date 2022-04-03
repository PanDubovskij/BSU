package com.company;

import java.util.Objects;

public class LedLamp extends Lamp{
    private int number;
    private final double CONST2=200;

    public LedLamp(String producer, int power,int number) {
        super(producer, power);
        this.number=number;
    }

    @Override
    public double countPrice() {
        return super.getPower()*number/CONST2;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return super.toString() +
                "number=" + number +
                ", price=" + String.format("%.2f",countPrice())+
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        LedLamp ledLamp = (LedLamp) o;
        return number == ledLamp.number;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), number);
    }
}
