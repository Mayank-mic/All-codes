#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class

    public:
    int real;
    int imaginary;

    ComplexNumbers(int x , int y){
        real = x;
        imaginary = y;
    }

    void plus(ComplexNumbers &c){
        real = real + c.real;
        imaginary = imaginary + c.imaginary;
    }

    void multiply(ComplexNumbers &c){
        int temp = real;
        real = real*c.real - imaginary*c.imaginary;

        imaginary = temp*c.imaginary+imaginary*c.real;
    }

    void print(){
        cout<<real<<" "<<"+"<<" "<<"i"<<imaginary<<endl;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}
