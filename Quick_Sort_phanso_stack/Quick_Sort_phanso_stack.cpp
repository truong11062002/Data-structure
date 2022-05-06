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
struct segment
{
	int Left;
	int Right;
};
typedef struct segment SEGMENT;
struct stack
{
	int n;
	SEGMENT a[10000];
};
typedef struct stack STACK;
void Init(STACK&);
int IsEmpty(STACK);
int IsFull(STACK);
void Push(STACK&,SEGMENT);
SEGMENT Pop(STACK&);
void Nhap(PHANSO&);
void Xuat(PHANSO);
int Nhap(PHANSO[], int&, string);
int Xuat(PHANSO[], int, string);
int SoSanh(PHANSO, PHANSO);
void Quick_Sort(PHANSO[], int);
int Parttion(PHANSO[], int, int);

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
			cout << "\nSap xep mang tang bang Quick Sort: ";
			Quick_Sort(b, k);
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
void Init(STACK& st)
{
	st.n = 0;
}
int IsEmpty(STACK st)
{
	if (st.n == 0)
		return 1;
	return 0;
}
int IsFull(STACK st)
{
	if (st.n == 10000)
		return 1;
	return 0;
}
void Push(STACK& st, SEGMENT x)
{
	st.a[st.n] = x;
	st.n++;
}
SEGMENT Pop(STACK& st)
{
	SEGMENT x = st.a[st.n - 1];
	st.n--;
	return x;
}


void Quick_Sort(PHANSO a[], int n)
{
	if (n <= 1)
		return;
	STACK stk;
	Init(stk);
	SEGMENT dd = { 0,n - 1 };
	Push(stk, dd);
	while (IsEmpty(stk) == 0)
	{
		dd = Pop(stk);
		int vt = Parttion(a, dd.Left, dd.Right);
		if (dd.Left < vt - 1)
			Push(stk, { dd.Left,vt - 1 });
		if (vt + 1 < dd.Right)
			Push(stk, { vt + 1,dd.Right });
	}
}

int Parttion(PHANSO a[], int Left, int Right)
{
	PHANSO pivot = a[Right];
	int vt = Left - 1;
	for (int i = Left; i <= Right - 1; i++)
		if (SoSanh(a[i], pivot) == -1)
		{
			vt++;
			swap(a[vt], a[i]);
		}
	vt++;
	swap(a[vt], a[Right]);
	return vt;
}
