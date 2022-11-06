import view.RegexView;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        RegexView regexView = new RegexView();
        regexView.pack();
        regexView.setVisible(true);
//        try (Scanner scanner = new Scanner(new File("MyClass.java"));
////             FileWriter fileWriter = new FileWriter("MyClass.java")
//        ) {
//            while (scanner.hasNextLine()) {
//                String tempstr = scanner.nextLine().replaceAll("^([^\"\\r\\n]*?(?:(?<=')\"[^\"\\r\\n]*?|(?<!')\"[^\"\\r\\n]*?\"[^\"\\r\\n]*?)*?)\\s*//[^\\r\\n]*", "$1");
//                System.out.print(tempstr + "\n");
//            }
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }

    }
}