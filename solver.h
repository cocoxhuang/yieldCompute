#ifndef solver_h
#define solver_h

#include <iostream>

double solveByBisect(double(*func)(double x), double target, double lEnd, double rEnd, double acc){
    double l = lEnd;
    double r = rEnd;
    double mid = (l + r)/2;

    double y_l = func(l) - target;
    double y_mid = func(mid) - target;

    while ((mid - l) > acc){
        if(y_l * y_mid < 0){
            r = mid;
        }else{
            l = mid;
            y_l = y_mid;
        }
        mid = (l+r)/2;
        y_mid = func(mid) - target;
    }
    return mid;
}

double solveByNewton(double(*func)(double x), double(*Dfunc)(double x), double target, double x0, double acc){
    double x_cur = x0;
    double x_next = x_cur - (func(x_cur) - target)/(Dfunc(x_cur));
    while (x_next - x_cur > acc || x_cur - x_next > acc){
        x_cur = x_next;
        x_next = x_cur - (func(x_cur) - target)/(Dfunc(x_cur));
    }
    return x_next;
}
#endif