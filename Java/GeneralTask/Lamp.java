package com.company;

import java.util.Objects;

public abstract class Lamp {
    private String producer;
    private int power;

    public Lamp(String producer, int power) {
        this.producer = producer;
        this.power = power;
    }

    public abstract double countPrice();

    public String getProducer() {
        return producer;
    }

    public void setProducer(String producer) {
        this.producer = producer;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    @Override
    public String toString() {
        return "Lamp{" +
                "producer='" + producer + '\'' +
                ", power=" + power +
                ", ";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Lamp lamp = (Lamp) o;
        return power == lamp.power && producer.equals(lamp.producer);
    }

    @Override
    public int hashCode() {
        return Objects.hash(producer, power);
    }
}
