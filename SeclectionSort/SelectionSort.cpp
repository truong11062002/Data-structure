#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int[][100], int&, int&, string);
int Xuat(int[][100], int, int, string);

void SelectionSort(int[][100], int, int);
int main()
{
	int b[100][100];
	int k, l;
	for (int i = 1; i <= 5; i++)
	{
		string filename = "intmatrandata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";

		if (Nhap(b, k, l, filenameinp) == 1)
		{
			cout << "\nMang sap tang bang Interchange Sort: ";
			SelectionSort(b, k, l);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, l, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << setw(4) << "\n";
	}
	cout << "\n\n\n";
	return 1;
}
int Nhap(int a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
	return 1;
}
int Xuat(int a[][100], int m, int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << m << n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << a[i][j] << setw(6);
	}
	return 1;
}
void SelectionSort(int a[][100], int m, int n)
{
	for (int i = 0; i <= m * n - 2; i++)
	{
		int lc = i;
		for (int j = i; j <= m * n - 1; j++)
		{
			if (a[j / n][j % n] < a[lc / n][lc % n])
				lc = j;
		}
		swap(a[i / n][i % n], a[lc / n][lc % n]);
	}
}

