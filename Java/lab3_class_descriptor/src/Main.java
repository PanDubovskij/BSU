import views.SimpleFrame;

import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.text.NumberFormat;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.Locale;

public class Main {
    public static void main(String[] args) throws ParseException {
        /*DateTimeFormatter formatter = DateTimeFormatter.ofLocalizedDate(FormatStyle.MEDIUM).localizedBy(Locale.US);
        LocalDate date = LocalDate.parse("Jan 12, 1952",formatter);
        System.out.println(date);
        formatter = DateTimeFormatter.ofLocalizedDate(FormatStyle.MEDIUM).localizedBy(Locale.ITALY);
        System.out.println(formatter.format(date));*/
        /*NumberFormat format = NumberFormat.getCurrencyInstance(Locale.US);
        Number number = format.parse("$5,600");
        System.out.println(number.doubleValue());*/
        SimpleFrame simpleFrame = new SimpleFrame();
        simpleFrame.pack();
        simpleFrame.setVisible(true);
//        String name = "java.lang.Integer";
//        Class cl;
//        try {
//            cl = Class.forName(name);
//            try (FileWriter fileWriter = new FileWriter(name + ".java")) {
//                Class supercl = cl.getSuperclass();
//                String modifiers = Modifier.toString(cl.getModifiers());
//                if (modifiers.length() > 0) fileWriter.write(modifiers + " ");
//                fileWriter.write("class " + name);
//                if (supercl != null && supercl != Object.class) fileWriter.write(" extends " + supercl.getName());
//                fileWriter.write("\n{\n");
//                printConstructors(cl, fileWriter);
//                fileWriter.write("\n");
//                printMethods(cl, fileWriter);
//                fileWriter.write("\n");
//                printFields(cl, fileWriter);
//                fileWriter.write("}");
//            } catch (IOException e) {
//                System.out.println(e.getMessage());
//            }
//        } catch (ClassNotFoundException e) {
//            System.out.println(e.getMessage());
//        }
//    }
//
//    public static void printConstructors(Class cl, FileWriter fileWriter) throws IOException {
//        Constructor[] constructors = cl.getDeclaredConstructors();
//        for (Constructor c : constructors) {
//            String name = c.getName();
//            fileWriter.write(" ");
//            String modifiers = Modifier.toString(c.getModifiers());
//            if (modifiers.length() > 0) fileWriter.write(modifiers + " ");
//            fileWriter.write(name + "(");
//
//            Class[] paramTypes = c.getParameterTypes();
//            for (int j = 0; j < paramTypes.length; j++) {
//                if (j > 0) fileWriter.write(", ");
//                fileWriter.write(paramTypes[j].getName());
//            }
//            fileWriter.write(");\n");
//        }
//    }
//
//    public static void printMethods(Class cl, FileWriter fileWriter) throws IOException {
//        Method[] methods = cl.getDeclaredMethods();
//        for (Method m : methods) {
//            Class retType = m.getReturnType();
//            String name = m.getName();
//            fileWriter.write(" ");
//            String modifiers = Modifier.toString(m.getModifiers());
//            if (modifiers.length() > 0) fileWriter.write(modifiers + " ");
//            fileWriter.write(retType.getName() + " " + name + "(");
//
//            Class[] paramTypes = m.getParameterTypes();
//            for (int j = 0; j < paramTypes.length; j++) {
//                if (j > 0) fileWriter.write(", ");
//                fileWriter.write(paramTypes[j].getName());
//            }
//            fileWriter.write(");\n");
//        }
//    }
//
//    public static void printFields(Class cl, FileWriter fileWriter) throws IOException {
//        Field[] fields = cl.getDeclaredFields();
//        for (Field f : fields) {
//            Class type = f.getType();
//            String name = f.getName();
//            fileWriter.write(" ");
//            String modifiers = Modifier.toString(f.getModifiers());
//            if (modifiers.length() > 0) fileWriter.write(modifiers + " ");
//            fileWriter.write(type.getName() + " " + name + ";\n");
//        }
    }
}