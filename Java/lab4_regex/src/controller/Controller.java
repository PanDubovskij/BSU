package controller;

import model.FileModel;
import model.ModelReader;
import model.ModelSaver;

import java.io.FileNotFoundException;
import java.io.IOException;

public class Controller {
    public void updateModel(FileModel fileModel) {
        fileModel.getClassDescriptionWithoutComments();
    }

    public void writeToFile(String path, ModelSaver modelSaver) throws IOException {
        modelSaver.writeToFile(path);
    }

    public void readFromFile(String path, ModelReader modelReader) throws FileNotFoundException {
        modelReader.readFromFile(path);
    }
}
