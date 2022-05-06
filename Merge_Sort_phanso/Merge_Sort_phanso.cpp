#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
struct phanso
{
	int tu;
	int mau;
};
typedef struct phanso PHANSO;

void Nhap(PHANSO&);
void Xuat(PHANSO);
int Nhap(PHANSO[], int&, string);
int Xuat(PHANSO[], int, string);
int SoSanh(PHANSO, PHANSO);
void Merge_Sort(PHANSO[], int);
void Merge_Sort(PHANSO[], int, int);
void Merge(PHANSO[], int, int, int);
int main()
{
	PHANSO b[100000];
	int k;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "phansodata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";

		if (Nhap(b, k, filenameinp) == 1)
		{
			cout << "\nSap xep mang tang bang Merge Sort: ";
			Merge_Sort(b, k);
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
void Nhap(PHANSO& x)
{
	cin >> x.tu >> x.mau;
}
void Xuat(PHANSO x)
{
	cout << x.tu << setw(10) << x.mau;
}
int Nhap(PHANSO a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i].tu >> a[i].mau;
	return 1;
}
int Xuat(PHANSO a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << a[i].tu << setw(5) << a[i].mau << endl;
	return 1;
}
int SoSanh(PHANSO x, PHANSO y)
{
	float a = (float)x.tu / x.mau;
	float b = (float)y.tu / y.mau;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}
void Merge_Sort(PHANSO a[], int n)
{
	Merge_Sort(a, 0, n - 1);
}

void Merge_Sort(PHANSO a[], int Left, int Right)
{
	if (Left < Right)
	{
		int Mid = (Left + Right) / 2;
		Merge_Sort(a, Left, Mid);
		Merge_Sort(a, Mid + 1, Right);
		Merge(a, Left, Mid, Right);
	}
}

void Merge(PHANSO a[], int Left, int Mid, int Right)
{
	PHANSO* temp = new PHANSO[Right - Left + 1];
	int m = 0;
	int i = Left;
	int j = Mid + 1;
	while (!(i > Mid && j > Right))
	{
		if ((i <= Mid && j <= Right && SoSanh(a[i], a[j]) == -1) || j > Right)
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for (int k = 0; k < m; k++)
		a[Left + k] = temp[k];
	delete[]temp;
}
