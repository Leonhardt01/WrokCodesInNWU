#ifndef _INSERT_VALUE_
#define _INSERT_VALUE_
#include<cmath>
#include<cstdio>
enum { num = 11 };
//这个数据是给数组是保存增广矩阵的

const double EPS = 1E-8;//不同于另外文件内的Eps这个-8是解方程所需要，另外一个是题目要求，其实合并也可以，懒得弄了
//拉格朗日插值计算法
double Lagrange_Insert(const double*, const double*, const int, const double);
//牛顿插值计算法
double Newton_Insert(const double*, double*, const int, const double);
//多项式拟合法
double Curve_Fitting(const double*, const double*, const int, const double);


#endif // !_INSERT_VALUE_