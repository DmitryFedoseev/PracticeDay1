#include <iostream>
#include <locale>
using namespace std;

void IRoundShiftMas(int* source, int n, int size);
void TestIRoundShiftMas(int n, int size);

int main()
{
	setlocale(LC_ALL, "Russian");


	const int size = 10;
	int source[size];
	srand(time(NULL));									   

	cout << "Исходный массив:\t";
	for (int i = 0; i < size; i++)						   
	{
		source[i] = rand()%100;
		cout << source[i] << " ";
	}
	cout << endl;

	int n;
	cout << "Введите число n на которое нужно сдвинуть массив влево:\t";
	cin >> n;

	IRoundShiftMas(source, n, size);

	cout << "Преобразованный массив:\t";
	for (int i = 0; i < size; i++)
		cout << source[i] << " ";
	cout << endl;

	cout << "Результат теста:\t";
	TestIRoundShiftMas(n, size);

	return 0;
}

void IRoundShiftMas(int* source, int n, int size)
{
	while (n > 0)
	{
		int a;
		a = source[0];
		for (int i = 0; i < size; i++)
			source[i] = source[i + 1];
		
		source[size - 1] = a;
		n--;
	}
}

void TestIRoundShiftMas(int n, int size)
{
	if (n < 0 || size <= 0)
		cout << "Ошибка" << endl;
	else
		cout << "Успех" << endl;
}