package com.company.test;

import com.company.present.Present;

public class Main {

    public static void main(String[] args) {
	// write your code here
/*        Chocolate ch1=new Chocolate("Alenka",100,0.95,3,10,"Peanuts");
        Chocolate ch2=new Chocolate("Mars",70,0.98,1.5,5,"Caramel");
        Cookies ck1=new Cookies("Oreo",50,0.70,3.5,"Strawberry",true);
        Cookies ck2=new Cookies("Esmeralda",120,0.65,3,"Coconut",false);
        Lollypop lp1=new Lollypop("Chupachyps",15,0.48,0.90,"Circle","Apple");
        Lollypop lp2 =new Lollypop("Petushok",25,0.8,1,"Oval","Pear");*/
        Present present=new Present();
        present.read("input.txt");
      /*  present.add(ch1);
        present.add(ch2);
        present.add(ck1);
        present.add(ck2);
        present.add(lp1);
        present.add(lp2);*/
        System.out.println(present);
        System.out.println(present.getWeight());
        present.sortByPrice();
        System.out.println(present);
        present.save("output.txt");
        System.out.println(present.findSweet(0.4,0.6));
    }
}
