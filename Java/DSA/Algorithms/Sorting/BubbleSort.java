// Bubble Sort Algorithm

import java.util.Scanner;

public class BubbleSort{
    public static void main(String[] args) {
        
        int size;

        Scanner in = new Scanner(System.in);

        System.out.print("Enter the number of the inputs: ");

        size = in.nextInt();

        // array to hold the inputs
        int[] arr = new int[size];

        for (int i=0; i<size; i++)
        {
            arr[i] = in.nextInt();
        }

        in.close();

        bubbleSort(arr);
        System.out.println("Sorted Array is: ");
        for (int i=0; i<size; i++)
        {
            System.out.print(arr[i]+" ");
        }

    }

    public static void bubbleSort(int[] arr)
    {
        int size = arr.length;

        for(int i=0; i<size-1; i++)
        {
            boolean swapped = false;
            for (int j = 0; j<size-1-i; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    swapped = true;
                }
            }

            if(swapped == false)
            {
                // numbers are already sorted;
                break;
            }
        }
    }
}

