// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Phone
{
protected:
	int p, bat;
	string name;

public:
	Phone()
	{
		p = 0;
		bat = 0;
		name = "";
	}
	/*friend int operator+(int s, const Phone& P) {
		return  s + P.p;
	}*/
};
class Provod :public Phone
{
protected:
	int dlinap;
public:
	Provod()
	{
		p = 0;
		bat = 0;
		name = "";
		dlinap = 0;
	}
	friend istream& operator>>(istream & is, Provod & P);
	friend ostream& operator<<(ostream & os, const Provod & P);
};
istream& operator>>(istream& i, Provod& P)
{
	cout << "Введите название: ";
	i >> P.name;
	cout << "Введите емкость аккумулятора: ";
	i >> P.bat;
	cout << "Введите цену: ";
	i >> P.p;
	cout << "Введите длину провода: ";
	i >> P.dlinap;
	return i;
}
ostream& operator<<(ostream& os, const Provod& P)
{
	return os << "Название: " << P.name << " Аккумулятор: " << P.bat << " Цена: " << P.p << " Длина провода: " << P.dlinap;
}
class Bezprovod :public Phone
{
protected:
	int dia;
public:
	Bezprovod()
	{
		p = 0;
		dia = 0;
		bat = 0;
		name = "";
	}
};
 class Android : public Bezprovod
 {
 protected:
	 double version;
 public:
	 Android()
	 {
		 p = 0;
		 dia = 0;
		 bat = 0;
		 name = "";
		 version = 0;
	 }
 };	
 class Samsung : public Android
 {
 private:
	 string model;
 public:
	 Samsung()
	 {
		 p = 0;
		 dia = 0;
		 bat = 0;
		 name = "";
		 version = 0;
		 model = "";
	 }
	 friend istream& operator>>(istream& is, Samsung& S);
	 friend ostream& operator<<(ostream& os, const Samsung& S);
 };
 istream& operator>>(istream& i, Samsung& S)
 {
	 cout << "Введите название: ";
	 i >> S.name;
	 cout << "Введите диагональ: ";
	 i >> S.dia;
	 cout << "Введите емкость аккумулятора: ";
	 i >> S.bat;
	 cout << "Введите цену: ";
	 i >> S.p;
	 cout << "Введите версию Android: ";
	 i >> S.version;
	 cout << "Введите модель: ";
	 i >> S.model;
	 return i;
 }
 ostream& operator<<(ostream& os, const Samsung& S)
 {
	 return os << "Название: " << S.name << " Диагональ: " << S.dia << " Аккумулятор: " << S.bat << " Цена: " << S.p << " Версия Android: " << S.version << " Модель: " << S.model;
 }
 class Ios :public Bezprovod
 {
 protected:
	 double version;
 public:
	 Ios()
	 {
		 p = 0;
		 dia = 0;
		 bat = 0;
		 name = "";
		 version = 0;
	 }
 };

 class iPhone :public Ios
 {
 private:
	 string model;
 public:
	 iPhone()
	 {
		 p = 0;
		 dia = 0;
		 bat = 0;
		 name = "";
		 version = 0;
		 model = "";
	 }
	 friend istream& operator>>(istream& is, iPhone& I);
	 friend ostream& operator<<(ostream& os, const iPhone& I);
 };
 istream& operator>>(istream& i, iPhone& I)
 {
	 cout << "Введите название: ";
	 i >> I.name;
	 cout << "Введите диагональ: ";
	 i >> I.dia;
	 cout << "Введите емкость аккумулятора: ";
	 i >> I.bat;
	 cout << "Введите цену: ";
	 i >> I.p;
	 cout << "Введите версию Android: ";
	 i >> I.version;
	 cout << "Введите модель: ";
	 i >> I.model;
	 return i;
 }
 ostream& operator<<(ostream& os, const iPhone& I)
 {
	 return os << "Название: " << I.name << " Диагональ: " << I.dia << " Аккумулятор: " << I.bat << " Цена: " << I.p << " Версия Android: " << I.version << " Модель: " << I.model;
 }
template <class T>
class Vector {
private:
	T *x;
public:
	
	Vector(int c)
	{
		x = new T[c];
		
	}
	void Vvod(int c)
	{
		for (int i = 0; i < c; i++)
		{
			cout << "Введите информацию о телефоне N" << i + 1 << ":" << endl;
			cin >> x[i];
			cout << endl;
		}
	}
	void Vivod(int c)
	{
		for (int i = 0; i < c; i++)
		{
			cout << "Телефон N" << i + 1 << ":" << endl;
			cout<< x[i];
			cout << endl;
		}
		cout << endl;
	}
	void summa(int c) {
		int s = 0;
		for (int i = 0; i < c; i++)
		{
			s =s+ x[i];
		}
		cout<<"summa= "<< s;
	}
	
};	

int main()
{
	//setlocale(LC_ALL, "Russian");
	int e, a;
	cout << "Выберите проводной или безпроводной телефонный аппарат(1-Проводной, 2-Безпроводной): ";
	cin >> e;
	if (e == 1)
	{
		cout << "Введите количество телефонных аппаратов: ";
		cin >> a;
		Vector<Provod> P(a);
		P.Vvod(a);
		P.Vivod(a);
	}
	else
	{
		cout << "Выберите ОС для вводимых телефонных аппаратов(1-Android, 2-Ios): ";
		cin >> e;
		cout << "Введите количество телефонных аппаратов: ";
		cin >> a;
		if (e == 1)
		{
			Vector<Samsung> S(a);
			S.Vvod(a);
			S.Vivod(a);
		}
		else
		{
			Vector<iPhone> I(a);
			I.Vvod(a);
			I.Vivod(a);
		}
	}
	//P.summa(e);
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
