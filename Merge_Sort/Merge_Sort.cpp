#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int[], int&, string);
int Xuat(int[], int, string);
void SapTang(int[], int);
void Merge_Sort(int[], int, int);
void Merge(int[], int, int, int);

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
			cout << "\nMang sap tang bang Merge Sort: ";
			SapTang(b, k);
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
	for (int i = 0; i < n; i++)
		fo << a[i] << setw(6);
	return 1;
}
void SapTang(int a[], int n)
{
	Merge_Sort(a, 0, n - 1);
}

void Merge_Sort(int a[], int Left, int Right)
{
	if (Left < Right)
	{
		int Mid = (Left + Right) / 2;
		Merge_Sort(a, Left, Mid);
		Merge_Sort(a, Mid + 1, Right);
		Merge(a, Left, Mid, Right);
	}
}

void Merge(int a[], int Left, int Mid, int Right)
{
	int* temp = new int[Right - Left + 1];
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
	for (int i = 0; i < m; i++)
		a[Left + i] = temp[i];
	delete[]temp;
}

