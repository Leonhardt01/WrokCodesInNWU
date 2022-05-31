#ifndef _INTEGRAL_DIFFERENTIAL_
#define	_INTEGRAL_DIFFERENTIAL_
#include<cmath>
#include<cstdio>

const double Eps = 1e-6;
//������������˼�ͱ���������˼һ��
//�������λ���
double Rectangle(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//���η�����
double Trapezium(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//����ɭ�������
double Simpson_Integral(double low_limit, double upper_limit, const int quantity, double(*function)(double));
//�ԳƲ��
double Symmetric_Difference(double point, const double eps, double(*function)(double));

//��������
double work_function_1(double);
double work_function_2(double);

#endif // !_INTEGRAL_DIFFERENTIAL_