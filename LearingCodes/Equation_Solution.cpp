#include"Equation_Solution.h"

//���ַ�
double Dichotomy(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	double res=(*f)(LeftEdge);//resΪ����ÿ�ε�����¼���м��ֵ,��ѭ�������ʼ��һ�α�֤��������
	double mid = -1;
	while (fabs(RightEdge - LeftEdge) >= EPS&& IterateNum)
	{
		double FunctionLeft = (*f)(LeftEdge);//������˵��ֵ
		mid = (RightEdge + LeftEdge) / 2.0;//��¼�е�ֵ
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
//�����������
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
//�ҽط�
double SecantMethod(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	//(*f)(LeftEdge)������һ���������б�ʣ��������ţ�ٷ���������һ����
	double res = LeftEdge - (*f)(LeftEdge) * (RightEdge - LeftEdge) / ((*f)(RightEdge) - (*f)(LeftEdge));
	while (IterateNum && (fabs(res - LeftEdge) || fabs((*f)(LeftEdge))))
	{
		LeftEdge = res;
		res = LeftEdge - (*f)(LeftEdge) * (RightEdge - LeftEdge) / ((*f)(RightEdge) - (*f)(LeftEdge));
		IterateNum--;
	}
	return res;
}
//ţ�ٵ�����
double NewtonIterate(double point, const double EPS, int IterateNum, double(*f)(double), double(*df)(double))
{
	//���df�������ǵ�������΢��
	double res = point - ((*f)(point) / (*df)(point));//����ţ�ٵ��������Եõ������ѧʽ��
	while (IterateNum &&(fabs(res-point)||fabs((*f)(point))))
	{
		point = res;
		res= point - ((*f)(point) / (*df)(point));
		IterateNum--;
	}
	return res;
}
//�ƽ���ʷָ
double GoldenRatio(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double))
{
	double NewLeftEdge, NewRightEdge, FNewLeftEdge, FNewRightEdge;
	NewLeftEdge = LeftEdge + (1 - GoldenRatioNum) * (RightEdge - LeftEdge);
	NewRightEdge = LeftEdge + GoldenRatioNum * (RightEdge - LeftEdge);
	//ǰ׺ΪF�����Ӧ�Ա����ĺ���ֵ
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
//���ַ����ĺ���
double f1(double x)
{
	return x * x * x - 6 * x - 1;
}
//������������ĺ���
double f2(double x)
{
	return cbrt (-(2 * x * x + 2 * x + 1));
}
//�ҽط��ĺ���
double f3(double x)
{
	return x * x * x - 2 * x * x + 7 * x - 4;
}
//ţ�ٷ��ĺ���
double f4(double x)
{
	return x * x * x - 2 * x * x + 4 * x + 1;
}
//ţ�ٷ������ĵ���
double ff4(double x)
{
	return 3 * x * x - 4 * x + 4;
}
//�ƽ�ָ�ĺ���
double f5(double x)
{
	return x * x - 4 * x + 4;
}
