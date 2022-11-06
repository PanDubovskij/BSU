package models;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class ClassDescription {
    private final String className;
    private String classDescription;

    public ClassDescription(String className) {
        this.className = className;
    }

    public void createClassDescription() throws ClassNotFoundException {
        StringBuilder strb = new StringBuilder();
        Class cl;
        cl = Class.forName(className);
        Class supercl = cl.getSuperclass();
        String modifiers = Modifier.toString(cl.getModifiers());
        if (modifiers.length() > 0) strb.append(modifiers).append(" ");
        strb.append("class ").append(className);
        if (supercl != null && supercl != Object.class) strb.append(" extends ").append(supercl.getName());
        strb.append("\n{\n");
        strb.append(constructorsToString(cl));
        strb.append("\n");
        strb.append(methodsToString(cl));
        strb.append("\n");
        strb.append(fieldsToString(cl));
        strb.append("}");
        classDescription = strb.toString();
    }

    private String constructorsToString(Class cl) {
        StringBuilder strb = new StringBuilder();
        Constructor[] constructors = cl.getDeclaredConstructors();
        for (Constructor c : constructors) {
            String name = c.getName();
            strb.append(" ");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0) strb.append(modifiers).append(" ");
            strb.append(name).append("(");

            Class[] paramTypes = c.getParameterTypes();
            for (int j = 0; j < paramTypes.length; j++) {
                if (j > 0) strb.append(", ");
                strb.append(paramTypes[j].getName());
            }
            strb.append(");\n");
        }

        return strb.toString();
    }

    private String methodsToString(Class cl) {
        StringBuilder strb = new StringBuilder();
        Method[] methods = cl.getDeclaredMethods();
        for (Method m : methods) {
            Class retType = m.getReturnType();
            String name = m.getName();
            strb.append(" ");
            String modifiers = Modifier.toString(m.getModifiers());
            if (modifiers.length() > 0) strb.append(modifiers).append(" ");
            strb.append(retType.getName()).append(" ").append(name).append("(");

            Class[] paramTypes = m.getParameterTypes();
            for (int j = 0; j < paramTypes.length; j++) {
                if (j > 0) strb.append(", ");
                strb.append(paramTypes[j].getName());
            }
            strb.append(");\n");
        }
        return strb.toString();
    }

    private String fieldsToString(Class cl) {
        StringBuilder strb = new StringBuilder();
        Field[] fields = cl.getDeclaredFields();
        for (Field f : fields) {
            Class type = f.getType();
            String name = f.getName();
            strb.append(" ");
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0) strb.append(modifiers).append(" ");
            strb.append(type.getName()).append(" ").append(name).append(";\n");
        }
        return strb.toString();
    }


    public String getClassName() {
        return className;
    }

    public String getClassDescription() {
        return classDescription;
    }


}
