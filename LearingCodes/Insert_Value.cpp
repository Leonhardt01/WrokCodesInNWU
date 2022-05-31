#include"Insert_Value.h"
//这个没得多说的，照着公式copy下来的
double B[13][13]{};
double Lagrange_Insert(const double* x, const double* y, const int n, const double point)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double Lsum = 1;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
				Lsum *= (point - x[j]) / (x[i] - x[j]);
		}
		sum += Lsum * y[i];
	}
	return sum;
}
//这个公式符号表示不利于写代码，这里加上了点自己的理解
double Newton_Insert(const double* x, double* y, const int n, const double point)
{
	double tmp = 0, _ans = y[0];
	for (int i = 0; i < n - 1; i++)
	{
		//倒着求每阶的差分方便计算
		//每求一次从前面废除一个数据
		for (int j = n - 1; j > i; j--)
		{
			//分母每阶的差分，其相差就加一
			y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - 1 - i]);
		}
		tmp = y[i + 1];//最上面是数据就是每个多项式的系数
		for (int k = 0; k < i + 1; k++)//每项的结果
		{
			tmp *= (point - x[k]);
		}
		_ans += tmp;
	}
	return _ans;
}

//Hermite插值属实是没看明白，
//分段线性插值感觉是概括整个函数的图像，
//两点之间是是线性关系，点再多也不影响直线上面的值。。
//所以就打算强行用多项式曲线拟合了。。。
//然后呢解线性方程组又是难点，，就借鉴了网上的解法，，，
double Curve_Fitting(const double* x, const double* y, const int n, const double point)
{
	double _ans = 0;
	for (int i = 0; i < n; i++)//读入数据
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = pow(x[i], n - 1.0 - j);
		}
		B[i][n] = y[i];
	}
	for (int i = 0; i < n; i++) {
		int pivot = i;
		for (int j = i; j < n; j++)//选择一个当前位置系数绝对值最大的调换过来，防止误差
			if (fabs(B[j][i] - B[pivot][i]) <= EPS)
				pivot = j;
		for (int j = 0; j <= n; j++)//交换操作，要将所有的全部交换过来 
		{
			double t = B[i][j];
			B[i][j] = B[pivot][j];
			B[pivot][j] = t;
		}
		if (fabs(B[i][i]) <= EPS)//如果该位置系数等于零，则0x=a，一定无解
		{
			printf("No Solution\n");
			return 0;
		}
		for (int j = i + 1; j <= n; j++)
			B[i][j] /= B[i][i];//将该位的系数变为1
		for (int j = 0; j < n; j++)
			if (i != j)
				for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];//将其他方程用加减法减去系数值
	}
	//计算point点时拟合曲线的值
	for (int i = 0; i < n; i++)
	{
		_ans += pow(point, n - 1.0 - i) * B[i][n];
	}
	return _ans;
}
