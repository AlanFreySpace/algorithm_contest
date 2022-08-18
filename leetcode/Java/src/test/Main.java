package test;

import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        int n=0,level=0,year=0;
        double salary=0;
        String name="";
        
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        //System.out.println(n);
        Employee[] em=new Employee[n];
        
        for(int i=0;i<n;i++){
            name=sc.next();
            //System.out.println(name);
            level=sc.nextInt();
            year=sc.nextInt();
            salary=sc.nextDouble();
            
            em[i]=new Employee(name,level,year,salary);
            //System.out.println(em[i].name+" "+em[i].level+" "+em[i].year+" "+em[i].salary);
        }
        
        Arrays.sort(em);
        for(int i=0;i<n;i++) {
        	System.out.print(em[i].name+" "+em[i].level+" "+em[i].year+" ");
        	System.out.printf("%.2f\n",em[i].salary);
        }
        
    }
}

class Employee implements Comparable<Employee>{
    public String name;
    public int level,year;
    public double salary;
    
    public Employee(String name,int level,int year,double salary){
        this.name=name;
        this.level=level;
        this.year=year;
        this.salary=salary;
    }
    
    @Override
    public int compareTo(Employee e){
        if(this.level!=e.level) return e.level-this.level;
        if(this.salary!=e.salary) {
        	if(this.salary-e.salary<0)
        		return -1;
        	else return 1;
        }
        return e.year-this.year;
    }
}

