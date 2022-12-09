#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include "melee.h"
#include "weapon.h"
#include "kind.h"
#include "form.h"
#include "transformer.h"
#include "windows.h"
using namespace std;

//ПЕРЕГРУЗКА +//
class overload_plus {
private:
	int min, sec;
public:
	void Init(int m, int s);
	overload_plus operator+ (overload_plus b);
};

void overload_plus::Init(int m, int s) {
	min = m;
	sec = s;
}

overload_plus overload_plus::operator+(overload_plus b) {
	overload_plus c;
	c.min = this->min + b.min;
	c.sec = this->sec + b.sec;
	if (c.sec >= 60) {
		c.min++;
		c.sec -= 60;
	}
	return c;
}
////////////
///ПЕРЕГРУЗКА ++/////
class overload_plusplus {
private:
	int min, sec;
public:
	void Init(int m, int s);
	overload_plusplus& operator ++();
	overload_plusplus operator ++(int unused);
};

void overload_plusplus::Init(int m, int s) {
	min = m;
	sec = s;
}

overload_plusplus& overload_plusplus::operator ++() { //ПРЕФИКС
	this->min++;
	return *this;
}

overload_plusplus overload_plusplus::operator++(int unused) { //ПОСТФИКС
	overload_plusplus c = *this;
	++* this;
	return c;
}


int main() {
	setlocale(LC_ALL, "RUS");
	int x;
	x = 0;
	int summa1, summa2;

	//ПЕРЕГРУЗКА++//
	overload_plusplus a, b;
	a.Init(2, 35);
	b = ++a;       //a: min=3 sec=35  b: min=3 sec=35
	printf("Pref=%d\n", b);
	a.Init(2, 35);
	b = a++;       //a: min=3 sec=35 b: min=2 sec=35
	printf("Postf=%d", b);
	////////////////
	//ПЕРЕГРУЗКА +//
	overload_plus ap, bp, cp, dp;
	ap.Init(2, 25);
	bp.Init(2, 45);
	cp.Init(3, 5);
	dp = ap + bp + cp;  //  d: min = 8 sec = 15
	printf("\nD=%d\n", dp);

	kind your_kind = kind();
	melee your_melee = melee();
	weapon your_weapon = weapon();
	form your_form = form();
	transformer* your_transformer = new transformer[1];
	for (int i = 0; i < 1; i++)
	{
		your_transformer[i] = transformer::transformer(your_kind, your_melee, your_weapon, your_form);
		your_transformer[i].input();
		your_transformer[i].output();
		your_transformer[i].weapon_details_counter(*your_transformer);
		//Дружественная функция
		components(*your_transformer);
	}
	while (x != 5) {
		cout << " Введите: 1 - для вывода характеристики вашего трансформера " << endl;
		cout << " 2 - для анализа цветовой гаммы вышего трансформера " << endl;
		cout << " 3 - для анализа скорости вашего трансформера " << endl;
		cout << " 4 - для вывода цены на оружие вашего трансформера " << endl;
		cout << " 5 - выхода" << endl;
		cin >> x;
		switch (x) {
		case 1:
			your_transformer->output();
			your_transformer->weapon_details_counter(*your_transformer);
			components(*your_transformer);
			break;
		case 2:
			your_transformer->color(*your_transformer);
			break;
		case 3: 
			your_transformer->speed_type(*your_transformer);
			break;
		case 4:
			//Демонстрация возврата значения из метода через указатель (*) и через ссылку (&)
			your_transformer->summa(*your_transformer, &summa1);
			cout << "Цена через указатель: " << summa1 << endl;
			your_transformer->summa(*your_transformer, summa2);
			cout << "Цена через параметр: " << summa2 << endl;
			break;
		}
		fflush(stdin);
	}
	for (int i = 0; i < 1; i++) {
		delete your_transformer;
	}
	delete[] your_transformer;

}