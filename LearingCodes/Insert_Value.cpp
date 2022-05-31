#include"Insert_Value.h"
//���û�ö�˵�ģ����Ź�ʽcopy������
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
//�����ʽ���ű�ʾ������д���룬��������˵��Լ������
double Newton_Insert(const double* x, double* y, const int n, const double point)
{
	double tmp = 0, _ans = y[0];
	for (int i = 0; i < n - 1; i++)
	{
		//������ÿ�׵Ĳ�ַ������
		//ÿ��һ�δ�ǰ��ϳ�һ������
		for (int j = n - 1; j > i; j--)
		{
			//��ĸÿ�׵Ĳ�֣������ͼ�һ
			y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - 1 - i]);
		}
		tmp = y[i + 1];//�����������ݾ���ÿ������ʽ��ϵ��
		for (int k = 0; k < i + 1; k++)//ÿ��Ľ��
		{
			tmp *= (point - x[k]);
		}
		_ans += tmp;
	}
	return _ans;
}

//Hermite��ֵ��ʵ��û�����ף�
//�ֶ����Բ�ֵ�о��Ǹ�������������ͼ��
//����֮���������Թ�ϵ�����ٶ�Ҳ��Ӱ��ֱ�������ֵ����
//���Ծʹ���ǿ���ö���ʽ��������ˡ�����
//Ȼ���ؽ����Է����������ѵ㣬���ͽ�������ϵĽⷨ������
double Curve_Fitting(const double* x, const double* y, const int n, const double point)
{
	double _ans = 0;
	for (int i = 0; i < n; i++)//��������
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = pow(x[i], n - 1.0 - j);
		}
		B[i][n] = y[i];
	}
	for (int i = 0; i < n; i++) {
		int pivot = i;
		for (int j = i; j < n; j++)//ѡ��һ����ǰλ��ϵ������ֵ���ĵ�����������ֹ���
			if (fabs(B[j][i] - B[pivot][i]) <= EPS)
				pivot = j;
		for (int j = 0; j <= n; j++)//����������Ҫ�����е�ȫ���������� 
		{
			double t = B[i][j];
			B[i][j] = B[pivot][j];
			B[pivot][j] = t;
		}
		if (fabs(B[i][i]) <= EPS)//�����λ��ϵ�������㣬��0x=a��һ���޽�
		{
			printf("No Solution\n");
			return 0;
		}
		for (int j = i + 1; j <= n; j++)
			B[i][j] /= B[i][i];//����λ��ϵ����Ϊ1
		for (int j = 0; j < n; j++)
			if (i != j)
				for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];//�����������üӼ�����ȥϵ��ֵ
	}
	//����point��ʱ������ߵ�ֵ
	for (int i = 0; i < n; i++)
	{
		_ans += pow(point, n - 1.0 - i) * B[i][n];
	}
	return _ans;
}
