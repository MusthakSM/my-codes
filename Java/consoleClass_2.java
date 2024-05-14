
/* Connecting console class to the Scanner to get primitive type inputs */

import java.io.Console;
import java.util.Scanner;

public class consoleClass_2 {
    
    public static void main(String[] args)
    {
        Console con = System.console();
        String msg = con.readLine("Enter a message: ");        // Non primitive input is taken, no need to connect the scanner class.
        con.printf("The message you typed is %s\n", msg);

        Scanner in = new Scanner(con.reader());                    // console object is connected to the Scanner object to parse primitive inputs..

        System.out.print("Enter your age: ");
        int age = in.nextInt();
        System.out.print("Enter your weight: ");
        double dble = in.nextDouble();
        in.close();
        System.out.printf("age is %d, weight is %.2f", age, dble);

        
    }
}
