#include <iostream>
#include <cmath>
#include <chrono>
#include "solver.h"

using namespace std;

int main(){
    double acc = pow(10.0,-8);
    double lEnd = 0.0;
    double rEnd = 2.0;
    double target = 0.0;
    quadratic func(2.0);

    auto start = std::chrono::high_resolution_clock::now();
    cout << "Root of x^2 - 2 = 0 by bisect method: " << solveByBisect(&func, target, lEnd, rEnd, acc) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for bisect method: " << duration.count() << "milliseconds."<< endl;


    double x0 = 1.0;
    start = std::chrono::high_resolution_clock::now();
    cout << "Root of x^2 - 2 = 0 by Newton method: " << solveByNewton(&func, target, x0, acc) << endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for Newton method: " << duration.count() << "milliseconds."<< endl;

    return 0;
}