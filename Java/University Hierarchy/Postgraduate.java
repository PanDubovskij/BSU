package com.company;

public class Postgraduate extends Student{
    private Academic supervisor;

    public Postgraduate(String name, String login, String email) {
        super(name, login, email);
    }

    public Academic getSupervisor() {
        return supervisor;
    }

    public void setSupervisor(Academic supervisor) {
        this.supervisor = supervisor;
    }
}
