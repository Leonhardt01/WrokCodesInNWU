#pragma warning (disable: 6011)
#pragma warning (disable: 6386)
#include"Insert_Value.h"
#include"Integral_Differential.h"
#include"Martix_Calculate.h"
#include"Equation_Solution.h"
#include<string>
#include<iostream>

bool CheckForPositiveSingleInput(int& val);
bool CheckForEdgeInput(double& LeftSubEdge, double& RightSubEdge);
/**************************************************************************************/
void IsInputAgain(std::string& choice);
void ShowReInput(void);
void Menu(void);
/**************************************************************************************/
//���˵���һ�����ܼ����Ӻ���
bool MartrixCalculate(std::string& option);
void CommonMultiple(int& m, int& n, int& ans, std::string& choice);
void CommonFactor(int& m, int& n, int& ans, std::string& choice);
void RealMartixMultiple(int& row, int& column, int& column2 ,std::string& choice);
void ComplexMartixMultiple(int& row, int& column, int& column2, std::string& choice);
/**************************************************************************************/
//���˵��ڶ������ܼ����Ӻ���
//�⼸���Ӻ�����������˵����ֱ����������������Ȼ���ٴ��ν�ȥ�����ǲ����ع���
//�������δ�����ʵ���ƶȻ���ͦ�ߵ�
bool InsertValue(std::string& option);
bool CheckForInsertMaxVal(int& DataSize);
void LagrangeInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
void NewtonInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
void PolynomialValuation(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
/**************************************************************************************/
//���˵����������ܼ����Ӻ���
//ͬ���ĵ�����������ʱ��ȷʵ����ֻдһ�δ��룬�����ع��ˣ�ÿ�������ڶ�������
//��������������Ӧ���������룬�ٽ��е���
//���ڱ����˲˵���һ���ԣ�������ȥ�ع�
bool IntegralDifferential(std::string& option);
void Statement(void);
void Rectangle(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void Trapezium(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void SimpsonIntegral(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void SymmetricDifference(std::string& choice);
/**************************************************************************************/
//���˵����ĸ����ܼ����Ӻ���
bool EquationSolution(std::string& option);
void Dichotomy(double& LeftEdge, double& RightEdge,int& IterateNum);
void FixedPointIteration(double& Intersection, int& IterateNum);
void SecantMethod(double& LeftEdge, double& RightEdge, int& IterateNum);
void NewtonIterate(double& Intersection, int& IterateNum);
void GoldenRatio(int& IterateNum);
/**************************************************************************************/
int main(void)
{
	printf("���ڱ����������ޣ������ܵı�����һЩ�Ƿ����룬������ȫ��\n");
	printf("�������������������ʱ�����ϸ�����ʾ��������\n");
	printf("�������ᷢ������Ԥ֪�Ĵ���\n");
	system("pause");
	system("CLS");
	bool Iscontinue = false;//�жϳ����Ƿ����
	std::string option;//��Ϊѡ������û�������
	while (true){
		Menu();
		getline(std::cin, option);
		if (option == "0") {
			return 0;
		}else if (option == "1") {
			system("CLS");
			Iscontinue = MartrixCalculate(option);
			if (Iscontinue) {
				system("CLS");
				continue;
			}
		}else if (option == "2") {
			system("CLS");
			Iscontinue = InsertValue(option);
			if (Iscontinue) {
				system("CLS");
				continue;
			}
		}else if (option == "3") {
			system("CLS");
			Iscontinue = IntegralDifferential(option);
			if (Iscontinue) {
				system("CLS");
				continue;
			}
		}else if (option == "4") {
			system("CLS");
			Iscontinue = EquationSolution(option);
			if (Iscontinue) {
				system("CLS");
				continue;
			}
		}else {
			ShowReInput();
		}
	}
}
/**************************************************************************************/

//��鵥ֵ���룬�������η�Χ�򷵻�true
bool CheckForPositiveSingleInput(int& val)
{
	//������������ջ�����
	if (std::cin >> val) 
	{
		//������ȷ��������������Ϊ�Ƿ�����
		if (val <= 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			return true;
		}
		return false;
	}
	else 
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowReInput();
	}
	return true;
}
//��麯���߽����룬�Ƿ����뷵��true
bool CheckForEdgeInput(double& LeftSubEdge, double& RightSubEdge)
{
	//������������ջ�����
	if (std::cin >> LeftSubEdge >> RightSubEdge) {
		return false;
	}else {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowReInput();
	}
	return true;
}
/**************************************************************************************************************/
//�����û�ѡ��Ĳ����������ú��������ж��Ƿ��������
void IsInputAgain(std::string& choice)
{
	(void)getchar();//����cin������'\n'
	getline(std::cin, choice);
	system("CLS");
}
//����������ʾ����
void ShowReInput(void)
{
	printf("\n��������������ѡ��\n");
	system("pause\n");
	system("CLS");
}
//���˵�����
void Menu(void)
{
	printf("\t\t\t��������ֵ�����������ģ��\n");
	printf("\t\t*************************************************\n");
	printf("\t\t*		[1].������˼���		*\n");
	printf("\t\t*		[2].��ֵ��������		*\n");
	printf("\t\t*		[3].΢���붨����		*\n");
	printf("\t\t*		[4].�����������		*\n");
	printf("\t\t*		[0].�˳����Ӧ��		*\n");
	printf("\t\t*************************************************\n");
	printf("��ѡ������ʹ�õ�ģ�飺");
}
/**************************************************************************************************************/
bool MartrixCalculate(std::string& option)
{
	int num1 = -1, num2 = -1, ans = -1;//��������洢����������С�������Լ��������

	//ͬʱҲ������Ϊ�����С���ж�
	while (true) {
		printf("\t\t�������˷�ģ��(���������������С������)\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].��С������	   	*\n");
		printf("\t\t*		  [2].�������		*\n");
		printf("\t\t*		  [3].ʵ����˷�		*\n");
		printf("\t\t*		  [4].������˷�		*\n");
		printf("\t\t*		  [0].������һ��		*\n");
		printf("\t\t*************************************************\n");
		printf("��ѡ������ʹ�õĹ��ܣ�");
		getline(std::cin, option);
		if (option == "0")
			return true;
		else if (option == "1") {
			system("CLS");
			CommonMultiple(num1,num2,ans,option);			
		}else if (option == "2") {
			system("CLS");
			CommonFactor(num1, num2, ans, option);
		}else if (option == "3") {
			system("CLS");
			RealMartixMultiple(num1, num2, ans, option);
		}else if (option == "4") {
			system("CLS");
			ComplexMartixMultiple(num1, num2, ans, option);
		}else {
			ShowReInput();
		}
	}
}
//��С������
void CommonMultiple(int& m,int& n,int& ans,std::string& choice)
{
	while (true) {
		printf("�����Ǽ�����С����������:\n");
		printf("������������������(����������õ��Ĵ�������,���ݹ���õ����Ҳ������)\n");	
		if (!(std::cin >> m >> n)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		if (getchar() != '\n') {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		ans = gcd(m, n);
		if (ans) {
			ans = m * n / ans;
		}//��ֹ����0�������
		//��������и�bug��Ŀǰ����������������������и��ʳ��֣��ݲ������Դ
		printf("\n%d��%d����С������Ϊ��%d\n", m, n, ans);
		printf("�Ƿ������⣿\n");
		printf("����1�������������˳�������һ�㣺\n");
		getline(std::cin, choice);
		system("CLS");//�����ƺ����ܵ���ShowReInput�������ǻ���������'\n'������
		if (choice != "1")
			break;
	}
}
//�������
void CommonFactor(int& m, int& n, int& ans, std::string& choice)
{
	while (true) {
		printf("�����Ǽ��������������:\n");
		printf("������������������(����������õ��Ĵ�������,���ݹ���õ����Ҳ������)\n");
		if (!(std::cin >> m >> n)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		if (getchar() != '\n') {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		ans = gcd(m, n);
		printf("\n%d��%d���������Ϊ��%d\n", m, n, ans);
		printf("�Ƿ������⣿\n");
		printf("����1�������������˳�������һ�㣺\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//ʵ����ĳ˷�����ʵ�ֺ���
void RealMartixMultiple(int& row, int& column, int& column2, std::string& choice)
{
	double** x_res = nullptr, ** y_res = nullptr, * _res = nullptr;
	while (true) {
		printf("�����Ǽ�������ʵ������˵�ģ��:(�Ƿ������������)\n");
		InputRowAndColumn_1(&row, &column);
		InputRowAndColumn_2(&column2);
		x_res = _2_Dimension_Array_Buy_Memory(&row, &column);
		y_res = _2_Dimension_Array_Buy_Memory(&column, &column2);
		_res = (double*)malloc(sizeof(double) * row * column2);//����һλ�����ڴ�(�������ݽ��)
		for (int i = 0; i < row * column2; i++)//��ʼ������𰸵�һά����
			_res[i] = 0;
		R_Matrix_XmulY(_res, &row, &column, &column2, x_res, y_res);
		Print_Array_R(_res, row, column2);
		printf("\n�Ƿ����������������(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
	//�ͷ��ڴ�
	if (!(x_res && y_res && _res)) {
		_2_Dimension_Array_Destory_Memory(x_res, &row);
		_2_Dimension_Array_Destory_Memory(y_res, &column);
		free(_res);
	}
}
//������ĳ˷�����ʵ�ֺ���
void ComplexMartixMultiple(int& row, int& column, int& column2, std::string& choice)
{
	double** x_res = nullptr, ** y_res = nullptr, * _res = nullptr, * Im_res = nullptr;
	while (true)
	{
		printf("�����Ǽ���������������˵�ģ��:\n");
		InputRowAndColumn_1(&row, &column);
		InputRowAndColumn_2(&column2);
		x_res = _2_Dimension_Array_Buy_Memory(&row, &column);
		y_res = _2_Dimension_Array_Buy_Memory(&column, &column2);
		_res = (double*)malloc(sizeof(double) * row * column2);//����һλ�����ڴ�(�������ݽ��)
		Im_res = (double*)malloc(sizeof(double) * row * column2);//���뱣���鲿��һλ����
		for (int i = 0; i < row * column2; i++)//��ʼ������𰸺��鲿��һά����
		{
			_res[i] = 0;
			Im_res[i] = 0;
		}
		C_Martix_XmulY(_res, &row, &column, &column2, x_res, y_res, Im_res);
		Print_Array_C(_res, row, column2, Im_res);
		printf("\n�Ƿ����������������(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
	//�ͷ��ڴ�
	if (!(x_res && y_res && _res)) {
		_2_Dimension_Array_Destory_Memory(x_res, &row);
		_2_Dimension_Array_Destory_Memory(y_res, &column);
		free(_res);
	}
}
/**************************************************************************************************************/
bool InsertValue(std::string& option)
{
	while (true) {
		//�������ݵ�ֵ,EstimatorPoint��Ҫ����ĵ�
		double x[num] = { 0 }, y[num] = { 0 }, EstimatorPoint = 0;
		//�޶����ݵķ�Χ
		int DataSize = 0;
		printf("\t\t\t\t�����Ǻ�����ֵ����ģ��\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].�������ղ�ֵ	   	*\n");
		printf("\t\t*		  [2].ţ�ٲ�ֵ����		*\n");
		printf("\t\t*		  [3].ʮ�ζ���ʽ		*\n");
		printf("\t\t*		  [0].������һ��		*\n");
		printf("\t\t*************************************************\n");
		printf("��ѡ������ʹ�õĹ��ܣ�");
		getline(std::cin, option);
		if (option == "0")
			return true;
		else if (option == "1") {
			system("CLS");
			LagrangeInsert(x, y, DataSize, EstimatorPoint, option);
		}
		else if (option == "2") {
			system("CLS");
			NewtonInsert(x, y, DataSize, EstimatorPoint, option);
		}
		else if (option == "3") {
			system("CLS");
			PolynomialValuation(x, y, DataSize, EstimatorPoint, option);
		}else {
			ShowReInput();
		}
	}
}
//����ֵ���ݵ����룬��Ϊ�������Ҵ��ڹ涨�����Сnum(�����и�ö����)������true
bool CheckForInsertMaxVal(int& DataSize)
{	
	if (std::cin >> DataSize)
	{
		//������ȷ��������������Ϊ�Ƿ�����
		if (DataSize <= 1||DataSize>=num) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			return true;
		}
		return false;
	}
	//������������ջ�����
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowReInput();
	}
	return true;
}
//�������ղ�ֵ����ʵ��
void LagrangeInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("�������������ղ�ֵ��,��������������(10����,С��Ĭ�Ͻض�):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("���Ա������룬�������Ӧ�����(�ո���߻س���Ϊ�ָ�)");
		for (int i = 0; i < DataSize; i++)
		{
			std::cout << "�������" << i+1 << "������";
			std::cin >> x[i] >> y[i];
		}
		printf("��������Ҫ���Ƶĵ�:\n");
		std::cin >> EstimatorPoint;
		double ans = Lagrange_Insert(x, y, DataSize, EstimatorPoint);
		std::cout << "\n��ֵ���Ϊ:" << ans;
		printf("�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//ţ�ٲ�ֵ����ʵ��
void NewtonInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("������ţ�ٲ�ֵ��,��������������(10����,С��Ĭ�Ͻض�):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("���Ա������룬�������Ӧ�����(�ո���߻س���Ϊ�ָ�)");
		for (int i = 0; i < DataSize; i++) {
			std::cout << "�������" << i + 1 << "������";
			std::cin >> x[i] >> y[i];
		}
		printf("��������Ҫ���Ƶĵ�:\n");
		std::cin >> EstimatorPoint;
		double ans = Newton_Insert(x, y, DataSize, EstimatorPoint);
		std::cout << "\n��ֵ���Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//����ʽ���
void PolynomialValuation(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("�����Ƕ���ʽ��,��������������(10����,С��Ĭ�Ͻض�):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("���Ա������룬�������Ӧ�����(�ո���߻س���Ϊ�ָ�)");
		for (int i = 0; i < DataSize; i++) {
			std::cout << "�������" << i + 1 << "������";
			std::cin >> x[i] >> y[i];
		}
		printf("��������Ҫ���Ƶĵ�:\n");
		std::cin >> EstimatorPoint;
		double ans = Curve_Fitting(x, y, DataSize, EstimatorPoint);
		std::cout << "\n��Ͻ��Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
/**************************************************************************************************************/
bool IntegralDifferential(std::string& option)
{
	while (true) {
		//��������
		double LeftEdge = 0, RightEdge = 0;
		//����ֿ��������
		int BlockAmount = 0;
		printf("\t\t\t�����Ƕ�������΢��(����)����ģ��\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].�������λ���	   	*\n");
		printf("\t\t*		  [2].���η�����		*\n");
		printf("\t\t*		  [3].����ɭ������		*\n");
		printf("\t\t*		  [4].�ԳƲ��΢��		*\n");
		printf("\t\t*		  [0].������һ��		*\n");
		printf("\t\t*************************************************\n");
		printf("��ѡ������ʹ�õĹ��ܣ�");
		getline(std::cin, option);
		if (option == "0")
			return true;
		else if (option == "1") {
			system("CLS");
			Rectangle(LeftEdge, RightEdge, BlockAmount, option);
		}
		else if (option == "2") {
			system("CLS");
			Trapezium(LeftEdge, RightEdge, BlockAmount, option);
		}
		else if (option == "3") {
			system("CLS");
			SimpsonIntegral(LeftEdge, RightEdge, BlockAmount, option);
		}
		else if (option == "4") {
			system("CLS");
			SymmetricDifference(option);

		}else {
			ShowReInput();
		}
	}
}
//�������֣�΢�ֵ�һЩ��������
void Statement(void)
{
	printf("�����ֺ���:f(x)=x/1+x^2\n");
	printf("�ݲ�֧�ַ������ֵ�����(����Ǵ��)��������������ʱ�뿼�Ƕ�����\n");
	printf("��ѡ����Ҫ���ֵ���������(�����η�Χ��):");
}
//�����ηָ������
void Rectangle(double& LeftEdge,double& RightEdge,int& BlockAmount,std::string& choice)
{
	while (true)
	{
		printf("�����Ƕ������λ��ֻ��ַ���\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("�����������ֺ������������䣺(�ո���߻س��ָ�)");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans=Rectangle(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n������Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//���η��ָ������
void Trapezium(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice)
{
	while (true)
	{
		printf("���������ηָ���ַ���\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("�����������ֺ�������������(�ո���߻س��ָ�):");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans = Trapezium(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n������Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//����ɭ�������
void SimpsonIntegral(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice)
{
	while (true)
	{
		printf("����������ɭ���ַ���\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("�����������ֺ������������䣺(�ո���߻س��ָ�)");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans = Simpson_Integral(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n������Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//�ԳƲ�ַ���΢��(����)
void SymmetricDifference(std::string& choice)
{
	while (true) {
		printf("�����ǶԳƲ�ַ���΢�֣�\n");
		printf("������Ϊf(x)=x/1+x^2\n");
		printf("��ע�ⶨ����(��������δ֪��)\n");
		printf("������Ҫ�������һ��:\n");
		double point;
		if (!(std::cin >>point)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		double ans = Symmetric_Difference(point, Eps, work_function_1);
		std::cout << "\nf(x)��("<<point<<",f("<<point<<"))�����ļ�����Ϊ:" << ans;
		printf("\n�Ƿ���������������ݣ�(����1�������������˳�������һ�㣺)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}

/**************************************************************************************************************/
bool EquationSolution(std::string& option)
{
	while (true)
	{
		//���Ҷ˵�
		double LeftEdge = 0, RightEdge = 0;
		//������������Ľ���,ͬʱҲ������Ϊţ�ٷ��ĳ�ʼ�����ж�
		double Intersection = 0;
		//��������
		int IterateNum = 0;
		printf("\t\t\t\t�����ǽⷽ��ģ��\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].���ַ����	   	*\n");
		printf("\t\t*		  [2].�����������		*\n");
		printf("\t\t*		  [3].�ҽط����		*\n");
		printf("\t\t*		  [4].ţ�ٵ�����		*\n");
		printf("\t\t*		  [5].�ƽ���ʷָ�		*\n");
		printf("\t\t*		  [0].������һ��		*\n");
		printf("\t\t*************************************************\n");
		printf("���Ĵ���ҵ�����������棬���5�����ܾ��Ƕ�Ӧ�μ�������ʵ�֣��ݽ�֧�ִ𰸵���ʾ\n");
		printf("��ѡ������ʹ�õĹ��ܣ�");
		getline(std::cin, option);
		if (option == "0")
			return true;
		else if (option == "1") {
			system("CLS");
			Dichotomy(LeftEdge, RightEdge, IterateNum);
		}
		else if (option == "2") {
			system("CLS");
			FixedPointIteration(Intersection, IterateNum);
		}
		else if (option == "3") {
			system("CLS");
			SecantMethod(LeftEdge, RightEdge, IterateNum);
		}
		else if (option == "4") {
			system("CLS");
			NewtonIterate(Intersection, IterateNum);
		}else if (option == "5") {
			system("CLS");
			GoldenRatio(IterateNum);
		}else {
			ShowReInput();
		}
	}
}
//���ַ��󷽳̽�
void Dichotomy(double& LeftEdge, double& RightEdge, int& IterateNum)
{
	while (true) {
		std::cout
			<< "�����Ǻ���f(x)=x^3-6x-1�Ķ���������ģ��\n"
			<< "����������ƵĽ�����(��������1��3������ܻ�õ�����һ����):\n";
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		std::cout << "�������������������������(�����η�Χ��)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = Dichotomy(LeftEdge, RightEdge, _EPS, IterateNum,f1);
		std::cout << "\n���Ƶķ��̽�Ϊ" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//������������󷽳̽�
void FixedPointIteration(double& Intersection, int& IterateNum)
{
	while(true){
		std::cout
			<< "�����Ǻ���f(x)=x^3+2x^2+2x+1�Ĳ������������ģ��\n"
			<< "����������Ƶĳ�ʼֵ��\n";
		if (!(std::cin >>Intersection)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		std::cout << "�����벻��������������������(�����η�Χ��)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res =FixedPointIteration(Intersection, _EPS, IterateNum, f2);
		std::cout << "\n���Ƶķ��̽�Ϊ" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//�ҽط��󷽳̽�
void SecantMethod(double& LeftEdge, double& RightEdge, int& IterateNum)
{
	while (true){
		std::cout
			<< "�����Ǻ���f(x)=x^3-2x^2+7x+4���ҽط�����ģ��\n"
			<< "����������ƵĽ����䣺\n";
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		std::cout << "�������ҽط�����������������(�����η�Χ��)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = SecantMethod(LeftEdge, RightEdge, _EPS, IterateNum, f3);
		std::cout << "\n���Ƶķ��̽�Ϊ" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//ţ�ٷ��󷽳̽�
void NewtonIterate(double& Intersection, int& IterateNum)
{
	while (true) {
		Intersection = 0;
		std::cout << "�����Ǻ���f(x)=x^3-2x^2+7x+4��ţ�ٷ�����ģ��\n";
		std::cout << "������Ŀ��������0����Ľ���ֵ������Ͳ���Ҫ�û������ʼֵ\n";
		std::cout << "������ţ�ٷ�����������������(�����η�Χ��)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = NewtonIterate(Intersection, _EPS, IterateNum, f4,ff4);
		std::cout << "\n���Ƶķ��̽�Ϊ" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//�ƽ�ָ�󷽳̽�
void GoldenRatio(int& IterateNum) 
{
	while (true) {
		double LeftEdge = 0, RightEdge = 4;
		std::cout
			<< "�����Ǻ���f(x)=x^2-4x+4�Ļƽ�ָ������Сֵģ��\n"
			<< "����������ƵĽ�����(��Ŀ�Ѹ���Ϊ[0,4],�ʲ�������)\n";
		std::cout << "������ƽ�ָ����������������(�����η�Χ��)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = GoldenRatio(LeftEdge, RightEdge, _EPS, IterateNum, f5);
		res = f5(res);
		if (res <= _EPS) {
			std::cout << "\n���Ƶ���СֵΪ0\n";
		}else {
			std::cout << "\n���Ƶ���СֵΪ" << res << std::endl;
		}
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
