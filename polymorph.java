class parent
{
    void m1()
    {
        System.out.println("In m1 method of parent");
    }
    void m2()
    {
        System.out.println("In m2 method of parent");
    }
}
class child extends parent
{
    void m1()
    {
        System.out.println("In m1 method of child");
    }

  void m3()
  {
    System.out.println("In m2 method of child");
  }  
}

public class polymorph {
public static void main(String[] args) {
    parent ob=new parent();                     //this is dynamic polymorphism.
    ob.m1();                                      
    ob=new child();             
    ob.m1();                    

}    
}
