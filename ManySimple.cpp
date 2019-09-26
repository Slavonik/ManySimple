#define _CRT_SECURE_NO_WARNINGS // Чтобы не ругался на незащищённые считывание и ввод
#include <iostream>
#include <stdio.h>
#include <fstream> // Работа с файлами
#include <ctime> // Работа с датой / временем
using namespace std;


int ProstOrNot(int x) {  //Содаю функцию типа int, потому на вывод пойдёт число в формате int; x в скобках - условное обозначение взодной переменой
	int f = 0;
	for (int j = 2; j < x; j++)
		if (x % j == 0)
			f = 1;

	return (f);
}


int main()
{
	ofstream fout;//		Открываю файл
	fout.open("Log.txt");//		на запись(Автоматически создаётся если не существует. Если существует, то он очищается)

	system("color A");// Меняю цвет шрифта в консоли

	time_t now = time(0);// Объявляю переменную 
	char* dt = ctime(&now);//  dt, в кторой будет записываться дата


	int R;// R - число до которого искать простые
	scanf_s("%d", &R);

	int Progress = 0;


	Progress = 0;
	now = time(0); //   Обновляем дату
	dt = ctime(&now);//    и время на ктуальные
	fout << "Начало нахождения простых чисел!       " << dt << "\n";

	for (int i = 1; i < (R + 1); i++) {
		if (ProstOrNot(i) == 0) {
			now = time(0);
			dt = ctime(&now);
			fout << "Найдено простое число! Это число " << i << "       " << dt << "\n";
		}

		Progress = i;
		cout << Progress << "       " << dt;
	}

	now = time(0);
	dt = ctime(&now);
	fout << "Нахождение простых чисел окончено!       " << dt << "\n";


	fout.close();
	return 0;
}
