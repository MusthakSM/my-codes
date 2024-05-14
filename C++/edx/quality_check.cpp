#include <iostream>
using namespace std;
int main() 
{
    int i,n=0;   
    
    cout<<"Enter the number of eggs"<<endl;
    cin>>n;
    
    float weight[n];
    cout<<"Enter the weight of the eggs(in grams)"<<endl;
    int ideal = 0;
    int non_ideal = 0;
    int faulty = 0;
    for (i=0;i<n;i++)
    {
        cin>>weight[i];
       
        //Fill the code here 
        if (weight[i]<50)
            faulty++;
        else if(50<=weight[i] && weight[i]<=70)
            ideal++;
        else
            non_ideal++;

        if (faulty>4)
        {
            cout << "The box contains more than four faulty eggs" << endl;
            return 0;
        }
    }

    cout << "Count of eggs with ideal weight=" << ideal << endl;

    cout << "Count of eggs with non-ideal weight=" << non_ideal << endl;

    cout << "Count of eggs with faulty weight=" << faulty << endl;
       
    return 0;
}
