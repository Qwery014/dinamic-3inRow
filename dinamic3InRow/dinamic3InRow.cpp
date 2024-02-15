#include <iostream>
#include <random>
using namespace std;

int threeInRow();

int main() {
	setlocale(LC_ALL, "rus");

	int check = 0;
	int* ptrCheck = &check;


	while (!check)
	{
		threeInRow() ? check = 1 : 0;
	}
	
	return 0;
}

int threeInRow() {
	int horizontal, vertical, line, max;

	cout << "Количество чисел по горизонтали: \n";
	cin >> horizontal;
	cout << "Количество чисел по вертикали: \n";
	cin >> vertical;
	cout << "Количество учёта одинаковых чисел в ряд: \n";
	cin >> line;

	if (line > horizontal || line > vertical)
	{
		cout << "Введены неверные значения" << endl;
		system("pause");
		return 1;
	}

	cout << "Максимальное значения чисел: \n";
	cin >> max;

	// Создание генератора случайных чисел
	random_device rd; // устройство, генерирующее случайные числа
	mt19937 gen(rd()); // генератор Mersenne Twister с начальным значением, полученным из rd()

	int lower_bound = 1;
	int upper_bound = max;
	uniform_int_distribution<> distrib(lower_bound, upper_bound);


	int** arr = new int* [vertical];
	for (int i = 0; i < vertical; ++i) {
		arr[i] = new int[horizontal];
	}

	for (int i = 0; i < vertical; i++) {
		for (int j = 0; j < horizontal; j++) {
			arr[i][j] = distrib(gen);
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			int sameHorizontal = 0;
			int sameVertical = 0;
			int sameDiagonalTop = 0;
			int sameDiagonalBottom = 0;

			for (int k = 0; k < line; k++)
			{
				if (sameDiagonalTop == k && i + k < vertical && j + k < horizontal && arr[i][j] == arr[i + k][j + k])
				{
					sameDiagonalTop += 1;
				}
				if (sameDiagonalBottom == k && i - k >= 0 && j + k < horizontal && arr[i][j] == arr[i - k][j + k])
				{
					sameDiagonalBottom += 1;
				}
				if (sameVertical == k && i + k < vertical && arr[i][j] == arr[i + k][j])
				{
					sameVertical += 1;
				}
				if (sameHorizontal == k && j + k < horizontal && arr[i][j] == arr[i][j + k])
				{
					sameHorizontal += 1;
				}


				if (sameDiagonalTop == line) {
					cout << "Есть по диагонали!" << i << " " << j << endl;
					sameDiagonalTop = 0;
				}
				if (sameDiagonalBottom == line) {
					cout << "Есть по диагонали!" << i << " " << j << endl;
					sameDiagonalBottom = 0;
				}
				if (sameVertical == line)
				{
					cout << "Есть по вертикали!" << i << " " << j << endl;
					sameVertical = 0;
				}
				if (sameHorizontal == line)
				{
					cout << "Есть по горизонтали!" << i << " " << j << endl;
					sameHorizontal = 0;
				}
			}
		}
	}

	int check;
	cout << "\nВведите 0 для повтора или 1 для завершения" << endl;
	cin >> check;

	return check;
}