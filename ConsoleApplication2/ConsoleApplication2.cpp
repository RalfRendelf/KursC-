// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <cstring> 
#include <cstddef>

using namespace std;

void rotate(int a[], unsigned size, int shift);
unsigned gcd(unsigned a, unsigned b);
void strcat1(char* to, const char* from);
unsigned strlen1(const char* str);
int strstr1(const char* text, const char* pattern);
#define strstr strstr1
struct test {
	
	int ret_value;
   const char* text;
	 const char* pattern;
	test(int a, const char* b, const char* c) { ret_value = a; text = b; pattern = c; }
};
test tests[] = {
		{0, "", ""}, //0
		{0, "a", ""}, //1
		{0, "a", "a"}, //2
		{-1, "a", "b"}, //3
		{0, "aa", ""}, //4
		{0, "aa", "a"}, //5
		{0, "ab", "a"}, //6
		{1, "ba", "a"}, //7
		{-1, "bb", "a"}, //8
		{0, "aaa", ""}, //9
		{0, "aaa", "a"}, //10
		{1, "abc", "b"}, //11
		{2, "abc", "c"}, //12
		{-1, "abc", "d"}, //13
		{-1, "a", "aa"}, //14
		{-1, "a", "ba"}, //15
		{-1, "a", "ab"}, //16
		{-1, "a", "bb"}, //17
		{-1, "a", "aaa"}, //18
		{-1, "aa", "aaa"}, //19
		{0, "aaa", "aaa"}, //20
		{0, "aaab", "aaa"}, //21
		{1, "baaa", "aaa"}, //22
		{1, "baaaa", "aaa"}, //23
		{1, "baaab", "aaa"}, //24
		{-1, "abd", "abc"}, //25
		{2, "ababc", "abc"}, //26
		{3, "abdabc", "abc"}, //27
		{-1, "", "a"}, //28
		{2, "asasaf", "asaf"}, //29
		{2, "ababac", "abac"} //30
};

int main()
{
	
	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
		int ret = strstr(tests[i].text, tests[i].pattern);
		(tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
		cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
	}
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
	int lengthoftext = 0;
	int lengthofpattern = 0;
	bool rez = 1;
	while (*(text + lengthoftext) != '\0')
	{
		lengthoftext++;
	}
	while (*(pattern + lengthofpattern) != '\0')
	{
		lengthofpattern++;
	}
	if (lengthofpattern == 0)
	{
		return 0;
}

	else if (lengthofpattern <= lengthoftext)
	{
		int lenght = 0;
		while (*(text + lenght) != '\0')
		{
			if(lengthoftext < lengthofpattern + lenght)
		{
			return -1;
		}
			int length2 = 0;
			rez = 1;
			while (*(pattern + length2) != '\0')
			{
				if(*(text+lenght+length2)!=*(pattern+length2)||lenght+length2>lengthoftext)
				{
					rez = 0;
					break;
				}
				length2++;
			}
			
			if(rez)
			{
				return lenght;
			}
				lenght++;
		}
	}
	else if
		(lengthofpattern > lengthoftext)
	{
		return -1;
	}
	if (!rez)
		return -1;
		

	
}
char* resize(const char* str, unsigned size, unsigned new_size)
{
	
	char* str1;
	str1 = new char[new_size];
	for (auto i = 0; i < size; i++)
	{
		str1[i] = str[i];
	}
	delete[] str;
	return str1;
}

struct String {

	/* Реализуйте этот конструктор */
	String(const char* str = "") {
		
		size = strlen(str)+1;
		this->str = new char[size];
			
			for (auto i = 0; i < size; ++i)
			{
				this->str[i] = str[i];
	}
			this->str[size + 1] = '\0';
			size--;
	}
	String(size_t n, char c) {
		str = new char[n+1];
		for (auto i = 0; i < n; ++i)
		{
			str[i] = c;
		}
		str[n + 1] = '\0';

		

	}

		/* и деструктор */
		~String() {
			delete[] str;
	}

	size_t size;
	char* str;
};


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
