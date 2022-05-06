#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int[], int&, string);
int Xuat(int[], int, string);

void QuickSort(int[], int);
int Partition(int[], int, int);

struct segment
{
	int Left;
	int Right;
};
typedef struct segment SEGMENT;
struct queue
{
	int n;
	SEGMENT a[10000];
};
typedef struct queue QUEUE;

void Init(QUEUE&);
int IsEmpty(QUEUE);
int IsFull(QUEUE);
void EnQueue(QUEUE&, SEGMENT);
SEGMENT DeQueue(QUEUE&);

int Nhap(int[], int&, string);
int Xuat(int[], int, string);

void QuickSort(int[], int);
int Partition(int[], int, int);
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
void Init(QUEUE& que)
{
	que.n = 0;
}
int IsEmpty(QUEUE que)
{
	if (que.n == 0)
		return 1;
	return 0;
}
int IsFull(QUEUE que)
{
	if (que.n == 10000)
		return 1;
	return 0;
}
void EnQueue(QUEUE& que, SEGMENT x)
{
	que.a[que.n] = x;
	que.n++;
}
SEGMENT DeQueue(QUEUE& que)
{
	SEGMENT x = que.a[0];
	for (int i = 0; i <= que.n - 2; i++)
		que.a[i] = que.a[i + 1];
	que.n--;
	return x;
}
void QuickSort(int a[], int n)
{
	if (n <= 1)
		return;
	QUEUE q;
	Init(q);

	SEGMENT ss = { 0,n - 1 };
	EnQueue(q, ss);
	while (IsEmpty(q) == 0)
	{
		ss = DeQueue(q);
		int vt = Partition(a, ss.Left, ss.Right);
		if (ss.Left < vt - 1)
			EnQueue(q, { ss.Left, vt - 1 });
		if (vt + 1 < ss.Right)
			EnQueue(q, { vt + 1, ss.Right });
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
