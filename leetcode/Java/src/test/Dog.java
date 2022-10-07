package test;

public abstract class Dog implements Animal {	 
	   public void travel(){
	      System.out.println("Dog travels");
	   }
	   
	   public static void main(String args[]){		  
	      Dog d = new Dog1();
	      d.eat();
	      d.travel();
	   }
}

class Dog1 extends Dog{
	public void eat() {
		System.out.println("Dog eats");
	}
}

