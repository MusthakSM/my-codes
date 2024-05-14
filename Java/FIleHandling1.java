import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Formatter; // Import the Scanner class to read text files

public class FIleHandling1 {
    public static void main(String[] args) throws FileNotFoundException{

        Formatter out = new Formatter(new File("txt1.txt"));
        int num1 = 1234;
        double num2 = 55.66;
        String name = "Musthak";

        out.format("Hi %s\n", name);
        out.format("number1 %d and floating value is %f\n", num1, num2);

        out.close();

    }
}