#pragma once
#include "iostream"
#include <vector>
#include <iomanip>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

using namespace std;

class Enter {
public:
	char login[20];
	char password[20];
public:
	Enter()
	{
		login[0] = NULL;
		password[0] = NULL;
	}
	friend ofstream &operator <<(ofstream &a, Enter &b);
	friend ifstream &operator >>(ifstream &a, Enter &b);
	~Enter() {}
};

class Matrix
{
public:
	static const int size = 3;

	int **R;
	int **C;
	double r[size];
	double D[size];
	double Ck[size];
	double Dc[size];
	
	void show();

	

	Matrix() {
		R = new int*[size];
		for (int i = 0; i < size; i++)
			R[i] = new int[size];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				R[i][j] = 0;
			}
		}
		C = new int*[size];
		for (int i = 0; i < size; i++)
			C[i] = new int[size];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				C[i][j] = 0;
			}
		}
		for (int j = 0; j < size; j++)
		{
			r[j] = 0;
			D[j] = 0;
			Ck[j] = 0;
			Dc[j] = 0;
		}

	}
	~Matrix() {
		for (int i = 0; i < size; i++)
		{
			delete[] R[i];
		}
		delete[]R;
		for (int i = 0; i < size; i++)
		{
			delete[] C[i];
		}
		delete[]C;
	}
};

void Matrix::show()
{
	std::cout << "������� �������� ������ �������������� ���������:" << std::endl;
	int k = 0;
	cout << setfill('_') << setw(10) << "_" << setw(size * 7 - 1) << "_" << endl;
	cout << setw(10) << setfill(' ') << "|" << setw(size * 7) << "�j |" << endl;
	cout << setw(10) << "�i |" << setw(size * 7) << setfill('-') << "|" << endl;
	cout << setw(10) << setfill(' ') << "|";
	for (int i = 0; i < size; i++)
		cout << setw(5) << "�" << i + 1 << "|";
	cout << endl << setfill('-') << setw(10) << "|" << setw(size * 7) << "|" << setfill(' ') << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(8) << "�" << k + 1 << "|"; k++;
		for (int j = 0; j < size; j++)
		{
			if(i == j) cout << setw(5) << " --" << " |";
			else cout << setw(6) << R[i][j] << "|";
		}
		cout << endl << setfill('-') << setw(10) << "|" << setw(size * 7) << "|" << setfill(' ') << endl;
	}
	cout <<  endl << "1. ��������" << endl << "2. �������� " << endl << "3. ���������" << endl;
	cout << "B1 - ��������� ����� ������������" << endl;
	cout << "B2 - ������ ����� ������� ��������� " << endl;
	cout << "B3 - ���������� ������������" << endl;
	std::cout << endl <<  "������� ������ �����" << std::endl;
	k = 0;
	cout << setfill('_') << setw(10) << "_" << setw(size * 7 - 1) << "_" << endl;
	cout << setw(10) << setfill(' ') << "|" << setw(size * 7) << "Bj |" << endl;
	cout << setw(10) << "�i |" << setw(size * 7) << setfill('-') << "|" << endl;
	cout << setw(10) << setfill(' ') << "|";
	for (int i = 0; i < size; i++)
		cout << setw(5) << "B" << i + 1 << "|";
	cout << endl << setfill('-') << setw(10) << "|" << setw(size * 7) << "|" << setfill(' ') << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(8) << "�" << k + 1 << "|"; k++;
		for (int j = 0; j < size; j++)
		{
			 cout << setw(6) << C[i][j] << "|";
		}
		cout << endl << setfill('-') << setw(10) << "|" << setw(size * 7) << "|" << setfill(' ') << endl;
	}
	
}