// ChyrunSofialab11.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_11_1.cpp
// < Чирун Софія >
// Лабораторна робота № 11.1
// Бінарні файли 
// Варіант 18

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <Windows.h> 

using namespace std;
void Create(char* filename, const int N);
void Print(char* filename);
void Remove(char* filename);
int Suma(int x, int y);

int main(int argc, char* argv[])
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	srand((unsigned)time(NULL));
	char filename[61];
	cout << "Enter file name : ";
	cin.getline(filename, sizeof(filename));
	int N;
	cout << "Enter count of components: "; cin >> N;
	Create(filename, N);
	cout << "Записані у файл випадково згенеровані числа: " << endl;
	Print(filename);
	Remove(filename);
	return 0;
}

void Create(char* filename, const int N)
{
	ofstream f(filename, ios::binary);
	int x;
	for (int i = 0; i < N; i++)
	{
		x = -100 + rand() % 201;
		f.write((char*)&x, sizeof(x));
	}
}

void Print(char* filename)
{
	ifstream f(filename, ios::binary);
	int x;
	while (f.read((char*)&x, sizeof(x)))
		  cout << x << "  ";
	      cout << endl << endl;
}

int Suma(int x, int y) 
{
	return x + y;
}

void Remove(char* filename)
{
	ifstream f(filename, ios::binary);
	ofstream t("TMP.DAT", ios::binary);
	int x, i=0, n;
	int a[100];
	cout << "Відємні числа: "<<endl;
	while (f.read((char*)&x, sizeof(x))) 
		if (x < 0) 
		{
			a[i] = x;
			cout << a[i] << " | ";
			i++;
		}
	cout << endl << endl; 
	n = i;
	int *b, s=0;
	b = new int[n];
	char newfilename[61];
	cout << "Enter file 2 name : ";
	cin>>newfilename;
	ofstream f2(newfilename, ios::binary);
	cout << "Суми відємних чисел: " << endl;
	for (i = 0; i < n; i++) 
	{
		s= Suma(s , a[i]);
		b[i] = s;
		cout << b[i] << " | ";
		t.write((char*)&b[i], sizeof(b[i])); 
		f2.write((char*)&b[i], sizeof(b[i])); 
	}
	cout << endl << endl;
	f.close(); 
	t.close(); 
	f2.close();
	cout << "Записані у файл суми відємних чисел: " << endl;
	Print(newfilename);
	remove(filename); 
	rename("TMP.DAT", filename); 
	delete []b;
}

