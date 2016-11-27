#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI  = acos(-1.0);

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
  point v1(a - O), v2(b - O);
  return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
    	ang+=2*PI;
    return ang;
}

int main() {

	/*

	complex<double> num1(2, 3);	// 2 + 3i

	std::cout << num1.real() << "+" << num1.imag() << "i\n";	// 2 + 3i

	complex<double> num2(1, 1);

	cout << "Modulus = " << abs(num2) << "\n";			// r = 1.41421
	cout << "Argument = " << arg(num2) << "\n";			// theta radian = 0.785398
	cout << "Angle = " << arg(num2) * 180 / PI << "\n";	// theta degree = 45
	cout << "Norm = " << norm(num2) << "\n";			// 2 (1*1 + 1*1)

	complex<double> num3 = std::polar(1.41421, 0.785398);
	cout << "(x+iy) from polar are: " << num3 << "\n";	// (0.999998,0.999997)

	complex<double> zero;
	complex<double> x_part = 15;
	cout << x_part << "\n";				// (15,0)

	complex<double> a(1, 2);
	complex<double> b(3, 4);

	cout<<a+b<<"\n";	// (4,6)
	cout<<a-b<<"\n";	// (-2,-2)
	cout<<a*b<<"\n";	// (-5,10)
	cout<<b*2.0<<"\n";	// (6,8)
	cout<<b/2.0<<"\n";	// (1.5,2)


    cout << fixed << std::setprecision(1);

	complex<double> i = -1;
	cout<<sqrt(i)<<"\n";		// (0,1)

	complex<double> c(2, 3);
	cout<<conj(c)<<"\n";		// (2,-3)
	cout<<pow(c, 2)<<"\n";		// (-5,12)

	complex<double> i1 (0, -1);
	cout<<exp(i1 * PI)<<"\n";	// (-1, 0)



	 std::cout << std::fixed << std::setprecision(1);

	 std::complex<double> z1 = 1i * 1i;     // imaginary unit squared
	 std::cout << "i * i = " << z1 << '\n';

	 std::complex<double> z2 = std::pow(1i, 2); // imaginary unit squared
	 std::cout << "pow(i, 2) = " << z2 << '\n';

	 double PI = std::acos(-1);
	 std::complex<double> z3 = std::exp(1i * PI); // Euler's formula
	 std::cout << "exp(i * pi) = " << z3 << '\n';

	 std::complex<double> z4 = 1. + 2i, z5 = 1. - 2i; // conjugates
	 std::cout << "(1+2i)*(1-2i) = " << z4*z5 << '\n';
	 */

	point a (10, 10);
	point m1 (1, 0);
	point m2 (0, 1);

	cout<<a<<" reflected around "<<m1<<" = "<<reflectO(a, m1)<<"\n";
	// 10,10) reflected around (1,0) = (10,-10)

	cout<<a<<" reflected around "<<m2<<" = "<<reflectO(a, m2)<<"\n";
	// (10,10) reflected around (0,1) = (-10,10)

	return 0;
}
