package controllers;

import models.ClassDescription;
import models.DescriptionSaver;

import java.io.IOException;

public class ClassDescriptionController {
    public void updateModel(ClassDescription classDescription) throws ClassNotFoundException {
        classDescription.createClassDescription();
    }

    public void saveToFileModel(String path, DescriptionSaver descriptionSaver) throws IOException {
        descriptionSaver.writeToFileDescription(path);
    }


}
