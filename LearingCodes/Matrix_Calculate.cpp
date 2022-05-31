#include"Martix_Calculate.h"
#pragma warning (disable: 6011)//取消对空指针的解引用，一般来说小程序动态内存分配是不会失败的
#pragma warning (disable: 6031)//scanf的警告
#pragma warning (disable: 6386)//这个警告属实莫名其妙，换成*(mrx+i)就没有，mrx[i]就有
void InputRowAndColumn_1(int* row, int* column)
{
	printf("请输入第一个矩阵的行数和列数(必须大于0，且在整形范围内，不然内存会崩溃)，以空格或者回车作为分隔：\n");
	scanf("%d%d", row, column);
}
void InputRowAndColumn_2(int* column_2)
{
	printf("请输入第二个矩阵的列数(必须大于0，且在整形范围内，不然内存会崩溃)：\n");
	scanf("%d", column_2);
}
void Print_Array_R(double* _res, const int row, const int colunm_2)
{
	printf("\n下面是矩阵相乘的结果：\n");
	for (int i = 0; i < row * colunm_2; i++)
	{
		printf("%.4f ", *(_res + i));
		for (int j = 1; j <= row; j++)
		{
			if (i == j * colunm_2 - 1)//判断什么时候该换行打印矩阵
				printf("\n");
		}
	}
	printf("\n");
}
void Print_Array_C(double* _res, const int row, const int colunm_2, double* Im_val)
{
	printf("\n下面是矩阵相乘的结果：\n");
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
			if (i == j * colunm_2 - 1)//判断什么时候该换行打印矩阵
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

	printf("下面是实矩阵的输入：\n");
	printf("请输入第一个矩阵的元素：\n");
	for (int i = 0; i < (*row); i++)
		for (int j = 0; j < (*column); j++)
			scanf("%lf", &x_res[i][j]);
	printf("请输入第二个矩阵的元素：\n");
	for (int i = 0; i < (*column); i++)
		for (int j = 0; j < (*column_2); j++)
			scanf("%lf", &y_res[i][j]);
	int t = 0, i = 0, j = 0;
	while (j < *row)//CRT detected that the application wrote to memory after end of heap buffer
					//修改了超过申请内存的大小
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
	char tmp[65];//保存非实部的数据
	double** Im_x_res, ** Im_y_res;
	Im_x_res = _2_Dimension_Array_Buy_Memory(row, column);
	Im_y_res = _2_Dimension_Array_Buy_Memory(column, column_2);
	printf("下面是复矩阵的输入：\n");
	printf("请输入第一个矩阵的元素：\n");
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
	printf("请输入第二个矩阵的元素：\n");
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
					//修改了超过申请内存的大小
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
	printf("\n注意事项！\n");
	printf("复矩阵输入的时候若虚部为0保留输入，也就是说\n");
	printf("2+0j这个样子,这里虚部我用j表示，输入时也必须使用j(小写)\n");
	printf("一定是数值在虚数符号前面，否则程序会出问题\n\n");
}
data gcd(data a, data b)
{
	return b ? gcd(b, a % b) : a;
}
