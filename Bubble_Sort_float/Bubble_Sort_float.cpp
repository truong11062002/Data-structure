#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
int Nhap(float[], int&, string);
int Xuat(float[], int, string);

void Bubble_Sort_float(float[], int);
int main()
{
	float b[100000];
	int k;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "floatdata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";

		if (Nhap(b, k, filenameinp) == 1)
		{
			cout << "\nSap xep mang tang bang Bubble Sort: ";
			Bubble_Sort_float(b, k);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, filenameout);
			cout << endl << filenameinp;
			cout << endl << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << setw(4) << endl;
	}
	cout << "\n\n\n";
	return 1;
}
int Nhap(float a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}
int Xuat(float a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	for (int i = 0; i < n; i++)
		fo << a[i] << setw(10);
	return 1;
}
void Bubble_Sort_float(float a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = n - 1; j >= i+1; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
