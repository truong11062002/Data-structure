#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
int Nhap(float[], int&, string);
int Xuat(float[], int, string);

void Merge_Sort_float(float[], int);
void Merge_Sort_float(float[], int, int);
void Merge(float[], int, int, int);
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
			cout << "\nSap xep mang tang bang Quick Sort: ";
			Merge_Sort_float(b, k);
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
void Merge_Sort_float(float a[], int n)
{
	Merge_Sort_float(a, 0, n - 1);
}
void Merge_Sort_float(float a[], int Left, int Right)
{
	if (Left < Right)
	{
		int Mid = (Left + Right) / 2;
		Merge_Sort_float(a, Left, Mid);
		Merge_Sort_float(a, Mid + 1, Right);
		Merge(a, Left, Mid, Right);
	}
}
void Merge(float a[], int Left, int Mid, int Right)
{
	float* temp = new float[Right - Left + 1];
	int m = 0;
	int i = Left;
	int j = Mid + 1;
	while (!(i > Mid && j > Right))
	{
		if ((i <= Mid && j <= Right && a[i] < a[j]) || j > Right)
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for (int k = 0; k < m; k++)
		a[Left + k] = temp[k];
	delete[]temp;
}
