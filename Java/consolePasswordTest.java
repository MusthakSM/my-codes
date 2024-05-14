
/* Inputting password via Console */

import java.io.Console;

public class consolePasswordTest {
    static String name;
    static char[] password;                     // creating a string as array of chars.. String class is immutable that's why we use array of chars. We can modify the password when ever we want..

    public static void main(String[] args){

        Console con = System.console();         // creating a console object.

        name = con.readLine("Enter your name: ");
        password = con.readPassword("Enter the password: ");

        String Pass = String.valueOf(password);             // converting char array into String....
        con.printf("The password you typed is: %s\n", Pass);

    }
}
