#ifndef _MARTIX_CALCULATE_
#define _MARTIX_CALCULATE_
#include<cstdio>
#include<cstdlib>
typedef int data;

//���������
data gcd(data a, data b);
//��ӡ�������ʵ����
void Print_Array_R(double* _res, const int row, const int colunm_2);
//��ӡ������ĸ�����
void Print_Array_C(double* _res, const int row, const int colunm_2, double* Im_val);
//�����ڴ�
double** _2_Dimension_Array_Buy_Memory(const int* row, const int* column);
//��ʼ������
void _2_Dimension_Array_Initialise(double** mrx, const int* row, const int* column);
//�ͷ��ڴ�,���ÿ�
void _2_Dimension_Array_Destory_Memory(double** mrx, const int* row);
//��һ���������ݵ�����
void InputRowAndColumn_1(int* row, int* column);
//�ڶ����������ݵ�����
void InputRowAndColumn_2(int* column_2);
//ʵ�����ʵ��
void R_Matrix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res);
//�������ʵ��
void C_Martix_XmulY(double* _res, const data* row, const data* column, const data* column_2, double** x_res, double** y_res, double* Im_val);
//�����������ע������
void Attention(void);


#endif // !_MARTIX_CALCULATE_