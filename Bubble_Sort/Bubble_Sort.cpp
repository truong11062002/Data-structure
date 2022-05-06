#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
int Nhap(int[], int&, string);
int Xuat(int[], int, string);
void Bubble_Sort(int[], int);
int main()
{
	int b[100000];
	int k;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";

		if (Nhap(b, k, filenameinp) == 1)
		{
			cout << "\nMang sap tang bang Bubble Sort: ";
			Bubble_Sort(b, k);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << setw(4) << "\n";
	}
	cout << "\n\n\n";
	return 1;
}
int Nhap(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}
int Xuat(int a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << n << setw(6) << endl;
	for (int i = 0; i < n; i++)
		fo << a[i] << setw(6);
	return 1;
}
void Bubble_Sort(int a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = n - 1; j >= i + 1; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
