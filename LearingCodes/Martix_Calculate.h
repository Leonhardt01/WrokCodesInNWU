#ifndef _MARTIX_CALCULATE_
#define _MARTIX_CALCULATE_
#include<cstdio>
#include<cstdlib>
typedef int data;

//求最大公因数
data gcd(data a, data b);
//打印出算出的实矩阵
void Print_Array_R(double* _res, const int row, const int colunm_2);
//打印出算出的复矩阵
void Print_Array_C(double* _res, const int row, const int colunm_2, double* Im_val);
//申请内存
double** _2_Dimension_Array_Buy_Memory(const int* row, const int* column);
//初始化数组
void _2_Dimension_Array_Initialise(double** mrx, const int* row, const int* column);
//释放内存,并置空
void _2_Dimension_Array_Destory_Memory(double** mrx, const int* row);
//第一个矩阵数据的输入
void InputRowAndColumn_1(int* row, int* column);
//第二个矩阵数据的输入
void InputRowAndColumn_2(int* column_2);
//实矩阵的实现
void R_Matrix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res);
//复矩阵的实现
void C_Martix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res, double* Im_val);
//复矩阵输入的注意事项
void Attention(void);


#endif // !_MARTIX_CALCULATE_