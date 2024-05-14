
import java.util.Scanner;

public class primeTest {
    
    public static void main(String[] args)
    {
        System.out.println("****** PRIME TESTER ******");
        System.out.println("--------------------------");
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int number = in.nextInt();
        in.close();

        int max_factor = (int)Math.sqrt(number);

        boolean state = true;
        for (int i=2; i<=max_factor; i++)
        {
            if (number % i == 0)
            {
                state = false;
                break;
            }
        }

        if (state == true)
        {
            System.out.println("Number is prime.");
        }
        else
            System.out.println("Number is not prime.");

    }
}
