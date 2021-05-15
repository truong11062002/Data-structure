#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void Init(TREE&);
NODE* GetNode(int);
int InsertNode(TREE&, int);
int Nhap(TREE&, string);
void Xuat(TREE);
int Xuat(TREE, string);
int Xuat(TREE, ofstream&);
int DemNode(TREE);

int main()
{
	TREE t;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += "0";
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";
		if (Nhap(t, filenameinp) == 1)
		{
			string filenameout = filename;
			filenameout += ".out";
			Xuat(t, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "Khong mo duoc file" << filename << "\n";
	}
	cout << "\n\n\n";
	return 1;
}
void Init(TREE& t)
{
	t = NULL;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}int InsertNode(TREE& t, int x)
{
	if (t != NULL)
	{
		int rValue = rand();
		if (rValue % 2 == 0)
			return InsertNode(t->pRight, x);
		return InsertNode(t->pLeft, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
int Nhap(TREE& t, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	int x;
	fi >> n;
	Init(t);
	for (int i = 1; i <= n; i++)
	{
		fi >> x;
		InsertNode(t, x);
	}
	return 1;
}
void Xuat(TREE t)
{
	if (t == NULL)
		return;
	Xuat(t->pRight);
	Xuat(t->pLeft);
	cout << t->info;
}



int Xuat(TREE t, string filename)
{
	ofstream fo(filename);
	if (fo.fail())
		return 0;
	fo << setw(6) << DemNode(t) << endl;
	return Xuat(t, fo);
}

int Xuat(TREE t, ofstream& fo)
{
	if (t == NULL)
		return 1;
	Xuat(t->pLeft, fo);
	fo << setw(6) << t->info;
	Xuat(t->pRight, fo);
}
int DemNode(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return a + b + 1;
}
