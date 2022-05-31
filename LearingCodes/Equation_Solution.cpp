#include"Equation_Solution.h"

//二分法
double Dichotomy(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	double res=(*f)(LeftEdge);//res为函数每次迭代记录的中间的值,在循环外面初始化一次保证数据正常
	double mid = -1;
	while (fabs(RightEdge - LeftEdge) >= EPS&& IterateNum)
	{
		double FunctionLeft = (*f)(LeftEdge);//函数左端点的值
		mid = (RightEdge + LeftEdge) / 2.0;//记录中点值
		res = (*f)(mid);
		if (res * FunctionLeft < 0)
		{
			RightEdge = mid;
		}
		else
		{
			LeftEdge = mid;
		}
		IterateNum--;
	}
	return mid;
}
//不动点迭代法
double FixedPointIteration(double point ,const double EPS,int IterateNum,double(*g)(double))
{
	double res = (*g)(point);
	while (IterateNum && fabs(res - point) >= EPS)
	{
		point = res;
		res = (*g)(point);
		IterateNum--;
	}
	return res;
}
//弦截法
double SecantMethod(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	//(*f)(LeftEdge)后面那一坨就是在求斜率，和下面的牛顿法本质上是一样的
	double res = LeftEdge - (*f)(LeftEdge) * (RightEdge - LeftEdge) / ((*f)(RightEdge) - (*f)(LeftEdge));
	while (IterateNum && (fabs(res - LeftEdge) || fabs((*f)(LeftEdge))))
	{
		LeftEdge = res;
		res = LeftEdge - (*f)(LeftEdge) * (RightEdge - LeftEdge) / ((*f)(RightEdge) - (*f)(LeftEdge));
		IterateNum--;
	}
	return res;
}
//牛顿迭代法
double NewtonIterate(double point, const double EPS, int IterateNum, double(*f)(double), double(*df)(double))
{
	//这个df在这里是导数不是微分
	double res = point - ((*f)(point) / (*df)(point));//根据牛顿迭代法可以得到这个数学式子
	while (IterateNum &&(fabs(res-point)||fabs((*f)(point))))
	{
		point = res;
		res= point - ((*f)(point) / (*df)(point));
		IterateNum--;
	}
	return res;
}
//黄金比率分割法
double GoldenRatio(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	double NewLeftEdge, NewRightEdge, FNewLeftEdge, FNewRightEdge;
	NewLeftEdge = LeftEdge + (1 - GoldenRatioNum) * (RightEdge - LeftEdge);
	NewRightEdge = LeftEdge + GoldenRatioNum * (RightEdge - LeftEdge);
	//前缀为F代表对应自变量的函数值
	FNewLeftEdge = (*f)(NewLeftEdge);
	FNewRightEdge = (*f)(NewRightEdge);
	while ((NewRightEdge - NewLeftEdge) >= EPS && IterateNum)
	{
		if (FNewLeftEdge > FNewRightEdge)
		{
			LeftEdge = NewLeftEdge;
			NewLeftEdge = NewRightEdge;
			NewRightEdge = LeftEdge + GoldenRatioNum * (RightEdge - LeftEdge);
		}
		else
		{
			RightEdge = NewRightEdge;
			NewRightEdge = NewLeftEdge;
			NewLeftEdge = LeftEdge + (1 - GoldenRatioNum) * (RightEdge - LeftEdge);
		}
		FNewLeftEdge = (*f)(NewLeftEdge);
		FNewRightEdge = (*f)(NewRightEdge);
		IterateNum--;
	}
	return FNewLeftEdge < FNewRightEdge ? NewLeftEdge : NewRightEdge;
}
//二分法求解的函数
double f1(double x)
{
	return x * x * x - 6 * x - 1;
}
//不动点迭代法的函数
double f2(double x)
{
	return cbrt (-(2 * x * x + 2 * x + 1));
}
//弦截法的函数
double f3(double x)
{
	return x * x * x - 2 * x * x + 7 * x - 4;
}
//牛顿法的函数
double f4(double x)
{
	return x * x * x - 2 * x * x + 4 * x + 1;
}
//牛顿法函数的导数
double ff4(double x)
{
	return 3 * x * x - 4 * x + 4;
}
//黄金分割法的函数
double f5(double x)
{
	return x * x - 4 * x + 4;
}
