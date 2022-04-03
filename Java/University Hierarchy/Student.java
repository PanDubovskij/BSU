package com.company;

public class Student extends Person implements Notifiable{
    private String login;
    private String email;

    public Student(String name, String login, String email) {
        super(name);
        this.login = login;
        this.email = email;
    }

    public String getLogin() {
        return login;
    }

    public String getEmail() {
        return email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + getName() + '\'' +
                "login='" + login + '\'' +
                ", email='" + email + '\'' +
                '}'+'\n';
    }

    @Override
    public void notify(String message) {
        System.out.println(email+":"+message);
    }
}
