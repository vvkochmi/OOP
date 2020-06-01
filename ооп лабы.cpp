// ооп лабы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Holod_tech
{
protected:
	int price, moch;
	string name;
public:
	Holod_tech()
	{
		moch = 0;
		price = 0;
		name = "";
	}
	Holod_tech(int price, int moch, string name)
	{
		this->price = price;
		this->moch = moch;
		this->name = name;
	}
	virtual void print()
	{
		cout << "Мощность:";
		cin >> moch;
		cout << "Цена:";
		cin >> price;
		cout << "Название:";
		cin >> name;
	}
	virtual void read()
	{
		cout << "Мощность:" << moch << endl;
		cout << "Цена:" << price << endl;
		cout << "Название:" << name << endl;
	}
};

///////Холодосики////////////////////

class Holod_obr : public Holod_tech
{
protected:
	int potreb;
public:
	Holod_obr() : Holod_tech()
	{
		potreb = 0;
	}
	Holod_obr(int price, int moch, string name, int potreb) :Holod_tech(price, moch, name)
	{
		this->potreb = potreb;
	}
	void print()
	{
		Holod_tech::print();
		cout << "Энергопотребление:";
		cin >> potreb;
	}
	void read()
	{
		Holod_tech::read();
		cout << "Энергопотребление:" << potreb << endl;
	}
};
class Holodos : public Holod_obr
{
protected:
	int kam;
public:
	Holodos() : Holod_obr()
	{
		kam = 0;
	}
	Holodos(int price, int moch, string name, int potreb, int kam) : Holod_obr(price, moch, name, potreb)
	{
		this->kam = kam;
	}
	void print()
	{
		Holod_obr::print();
		cout << "Количество камер:";
		cin >> kam;
	}
	void read()
	{
		Holod_obr::read();
		cout << "Количество камер:" << kam << endl;
	}
};
class Holod_vitr : public Holod_obr
{
protected:
	string kompres;
public:
	Holod_vitr() : Holod_obr()
	{
		kompres = "";
	}
	Holod_vitr(int price, int moch, string name, int potreb, string kompres) : Holod_obr(price, moch, name, potreb)
	{
		this->kompres = kompres;
	}
	void print()
	{
		Holod_obr::print();
		cout << "Имеется ли компрессор:";
		cin >> kompres;
	}
	void read()
	{
		Holod_obr::read();
		cout << "Наличие компрессора:" << kompres << endl;
	}
};
class Holod_display : public Holodos, public Holod_vitr
{
protected:
	string display;
public:
	Holod_display() : Holod_vitr()
	{
		display = "";
	}
	Holod_display(int price, int moch, string name, int potreb, string kompres, string display) : Holod_vitr(price, moch, name, potreb, kompres)
	{
		this->display=display;
	}
	void print()
	{
		Holod_vitr::print();
		Holodos::print();
		cout << "Имеется ли дисплей:";
		cin >> display;
	}
	void read()
	{
		Holod_vitr::read();
		Holodos::print();
		cout << "Наличие дисплея:" << display << endl;
	}
};

//////Морозилочки//////////////////

class Moroz_obr : public Holod_tech
{

};
class Moroz_shkaf : public Moroz_obr
{

};
class Moroz_lar : public Moroz_obr
{

};
class Moroz_zamok : public Moroz_shkaf, public Moroz_lar
{

};



class Vector
{
private:
	Holod_tech *vec;
	int b;
public:
	Vector(int n)
	{
		try 
		{
			if (n == 0) throw 1;
			vec = new Holod_tech[n];
			b = n;
		}
		catch (int b)
		{
			cout << "Размер вектора не может быть равен 0" << endl;
		}
	}
	friend ostream& operator<< (ostream& out, const Vector & a)
	{
		for (int i = 0; i < a.b; i++)
		{
			a.vec[i].print();

		}
		out << endl;
		return out;
	}
	void zapis(int i, Holod_tech& mas)
	{
		vec[i] = mas;
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i=0, capacity;
	cout << "Введите количество элементов:";
	cin >> n;
	Vector a(n);
	if (n == 0)
	{
		return 0;
	}
	cout << "Выберите какой элемент хотите добавить:" << endl << "1-Холодильное оборудование" << endl << "2-Холодильник" << endl << "3-Холодильная витрина" << endl << "4-Холодильное оборудование с дисплеем" << endl;
	cin >> capacity;
	while (capacity != 0)
	{
		if (capacity == 1)
		{
			Holod_obr obr;
			obr.print();
			a.zapis(i, obr);
			cout << endl;
		}
		if (capacity == 2)
		{
			Holodos hol;
			hol.print();
			a.zapis(i, hol);
			cout << endl;
		}
		if (capacity == 3)
		{
			Holod_vitr vitr;
			vitr.print();
			a.zapis(i, vitr);
			cout << endl;
		}
		/*if (capacity == 4)
		{
			Holod_display dis;
			dis.print();
			a.zapis(i, dis);
			cout << endl;
		}*/
		i++;
		if (i < n)
		{
			cout << "Выберите какой элемент хотите добавить:" << endl << "1-Холодильное оборудование" << endl << "2-Холодильник" << endl << "3-Холодильная витрина" << endl << "4-Холодильное оборудование с дисплеем" << endl;
			cin >> capacity;
		}
		else
		{
			capacity = 0;
		}
	}
	//cout << a;
	system("pause");
	return 0;
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
