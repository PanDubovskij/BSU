import view.SwingForm;

import java.io.IOException;
import java.text.ParseException;

public class Main {
    public static void main(String[] args) throws ParseException, IOException {
//        File outFile = new File("output.txt");
//        OutputStream os = new FileOutputStream(outFile);
//        ObjectOutputStream oos = new ObjectOutputStream(os);
//        SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy");
//        Service s1 = new Service(ServiceType.CLEANING);
//        Service s2 = new Service(ServiceType.SHOES_REPAIR);
//        Service s3 = new Service(ServiceType.CLOTHING_REPAIR);
//        Service s4 = new Service(ServiceType.TAILORING);
//        Service s5 = new Service(ServiceType.ZIPPER_REPLACEMENT);
//        ArrayList<Service> as1 = new ArrayList<>();
//        as1.add(s1);
//        as1.add(s2);
//        as1.add(s3);
//        as1.add(s4);
//        as1.add(s5);
//        Order o1 = new Order(formatter.parse("01-09-2022"), as1);
//        Order o2 = new Order(formatter.parse("01-10-2022"), as1);
//        Order o3 = new Order(formatter.parse("01-10-2022"), as1);
//        Order o4 = new Order(formatter.parse("01-09-2022"), as1);
//        Order o5 = new Order(formatter.parse("01-08-2022"), as1);
//        ArrayList<Order> orders = new ArrayList<>();
//        orders.add(o1);
//        orders.add(o2);
//        orders.add(o3);
//        orders.add(o4);
//        orders.add(o5);
//        Atelier atelier = new Atelier(orders);
//        oos.writeObject(atelier);
//        AtelierManager atelierManager = new AtelierManager(atelier);
//        List<Order> neededOrders = atelierManager.getOrdersPerMonth(9);
//        System.out.println(neededOrders.size());
//        for(Order order: neededOrders){
//            for(Service service: order.getServices()){
//                System.out.print(service.getType().toString()+" ");
//            }
//            System.out.println();
//        }
//        controller.AtelierManager atelierManager = new controller.AtelierManager(atelier);
//        List<Order> neededOrders = atelierManager.getOrdersPerDay(formatter.parse("01-09-2022"));
//        System.out.println(neededOrders.size());
//        for(Order order: neededOrders){
//            for(Service service: order.getServices()){
//                System.out.print(service.getType().toString()+" ");
//            }
//            System.out.println();
//        }

//        controller.AtelierManager atelierManager = new controller.AtelierManager(atelier);
//        List<Order> neededOrders = atelierManager.getOrdersPerQuarter(4);
//        System.out.println(neededOrders.size());
//        for (Order order : neededOrders) {
//            System.out.print(order.getDate().toString()+" ");
//            for (Service service : order.getServices()) {
//                System.out.print(service.getType().toString() + " ");
//            }
//            System.out.println();
//        }

        SwingForm swingForm = new SwingForm();
    }
}