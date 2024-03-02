#include <iostream>
#include <cmath>
#include <chrono>
#include "solver.h"

using namespace std;

int main(){
    double acc = pow(10.0,-4);
    double lEnd = 0.0;
    double rEnd = 1.0;

    double target = 100.0;                      // bond is issued at par :$100
    bondPrice bond(3, 5.0, 100.0);              // a bond with 3 years to maturity, $5 annual coupon, $100 face value 

    auto start = std::chrono::high_resolution_clock::now();
    cout << "Yield of bond by bisect method: " << solveByBisect(&bond, target, lEnd, rEnd, acc) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for bisect method: " << duration.count() << "milliseconds."<< endl;


    double x0 = 1.0;
    start = std::chrono::high_resolution_clock::now();
    cout << "Yield of bond by Newton method: " << solveByNewton(&bond, target, x0, acc) << endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for Newton method: " << duration.count() << "milliseconds."<< endl;

    return 0;
}