#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
class Complex
{
public:
 Complex(){real=0;imag=0;}
 Complex(double r,double i){real=r;imag=i;}
 friend Complex operator+(Complex& c1, Complex& c2); // add
 friend Complex operator*(Complex& c1, Complex& c2);  // product
 friend Complex operator-(Complex& c1, Complex& c2); // minus
 friend Complex operator/(Complex& c1, Complex& c2); //
 //Complex operator=(Complex& c);// doesnot work well
 Complex operator+=(Complex& c2); 
 friend std::ostream &operator<<(std::ostream &os,const Complex &c);
//the module of complex 
 double mod();
private:
 double real;
 double imag;
};

Complex operator+(Complex& c1, Complex& c2)
{
 //return Complex(real+c2.real,imag+c2.imag); //
 return Complex(c1.real+c2.real,c1.imag+c2.imag);
}

Complex operator*(Complex& c1, Complex& c2)
{
return Complex (c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+c1.imag*c2.real);
}

Complex operator-(Complex& c1, Complex& c2){
return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
Complex operator/(Complex& c1, Complex& c2){
double mod = c2.real*c2.real+c2.imag*c2.imag;
return Complex((c1.real*c2.real+c1.imag*c2.imag)/mod,(c1.imag*c2.real-c1.real*c2.imag)/mod);
}

Complex Complex::operator+=(Complex& c2){
return Complex(real+=c2.real,imag+=c2.imag);
}

//Complex Complex::operator=(Complex& c){
//return Complex(c.real,c.imag);  //why not: return Complex(c.real,c.imag); doesnot work well
//}

std::ostream & operator<<(std::ostream &os,const Complex &c)
{
    os << c.real << "+" << c.imag << "i" << std::endl;
    return os;
}

double Complex::mod() {
return std::sqrt(real*real+imag*imag);
}

int main() {
Complex c1(1,2),c2(2,3),c3;
c3 = c1+c2;
std::cout << "c1= " << c1 << std::endl;
std::cout << "c2= " << c2 << std::endl;
std::cout << "c3= " << c3 << std::endl;
std::cout <<"the module of c1 is " << c1.mod() << std::endl;
return 0;
}
#endif
