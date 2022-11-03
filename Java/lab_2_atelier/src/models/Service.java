package models;

import java.io.Serializable;

public class Service implements Serializable {

    private ServiceType type;

    public Service(ServiceType type) {
        this.type = type;
    }

    public ServiceType getType() {
        return type;
    }

    public void setType(ServiceType type) {
        this.type = type;
    }
}
