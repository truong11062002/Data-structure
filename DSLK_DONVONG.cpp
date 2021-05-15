#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
struct node
{
	int info;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list	LIST;

void Init(LIST&);
int IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
int DemNode(LIST);

int Nhap(LIST&, string);
int Xuat(LIST, string);
void InterchangeSort(LIST&);

int main()
{
	LIST l;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";
		if (Nhap(l, filenameinp) == 1)
		{
			cout << "\nSap tang bang interchange sort";
			InterchangeSort(l);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(l, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << "\n";
	}
	cout << "\n\n\n";
	return 1;
}
void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		p->pNext = l.pHead;
		l.pTail = p;
	}
}
int Nhap(LIST& l, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	int x;
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		fi >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
		{
			AddTail(l, p);
		}
	}
	return 1;
}
int Xuat(LIST l, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << DemNode(l) << endl;
	NODE* p = l.pHead;
	do {
		fo << p->info << setw(5);
		p = p->pNext;
	} while (p != l.pHead);
	return 1;
}
int DemNode(LIST l)
{
	int dem = 0;
	NODE* p = l.pHead;
	do {
		dem++;
		p = p->pNext;
	} while (p != l.pHead);
	return dem;
}
void InterchangeSort(LIST& l)
{
	for (NODE* p = l.pHead; p != l.pTail; p = p->pNext)
		for (NODE* q = p->pNext; q != l.pHead; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}