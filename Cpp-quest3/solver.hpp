#ifndef SOLVER_H
#define SOLVER_H
#include <complex>
using std::complex;
namespace solver{


    class RealVariable{
    double a,b,c;
       
//cunstractors
public:
    RealVariable() :a(0),b(1),c(0){}    //x
    RealVariable(double _a, double _b, double _c) :a(_a), b(_b), c(_c){} 

    //Overload addition in RealVariable
    friend RealVariable operator+(const double y,const RealVariable x);
    friend RealVariable operator+(const RealVariable x,const double y);
    friend RealVariable operator+(const RealVariable x,const RealVariable r);
    //Overload subtraction in RealVariable
    friend RealVariable operator-(const RealVariable x);
    friend RealVariable operator-(const RealVariable x,const double y);
    friend RealVariable operator-(const RealVariable x,const RealVariable r);
    friend RealVariable operator-(const double y,const RealVariable x);
    //Overload multiplication in RealVariable
    friend RealVariable operator*(const double y,const RealVariable x);
    friend RealVariable operator*(const RealVariable x,const double y);
    friend RealVariable operator*(const RealVariable x,const RealVariable r);
    //Overload operator division in RealVariable
    friend RealVariable operator/(const RealVariable x,const double y);
    //Overload operator exponentiation in RealVariable
    friend RealVariable operator^(const RealVariable x,const int y);
    //Overload operator equalization in RealVariable
    friend double operator==(const RealVariable x,const double y); 
    friend double operator==(const RealVariable x,const RealVariable r);
    friend double operator==(const double y,const RealVariable x);
    };



    class ComplexVariable{
    complex<double> a,b,c;

    //cunstractors
        public:
		ComplexVariable():a(0),b(1),c(0){}    //x
        ComplexVariable(complex<double> _a, complex<double> _b, complex<double> _c):a(_a), b(_b), c(_c){}

    //Overload addition in ComplexVariable
    friend ComplexVariable operator+(const double y,const ComplexVariable x);
    friend ComplexVariable operator+(const ComplexVariable x,const double y);
    friend ComplexVariable operator+(const ComplexVariable x,const ComplexVariable c);
    friend ComplexVariable operator+(const std::complex<double> y,const ComplexVariable x);
    friend ComplexVariable operator+(const ComplexVariable x,const std::complex<double> y);
    //Overload subtraction in ComplexVariable
    friend ComplexVariable operator-(const ComplexVariable x);
    friend ComplexVariable operator-(const ComplexVariable x,const double y);
    friend ComplexVariable operator-(const ComplexVariable x,const ComplexVariable c);
    friend ComplexVariable operator-(const double y,const ComplexVariable x);
    friend ComplexVariable operator-(const ComplexVariable x,const complex<double> y);
    friend ComplexVariable operator-(const complex<double> y,const ComplexVariable x);
    //Overload multiplication in ComplexVariable
     friend ComplexVariable operator*(const ComplexVariable x,const double y);
    friend ComplexVariable operator*(const double y,const ComplexVariable x);
    friend ComplexVariable operator*(const ComplexVariable x,const ComplexVariable c);
    friend ComplexVariable operator*(const ComplexVariable x,const complex<double> y);
    friend ComplexVariable operator*(const complex<double> y,const ComplexVariable x);
    //Overload division in ComplexVariable
    friend ComplexVariable operator/(const ComplexVariable x,const double y);
    friend ComplexVariable operator/(const ComplexVariable x,const complex<double> y);
    //Overload exponentation in ComplexVariable
    friend ComplexVariable operator^(const ComplexVariable x,const double y);
    friend ComplexVariable operator^(const ComplexVariable x, const complex<double> y);
    //Overload equalization in ComplexVariable
    friend complex<double> operator==(const ComplexVariable x,const double y); 
    friend complex<double> operator==(const ComplexVariable x,const ComplexVariable c);
    friend complex<double> operator==(const double y,const ComplexVariable x);
    friend complex<double> operator==(const ComplexVariable x,const std::complex<double> c);
    friend complex<double> operator==(const std::complex<double> y,const ComplexVariable x);

    };

    double solve(double v);
    complex<double> solve(complex<double> c);
 
}

#endif
