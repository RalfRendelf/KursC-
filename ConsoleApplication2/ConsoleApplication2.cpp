// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int recfunc(long stpznach, int stp, long stpkontr, bool f);

int main()
{
	int numOfMembers;
	cin >>  numOfMembers;
	
	vector<int> stepeni;
	for (int i = 0; i < numOfMembers; ++i)
	{
		int stp = 65536, chln;
		long chslo = 16;
		cin >> chln;
		if (chln > stp)
		{
			stepeni.push_back(recfunc(stp*2, chslo+1, chln, false));
		}
		else
		{
			stepeni.push_back(recfunc(stp/2, chslo-1, chln, true));
		}
	}
	for (auto a : stepeni)
	{
		cout << a << '\n';
	}
	return 0;
	
}

int recfunc(long stpznach, int stp, long stpkontr, bool f)
{
	if (f) {
		if (stpkontr < stpznach)
			return stp;
		else
		{
			return recfunc(stpznach / 2, stp - 1, stpkontr,true);
		}
	}
	else
	{
		if (stpkontr < stpznach)
			return stp-1;
		else
		{
			return recfunc(stpznach * 2, stp + 1, stpkontr, 0);
		}
	}
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
