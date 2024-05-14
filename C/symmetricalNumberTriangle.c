// printing a symmetrical number triangle...

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{

    int number;
    printf("Enter N: ");
    scanf("%d", &number);



    for ( int i=1; i<=number; i++)
    {
        // loop for adding spaces before numbers..
        for (int k=number-i; k>0; k--)
        {
            if (i<=9) 
                printf("   ");
            else
                printf("   ");
        }

        if (i<=9) printf(" ");

        // loop for insert numbers in rows
        int max_number = 2*i - 1;
        for (int j=i; j<=max_number; j++)
        {
            if (j >= 9)
                printf("%d ",j);
            else
            printf("%d  ", j);
        }

        
        for (int m = max_number-1 ; m>=i; m--)
        {
            if (m>=9) 
                printf("%d ", m);
            else
                printf("%d  ", m);

        }

        

        printf("\n");
    }

    return 0;

}
