package models;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;

public class Order implements Serializable {
    private Date date;
    private ArrayList<Service> services;


    public Order(Date date, ArrayList<Service> services) {
        this.date = date;
        this.services = services;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public ArrayList<Service> getServices() {
        return services;
    }

    public void setServices(ArrayList<Service> services) {
        this.services = services;
    }

    @Override
    public String toString() {
        var stringBuilder = new StringBuilder();
        for (Service service : services) {
            stringBuilder.append(service.getType().toString());
            stringBuilder.append(" ");
        }
        return stringBuilder.toString();
    }
}
