#ifndef _INSERT_VALUE_
#define _INSERT_VALUE_
#include<cmath>
#include<cstdio>
enum { num = 11 };
//��������Ǹ������Ǳ�����������

const double EPS = 1E-8;//��ͬ�������ļ��ڵ�Eps���-8�ǽⷽ������Ҫ������һ������ĿҪ����ʵ�ϲ�Ҳ���ԣ�����Ū��
//�������ղ�ֵ���㷨
double Lagrange_Insert(const double*, const double*, const int, const double);
//ţ�ٲ�ֵ���㷨
double Newton_Insert(const double*, double*, const int, const double);
//����ʽ��Ϸ�
double Curve_Fitting(const double*, const double*, const int, const double);


#endif // !_INSERT_VALUE_