#include "solver.hpp"
#include <complex>
using std::complex;
using namespace solver;

//The solve functions implementation
double solver::solve(double v){
    return v;
}
complex<double> solver::solve(complex<double> c){
    return c;
}

//Operators overload of RealVariable 
//-----------------------------------

//Overload subtraction in RealVariable
RealVariable solver::operator-(const RealVariable x){
    return RealVariable(-x.a,-x.b,-x.c);
}
RealVariable solver::operator-(const RealVariable x,const double y){
    return RealVariable(x.a,x.b,x.c-y);
}
RealVariable solver::operator-(const RealVariable x,const RealVariable r){
    return RealVariable(x.a-r.a,x.b-r.b,x.c-r.c);
}
RealVariable solver::operator-(const double y,const RealVariable x){
    return RealVariable(-x.a,-x.b,-x.c+y);
}
//Overload addition in RealVariable
RealVariable solver::operator+(const double y,const RealVariable x){
    return RealVariable(x.a,x.b,x.c+y);
}
RealVariable solver::operator+(const RealVariable x,const double y){
    return RealVariable(y+x);
}
RealVariable solver::operator+(const RealVariable x,const RealVariable r){
    return RealVariable(x.a+r.a,x.b+r.b,x.c+r.c);
}
//Overload multiplication in RealVariable
RealVariable solver::operator*(const double y,const RealVariable x){
    return RealVariable(x.a*y,x.b*y,x.c*y);
}
RealVariable solver::operator*(const RealVariable x,const double y){
    return RealVariable(y*x);
}
RealVariable solver::operator*(const RealVariable x,const RealVariable r){
    if(x.a*r.a==0 && x.b*r.a==0 && x.a*r.b==0)
    {
        return RealVariable(x.b*r.b,x.b*r.c + x.c*r.b,x.c*r.c);
    }
    throw std::runtime_error("Possession greater than 2");
}


//Overload operator division in RealVariable
RealVariable solver::operator/(const RealVariable x,const double y){
    if(y==0)
    throw std::runtime_error("Difference in 0");
    return RealVariable(x.a/y,x.b/y,x.c/y);
}

//Overload operator exponentiation in RealVariable
RealVariable solver::operator^(const RealVariable x,const int y){
    if(y==2)
    return x*x;
    else if(y==1)
    return x;
    else if(y==0)
    return RealVariable(0,0,1); 
    else
    {
        throw std::runtime_error("in ^ Possession greater than 2");
    }
}
//Overload operator equalization in RealVariable
double solver::operator==(const RealVariable x,const double y){
    RealVariable temp = x-y;
    if (temp.a!=0) //Quadratic Equation
    {
        if(temp.b*temp.b-4*temp.a*temp.c<0)
        throw std::runtime_error("There is no solution to the equation");
        return((-temp.b+sqrt(temp.b*temp.b-4*temp.a*temp.c))/(2*temp.a));
    }
    else if(temp.b!=0) 
    {
    return((-temp.c)/temp.b);
    }
    else if(temp.c==0)
    { 
        return 0;
    }
    else
    {
        throw std::runtime_error("There is no solution to the equation");
    }
    
} 
double solver::operator==(const RealVariable x,const RealVariable r){
    return ((x-r)==0);
}
double solver::operator==(double y,RealVariable x){
    return (x==y);
}


//Operators overload of ComplexVariable 
//-----------------------------------
//Overload subtraction in ComplexVariable
ComplexVariable solver::operator-(const ComplexVariable x){
    return ComplexVariable(-x.a,-x.b,-x.c);
}
ComplexVariable solver::operator-(const ComplexVariable x,const double y){
    return ComplexVariable(x.a,x.b,x.c-y);
}
ComplexVariable solver::operator-(const ComplexVariable x,const ComplexVariable c){
    return ComplexVariable(x.a-c.a,x.b-c.b,x.c-c.c);
}
ComplexVariable solver::operator-(const double y,const ComplexVariable x){
    return ComplexVariable(-x.a,-x.b,-x.c+y);
}
ComplexVariable solver::operator-(const ComplexVariable x,const complex<double> y) {
    return ComplexVariable(x.a, x.b, x.c-y);
}
ComplexVariable solver::operator-(const complex<double> y,const ComplexVariable x) {
    return ComplexVariable(-x.a, -x.b, -x.c+y);
}


//Overload addition in ComplexVariable
ComplexVariable solver::operator+(const double y,const ComplexVariable x){
    return ComplexVariable(x.a,x.b,x.c+y);
}
ComplexVariable solver::operator+(const ComplexVariable x,const double y){
    return (y+x);
}
ComplexVariable solver::operator+(const ComplexVariable x,const ComplexVariable c){
    return ComplexVariable(x.a+c.a,x.b+c.b,x.c+c.c);
}
ComplexVariable solver::operator+(const complex<double> y,const ComplexVariable x){
    return ComplexVariable(x.a,x.b,x.c+y);
}
ComplexVariable solver::operator+(const ComplexVariable x,const complex<double> y){
    return (y+x);
}

//Overload multiplication in ComplexVariable
ComplexVariable solver::operator*(const ComplexVariable x,const double y){
    return ComplexVariable(x.a*y,x.b*y,x.c*y);
}
ComplexVariable solver::operator*(const double y,const ComplexVariable x){
    return (x*y);
}
ComplexVariable solver::operator*(const ComplexVariable x,const ComplexVariable c){
    if(x.a != complex(0.0,0.0) && c.a != complex(0.0,0.0)) throw std::runtime_error("power greater than 2");
    if(x.a != complex(0.0,0.0) && c.b != complex(0.0,0.0)) throw std::runtime_error("power greater than 2");
    if(x.b != complex(0.0,0.0) && c.a != complex(0.0,0.0)) throw std::runtime_error("power greater than 2");
    return ComplexVariable(x.b*c.b,x.b*c.c+x.c*c.b,x.c*c.c);
}
ComplexVariable solver::operator*(const ComplexVariable x,const complex<double> y) {
    return ComplexVariable(x.a*y,x.b*y,x.c*y);
}
ComplexVariable solver::operator*(const complex<double> y,const ComplexVariable x) {
    return (x*y);
}
//Overload division in ComplexVariable
ComplexVariable solver::operator/(const ComplexVariable x,const double y){
    if(y==0) throw std::runtime_error("Difference in 0");
    return ComplexVariable(x.a/y,x.b/y,x.c/y);
}

ComplexVariable solver::operator/(const ComplexVariable x,const complex<double> y){
    if(y==complex(0.0,0.0)) throw std::runtime_error("Difference in 0");
    return ComplexVariable(x.a/y,x.b/y,x.c/y);
}
//Overload exponentation in ComplexVariable
ComplexVariable solver::operator^(const ComplexVariable x,const double y){
    if(y==0)
    return ComplexVariable(complex<double>(0,0),complex<double>(0,0),complex<double>(1,0));
    else if(y==1)
    return ComplexVariable(x.a,x.b,x.c);
    else if(y==2)
    {
        if(x.a!=complex<double>(0,0))
        throw std::runtime_error("Possession greater than 2");
        return ComplexVariable(x.b*x.b,2.0*x.b*x.c,x.c*x.c);  //(a+b)^2
    }
    else
    {
        throw std::runtime_error("Possession greater than 2");
    }
}
ComplexVariable operator^ (const ComplexVariable x, const complex<double> y) {
        if(y.imag() != 0) throw std::runtime_error("Cannot be raised strongly");
        if(y.real() == 2) return x*x;
        if (y.real() == 1) return x;
        if (y.real() == 0) return ComplexVariable(complex<double>(0,0),complex<double>(0,0),complex<double>(1,0));
        else
        {
             throw std::runtime_error("Cannot be raised strongly");
        }
    }
//Overload equalization in ComplexVariable
complex<double> solver::operator==(const ComplexVariable x,const double y){
    ComplexVariable temp=x-y;
    if(temp.a!=complex<double>(0,0))
    {
        return((-temp.b+sqrt(temp.b*temp.b-4.0*temp.a*temp.c))/(2.0*temp.a));
    }
    else if(temp.b!=complex<double>(0,0))
    {
        return (-temp.c)/temp.b;
    }
    else if(temp.c==complex<double>(0,0))
    {
        return complex<double>(0,0);
    }
    else
    {
        throw std::runtime_error("variablePossession greater than 2");
    }
}

complex<double> solver::operator==(const ComplexVariable x,const ComplexVariable c){
    return ((x-c)==0);
}
complex<double> solver::operator==(const double y,const ComplexVariable x){
    return (x==y);
}
complex<double> solver::operator==(const ComplexVariable x,const std::complex<double> c){
    return ((x-c)==0);
}
complex<double> solver::operator==(const std::complex<double> y,const ComplexVariable x){
    return (x==y);
}
