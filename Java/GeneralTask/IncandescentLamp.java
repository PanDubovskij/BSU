package com.company;

import java.util.Objects;

public class IncandescentLamp extends Lamp{
    private double time;
    private final double CONST1=0.0007;

    public IncandescentLamp(String producer, int power,double time) {
        super(producer, power);
        this.time=time;
    }

    @Override
    public double countPrice() {
        return super.getPower()*CONST1*time;
    }

    public double getTime() {
        return time;
    }

    public void setTime(double time) {
        this.time = time;
    }

    @Override
    public String toString() {
        return super.toString() +
                "time=" + time +
                ", price=" + String.format("%.2f",countPrice())+
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        IncandescentLamp that = (IncandescentLamp) o;
        return Double.compare(that.time, time) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), time);
    }
}
