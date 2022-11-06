package model;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ModelReader {
    private final FileModel fileModel;

    public ModelReader(FileModel fileModel) {
        this.fileModel = fileModel;
    }

    public void readFromFile(String path) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(path));
        StringBuilder strb = new StringBuilder();
        while (scanner.hasNextLine()) {
            strb.append(scanner.nextLine()).append("\n");
        }
        fileModel.setClassDescription(strb.toString());
    }
}
