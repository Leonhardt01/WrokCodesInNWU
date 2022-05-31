#include"Integral_Differential.h"
double Rectangle(double low_limit, double upper_limit, const int quantity, double(*function)(double))
{
	double length = (upper_limit - low_limit) / quantity, sum = 0, var = low_limit;
	for (int i = 0; i < quantity; i++)
	{
		var += length;
		sum += (*function)(var) * length;
	}
	return sum;
}


double Trapezium(double low_limit, double upper_limit, const int quantity, double(*function)(double))
{
	double length = (upper_limit - low_limit) / quantity, sum = 0, var = low_limit;
	double f_left, f_right;//区间左右函数值
	for (int i = 0; i < quantity; i++)
	{
		f_left = (*function)(var + length * i);
		f_right = (*function)(var + length * (i + 1.0));
		sum += (f_left + f_right) * length / 2;
	}
	return sum;
}

double Simpson_Integral(double low_limit, double upper_limit, const int quantity, double(*function)(double))
{
	double length = (upper_limit - low_limit) / quantity, sum = 0, var = low_limit;
	double f_left, f_right;//区间左右函数值
	double f_mid;//区间中点函数值
	for (int i = 0; i < quantity; i++)
	{
		f_left = (*function)(var + length * i);
		f_right = (*function)(var + length * (i + 1.0));
		f_mid = (*function)(var + length * i + length / 2);
		sum += length / 6 * (f_left + 4 * f_mid + f_right);//代入公式
	}
	return sum;
}
//利用中间差商误差为O(x^2)
double Symmetric_Difference(double point, const double eps, double(*function)(double))
{
	
	double h = 1, ans_2, tmp;
	double ans_1 = ((*function)(point + h) - (*function)(point - h)) / (2 * h);
	do
	{
		h /= 2;
		ans_2 = ((*function)(point + h) - (*function)(point - h)) / (2 * h);
		tmp = ans_1;
		ans_1 = ans_2;
	} while (fabs(tmp - ans_2) > eps);
	return ans_2;
}


double work_function_1(double x)
{
	return x / (1 + x * x);
}

double work_function_2(double x)
{
	return 1 + x * x;
}
