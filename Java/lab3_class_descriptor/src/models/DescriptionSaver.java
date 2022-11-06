package models;

import java.io.FileWriter;
import java.io.IOException;

public class DescriptionSaver {

    private final ClassDescription classDesc;

    public DescriptionSaver(ClassDescription classDescription) {
        this.classDesc = classDescription;
    }

    public void writeToFileDescription(String path) throws IOException {
        FileWriter fileWriter;
        fileWriter = new FileWriter(path + ".java");
        fileWriter.write(classDesc.getClassDescription());
        fileWriter.close();

    }
}
