
public class CircleTest {
    
    public static void main(String[] args){

        Circle c1 = new Circle();
        Circle c2 = new Circle(7);
        Circle c3 = new Circle(7, "Blue");

        System.out.println(c1.getRadius());
        System.out.println(c1.getColor());
        System.out.printf("%.4f\n",c1.getArea());
        System.out.println();
        System.out.println(c2.getRadius());
        System.out.println(c2.getColor());
        System.out.printf("%.4f\n",c2.getArea());
        System.out.println();
        System.out.println(c3.getRadius());
        System.out.println(c3.getColor());
        System.out.printf("%.4f\n",c3.getArea());
    }
}

