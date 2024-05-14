
/* declare an array, and then print the array as a string using Arrays.toString() method */

import java.util.Arrays;            // Needed for use Arrays.toString() method 
public class ArrayToString {
    
    public static void main(String[] args)
    {
        int numbers[] = new int[10];

        for (int i=0; i<10; i++)
        {
            numbers[i] = i+1;
        }

        String numbersArray = Arrays.toString(numbers);

        System.out.println(numbersArray);  // Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    }
}
