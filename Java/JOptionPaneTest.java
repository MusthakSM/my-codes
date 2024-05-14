/* Getting user inputs via a graphical dialog box, using the JOptionPaneTest class */

import javax.swing.JOptionPane;         // Needed to use the JOptionPane

public class JOptionPaneTest {
    
    public static void main(String[] args)
    {
        String radiusStr;
        double area, radius;

        radiusStr = JOptionPane.showInputDialog("Enter the radius: ");
        radius = Double.parseDouble(radiusStr);         // Converts a string to double type

        area = radius*radius*Math.PI;
        System.out.println("Ther area is "+ area);
    }
}
