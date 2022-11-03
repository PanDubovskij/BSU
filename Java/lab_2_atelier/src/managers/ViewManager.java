package managers;

import models.Atelier;
import models.Order;

import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

public class ViewManager {

    private static ViewManager instance;
    private Atelier atelier;
    private AtelierManager atelierManager;
    private String results;

    private ViewManager() {}

    public static ViewManager getInstance() {
        if (instance == null) {
            instance = new ViewManager();
        }
        return instance;
    }

    public Atelier getAtelier() {
        return atelier;
    }


    public String getAtelierString(String path) throws IOException, ClassNotFoundException {
        var inFile = new File(String.valueOf(path));
        InputStream is = new FileInputStream(inFile);
        var ois = new ObjectInputStream(is);
        atelier = (Atelier) ois.readObject();
        atelierManager = new AtelierManager(atelier);
        return atelier.toString();
    }

    public void saveAtelierString(File outFile) throws IOException {
        OutputStream os = new FileOutputStream(outFile);
        var oos = new ObjectOutputStream(os);
        oos.writeObject(atelier);
    }

    public void showResults(String period, String data) throws ParseException {
        var result = new StringBuilder();
        var formatter = new SimpleDateFormat("dd-MM-yyyy");
        List<Order> orders = new ArrayList<>();
        switch (period) {
            case "Day" -> {
                orders = atelierManager.getOrdersPerDay(formatter.parse(data));
            }
            case "Month" -> {
                orders = atelierManager.getOrdersPerMonth(Integer.parseInt(data));
            }
            case "Quarter" -> {
                orders = atelierManager.getOrdersPerQuarter(Integer.parseInt(data));
            }
        }
        result.append("Number of orders: ").append(orders.size()).append("\n");
        for (Order order : orders) {
            result.append(order.getDate().toString()).append("\n").append(order).append("\n");
        }
        results = result.toString();
    }

    public String getResults() {
        return results;
    }

    public void addOrder(Order order) {
        atelierManager.addOrder(order);
    }
}
