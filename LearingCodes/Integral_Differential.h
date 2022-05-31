#ifndef _INTEGRAL_DIFFERENTIAL_
#define	_INTEGRAL_DIFFERENTIAL_
#include<cmath>
#include<cstdio>

const double Eps = 1e-6;
//函数参数的意思和变量名称意思一样
//定长矩形积分
double Rectangle(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//梯形法积分
double Trapezium(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//辛普森法则积分
double Simpson_Integral(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//对称差分
double Symmetric_Difference(double point, const double eps, double(*function)(double));

//函数区域
double work_function_1(double);
double work_function_2(double);

#endif // !_INTEGRAL_DIFFERENTIAL_