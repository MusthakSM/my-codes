
public class Circle{            // create a class called circle.

    // private instance variables
    private double radius;
    private String color;

    // Declaration of 3 constructors (overloaded)
    /* constructs a circle with default radius and color */
    public Circle()
    {
        radius = 1.0;
        color = "red";
    }

    /* constructs a circle instance with the given radius and default color */
    public Circle(double rad){
        radius = rad;
        color = "red";
    }

    /* constructs a circle instance with the given radius and color */
    public Circle(double rad, String clr)
    {
        radius = rad;
        color = clr;
    }

    // public methods
    /* Returns the radius */
    public double getRadius()
    {
        return radius;
    }

    /* Returns the color */
    public String getColor()
    {
        return color;
    }

    /* Returns the area */
    public double getArea()
    {
        return Math.PI * radius * radius;
    }
}