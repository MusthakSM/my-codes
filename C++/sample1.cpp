#include<iostream>
using namespace std;
class Circle
{
  private:
  int radius;

  //Include appopriate methods for the class
  public:
    Circle(int x)
    {
      radius = x;
    }

    int getRadius()
    {
      return radius;
    }
};

class Utility
{
  //Include appopriate methods for the class
  public:
    double calculateArea(Circle c)
    {
      double area = 3.14 * c.getRadius() * c.getRadius();
      return area;
    }
};
int main()
{
  //Input statements are provided as part of the code skeleton
  int radius=0;
  cout<<"Enter the radius(in cm)"<<endl;
  cin>>radius;
  
  //Fill the code here 
  Circle c(radius);
  Utility ut;

  double area = ut.calculateArea(c);

  cout << "Circle Area=" << area << "cm2";

  return 0;

}