#include <iostream>
#include <cmath>
class Complex
{
public:
 Complex(){real=0;imag=0;}
 Complex(double r,double i){real=r;imag=i;}
 Complex operator+(Complex& c2); // add
 Complex operator*(Complex& c2);  // product
 Complex operator-(Complex& c2); // minus
 Complex operator/(Complex& c2); //
 Complex operator+=(Complex& c2); // doesnot work well
 friend std::ostream &operator<<(std::ostream &os,const Complex &c);
//the module of complex 
 double mod();
private:
 double real;
 double imag;
};

Complex Complex::operator+(Complex& c2)
{
 return Complex(real+c2.real,imag+c2.imag);
}

Complex Complex::operator*(Complex& c2)
{
return Complex (real*c2.real-imag*c2.imag,real*c2.imag+imag*c2.real);
}

Complex Complex::operator-(Complex& c2){
return Complex(real-c2.real,imag-c2.imag);
}
Complex Complex::operator/(Complex& c2){
double mod = c2.real*c2.real+c2.imag*c2.imag;
return Complex((real*c2.real+imag*c2.imag)/mod,(imag*c2.real-real*c2.imag)/mod);
}

Complex Complex::operator+=(Complex& c2){
return Complex(real+c2.real,imag+c2.imag);
}

std::ostream & operator<<(std::ostream &os,const Complex &c)
{
    os << c.real;
    if(c.imag > 0)
        os << "+" << c.imag << "i" << std::endl;
    else
        os << "+" << c.imag << "i" << std::endl;
    return os;
}

double Complex::mod() {
return std::sqrt(real*real+imag*imag);
}

int main() {
Complex c1(1,2),c2(2,3),c3;
c3 += c1;
std::cout << "hello" << std::endl;
std::cout << c3  << std::endl;
std::cout <<"the module of c1 is " << c1.mod() << std::endl;
return 0;
}
