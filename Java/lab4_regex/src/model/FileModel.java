package model;

import java.util.Scanner;

public class FileModel {
    private String classDescription;

    public FileModel() {
    }

    public FileModel(String classDescription) {
        this.classDescription = classDescription;
    }

    public String getClassDescriptionWithoutComments() {
        StringBuilder strb = new StringBuilder();
        try (Scanner scanner = new Scanner(classDescription)) {
            while (scanner.hasNextLine()) {
                String tempstr = scanner.nextLine().replaceAll("^([^\"\\r\\n]*?(?:(?<=')\"[^\"\\r\\n]*?|(?<!')\"[^\"\\r\\n]*?\"[^\"\\r\\n]*?)*?)\\s*//[^\\r\\n]*", "$1");
                strb.append(tempstr).append("\n");
            }
        }
        return strb.toString();
    }

    public String getClassDescription() {
        return classDescription;
    }

    public void setClassDescription(String classDescription) {
        this.classDescription = classDescription;
    }
}
