#include <iostream>
#include <fstream>
#include "Cluster.h"
using namespace std;

vector<POINT> initData(string file)
{
	vector<POINT> tmp;
	ifstream in(file);
	POINT tmpPoint;
	while (!in.eof())
	{	
		in >> tmpPoint.human >> tmpPoint.x >> tmpPoint.y;
		tmp.push_back(tmpPoint);
	}
	return tmp;
}

int main()
{
	vector<POINT> vpoints = initData("data.txt");
	int k;
	cout << "Enter the number clusters: ";
	cin >> k;
	vector<Cluster> clusters(k);
	Start(k, clusters, vpoints);
	system("pause");
	return 0;
}