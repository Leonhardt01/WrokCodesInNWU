#include"Martix_Calculate.h"
#pragma warning (disable: 6011)//ȡ���Կ�ָ��Ľ����ã�һ����˵С����̬�ڴ�����ǲ���ʧ�ܵ�
#pragma warning (disable: 6031)//scanf�ľ���
#pragma warning (disable: 6386)//���������ʵĪ���������*(mrx+i)��û�У�mrx[i]����
void InputRowAndColumn_1(int* row, int* column)
{
	printf("�������һ�����������������(�������0���������η�Χ�ڣ���Ȼ�ڴ�����)���Կո���߻س���Ϊ�ָ���\n");
	scanf("%d%d", row, column);
}
void InputRowAndColumn_2(int* column_2)
{
	printf("������ڶ������������(�������0���������η�Χ�ڣ���Ȼ�ڴ�����)��\n");
	scanf("%d", column_2);
}
void Print_Array_R(double* _res, const int row, const int colunm_2)
{
	printf("\n�����Ǿ�����˵Ľ����\n");
	for (int i = 0; i < row * colunm_2; i++)
	{
		printf("%.4f ", *(_res + i));
		for (int j = 1; j <= row; j++)
		{
			if (i == j * colunm_2 - 1)//�ж�ʲôʱ��û��д�ӡ����
				printf("\n");
		}
	}
	printf("\n");
}
void Print_Array_C(double* _res, const int row, const int colunm_2, double* Im_val)
{
	printf("\n�����Ǿ�����˵Ľ����\n");
	for (int i = 0; i < row * colunm_2; i++)
	{
		printf("%.4f", *(_res + i));
		if (*(Im_val + i) >= 0)
		{
			printf("+");
		}
		printf("%.4f", *(Im_val + i));
		printf("j ");
		for (int j = 1; j <= row; j++)
		{
			if (i == j * colunm_2 - 1)//�ж�ʲôʱ��û��д�ӡ����
				printf("\n");
		}
	}
	printf("\n");
}
double** _2_Dimension_Array_Buy_Memory(const int* row, const int* column)
{
	double** mrx = (double**)malloc(sizeof(double*) * (*row));
	for (int i = 0; i < (*row); i++)
	{
		*(mrx+i) = (double*)malloc(sizeof(double) * (*column));
	}
	return mrx;
}
void _2_Dimension_Array_Initialise(double** mrx, const int* row, const int* column)
{
	for (int i = 0; i < (*row); i++)
		for (int j = 0; j < (*column); j++)
			mrx[i][j] = 0;
}
void _2_Dimension_Array_Destory_Memory(double** mrx, const int* row)
{
	for (int i = 0; i < (*row); i++)
		free(mrx[i]);
	free(mrx);
	mrx = nullptr;
}

void  R_Matrix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res)
{

	printf("������ʵ��������룺\n");
	printf("�������һ�������Ԫ�أ�\n");
	for (int i = 0; i < (*row); i++)
		for (int j = 0; j < (*column); j++)
			scanf("%lf", &x_res[i][j]);
	printf("������ڶ��������Ԫ�أ�\n");
	for (int i = 0; i < (*column); i++)
		for (int j = 0; j < (*column_2); j++)
			scanf("%lf", &y_res[i][j]);
	int t = 0, i = 0, j = 0;
	while (j < *row)//CRT detected that the application wrote to memory after end of heap buffer
					//�޸��˳��������ڴ�Ĵ�С
	{
		for (int k = 0; k < *column; k++)
		{
			_res[i] += (x_res[j][k]) * (y_res[k][t]);
		}
		i++;
		t++;
		if (t == *column_2)
		{
			t = 0;
			j++;
		}
	}
}
void C_Martix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res, double* Im_val)
{
	Attention();
	char tmp[65];//�����ʵ��������
	double** Im_x_res, ** Im_y_res;
	Im_x_res = _2_Dimension_Array_Buy_Memory(row, column);
	Im_y_res = _2_Dimension_Array_Buy_Memory(column, column_2);
	printf("�����Ǹ���������룺\n");
	printf("�������һ�������Ԫ�أ�\n");
	for (int i = 0; i < (*row); i++)
		for (int j = 0; j < (*column); j++)
		{
			scanf("%lf%s", &x_res[i][j], tmp);
			if (tmp[1] == 'j' && tmp[0] == '+')
				Im_x_res[i][j] = 1;
			else if (tmp[1] == 'j' && tmp[0] == '-')
				Im_x_res[i][j] = -1;
			else
				Im_x_res[i][j] = atof(tmp);
		}
	printf("������ڶ��������Ԫ�أ�\n");
	for (int i = 0; i < (*column); i++)
		for (int j = 0; j < (*column_2); j++)
		{
			scanf("%lf%s", &y_res[i][j], tmp);
			if (tmp[1] == 'j' && tmp[0] == '+')
				Im_y_res[i][j] = 1;
			else if (tmp[1] == 'j' && tmp[0] == '-')
				Im_y_res[i][j] = -1;
			else
				Im_y_res[i][j] = atof(tmp);
		}
	int t = 0, i = 0, j = 0;
	while (j < *row)//CRT detected that the application wrote to memory after end of heap buffer
					//�޸��˳��������ڴ�Ĵ�С
	{
		for (int k = 0; k < *column; k++)
		{
			_res[i] += (x_res[j][k]) * (y_res[k][t]) - (Im_x_res[j][k] * Im_y_res[k][t]);
			Im_val[i] += (x_res[j][k] * Im_y_res[k][t]) + (y_res[k][t] * Im_x_res[j][k]);
		}
		i++;
		t++;
		if (t == *column_2)
		{
			t = 0;
			j++;
		}
	}
	_2_Dimension_Array_Destory_Memory(Im_x_res, row);
	_2_Dimension_Array_Destory_Memory(Im_y_res, column);
}
void Attention(void)
{
	printf("\nע�����\n");
	printf("�����������ʱ�����鲿Ϊ0�������룬Ҳ����˵\n");
	printf("2+0j�������,�����鲿����j��ʾ������ʱҲ����ʹ��j(Сд)\n");
	printf("һ������ֵ����������ǰ�棬�������������\n\n");
}
data gcd(data a, data b)
{
	return b ? gcd(b, a % b) : a;
}
