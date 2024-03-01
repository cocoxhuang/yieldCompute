#include <iostream>
#include <cmath>
#include "solver.h"

using namespace std;

double f(double x){return x*x - 2;}
double df(double x){return 2*x;}

int main(){
    double acc = pow(10.0,-3);
    double lEnd = 0.0;
    double rEnd = 2.0;
    double target = 0.0;

    cout << "Root of x^2 -2 = 0 by bisect method: " << solveByBisect(f, target, lEnd, rEnd, acc) << endl;

    double x0 = 1.0;
    cout << "Root of x^2 -2 = 0 by Newton method: " << solveByNewton(f, df, target, x0, acc) << endl;

    return 0;
}