#include <iostream>
#include <cmath> 

using namespace std;

class Circle {
private:
    double radius; 

public:
    
    Circle(double r) {
        radius = r;
    }

    double area() {
        return M_PI * radius * radius; 
    }

    void display() {
      cout<<"Area: "<<area()<<endl;
    }
};

int main() {
    
    double radius;

    cout<<"Enter Radius"<<endl;
    cin>>radius;

    Circle c(radius);  
    c.display();    

    return 0;
}


