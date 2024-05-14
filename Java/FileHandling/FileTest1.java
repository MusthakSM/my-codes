
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileTest1{
    public static void main(String[] args){

        File file = new File("StudentDetails.txt");
        System.out.println("File length: " + file.length() + " bytes");
        long startTime, elapsedTime;

        try {
            Scanner in = new Scanner(file);

            startTime = System.nanoTime();
            while(in.hasNextLine())
            {
                String line = in.nextLine();
                int size = line.length();

                for (int i=0; i<size; i++)
                {
                    if (line.charAt(i) == ',')
                    {
                        System.out.print(" ");
                    }
                    else{
                        System.out.print(line.charAt(i));
                    }
                }
                System.out.println();
            }
            elapsedTime = System.nanoTime() - startTime;
            System.out.println(elapsedTime/1000000.00+"msec");
            in.close();
        } catch (FileNotFoundException e) {
            // TODO: handle exception
            e.printStackTrace();

        }

    }
}
