#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int[][500], int&, int&, string);
int Xuat(int[][500], int, int, string);

void QuickSort(int[][500], int, int);
void QuickSort(int[][500], int, int, int);
int Parttion(int[][500], int, int, int);
int main()
{
	int b[500][500];
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
			cout << "\nMang sap tang bang Quick Sort: ";
			QuickSort(b, k, l);
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
int Nhap(int a[][500], int& m, int& n, string filename)
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
int Xuat(int a[][500], int m, int n, string filename)
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
void QuickSort(int a[][500], int m, int n)
{
	QuickSort(a, n, 0, m * n - 1);
}
void QuickSort(int a[][500], int n, int Left, int Right)
{
	if (Left < Right)
	{
		int ipivot = Parttion(a, n, Left, Right);
		QuickSort(a, n, Left, ipivot - 1);
		QuickSort(a, n, ipivot + 1, Right);
	}
}
int Parttion(int a[][500], int n, int Left, int Right)
{
	int pivot = a[Right / n][Right % n];
	int vt = (Left - 1);
	for (int i = Left; i <= Right - 1; i++)
		if (a[i / n][i % n] < pivot)
		{
			vt++;
			swap(a[vt / n][vt % n], a[i / n][i % n]);
		}
	vt++;
	swap(a[vt / n][vt % n], a[Right / n][Right % n]);
	return vt;
}
