import java.io.*;

public class FileTest2 {
    
    public static void main(String[] args){
        
        File file = new File("StudentDetails.txt");
        System.out.println("Size of the input file: " + file.length() + " bytes.");

        double startTime, elapsedTime;

        try (BufferedReader in = new BufferedReader(new FileReader("StudentDetails.txt"))) {

            startTime = System.nanoTime();
            String line;
            while((line = in.readLine())!= null)
            {
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

            System.out.println("Time taken is: " + elapsedTime/1000000 + " mseconds");
    
        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        }

    }
}
