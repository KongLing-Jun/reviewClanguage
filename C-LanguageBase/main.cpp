#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//Day1 2024.12.06
//author:Alan
//version:1.0

//1.����������
////main�����ǳ�������
//һ��������main�������ҽ���һ��
//int main() {
//
//	printf("Hello world!");
//
//	return 0;
//}
//int main(int argc, char* argv[]) {//��ָ��main������Ĳ���
//	printf("Hello world!");
//
//	return 0;
//}

//2.��������
//int main() {
//	printf("%d\n", sizeof(char));      //�ַ���������
//	printf("%d\n", sizeof(short));     //��������������
//	printf("%d\n", sizeof(int));       //������������
//	printf("%d\n", sizeof(long));      //��������������
//	printf("%d\n", sizeof(long long)); //����������������
//	printf("%d\n", sizeof(float));     //�����ȸ�������������
//	printf("%d\n", sizeof(double));    //˫���ȸ�������������
//	//C���Ա�׼��sizeof(long long) >= sizeof(long) >= sizeof(int) > sizeof(short) > sizeof(char)
//	
//	//Ϊʲô������ô�����ͣ� ������Ϊ�˴������� -> Ϊ�˺������������洢�ռ䡣
//  //ע�⣺������ô������ͣ���ʵ��Ϊ�˸��ӷḻ�ı��������еĸ���ֵ��
// 
//	//������Ĵ洢��λ��bit(���أ�byte(�ֽڣ�KB MB GB TB PB  1024 = 2^10
//	//1byte = 8bit 1KB = 1024byte 1MB = 1024KB 1GB = 1024MB  1TB = 1024GB 1PB = 1024TB
//}

//3.�����볣��
//�����е���Щֵ�ǲ���ģ����磺Բ���ʣ��Ա�����֤���룬Ѫ�͵ȵȣ�
//��Щֵ�ǿɱ�ģ����磺���䣬���أ�н�ʣ���
//�����ֵ��C�������ó����ĸ�������ʾ�����ֵC�������ñ�������ʾ��
//3.1 ��������ķ���
//int main() {
//
//	int age = 150;
//	float weight = 45.5f;
//	char ch = 'w';
//
//	return  0;
//}

//3.2 ����������
//1��C���Թ涨���������ĵ�һ���ַ���������ĸ�����»��ߣ������ַ���������ĸ�����ֻ��»��ߣ��ⲻ�������ڱ����������������ں����������������������ȣ�
//2����Сд���У�
//3���������ĳ��Ȳ������޵ģ�C���Ա�׼û�й涨�������ĳ��ȣ���ͬ��C����ϵͳ�����Լ��Ĺ涨��
//��ȥ��һЩCϵͳֻ��������������8���ַ�������ʹ�õ�C����ϵͳ����������������󳤶�Ϊ32���ַ��������ࣻ
//4���������������׼ǡ�����֮�⣻
//5����ͬһ�����ͬһ�����У���ͬ�ı�������ȡ��ͬ�ı����������������
//6���������롰�ȶ����ʹ�á���
//6.1�����ݶ������ʱָ�������ͣ�����ϵͳ��Ϊ����������Ӧ�Ĵ洢��Ԫ��
//6.2����δ�����ȶ���ģ�ϵͳ��������������������ͱ�֤�˳����еı�����ʹ�õ���ȷ�ԣ�
//6.3��ָ����ÿһ����������һ�����ͣ������ڱ���ʱ�ݴ˼������н���ĳЩ����ĺϷ��ԣ�
//�� % �ǡ����ࡱ���������ʵ����a��b�������ǲ����Խ�������ġ�

//3.3 �����ķ���
//�ֲ�������ȫ�ֱ���
//int global = 2024;//ȫ�ֱ���
//
//int main() {
//
//	int global = 2022;//�ֲ�����
//	//���涨���global�᲻�������⣿
//	printf("global = %d\n", global);
//
//	return 0;
//}
//�ܽ᣺
//����ľֲ�����global�����Ķ�����ʵû��ʲô����ģ�
//���ֲ�������ȫ�ֱ���ͬ����ʱ�򣬾ֲ���������ʹ�á�

//3.4 ������ʹ��
//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("��������������:>");
//    scanf("%d %d", &num1, &num2);
//    sum = num1 + num2;
//    printf("sum = %d\n", sum);
//    return 0;
//}
//�������һ�����룬������
//scanf  ��������
//printf �������

//Day2 2024.12.07
//author:Alan
//version:1.0

//3.5 ���������������������
//������scope���ǳ�����Ƹ��ͨ����˵��һ�γ����������
// �õ������ֲ���������Ч / ���õĶ��޶�������ֵĿ����ԵĴ��뷶Χ
//����������ֵ�������
//1. �ֲ��������������Ǳ������ڵľֲ���Χ��
//2. ȫ�ֱ��������������������̡�
//��������: ��������������ָ���Ǳ����Ĵ���������������֮���һ��ʱ���
//1. �ֲ����������������ǣ������������������ڿ�ʼ�����������������ڽ�����
//2. ȫ�ֱ��������������ǣ�����������������ڡ�

//3.6����
//C�����еĳ����ͱ����Ķ������ʽ�������졣
//C�����еĳ�����Ϊ�������¼��֣�
//1.���泣�� 2.const ���εĳ����� 3.#define ����ı�ʶ������ 4.ö�ٳ���
//������
//enum Sex
//{
//	Male,
//	Female,
//	Select
//};
//�����е�Male,Female,Select��ö�ٳ���
//int main() {
//	//���泣����ʾ
//	3.14;
//	1000;
//
//	//const ���εĳ�����
//	const float pai = 3.14f;
//	//pai = 5.15;  //����
//	
//	//#define�ı�ʶ������ 
//	#define MAX 100
//	printf("max  = %d\n", MAX);
//
//	//ö�ٳ���
//	printf("%d\n", Male);
//	printf("%d\n", Female);
//	printf("%d\n", Select);
//	//ע��ö�ٳ�����Ĭ���Ǵ�0��ʼ���������µ���1��
//
//	return 0;
//}
//���������ϵ� pai ����Ϊ const ���εĳ�����, const ���εĳ�������C������ֻ�����﷨����������
//���� pai ����ֱ�ӱ��ı䣬���� pai �����ϻ���һ�������ģ����Խг�������

//4. �ַ���+ת���ַ�+ע��
//4.1 �ַ���
// �ַ����Ľ�����־��һ�� \0 ��ת���ַ���
// �ڼ����ַ������ȵ�ʱ�� \0 �ǽ�����־���������ַ������ݡ�

//������룬��ӡ�����ʲô��Ϊʲô����ͻ��'\0'����Ҫ�ԣ�
//int main()
//{
//    char arr1[] = "bit";
//    char arr2[] = { 'b', 'i', 't' }; //���������
//    char arr3[] = { 'b', 'i', 't', '\0' };
//    printf("%s\n", arr1);
//    printf("%s\n", arr2);
//    printf("%s\n", arr3);
//    return 0;
//}

//4.2 ת���ַ�
//����Ҫ����Ļ�ϴ�ӡһ��Ŀ¼�� c : \code\test.c
//�����
//int main()
//{
//    printf("c:\code\test.c\n");
//    return 0;
//}
//��ȷ��
//int main() {
//    printf("c:\code\\test.c\n");
//}
//ת���ַ� ����
//  \ ? ����д��������ʺ�ʱʹ�ã���ֹ���Ǳ�����������ĸ��
//  \' ���ڱ�ʾ�ַ�����'
//  \�� ���ڱ�ʾһ���ַ����ڲ���˫����
//  \\ ���ڱ�ʾһ����б�ܣ���ֹ��������Ϊһ��ת�����з���
//  \a �����ַ�������
//  \b �˸��
//  \f ��ֽ��
//  \n ����
//  \r �س�
//  \t ˮƽ�Ʊ���
//  \v ��ֱ�Ʊ���
//  \ddd ddd��ʾ1~3���˽��Ƶ����֡� �磺 \130 X 
// �ַ��İ˽��Ʊ�ʾ��ʽ 1  3  0 = 8^2 * 1 + 8^1 * 3 +8^0 * 0 = 88->��Ӧ��ASCII��Ϊ X
//  \xdd dd��ʾ2��ʮ���������֡� �磺 \x30 0
// �ַ���ʮ�����Ʊ�ʾ��ʽ  3 0 = 16^1 * 3 + 16^0 * 0 = 48 ->��Ӧ��ASCII��ֵΪ 0
//#include <stdio.h>
//int main()
//{
//    //����1������Ļ�ϴ�ӡһ��������'����ô����
//    //����2������Ļ�ϴ�ӡһ���ַ������ַ�����������һ��˫���š�����ô����
//    printf("%c\n", '\'');
//    printf("%s\n", "\"");
//    return 0;
//}
//�������ʲô��
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    printf("%d\n", strlen("abcdef"));
//    // \62��������һ��ת���ַ�
//    printf("%d\n", strlen("c:\test\628\test.c"));
//    return 0;
//}

//5. ע��
//1. �������в���Ҫ�Ĵ������ֱ��ɾ����Ҳ����ע�͵�
//2. ��������Щ����Ƚ��Ѷ������Լ�һ��ע������
//ע�������ַ��
//C���Է���ע�� /*xxxxxx*/
//ȱ�ݣ�����Ƕ��ע��
//C++����ע�� //xxxxxxxx
//����ע��һ��Ҳ����ע�Ͷ���

//c���� -> �ṹ���ĳ����������
// ˳��ṹ 
// ѡ��ṹ if else switch case default 
// ѭ���ṹ for while do-while break continue goto

//6.ѡ��ṹ
//#include <stdio.h>
//int main()
//{
//    int coding = 0;
//    printf("���ȥ�ô����𣿣�ѡ��1 or 0��:>");
//    scanf("%d", &coding);
//    if (coding == 1)
//    {
//        printf("��֣�����к�offer\n");
//    }
//    else
//    {
//        printf("�������ؼ�������\n");
//    }
//    return 0;
//}

//ѭ���ṹ ����Щ�±���һֱ���������ѧ�����ո�һ�յ�ѧϰ��
// C���������ʵ��ѭ���أ�
// while���  for��� do ... while���
//whileѭ����ʵ��
//int main()
//{
//    printf("���붫��\n");
//    int line = 0;
//    while (line <= 20000)
//    {
//        line++;
//        printf("��Ҫ����Ŭ���ô���\n");
//    }
//    if (line > 20000)
//        printf("��offer\n");
//    return 0;
//}

//������������һ�����ظ�ʹ�õĴ���飬����ִ���ض�������
//�������԰���������֯��ģ�黯���룬ʹ������������ά����ͨ��������
//�ֽ�ɶ�����������ǿ���ʵ�ִ���������ԣ����ҿ���ͨ�����ú�����ִ���ض��Ĳ�����
//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("��������������:>");
//    scanf("%d %d", &num1, &num2);
//    sum = num1 + num2;
//    printf("sum = %d\n", sum);
//    return 0;
//}
//�������룬д�ɺ������£�
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
//    printf("��������������:>");
//    scanf("%d %d", &num1, &num2);
//    sum = Add(num1, num2);
//    printf("sum = %d\n", sum);
//    return 0;
//}
//�������ص���Ǽ򻯴��룬���븴�á�

//Day3 2024.12.08
//author:Alan
//version:1.0
//1.����

//1.1����Ķ���
//����һ���������飬����10��Ԫ��
//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

//1.2������±�
//C���Թ涨�������ÿ��Ԫ�ض���һ���±꣬�±��Ǵ�0��ʼ�ġ�
//�������ͨ���±������ʵġ�
//int arr[10] = { 0 };
//�������10��Ԫ�أ��±�ķ�Χ��0-9

//1.3�����ʹ��
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

//2.������
//���������� + - * / %
//��λ���з� >> << 
//λ���� $ ^ |
//��ֵ������ = += -= /= %= ^= |= >>= <<=

//��Ŀ������
//!      �߼�������
//-      ��ֵ
//+      ��ֵ
//&      ȡ��ַ
//sizeof �����������ͳ��ȣ����ֽ�Ϊ��λ��
//~	   ��һ�����Ķ����ư�λȡ��
//--     ǰ�á�����--
//++	   ǰ�á�����++
//*      ��ӷ��ʲ�����(�����ò�����)
//(����) ǿ������ת��

//��ϵ�����
//>
//>=
//<
//<=
//!=  ���ڲ��ԡ�����ȡ�
//==  ���ڲ��ԡ���ȡ�

//�߼������
//&&  �߼���
//||  �߼���

//���������
//exp1 ? exp2 : exp3

//���ű���ʽ
//exp1, exp2, exp3, ��expN

//�±����á��������úͽṹ��Ա
//[] () . ->

//3.�����Ĺؼ���
//C�����ṩ�˷ḻ�Ĺؼ��֣�
//��Щ�ؼ��ֶ������Ա���Ԥ���趨�õģ��û��Լ��ǲ��ܴ���ؼ��ֵġ�

//3.1typedef ����˼�������Ͷ��壬����Ӧ������Ϊ����������
//typedef unsigned int uint_32;
//
//int main()
//{
//	//�۲�num1��num2,������������������һ����
//	unsigned int num1 = 0;
//	uint_32 num2 = 0;
//	return 0;
//}

//3.2static
//��C�����У�static���������α����ͺ�����
//1. ���ξֲ����� - ��Ϊ��̬�ֲ�����
//2. ����ȫ�ֱ��� - ��Ϊ��̬ȫ�ֱ���
//3. ���κ��� - ��Ϊ��̬����

//void test()
//{
//	//static���ξֲ�����
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
//���ۣ�static���ξֲ������ı��˱�������������
//�þ�̬�ֲ�����������������Ȼ���ڣ�������������������ڲŽ�����

////����1
////add.c
//int g_val = 2018;
////test.c
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}
////����2
////add.c
//static int g_val = 2018;
////test.c
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}
//���ۣ�һ��ȫ�ֱ�����static���Σ�ʹ�����ȫ�ֱ���ֻ���ڱ�Դ�ļ���ʹ�ã�
//����������Դ�ļ���ʹ�á�

//����1
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
////����2
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
//���ۣ�һ��������static���Σ�ʹ���������ֻ���ڱ�Դ�ļ���ʹ�ã�
//����������Դ�ļ���ʹ�á�

//3.3 define
//define�����ʶ������
//#define MAX 1000

//define�����
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

//4.ָ��
//1.Ϊ���ܹ���Ч�ķ��ʵ��ڴ��ÿ����Ԫ���͸��ڴ浥Ԫ�����˱�ţ�
// ��Щ��ű���Ϊ���ڴ浥Ԫ�ĵ�ַ��(��ָ��)

//int main()
//{
//	int num = 0;
//	&num; //ȡ��num�ĵ�ַ
//	//ע������num��4���ֽڣ�ÿ���ֽڶ��е�ַ��
//	//ȡ�����ǵ�һ���ֽڵĵ�ַ����С�ĵ�ַ��
//	printf("num�ĵ�ַΪ��%p\n", &num);
//    return 0;
//}

//2.ָ�����
//int main()
//{
//	int num = 10;
//	int* p = &num;
//    *p = 20;
//	printf("num�ĵ�ַΪ��%p\n", p);
//    printf("num��ֵΪ��%d\n", num);
//	return 0;
//}

//������ָ������������ƹ㵽�������ͣ��磺
//int main()
//{
//	char ch = 'A';
//	char* pc = &ch;
//	*pc = 'B';
//    printf("ch����ֵΪ��%c\n", ch);
//	printf("ch�ĵ�ֵַΪ��%p\n", pc);
//    return 0;
//}

//3.ָ���С
//ָ������Ĵ�Сȡ���ڵ�ַ�Ĵ�С
//32λƽ̨�µ�ַ��32��bitλ����4���ֽڣ�
//64λƽ̨�µ�ַ��64��bitλ����8���ֽڣ�

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
//���ۣ�ָ���С��32λƽ̨��4���ֽڣ�64λƽ̨��8���ֽ�.

//5.�ṹ��
//�ṹ����C�������ر���Ҫ��֪ʶ�㣬�ṹ��ʹ��C���������������������͡�

//��������ѧ����ѧ������������ + ���� + �Ա� + ѧ���⼸����Ϣ��
//ʹ�ýṹ������ѧ����
//struct Student
//{
//	char name[32]; //����
//	int age;       //����
//	char gender[4];   //�Ա�
//	char id[15];   //ѧ��
//};
//
//int main()
//{
//	// ��ӡ�ṹ����Ϣ
//	struct Student student1 = {"Alan",22, "man","22216920213"};
//
//	//.Ϊ�ṹ��Ա���ʲ�����
//	printf("student1�������ǣ�%s\n", student1.name);
//    printf("student1�������ǣ�%d\n", student1.age);
//    printf("student1���Ա��ǣ�%s\n", student1.gender);
//    printf("student1��ѧ���ǣ�%s\n", student1.id);
//
//	//->������
//    struct Student* pStudent = &student1;
//	printf("student1�������ǣ�%s\n", pStudent->name);
//    printf("student1�������ǣ�%d\n", pStudent->age);
//    printf("student1���Ա��ǣ�%s\n", pStudent->gender);
//    printf("student1��ѧ���ǣ�%s\n", pStudent->id);
//
//	return 0;
//}







