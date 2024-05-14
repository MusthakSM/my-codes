
public class sample2{
    public static void main(String[] args) {
        
        Base b = new Base();
        DerivedBase a =  new DerivedBase();
        Base c = new DerivedBase();

        b.mt();
        a.mt();
        c.mt();

    }
}

class Base{
    void mt(){
        System.out.println("mt Base");
    }
}

class DerivedBase extends Base{
    void mt(){
        System.out.println("Derived mt Base");
    }
}