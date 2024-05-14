
public class ToStringTestOOP {
    
    public static void main(String... args)
    {
        Square s1 = new Square(4, "red");
        Square s2 = new Square(10.0, "Blue");
        Square s3 = new Square(7.70, "yellow");
        Square s4 = new Square(3, "green");

        System.out.println(s1.toString());
        System.out.println(s2);
        System.out.println("s3 is: " + s3);
        System.out.println(s4.toString());
    }
}


class Square{
    private double length;
    private String color;

    Square(double length, String color)
    {
        this.length = length;
        this.color = color;
    }

    // defining toString() method
    public String toString()
    {
        return "Sqaure[length=" +length+ ", color=" +color+"]";
    }
}