// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void rotate(int a[], unsigned size, int shift);
unsigned gcd(unsigned a, unsigned b);
void strcat1(char* to, const char* from);
unsigned strlen1(const char* str);
int strstr1(const char* text, const char* pattern);

int main()
{
	//cout << gcd(0, 45);
	/*int arr[5] = { 1,2,3,4,5 };
	rotate(arr, 5, 13);
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i];
	}*/
	char str[50] = "same old song";
	/*cout << strlen1(str);*/
	char str2[] = "ffff as d sdse";
	strcat1(str, str2);
	for(auto a: str)
	{
		cout << a;
	}
	cout << '1';
	strstr();
	return 0;
	
}

unsigned recfunc(unsigned a, unsigned b, unsigned mod)
{
	if(a%mod == 0 && b%mod == 0)

	return mod;
	return recfunc(a, b, mod - 1);

	
	
	}
unsigned gcd(unsigned a, unsigned b)
{
	unsigned mod;
	if (a == 0 || b == 0)
		return (a > b ? a : b);
	if (a > b)
	{
		mod = recfunc(a, b,b);

	}
	else
	{
		mod = recfunc(b, a, a);
	}
	return mod;
}
void rotate(int a[], unsigned size, int shift)
{
	int shiftrez = size - (shift % size);
	
	
	
	int sdvg, sdvg2;
	if (shiftrez == 0)
	{
		
	}
	else {
		for (int i = 0; i < shiftrez; ++i)
		{
			
				sdvg2 = a[0];
			
			
			for (int g = 0; g < size; ++g)
			{
				if (g % 2 == 0) {
					sdvg = a[(g + 1) % size];
					a[(g + 1)%size] = sdvg2;
					
				}
				else
				{
					sdvg2 = a[(g + 1) % size];
					a[(g + 1) % size] = sdvg;
					

				}
			}
		}
	}


}
unsigned strlen1(const char* str)
{
	unsigned strlen=0;
	
	while (*(str + strlen) != '\0')
	{
		 
		++strlen;
	}

	return strlen;

}
void strcat1(char* to, const char* from)
{
	int lengthofstr = 0;
	int lengthofstr2 = 0;
	while (*(to + lengthofstr) != '\0')
	{
		lengthofstr++;

	}
	while (*(from + lengthofstr2) != '\0')
	{
		*(to + lengthofstr++) = *(from + lengthofstr2++);

	}
	*(to + lengthofstr) = '\0';


}
int strstr1(const char* text, const char* pattern)
{
	
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
