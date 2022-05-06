#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
int Nhap(float[], int&, string);
int Xuat(float[], int, string);

void BuildHeap(float[], int);
void Heapify(float[], int, int);
void HeapSort(float[], int);

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
			cout << "\nSap xep mang tang bang Heap Sort: ";
			HeapSort(b, k);
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
void BuildHeap(float a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}
void Heapify(float a[], int n, int vt)
{
	while (vt <= n / 2 - 1)
	{
		int lc = 2 * vt + 1;
		if (lc + 1 < n && a[lc] < a[lc + 1])
			lc++;
		if (a[vt] < a[lc])
			swap(a[vt], a[lc]);
		vt = lc;
	}
}
void HeapSort(float a[], int n)
{
	BuildHeap(a, n);
	int length = n;
	while (length > 1)
	{
		swap(a[0], a[length - 1]);
		length--;
		Heapify(a, length, 0);
	}
}