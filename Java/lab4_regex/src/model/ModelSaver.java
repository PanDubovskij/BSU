package model;

import java.io.FileWriter;
import java.io.IOException;

public class ModelSaver {
    private final FileModel fileModel;

    public ModelSaver(FileModel fileModel) {
        this.fileModel = fileModel;
    }

    public void writeToFile(String path) throws IOException {
        FileWriter fileWriter;
        fileWriter = new FileWriter(path);
        fileWriter.write(fileModel.getClassDescription());
        fileWriter.close();
    }
}
