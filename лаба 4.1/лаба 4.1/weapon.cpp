#include "weapon.h"
#include <iostream>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

weapon::weapon(string type_of_weapon, int durability_of_weapon, string color_of_weapon, int ammo_of_weapon, int cost_weapon) {
	this->type_of_weapon = type_of_weapon;
	this->durability_of_weapon = 0;
	this->color_of_weapon = color_of_weapon;
	this->ammo_of_weapon = 0;
	this->cost_weapon = 0;
}
weapon::weapon(string type_of_weapon) {
	this->type_of_weapon = type_of_weapon;
}
weapon::weapon() {
	this->type_of_weapon = "laser";
	this->durability_of_weapon = 50;
	this->color_of_weapon = "red";
	this->ammo_of_weapon = 100;
	this->cost_weapon = 0;
}
weapon::~weapon() {

}
void weapon::input() {
	cout << "������� ����� ������� �������� ��� ������� ��� �����������(machinegun, rocketlauncher, laser): ";
	cin >> type_of_weapon;
	cout << "������� ��������� ������ �������� ���(�� 1 �� 100): ";
	cin >> durability_of_weapon;
	cout << "������� ���� ������ �������� ���(eng): ";
	cin >> color_of_weapon;
	cout << "������� ���������� �������� � ������ �������� ���(�� 0 �� 200): ";
	cin >> ammo_of_weapon;
	Sleep(800);
	srand(time(0));
	cost_weapon = rand() % 500 + 50;
}
void weapon::output() {
	cout << "������ �������� ��� ������ ������������: " << type_of_weapon << endl;
	cout << "��������� ������ �������� ���: " << durability_of_weapon << endl;
	cout << "���� ������ �������� ���: " << color_of_weapon << endl;
	cout << "���������� �������� � ������ �������� ���: " << ammo_of_weapon << endl;
	cout << "���� ������ �������� ���: " << cost_weapon << endl;
}
void weapon::weapon_counter(static int wc) {
	wc++;
}