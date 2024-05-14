public class TestCylinder {

    public static void main(String... args)
    {
        Cylinder cy1 = new Cylinder();

        System.out.println(cy1);
        System.out.println("Volume of the cylinder is " + cy1.getVolume());
        System.out.println("Circle area of the Cylinder is " + cy1.getArea());

        Cylinder cy2 = new Cylinder(5.0, 2.0);
        System.out.println(cy2);
        System.out.println("Volume of the cylinder is " + cy2.getVolume());
        System.out.println("Circle area of the Cylinder is " + cy2.getArea());

    }
    
}
