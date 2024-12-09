#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//Day1 2024.12.06
//author:Alan
//version:1.0

//1.主函数介绍
////main函数是程序的入口
//一个工程中main函数有且仅有一个
//int main() {
//
//	printf("Hello world!");
//
//	return 0;
//}
//int main(int argc, char* argv[]) {//在指定main函数里的参数
//	printf("Hello world!");
//
//	return 0;
//}

//2.数据类型
//int main() {
//	printf("%d\n", sizeof(char));      //字符数据类型
//	printf("%d\n", sizeof(short));     //短整型数据类型
//	printf("%d\n", sizeof(int));       //整型数据类型
//	printf("%d\n", sizeof(long));      //长整型数据类型
//	printf("%d\n", sizeof(long long)); //长长整型数据类型
//	printf("%d\n", sizeof(float));     //单精度浮点型数据类型
//	printf("%d\n", sizeof(double));    //双精度浮点型数据类型
//	//C语言标准：sizeof(long long) >= sizeof(long) >= sizeof(int) > sizeof(short) > sizeof(char)
//	
//	//为什么出现这么的类型？ 类型是为了创建变量 -> 为了合理分配计算机存储空间。
//  //注意：存在这么多的类型，其实是为了更加丰富的表达生活中的各种值。
// 
//	//计算机的存储单位：bit(比特）byte(字节）KB MB GB TB PB  1024 = 2^10
//	//1byte = 8bit 1KB = 1024byte 1MB = 1024KB 1GB = 1024MB  1TB = 1024GB 1PB = 1024TB
//}

//3.变量与常量
//生活中的有些值是不变的（比如：圆周率，性别，身份证号码，血型等等）
//有些值是可变的（比如：年龄，体重，薪资）。
//不变的值，C语言中用常量的概念来表示，变得值C语言中用变量来表示。
//3.1 定义变量的方法
//int main() {
//
//	int age = 150;
//	float weight = 45.5f;
//	char ch = 'w';
//
//	return  0;
//}

//3.2 变量的命名
//1、C语言规定，变量名的第一个字符必须是字母或者下划线，其后的字符必须是字母、数字或下划线，这不仅适用于变量名，而且适用于函数名、数组名、类型名等；
//2、大小写敏感；
//3、变量名的长度不是无限的，C语言标准没有规定变量名的长度，不同的C编译系统都有自己的规定，
//过去有一些C系统只允许变量名包含8个字符，现在使用的C编译系统都允许变量名的最大长度为32个字符甚至更多；
//4、变量名尽量简单易记、见名之意；
//5、在同一程序的同一函数中，不同的变量不能取相同的变量名，以免混淆；
//6、变量必须“先定义后使用”：
//6.1、根据定义变量时指定的类型，编译系统会为变量分配相应的存储单元；
//6.2、凡未被事先定义的，系统不把它认作变量名，这就保证了程序中的变量名使用的正确性；
//6.3、指定了每一个变量属于一个类型，便于在编译时据此检查程序中进行某些运算的合法性，
//如 % 是“求余”，如果两个实数型a和b，他们是不可以进行求余的。

//3.3 变量的分类
//局部变量和全局变量
//int global = 2024;//全局变量
//
//int main() {
//
//	int global = 2022;//局部变量
//	//下面定义的global会不会有问题？
//	printf("global = %d\n", global);
//
//	return 0;
//}
//总结：
//上面的局部变量global变量的定义其实没有什么问题的！
//当局部变量和全局变量同名的时候，局部变量优先使用。

//3.4 变量的使用
//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("输入两个操作数:>");
//    scanf("%d %d", &num1, &num2);
//    sum = num1 + num2;
//    printf("sum = %d\n", sum);
//    return 0;
//}
//这里介绍一下输入，输出语句
//scanf  输入内容
//printf 输出内容

//Day2 2024.12.07
//author:Alan
//version:1.0

//3.5 变量的作用域和生命周期
//作用域（scope）是程序设计概念，通常来说，一段程序代码中所
// 用到的名字并不总是有效 / 可用的而限定这个名字的可用性的代码范围
//就是这个名字的作用域。
//1. 局部变量的作用域是变量所在的局部范围。
//2. 全局变量的作用域是整个工程。
//生命周期: 变量的生命周期指的是变量的创建到变量的销毁之间的一个时间段
//1. 局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束。
//2. 全局变量的生命周期是：整个程序的生命周期。

//3.6常量
//C语言中的常量和变量的定义的形式有所差异。
//C语言中的常量分为以下以下几种：
//1.字面常量 2.const 修饰的常变量 3.#define 定义的标识符常量 4.枚举常量
//举例：
//enum Sex
//{
//	Male,
//	Female,
//	Select
//};
//括号中的Male,Female,Select是枚举常量
//int main() {
//	//字面常量演示
//	3.14;
//	1000;
//
//	//const 修饰的常变量
//	const float pai = 3.14f;
//	//pai = 5.15;  //报错
//	
//	//#define的标识符常量 
//	#define MAX 100
//	printf("max  = %d\n", MAX);
//
//	//枚举常量
//	printf("%d\n", Male);
//	printf("%d\n", Female);
//	printf("%d\n", Select);
//	//注：枚举常量的默认是从0开始，依次向下递增1的
//
//	return 0;
//}
//上面例子上的 pai 被称为 const 修饰的常变量, const 修饰的常变量在C语言中只是在语法层面限制了
//变量 pai 不能直接被改变，但是 pai 本质上还是一个变量的，所以叫常变量。

//4. 字符串+转义字符+注释
//4.1 字符串
// 字符串的结束标志是一个 \0 的转义字符。
// 在计算字符串长度的时候 \0 是结束标志，不算作字符串内容。

//下面代码，打印结果是什么？为什么？（突出'\0'的重要性）
//int main()
//{
//    char arr1[] = "bit";
//    char arr2[] = { 'b', 'i', 't' }; //会出现乱码
//    char arr3[] = { 'b', 'i', 't', '\0' };
//    printf("%s\n", arr1);
//    printf("%s\n", arr2);
//    printf("%s\n", arr3);
//    return 0;
//}

//4.2 转义字符
//我们要在屏幕上打印一个目录： c : \code\test.c
//错误的
//int main()
//{
//    printf("c:\code\test.c\n");
//    return 0;
//}
//正确的
//int main() {
//    printf("c:\code\\test.c\n");
//}
//转义字符 释义
//  \ ? 在书写连续多个问号时使用，防止他们被解析成三字母词
//  \' 用于表示字符常量'
//  \“ 用于表示一个字符串内部的双引号
//  \\ 用于表示一个反斜杠，防止它被解释为一个转义序列符。
//  \a 警告字符，蜂鸣
//  \b 退格符
//  \f 进纸符
//  \n 换行
//  \r 回车
//  \t 水平制表符
//  \v 垂直制表符
//  \ddd ddd表示1~3个八进制的数字。 如： \130 X 
// 字符的八进制表示形式 1  3  0 = 8^2 * 1 + 8^1 * 3 +8^0 * 0 = 88->对应的ASCII码为 X
//  \xdd dd表示2个十六进制数字。 如： \x30 0
// 字符的十六进制表示形式  3 0 = 16^1 * 3 + 16^0 * 0 = 48 ->对应的ASCII码值为 0
//#include <stdio.h>
//int main()
//{
//    //问题1：在屏幕上打印一个单引号'，怎么做？
//    //问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
//    printf("%c\n", '\'');
//    printf("%s\n", "\"");
//    return 0;
//}
//程序输出什么？
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    printf("%d\n", strlen("abcdef"));
//    // \62被解析成一个转义字符
//    printf("%d\n", strlen("c:\test\628\test.c"));
//    return 0;
//}

//5. 注释
//1. 代码中有不需要的代码可以直接删除，也可以注释掉
//2. 代码中有些代码比较难懂，可以加一下注释文字
//注释有两种风格：
//C语言风格的注释 /*xxxxxx*/
//缺陷：不能嵌套注释
//C++风格的注释 //xxxxxxxx
//可以注释一行也可以注释多行

//c语言 -> 结构化的程序设计语言
// 顺序结构 
// 选择结构 if else switch case default 
// 循环结构 for while do-while break continue goto

//6.选择结构
//#include <stdio.h>
//int main()
//{
//    int coding = 0;
//    printf("你会去敲代码吗？（选择1 or 0）:>");
//    scanf("%d", &coding);
//    if (coding == 1)
//    {
//        printf("坚持，你会有好offer\n");
//    }
//    else
//    {
//        printf("放弃，回家卖红薯\n");
//    }
//    return 0;
//}

//循环结构 ：有些事必须一直做，比如大学生，日复一日的学习。
// C语言中如何实现循环呢？
// while语句  for语句 do ... while语句
//while循环的实例
//int main()
//{
//    printf("加入东软\n");
//    int line = 0;
//    while (line <= 20000)
//    {
//        line++;
//        printf("我要继续努力敲代码\n");
//    }
//    if (line > 20000)
//        printf("好offer\n");
//    return 0;
//}

//函数：函数是一个可重复使用的代码块，用于执行特定的任务。
//函数可以帮助我们组织和模块化代码，使其更易于理解和维护。通过将代码
//分解成多个函数，我们可以实现代码的重用性，并且可以通过调用函数来执行特定的操作。
//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("输入两个操作数:>");
//    scanf("%d %d", &num1, &num2);
//    sum = num1 + num2;
//    printf("sum = %d\n", sum);
//    return 0;
//}
//上述代码，写成函数如下：
//#include <stdio.h>
//int Add(int x, int y)
//{
//    int z = x + y;
//    return z;
//}
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("输入两个操作数:>");
//    scanf("%d %d", &num1, &num2);
//    sum = Add(num1, num2);
//    printf("sum = %d\n", sum);
//    return 0;
//}
//函数的特点就是简化代码，代码复用。

//Day3 2024.12.08
//author:Alan
//version:1.0
//1.数组

//1.1数组的定义
//定义一个整形数组，最多放10个元素
//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

//1.2数组的下标
//C语言规定：数组的每个元素都有一个下标，下标是从0开始的。
//数组可以通过下标来访问的。
//int arr[10] = { 0 };
//如果数组10个元素，下标的范围是0-9

//1.3数组的使用
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//2.操作符
//算术操作符 + - * / %
//移位运行符 >> << 
//位运算 $ ^ |
//赋值操作符 = += -= /= %= ^= |= >>= <<=

//单目操作符
//!      逻辑反操作
//-      负值
//+      正值
//&      取地址
//sizeof 操作数的类型长度（以字节为单位）
//~	   对一个数的二进制按位取反
//--     前置、后置--
//++	   前置、后置++
//*      间接访问操作符(解引用操作符)
//(类型) 强制类型转换

//关系运算符
//>
//>=
//<
//<=
//!=  用于测试“不相等”
//==  用于测试“相等”

//逻辑运算符
//&&  逻辑与
//||  逻辑或

//条件运算符
//exp1 ? exp2 : exp3

//逗号表达式
//exp1, exp2, exp3, …expN

//下标引用、函数调用和结构成员
//[] () . ->

//3.常见的关键字
//C语言提供了丰富的关键字，
//这些关键字都是语言本身预先设定好的，用户自己是不能创造关键字的。

//3.1typedef 顾名思义是类型定义，这里应该理解为类型重命名
//typedef unsigned int uint_32;
//
//int main()
//{
//	//观察num1和num2,这两个变量的类型是一样的
//	unsigned int num1 = 0;
//	uint_32 num2 = 0;
//	return 0;
//}

//3.2static
//在C语言中：static是用来修饰变量和函数的
//1. 修饰局部变量 - 称为静态局部变量
//2. 修饰全局变量 - 称为静态全局变量
//3. 修饰函数 - 称为静态函数

//void test()
//{
//	//static修饰局部变量
//	static int num = 0;
//    num++;
//    printf("num = %d\n", num);
//}
//
//int main()
//{
//	int i = 0;
//	for (int i = 0; i < 10; i++) {
//		test();
//	}
//	return 0;
//}
//结论：static修饰局部变量改变了变量的生命周期
//让静态局部变量出了作用域依然存在，到程序结束，生命周期才结束。

////代码1
////add.c
//int g_val = 2018;
////test.c
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}
////代码2
////add.c
//static int g_val = 2018;
////test.c
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}
//结论：一个全局变量被static修饰，使得这个全局变量只能在本源文件内使用，
//不能在其他源文件内使用。

//代码1
 //add.c
//int Add(int x, int y)
//{
//	return x + y;
//}
////test.c
//int main()
//{
//	printf("%d\n", Add(2, 3));
//	return 0;
//}
////代码2
// //add.c
//static int Add(int x, int y)
//{
//	return x + y;
//}
////test.c
//int main()
//{
//	printf("%d\n", Add(2, 3));
//	return 0;
//}
//结论：一个函数被static修饰，使得这个函数只能在本源文件内使用，
//不能在其他源文件内使用。

//3.3 define
//define定义标识符常量
//#define MAX 1000

//define定义宏
//#define ADD(x,y) ((x) +(y))
//
//int main()
//{
//	int sum = ADD(2, 3);
//	printf("sum = %d\n", sum);
//	sum = 10 * ADD(2, 3);
//	printf("sum = %d\n", sum);
//
//	return 0;
//}

//4.指针
//1.为了能够有效的访问到内存的每个单元，就给内存单元进行了编号，
// 这些编号被称为该内存单元的地址。(即指针)

//int main()
//{
//	int num = 0;
//	&num; //取出num的地址
//	//注：这里num的4个字节，每个字节都有地址，
//	//取出的是第一个字节的地址（较小的地址）
//	printf("num的地址为：%p\n", &num);
//    return 0;
//}

//2.指针变量
//int main()
//{
//	int num = 10;
//	int* p = &num;
//    *p = 20;
//	printf("num的地址为：%p\n", p);
//    printf("num的值为：%d\n", num);
//	return 0;
//}

//以整形指针举例，可以推广到其他类型，如：
//int main()
//{
//	char ch = 'A';
//	char* pc = &ch;
//	*pc = 'B';
//    printf("ch的数值为：%c\n", ch);
//	printf("ch的地址值为：%p\n", pc);
//    return 0;
//}

//3.指针大小
//指针变量的大小取决于地址的大小
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）

//int main()
//{
//	printf("%zu\n", sizeof(char*));
//	printf("%zu\n", sizeof(short*));
//	printf("%zu\n", sizeof(int*));
//	printf("%zu\n", sizeof(long long*));
//	printf("%zu\n", sizeof(float*));
//	printf("%zu\n", sizeof(double*));
//	printf("%zu\n", sizeof(long double*));
//	printf("%zu\n", sizeof(void*));
//
//	return 0;
//}
//结论：指针大小在32位平台是4个字节，64位平台是8个字节.

//5.结构体
//结构体是C语言中特别重要的知识点，结构体使得C语言有能力描述复杂类型。

//比如描述学生，学生包含：名字 + 年龄 + 性别 + 学号这几项信息。
//使用结构体描述学生：
//struct Student
//{
//	char name[32]; //名字
//	int age;       //年龄
//	char gender[4];   //性别
//	char id[15];   //学号
//};
//
//int main()
//{
//	// 打印结构体信息
//	struct Student student1 = {"Alan",22, "man","22216920213"};
//
//	//.为结构成员访问操作符
//	printf("student1的名字是：%s\n", student1.name);
//    printf("student1的年龄是：%d\n", student1.age);
//    printf("student1的性别是：%s\n", student1.gender);
//    printf("student1的学号是：%s\n", student1.id);
//
//	//->操作符
//    struct Student* pStudent = &student1;
//	printf("student1的名字是：%s\n", pStudent->name);
//    printf("student1的年龄是：%d\n", pStudent->age);
//    printf("student1的性别是：%s\n", pStudent->gender);
//    printf("student1的学号是：%s\n", pStudent->id);
//
//	return 0;
//}








