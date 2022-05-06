#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;
int Nhap(int[], int&, string);
int Xuat(int[], int,string);
void QuickSort(int[], int);
void QuickSort(int[], int, int);
int Partition(int[], int, int);

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
			cout << "\nMang sap tang bang Quick Sort: ";
			QuickSort(b, k);
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
void QuickSort(int a[], int n)
{
	QuickSort(a, 0, n - 1);
}
void QuickSort(int a[], int Left, int Right)
{
	if (Left < Right)
	{
		int Ipivot = Partition(a, Left, Right);
		QuickSort(a, Left, Ipivot-1);
		QuickSort(a, Ipivot+1, Right);
	}
}
int Partition(int a[], int Left, int Right)
{
	int pivot = a[Right];
	int vt = Left - 1;
	for (int i = Left; i <= Right - 1; i++)
		if (a[i] < pivot)
		{
			vt++;
			swap(a[vt], a[i]);
		}
	vt++;
	swap(a[vt], a[Right]);
	return vt;
}

