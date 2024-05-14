
/* Java console class (1) */

import java.io.Console;     // Needed for using console Class

public class consoleClass {
    
    public static void main(String[] args)
    {
        Console con = System.console();     // creating a console object..
        String name = "Musthak";
        String msg = con.readLine("%s, Enter a string: ", name);            // reading a line from the console..
        con.printf("%s",msg);        // write a formatted output to the output console..
    }
}
