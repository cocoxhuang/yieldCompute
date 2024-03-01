#include <iostream>
#include <cmath>
#include "solver.h"

using namespace std;

int main(){
    double acc = pow(10.0,-8);
    double lEnd = 0.0;
    double rEnd = 2.0;
    double target = 0.0;
    quadratic func(2.0);

    cout << "Root of x^2 - 2 = 0 by bisect method: " << solveByBisect(&func, target, lEnd, rEnd, acc) << endl;

    double x0 = 1.0;
    cout << "Root of x^2 - 2 = 0 by Newton method: " << solveByNewton(&func, target, x0, acc) << endl;

    return 0;
}