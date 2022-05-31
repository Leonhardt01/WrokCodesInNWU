#pragma once
#ifndef _EQUATION_SOLUTION_H_
#define _EQUATION_SOLUTION_H_
#include <cstdio>
#include <cmath>
const double _EPS = 1e-6;
const double GoldenRatioNum = 0.618;
//���ַ�
double Dichotomy(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));
//�����������
double FixedPointIteration(double point, double EPS, int IterateNum, double(*g)(double));
//�ҽط�
double SecantMethod(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));
//ţ�ٵ�����
double NewtonIterate(double point, double EPS, int IterateNum, double(*f)(double), double(*df)(double));
//�ƽ���ʷָ
double GoldenRatio(double LeftEdge, double RightEdge, const double EPS, int IterateNum, double(*f)(double));

//���ַ����ĺ���
double f1(double x);
//������������ĺ���
double f2(double x);
//�ҽط��ĺ���
double f3(double x);
//ţ�ٷ��ĺ���
double f4(double x);
//ţ�ٷ������ĵ���
double ff4(double x);
//�ƽ�ָ�ĺ���
double f5(double x);
#endif // !_EQUATION_SOLUTION_H_
