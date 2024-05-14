import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);

        int size; 

        System.out.print("Enter the number of inputs: ");

        size = in.nextInt();

        int[] arr = new int[size];

        for(int i=0; i<size; i++)
        {
            arr[i] = in.nextInt();
        }

        in.close();

        selectionSort(arr);

        System.out.println("Sorted array is: ");
        for(int i=0; i<size; i++)
        {
            System.out.print(arr[i]+" ");
        }
    }

    public static void selectionSort(int[] arr)
    {
        int size = arr.length;
        for(int i=0; i<size-1; i++)
        {
            int min = i;

            for(int j=i+1; j<size; j++)
            {
                if(arr[j] < arr[min])
                {
                    min =j; 
                }
            }

            if(min != i)
            {
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
