#pragma once
#ifndef _EQUATION_SOLUTION_H_
#define _EQUATION_SOLUTION_H_
#include <cstdio>
#include <cmath>
const double _EPS = 1e-6;
const double GoldenRatioNum = 0.618;
//二分法
double Dichotomy(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));
//不动点迭代法
double FixedPointIteration(double point, double EPS, int IterateNum, double(*g)(double));
//弦截法
double SecantMethod(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));
//牛顿迭代法
double NewtonIterate(double point, double EPS, int IterateNum, double(*f)(double), double(*df)(double));
//黄金比率分割法
double GoldenRatio(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));

//二分法求解的函数
double f1(double x);
//不动点迭代法的函数
double f2(double x);
//弦截法的函数
double f3(double x);
//牛顿法的函数
double f4(double x);
//牛顿法函数的导数
double ff4(double x);
//黄金分割法的函数
double f5(double x);
#endif // !_EQUATION_SOLUTION_H_
