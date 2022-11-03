package managers;

import models.Atelier;
import models.Order;

import java.util.Date;
import java.util.List;

public class AtelierManager {
    private Atelier atelier;

    public AtelierManager(Atelier atelier) {
        this.atelier = atelier;
    }

    public List<Order> getOrdersPerMonth(int month) {
        return atelier.getOrders().stream().filter((order) -> (order.getDate().getMonth() == month)).toList();
    }

    public List<Order> getOrdersPerDay(Date date) {
        return atelier.getOrders().stream().filter((order) -> (order.getDate().equals(date))).toList();
    }

    public List<Order> getOrdersPerQuarter(int quarter) {
        return atelier.getOrders().stream().filter((order) -> ((order.getDate().getMonth()) / 3 == quarter)).toList();
    }

    public void addOrder(Order order) {
        atelier.getOrders().add(order);
    }
}
