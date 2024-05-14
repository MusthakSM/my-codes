
public class Line {
    private Point begin;
    private Point end;

    public Line(int x1, int y1, int x2, int y2)
    {
        begin = new Point(x1, y1);
        end = new Point(x2, y2);
    }
    
    public Line(Point begin, Point end)
    {
        this.begin = begin;
        this.end = end;
    }

    public Point getBegin() {
        return begin;
    }

    public void setBegin(Point begin)
    {
        this.begin = begin;
    }

    public Point getEnd() {
        return end;
    }

    public void setEnd(Point end)
    {
        this.end = end;
    }

    public int getBeginX()
    {
        return begin.getX();
    }

    public void setBeginX(int x)
    {
        this.begin.setX(x);
    }

    public int getBeginY()
    {
        return begin.getY();
    }

    public void setBeginY(int y)
    {
        this.begin.setY(y);
    }

    public int[] getBeginXY()
    {
        return begin.getXY();
    }

    public String toString()
    {
        return "Line[begin=" + this.begin + ", end=" + this.end + "]";
    }
}
