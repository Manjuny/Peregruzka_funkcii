// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*Тема : Функции. Перегрузка функций
Домашнеезадание
Задание 1:
Написать перегруженные функции (int, double, char) для выполнения следующих задач:
Инициализация квадратной матрицы;
Вывод матрицы на экран;
Определение максимального и минимального элемента на главной диагонали матрицы;
Сортировка элементов по возрастанию отдельно для каждой строки матрицы.
Задание 2:
Написать перегруженные функции и протестировать их в основной программе:
Нахождения максимального значения в одномерном массиве;
Нахождения максимального значения в двумерном массиве;
Нахождения максимального значения в трёхмерном массиве;
Нахождения максимального значения двух целых;
Нахождения максимального значения трёх целых;
Задание 3:
Измените программы из первого и второго задания с помощью шаблонов
*/

#include <iostream>

void matrix(int[5][5]);//поленилась для этой дз делать динамический массив
void matrix(double[5][5]);
void matrix(char[5][5]);
void max(int[5][5], int*, int*);//зато сделала указатели))
void max(double[5][5], double*, double*);
void max(char[5][5], char* , char* );
void max_diag(int[5][5], int*, int*);
void max_diag(double[5][5], double*, double*);
void max_diag(char[5][5], char*, char*);
void print(int[5][5], int, int);
void print(double[5][5], double, double);
void print(char[5][5], char, char);
///second question for two-dimensional array , the solution is in the first assignment
void matrix(int[5]);
void matrix(int[5][5][5]);
void max(int[5], int*, int*);
void max(int[5][5][5], int*, int*);
void print(int[5][5], int, int);
void print(int[5], int, int);
void print(int[5][5][5], int, int);


//templates for the third task
template <typename T>
void gen_array(T a[], int size)
{
    std::cout << typeid(T).name() << std::endl;
    for (int i = 0; i < size; i++)
        a[i] = rand() % 101;
}
template <typename T>
T max_array(T a[], int size)
{
	T max = a[0][0];
	for (int i = 0; i < size; i++) {
		
			if (a[i] > max)
				max = a[i];
		
	}
	return max;
}
template <typename T>
void print_array(T a[], int size)
{
	std::cout << typeid(a[0]).name() << std::endl;
	for (int i = 0; i < size; i++) {
		
			std::cout << a[i]<< " ";
		}
		std::cout << "\n";
	
}
template <typename T, int cols>
void gen_array(T a[][cols], int rows)
{
	std::cout << typeid(a[0][0]).name() << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			a[i][j] = rand() % 101;
		}
	}
}
template <typename T, int cols>
void print_array(T a[][cols], int rows)
{
	std::cout << typeid(a[0][0]).name() << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}
template <typename T, int cols>
T max_array(T a[][cols], int rows)
{
	T max = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
template <typename T, int cols>
T max_array_diag(T a[][cols], int rows)//поиск максимума для главной диагонали
{
	T max = a[0][0];
	int n = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j+n] > max)
				max = a[i][j+n];
		}
		n++
	}
	return max;
}
template <typename T, int cols>
T min_array(T a[][cols], int rows)
{
	T min = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] < min)
				min = a[i][j];
		}
	}
	return min;
}
void gen_array(T a[][cols], int rows)
{
	std::cout << typeid(a[0][0]).name() << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			a[i][j] = rand() % 101;
		}
	}
}
template <typename T, int cols, int axis_z>
void print_array(T a[][cols][axis_z], int rows)
{
	std::cout << typeid(a[0][0][0]).name() << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int h = 0; h < cols; h++) {
				std::cout << a[i][j][h] << " ";
			}
		}
		std::cout << "\n";
	}
}
template <typename T, int cols, int axis_z>
T max_array(T a[][cols][axis_z], int rows)
{
	T max = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
template <typename T, int cols, int axis_z>
T min_array(T a[][cols][axis_z], int rows)
{
	T min = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int h = 0; h < cols; h++) {
				if (a[i][j][h] < min)
					min = a[i][j][h];
			}
		}
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int square[5][5]{};
	double square_do[5][5]{};
	char square_ch[5][5]{};

	int maxim{};
	int* pmax{ &maxim };
	int min{};
	int* pmin{ &min };

	char max_ch{};//можно было сделать и одну переменную для всех значений и один общий указатель, но для себя я решила не путаться
	char* pmax_ch{ &max_ch };
	char min_ch{};
	char* pmin_ch{ &min_ch };

	double max_do{};
	double* pmax_do{ &max_do };
	double min_do{};
	double* pmin_do{ &min_do };
	
	std::cout << "Целые числа двухмерный массив" << std::endl;
	matrix(square);
	max(square,pmax, pmin);
	print(square, maxim, min);

	int* pmax_diag{ &maxim };
	int* pmin_diag{ &min };
	max_diag(square, pmax_diag, pmin_diag);
	std::cout << "Максимум на главной диагонали = " << maxim<< " Минимум на главной диагонали = "<< min <<std::endl;

	std::cout << std::endl;
	std::cout << "Натуральные числа, двухмерный массив" << std::endl;
	matrix(square_do);
	max(square_do,pmax_do, pmin_do);
	print(square_do, max_do, min_do);

	double* pmax_diag_do{ &max_do };
	double* pmin_diag_do{ &min_do };
	max_diag(square_do, pmax_diag_do, pmin_diag_do);
	std::cout << "Максимум на главной диагонали = " << max_do << " Минимум на главной диагонали = " << min_do << std::endl;
	std::cout << std::endl;
	std::cout << "Символы по ASCII двухмерный массив" << std::endl;
	matrix(square_ch);
	max(square_ch,pmax_ch, pmin_ch);
	print(square_ch, max_ch, min_ch);

	char* pmax_diag_ch{ &max_ch };
	char* pmin_diag_ch{ &min_ch };

	max_diag(square_ch, pmax_diag_ch, pmin_diag_ch);
	
	std::cout << "Максимум на главной диагонали = " << max_ch << " Минимум на главной диагонали = " << min_ch << std::endl;
	std::cout << std::endl;
	int mono[5]{};
	int max_mono{};
	int min_mono{};
	int* pmax_mono{ &max_mono };
	int* pmin_mono{ &min_mono };
	int three_dim[5][5][5]{};
	int max_three_dim{};
	int min_three_dim{};
	int* pmax_three_dim{ &max_three_dim };
	int* pmin_three_dim{ &min_three_dim };
	std::cout << "Целые числа одномерный массив" << std::endl;
	matrix(mono);
	max(mono, pmax_mono, pmin_mono);
	print(mono, max_mono, min_mono);
	std::cout << std::endl;
	std::cout << "Целые числа трехмерный массив" << std::endl;
	matrix(three_dim);
	max(three_dim, pmax_three_dim, pmin_three_dim);
	print(three_dim, max_three_dim, min_three_dim);

	std::cout << std::endl;

}
void matrix(int square[5][5])
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			square[i][j] = rand() % 101;
		}
	}
}
void matrix(double square_do[5][5])
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			square_do[i][j] = ((rand() % 101) + (rand() % 101 * 0.01) - (rand() % 100));
		}
	}
}
void matrix(char square_ch[5][5])
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			square_ch[i][j] = rand() % 127;
		}
	}
}
void max(int square[5][5],int* pmax,int* pmin)
{
	*pmax = square[0][0];
	*pmin = square[0][0];
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			if(square[i][j]> *pmax)
			{
				*pmax = square[i][j];
			}
			if (square[i][j] < *pmin)
			{
				*pmin = square[i][j];
			}

		}
	}
	
}
void max_diag(int square[5][5], int* pmax_diag, int* pmin_diag){
	*pmax_diag = square[0][0];
	*pmin_diag = square[0][0];
	int n = 0;
	for (int i = 0; i < 5;i++){
		for (int j = 0;j < 5;j++){
			if (square[i][j] > *pmax_diag){
				*pmax_diag = square[i][j + n];
			}
			if (square[i][j] < *pmin_diag){
				*pmin_diag = square[i][j + n];
			}

		}
		n++;

	}
}
void max(double square_do[5][5], double* pmax_do, double* pmin_do)
{
	*pmax_do = square_do[0][0];
	*pmin_do = square_do[0][0];
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			if (square_do[i][j] > *pmax_do)
			{
				*pmax_do = square_do[i][j];
			}
			if (square_do[i][j] < *pmin_do)
			{
				*pmin_do = square_do[i][j];
			}
		}
	}
	
}
void max_diag(double square_do[5][5], double* pmax_diag_do, double* pmin_diag_do) {
	*pmax_diag_do = square_do[0][0];
	*pmin_diag_do = square_do[0][0];
	int n = 0;
	for (int i = 0; i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (square_do[i][j] > *pmax_diag_do) {
				*pmax_diag_do = square_do[i][j + n];
			}
			if (square_do[i][j] < *pmin_diag_do) {
				*pmin_diag_do = square_do[i][j + n];
			}

		}
		n++;

	}
}
void max(char square_ch[5][5], char* pmax_ch, char* pmin_ch)
{
	*pmax_ch = square_ch[0][0];
	*pmin_ch = square_ch[0][0];
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			if (square_ch[i][j] > *pmax_ch)
			{
				*pmax_ch = square_ch[i][j];
			}
			if (square_ch[i][j] < *pmin_ch)
			{
				*pmin_ch = square_ch[i][j];
			}
		}
	}
	
}
void max_diag(char square_ch[5][5], char* pmax_diag_ch, char* pmin_diag_ch) {
	*pmax_diag_ch = square_ch[0][0];
	*pmin_diag_ch = square_ch[0][0];
	int n = 0;
	for (int i = 0; i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (square_ch[i][j] > *pmax_diag_ch) {
				*pmax_diag_ch = square_ch[i][j + n];
			}
			if (square_ch[i][j] < *pmin_diag_ch) {
				*pmin_diag_ch = square_ch[i][j + n];
			}

		}
		n++;

	}

}
void print(int square[5][5], int max, int min)
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			std::cout << " " << square[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << " min = " << min << std::endl;
	std::cout << " max = " << max << std::endl;
	std::cout << std::endl;
}
void print(double square_do[5][5], double max, double min)
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			std::cout << " " << square_do[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << " min = " << min << std::endl;
	std::cout << " max = " << max << std::endl;
	std::cout << std::endl;
}
void print(char square_ch[5][5], char max, char min)
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j<5;j++)
		{
			std::cout << " " << square_ch[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout <<" min = "<<min << std::endl;
	std::cout << " max = " << max << std::endl;
	std::cout << std::endl;
}
void matrix(int mono[5]) {
	for (int j = 0;j < 5;j++)
	{
		mono[j] = rand() % 101;
	}

}
void max(int mono[5], int* pmax_mono, int* pmin_mono) {
	for (int j = 0;j < 5;j++)
	{
		*pmax_mono = mono[0];
		*pmin_mono = mono[0];
		if (mono[j] > *pmax_mono)
		{
			*pmax_mono = mono[j];
		}
		if (mono[j] < *pmin_mono)
		{
			*pmin_mono = mono[j];
		}
	}
}
void print(int mono[5], int max, int min){
		for (int j = 0;j < 5;j++){
			std::cout << " " << mono[j];
		}
	std::cout << std::endl;
	std::cout << " min = " << min << std::endl;
	std::cout << " max = " << max << std::endl;
	std::cout << std::endl;
}
void matrix(int three_dim[5][5][5]){
	for (int i = 0; i < 5;i++){
		for (int j = 0;j < 5;j++){
			for (int h = 0;h < 5;h++) {
				three_dim[i][j][h] = rand() % 101;
			}
		}
	}
}			
void max(int three_dim[5][5][5], int* pmax_three_dim, int* pmin_three_dim) {
		*pmax_three_dim = three_dim[0][0][0];
		*pmin_three_dim = three_dim[0][0][0];
	for (int i = 0; i < 5;i++){
		for (int j = 0;j < 5;j++){
			for (int h = 0;h < 5;h++) {
				if (three_dim[i][j][h] > *pmax_three_dim){
						*pmax_three_dim = three_dim[i][j][h];
				}
				if (three_dim[i][j][h] < *pmin_three_dim){
						*pmin_three_dim = three_dim[i][j][h];
				}
			}
		}
	}

}
void print(int three_dim[5][5][5], int max, int min)
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j < 5;j++){
			for (int h = 0;h < 5;h++) {
					std::cout << " " << three_dim[i][j][h];
			}
				std::cout << std::endl;
		}
			std::cout << std::endl;
	}
		std::cout << std::endl;
		std::cout << " min = " << min << std::endl;
		std::cout << " max = " << max << std::endl;
		std::cout << std::endl;
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

void max_diag(char[5][5], char*, char*);