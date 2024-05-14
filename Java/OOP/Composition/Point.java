
public class Point {
    private int x;
    private int y;

    public Point()
    {
        this.x = 0;
        this.y = 0;
    }

    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return x;
    }

    public void setX(int x)
    {
        this.x = x;
    }

    public int getY()
    {
        return y;
    }

    public void setY(int y)
    {
        this.y = y;
    }

    public String toString()
    {
        return String.format("(%d, %d)", x, y);
    }

    public int[] getXY()
    {
        int[] point = new int[2];
        point[0] = x;
        point[1] = y;
        return point;
    }

    public void setXY(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public double distance(int x, int y)
    {
        double dis = (this.x-x)*(this.x-x)+(this.y-y)*(this.y-y);
        dis = Math.sqrt(dis);
        return dis;
    }

    public double distance(Point another)
    {
        double dis = (this.x-another.x)*(this.x-another.x)+(this.y-another.y)*(this.y-another.y);
        dis = Math.sqrt(dis);
        return dis;
    }

    public double distance()
    {
        double dis = this.x*this.x + this.y*this.y;
        dis = Math.sqrt(dis);
        return dis;
    }
    
}
