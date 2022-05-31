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
//主菜单第一个功能及其子函数
bool MartrixCalculate(std::string& option);
void CommonMultiple(int& m, int& n, int& ans, std::string& choice);
void CommonFactor(int& m, int& n, int& ans, std::string& choice);
void RealMartixMultiple(int& row, int& column, int& column2 ,std::string& choice);
void ComplexMartixMultiple(int& row, int& column, int& column2, std::string& choice);
/**************************************************************************************/
//主菜单第二个功能及其子函数
//这几个子函数理论上来说可以直接在外面输入数据然后再传参进去，但是不想重构了
//所以三段代码其实相似度还是挺高的
bool InsertValue(std::string& option);
bool CheckForInsertMaxVal(int& DataSize);
void LagrangeInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
void NewtonInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
void PolynomialValuation(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice);
/**************************************************************************************/
//主菜单第三个功能及其子函数
//同样的道理，输入数据时候确实可以只写一次代码，不想重构了，每个函数内都有输入
//所以理论上来讲应该是先输入，再进行调用
//由于保持了菜单的一致性，就懒得去重构
bool IntegralDifferential(std::string& option);
void Statement(void);
void Rectangle(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void Trapezium(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void SimpsonIntegral(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice);
void SymmetricDifference(std::string& choice);
/**************************************************************************************/
//主菜单第四个功能及其子函数
bool EquationSolution(std::string& option);
void Dichotomy(double& LeftEdge, double& RightEdge,int& IterateNum);
void FixedPointIteration(double& Intersection, int& IterateNum);
void SecantMethod(double& LeftEdge, double& RightEdge, int& IterateNum);
void NewtonIterate(double& Intersection, int& IterateNum);
void GoldenRatio(int& IterateNum);
/**************************************************************************************/
int main(void)
{
	printf("由于本人能力有限，尽可能的避免了一些非法输入，但不完全，\n");
	printf("所以在所有数据输入的时候请严格按照提示进行输入\n");
	printf("否则程序会发生不可预知的错误\n");
	system("pause");
	system("CLS");
	bool Iscontinue = false;//判断程序是否继续
	std::string option;//作为选择接受用户的输入
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

//检查单值输入，非正整形范围则返回true
bool CheckForPositiveSingleInput(int& val)
{
	//错误输入则清空缓冲区
	if (std::cin >> val) 
	{
		//输入正确，但不是正数仍为非法输入
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
//检查函数边界输入，非法输入返回true
bool CheckForEdgeInput(double& LeftSubEdge, double& RightSubEdge)
{
	//错误输入则清空缓冲区
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
//接受用户选择的参数，进而让后面的语句判断是否继续输入
void IsInputAgain(std::string& choice)
{
	(void)getchar();//处理cin残留的'\n'
	getline(std::cin, choice);
	system("CLS");
}
//重新输入提示界面
void ShowReInput(void)
{
	printf("\n输入有误，请重新选择！\n");
	system("pause\n");
	system("CLS");
}
//主菜单界面
void Menu(void)
{
	printf("\t\t\t这里是数值分析各项功能总模块\n");
	printf("\t\t*************************************************\n");
	printf("\t\t*		[1].矩阵相乘计算		*\n");
	printf("\t\t*		[2].插值函数计算		*\n");
	printf("\t\t*		[3].微分与定积分		*\n");
	printf("\t\t*		[4].方程求根计算		*\n");
	printf("\t\t*		[0].退出这个应用		*\n");
	printf("\t\t*************************************************\n");
	printf("请选择你想使用的模块：");
}
/**************************************************************************************************************/
bool MartrixCalculate(std::string& option)
{
	int num1 = -1, num2 = -1, ans = -1;//用来计算存储两个数的最小公倍数以及最大公因数

	//同时也可以作为矩阵大小的判断
	while (true) {
		printf("\t\t这里矩阵乘法模块(包括最大公因数，最小公倍数)\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].最小公倍数	   	*\n");
		printf("\t\t*		  [2].最大公因数		*\n");
		printf("\t\t*		  [3].实矩阵乘法		*\n");
		printf("\t\t*		  [4].复矩阵乘法		*\n");
		printf("\t\t*		  [0].返回上一层		*\n");
		printf("\t\t*************************************************\n");
		printf("请选择你想使用的功能：");
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
//最小公倍数
void CommonMultiple(int& m,int& n,int& ans,std::string& choice)
{
	while (true) {
		printf("这里是计算最小公倍数功能:\n");
		printf("请输入两个正整数：(输入非正数得到的答案无意义,数据过大得到结果也无意义)\n");	
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
		}//防止输入0程序崩溃
		//这里好像有个bug，目前看来是在输入错误的情况下有概率出现，暂不清楚来源
		printf("\n%d和%d的最小公倍数为：%d\n", m, n, ans);
		printf("是否继续求解？\n");
		printf("输入1继续，其他则退出返回上一层：\n");
		getline(std::cin, choice);
		system("CLS");//这里似乎不能调用ShowReInput，好像是缓冲区残留'\n'的问题
		if (choice != "1")
			break;
	}
}
//最大公因数
void CommonFactor(int& m, int& n, int& ans, std::string& choice)
{
	while (true) {
		printf("这里是计算最大公因数功能:\n");
		printf("请输入两个正整数：(输入非正数得到的答案无意义,数据过大得到结果也无意义)\n");
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
		printf("\n%d和%d的最大公因数为：%d\n", m, n, ans);
		printf("是否继续求解？\n");
		printf("输入1继续，其他则退出返回上一层：\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//实矩阵的乘法调用实现函数
void RealMartixMultiple(int& row, int& column, int& column2, std::string& choice)
{
	double** x_res = nullptr, ** y_res = nullptr, * _res = nullptr;
	while (true) {
		printf("这里是计算两个实矩阵相乘的模块:(非法输入程序会崩溃)\n");
		InputRowAndColumn_1(&row, &column);
		InputRowAndColumn_2(&column2);
		x_res = _2_Dimension_Array_Buy_Memory(&row, &column);
		y_res = _2_Dimension_Array_Buy_Memory(&column, &column2);
		_res = (double*)malloc(sizeof(double) * row * column2);//申请一位数组内存(保存数据结果)
		for (int i = 0; i < row * column2; i++)//初始化保存答案的一维数组
			_res[i] = 0;
		R_Matrix_XmulY(_res, &row, &column, &column2, x_res, y_res);
		Print_Array_R(_res, row, column2);
		printf("\n是否继续计算其他矩阵？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
	//释放内存
	if (!(x_res && y_res && _res)) {
		_2_Dimension_Array_Destory_Memory(x_res, &row);
		_2_Dimension_Array_Destory_Memory(y_res, &column);
		free(_res);
	}
}
//复矩阵的乘法调用实现函数
void ComplexMartixMultiple(int& row, int& column, int& column2, std::string& choice)
{
	double** x_res = nullptr, ** y_res = nullptr, * _res = nullptr, * Im_res = nullptr;
	while (true)
	{
		printf("这里是计算两个复矩阵相乘的模块:\n");
		InputRowAndColumn_1(&row, &column);
		InputRowAndColumn_2(&column2);
		x_res = _2_Dimension_Array_Buy_Memory(&row, &column);
		y_res = _2_Dimension_Array_Buy_Memory(&column, &column2);
		_res = (double*)malloc(sizeof(double) * row * column2);//申请一位数组内存(保存数据结果)
		Im_res = (double*)malloc(sizeof(double) * row * column2);//申请保存虚部的一位数组
		for (int i = 0; i < row * column2; i++)//初始化保存答案和虚部的一维数组
		{
			_res[i] = 0;
			Im_res[i] = 0;
		}
		C_Martix_XmulY(_res, &row, &column, &column2, x_res, y_res, Im_res);
		Print_Array_C(_res, row, column2, Im_res);
		printf("\n是否继续计算其他矩阵？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
	//释放内存
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
		//保存数据的值,EstimatorPoint是要计算的点
		double x[num] = { 0 }, y[num] = { 0 }, EstimatorPoint = 0;
		//限定数据的范围
		int DataSize = 0;
		printf("\t\t\t\t这里是函数插值计算模块\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].拉格朗日插值	   	*\n");
		printf("\t\t*		  [2].牛顿插值计算		*\n");
		printf("\t\t*		  [3].十次多项式		*\n");
		printf("\t\t*		  [0].返回上一层		*\n");
		printf("\t\t*************************************************\n");
		printf("请选择你想使用的功能：");
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
//检查插值数据的输入，若为非正数且大于规定数组大小num(这里有个枚举题)，返回true
bool CheckForInsertMaxVal(int& DataSize)
{	
	if (std::cin >> DataSize)
	{
		//输入正确，但不是正数仍为非法输入
		if (DataSize <= 1||DataSize>=num) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			return true;
		}
		return false;
	}
	//错误输入则清空缓冲区
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowReInput();
	}
	return true;
}
//拉格朗日插值调用实现
void LagrangeInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("这里是拉格朗日插值法,请输入数据组数(10以内,小数默认截断):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("先自变量输入，后输入对应因变量(空格或者回车作为分隔)");
		for (int i = 0; i < DataSize; i++)
		{
			std::cout << "请输入第" << i+1 << "组数据";
			std::cin >> x[i] >> y[i];
		}
		printf("请输入想要估计的点:\n");
		std::cin >> EstimatorPoint;
		double ans = Lagrange_Insert(x, y, DataSize, EstimatorPoint);
		std::cout << "\n插值结果为:" << ans;
		printf("是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//牛顿插值调用实现
void NewtonInsert(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("这里是牛顿插值法,请输入数据组数(10以内,小数默认截断):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("先自变量输入，后输入对应因变量(空格或者回车作为分隔)");
		for (int i = 0; i < DataSize; i++) {
			std::cout << "请输入第" << i + 1 << "组数据";
			std::cin >> x[i] >> y[i];
		}
		printf("请输入想要估计的点:\n");
		std::cin >> EstimatorPoint;
		double ans = Newton_Insert(x, y, DataSize, EstimatorPoint);
		std::cout << "\n插值结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//多项式拟合
void PolynomialValuation(double* x, double* y, int& DataSize, double& EstimatorPoint, std::string& choice)
{
	while (true) {
		printf("这里是多项式法,请输入数据组数(10以内,小数默认截断):\n");
		if (CheckForInsertMaxVal(DataSize)) {
			continue;
		}
		printf("先自变量输入，后输入对应因变量(空格或者回车作为分隔)");
		for (int i = 0; i < DataSize; i++) {
			std::cout << "请输入第" << i + 1 << "组数据";
			std::cin >> x[i] >> y[i];
		}
		printf("请输入想要估计的点:\n");
		std::cin >> EstimatorPoint;
		double ans = Curve_Fitting(x, y, DataSize, EstimatorPoint);
		std::cout << "\n拟合结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
/**************************************************************************************************************/
bool IntegralDifferential(std::string& option)
{
	while (true) {
		//左右区间
		double LeftEdge = 0, RightEdge = 0;
		//区间分块多少数量
		int BlockAmount = 0;
		printf("\t\t\t这里是定积分与微分(导数)计算模块\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].定长矩形积分	   	*\n");
		printf("\t\t*		  [2].梯形法积分		*\n");
		printf("\t\t*		  [3].辛普森法积分		*\n");
		printf("\t\t*		  [4].对称差分微分		*\n");
		printf("\t\t*		  [0].返回上一层		*\n");
		printf("\t\t*************************************************\n");
		printf("请选择你想使用的功能：");
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
//函数积分，微分的一些声明事项
void Statement(void)
{
	printf("所积分函数:f(x)=x/1+x^2\n");
	printf("暂不支持反常积分的运算(结果是错的)，所以输入区间时请考虑定义域\n");
	printf("请选择你要划分的区间数量(正整形范围内):");
}
//定矩形分割求积分
void Rectangle(double& LeftEdge,double& RightEdge,int& BlockAmount,std::string& choice)
{
	while (true)
	{
		printf("这里是定长矩形划分积分法：\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("请输入所积分函数的左右区间：(空格或者回车分割)");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans=Rectangle(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n计算结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//梯形法分割求积分
void Trapezium(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice)
{
	while (true)
	{
		printf("这里是梯形分割积分法：\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("请输入所积分函数的左右区间(空格或者回车分割):");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans = Trapezium(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n计算结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//辛普森法求积分
void SimpsonIntegral(double& LeftEdge, double& RightEdge, int& BlockAmount, std::string& choice)
{
	while (true)
	{
		printf("这里是辛普森积分法：\n");
		Statement();
		if (CheckForPositiveSingleInput(BlockAmount)) {
			continue;
		}
		printf("请输入所积分函数的左右区间：(空格或者回车分割)");
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		double ans = Simpson_Integral(LeftEdge, RightEdge, BlockAmount, work_function_1);
		std::cout << "\n计算结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
		IsInputAgain(choice);
		if (choice != "1")
			break;
	}
}
//对称差分法求微分(导数)
void SymmetricDifference(std::string& choice)
{
	while (true) {
		printf("这里是对称差分法求微分：\n");
		printf("所求函数为f(x)=x/1+x^2\n");
		printf("请注意定义域(否则结果是未知的)\n");
		printf("请输入要计算的那一点:\n");
		double point;
		if (!(std::cin >>point)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		double ans = Symmetric_Difference(point, Eps, work_function_1);
		std::cout << "\nf(x)在("<<point<<",f("<<point<<"))导数的计算结果为:" << ans;
		printf("\n是否继续计算其他数据？(输入1继续，其他则退出返回上一层：)\n");
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
		//左右端点
		double LeftEdge = 0, RightEdge = 0;
		//不动点迭代法的交点,同时也可以作为牛顿法的初始条件判断
		double Intersection = 0;
		//迭代次数
		int IterateNum = 0;
		printf("\t\t\t\t这里是解方程模块\n");
		printf("\t\t*************************************************\n");
		printf("\t\t*		  [1].二分法求解	   	*\n");
		printf("\t\t*		  [2].不动点迭代法		*\n");
		printf("\t\t*		  [3].弦截法求解		*\n");
		printf("\t\t*		  [4].牛顿迭代法		*\n");
		printf("\t\t*		  [5].黄金比率分割		*\n");
		printf("\t\t*		  [0].返回上一层		*\n");
		printf("\t\t*************************************************\n");
		printf("第四次作业集成在了里面，因此5个功能就是对应课件函数的实现，暂仅支持答案的显示\n");
		printf("请选择你想使用的功能：");
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
//二分法求方程解
void Dichotomy(double& LeftEdge, double& RightEdge, int& IterateNum)
{
	while (true) {
		std::cout
			<< "这里是函数f(x)=x^3-6x-1的二分零点估计模块\n"
			<< "请输入拟估计的解区间(建议输入1与3否则可能会得到另外一个根):\n";
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		std::cout << "请输入二分求解的最大迭代次数：(正整形范围内)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = Dichotomy(LeftEdge, RightEdge, _EPS, IterateNum,f1);
		std::cout << "\n估计的方程解为" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//不动点迭代法求方程解
void FixedPointIteration(double& Intersection, int& IterateNum)
{
	while(true){
		std::cout
			<< "这里是函数f(x)=x^3+2x^2+2x+1的不动点迭代估计模块\n"
			<< "请输入拟估计的初始值：\n";
		if (!(std::cin >>Intersection)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ShowReInput();
			continue;
		}
		std::cout << "请输入不动点求解的最大迭代次数：(正整形范围内)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res =FixedPointIteration(Intersection, _EPS, IterateNum, f2);
		std::cout << "\n估计的方程解为" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//弦截法求方程解
void SecantMethod(double& LeftEdge, double& RightEdge, int& IterateNum)
{
	while (true){
		std::cout
			<< "这里是函数f(x)=x^3-2x^2+7x+4的弦截法估计模块\n"
			<< "请输入拟估计的解区间：\n";
		if (CheckForEdgeInput(LeftEdge, RightEdge)) {
			continue;
		}
		std::cout << "请输入弦截法求解的最大迭代次数：(正整形范围内)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = SecantMethod(LeftEdge, RightEdge, _EPS, IterateNum, f3);
		std::cout << "\n估计的方程解为" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//牛顿法求方程解
void NewtonIterate(double& Intersection, int& IterateNum)
{
	while (true) {
		Intersection = 0;
		std::cout << "这里是函数f(x)=x^3-2x^2+7x+4的牛顿法估计模块\n";
		std::cout << "由于题目给出了求0点出的近似值，这里就不需要用户输入初始值\n";
		std::cout << "请输入牛顿法求解的最大迭代次数：(正整形范围内)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = NewtonIterate(Intersection, _EPS, IterateNum, f4,ff4);
		std::cout << "\n估计的方程解为" << res << std::endl;
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
//黄金分割法求方程解
void GoldenRatio(int& IterateNum) 
{
	while (true) {
		double LeftEdge = 0, RightEdge = 4;
		std::cout
			<< "这里是函数f(x)=x^2-4x+4的黄金分割估计最小值模块\n"
			<< "请输入拟估计的解区间(题目已给出为[0,4],故不予输入)\n";
		std::cout << "请输入黄金分割法求解的最大迭代次数：(正整形范围内)";
		if (CheckForPositiveSingleInput(IterateNum)) {
			continue;
		}
		double res = GoldenRatio(LeftEdge, RightEdge, _EPS, IterateNum, f5);
		res = f5(res);
		if (res <= _EPS) {
			std::cout << "\n估计的最小值为0\n";
		}else {
			std::cout << "\n估计的最小值为" << res << std::endl;
		}
		(void)getchar();
		system("pause");
		system("CLS");
		break;
	}
}
