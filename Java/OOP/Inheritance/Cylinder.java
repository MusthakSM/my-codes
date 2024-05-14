
public class Cylinder extends Circle {
    double height;

    public Cylinder()
    {
        super();
        this.height = 1.0;
    }

    public Cylinder(double height)
    {
        super();
        this.height = height;
    }

    public Cylinder(double height, double radius)
    {
        super(radius);
        this.height = height;
    }

    public Cylinder(double height, double radius, String color )
    {
        super(radius, color);
        this.height = height;
    }

    public double getHeight()
    {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public String toString()
    {
        return "Cylinder[height = " + height + ", radius = " + getRadius() + ", color = " + getColor() + "]";
    }

    // override the getArea() method inherited from superclass circle
    @Override
    public double getArea()
    {
        return 2 * Math.PI * getRadius() * height + 2 * super.getArea();
    }

    public double getVolume()
    {
        return super.getArea()*height;
    }
    
}

