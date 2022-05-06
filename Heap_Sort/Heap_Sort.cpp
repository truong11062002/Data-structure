#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
int Nhap(int[], int&, string);
int Xuat(int[], int, string);

void Heapify(int[], int, int);
void BuildHeap(int[], int);
void HeapSort(int[], int);
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
			cout << "\nMang sap tang bang Heap Sort: ";
			HeapSort(b, k);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << setw(4);
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
void BuildHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}
void Heapify(int a[], int n, int vt)
{
	while (vt <= n / 2 - 1)
	{
		int child1 = 2 * vt + 1;
		int child2 = 2 * vt + 2;
		int lc = child1;
		if (child2 < n && a[lc] < a[child2])
			lc = child2;
		if (a[vt] < a[lc])
			swap(a[vt], a[lc]);
		vt = lc;
	}

}

void HeapSort(int a[], int n)
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
