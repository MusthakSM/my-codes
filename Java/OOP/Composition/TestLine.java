
public class TestLine {
    public static void main(String... args)
    {
        Line l1 = new Line(1,2,3,4);
        System.out.println(l1);        

        Line l2 = new Line(new Point(5,6),  new Point(7,8));
        System.out.println(l2);

        l1.setBegin(new Point(11, 12));
        l1.setEnd(new Point(13, 14));
        System.out.println(l1);

        System.out.println("begin of l1 is: " + l1.getBegin());
        System.out.println("end of l1 is: " + l1.getEnd() );

        l1.setBeginX(21);
        l1.setBeginY(22);
        l1.setEnd(new Point(23, 24));
        System.out.println(l1);


    }
}
