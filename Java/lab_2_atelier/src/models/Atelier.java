package models;

import java.io.Serializable;
import java.util.ArrayList;

public class Atelier implements Serializable {

    private ArrayList<Order> orders;

    public Atelier(ArrayList<Order> orders) {
        this.orders = orders;
    }

    public ArrayList<Order> getOrders() {
        return orders;
    }

    public void setOrders(ArrayList<Order> orders) {
        this.orders = orders;
    }

    @Override
    public String toString() {
        var str = new StringBuilder();
        for (Order order : orders) {
            str.append(order.getDate().toString());
            str.append("\n");
            for (Service service : order.getServices()) {
                str.append(service.getType().toString());
                str.append(" ");
            }
            str.append("\n");
        }
        return str.toString();
    }
}
