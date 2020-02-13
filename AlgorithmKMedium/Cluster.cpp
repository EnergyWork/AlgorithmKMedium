#include "Cluster.h"

void Cluster::Clear()
{
	points.clear();
}
void Cluster::Add(POINT newPoint)
{
	points.push_back(newPoint);
}
POINT& Cluster::at(unsigned i)
{
	return points.at(i);
}
size_t Cluster::Size()
{
	return points.size();
}
POINT Cluster::GetCenter()
{
	return center;
}
POINT Cluster::GetPrevCenter()
{
	return prevCenter;
}
void Cluster::SetCenter()
{
	double tmpX = 0, tmpY = 0;
	for (size_t i = 0; i < points.size(); i++)
	{
		tmpX += points[i].x;
		tmpY += points[i].y;
	}
	prevCenter.human = center.human;
	prevCenter.x = center.x;
	prevCenter.y = center.y;
	center.human = "not human";
	center.x = tmpX / points.size(); 
	center.y = tmpY / points.size();
}
void Cluster::SetCenterHandle(POINT point)
{
	center = point;
}
void Cluster::PrintCluster()
{
	cout << "Center: " << center.x << " " << center.y << endl << "points: " << endl;
	for (auto p : points)
	{
		cout << p.human << " " << p.x << " " << p.y << endl;
	}
	cout << endl;
}
void PrintLine()
{
	cout << "================================================" << endl;
}
bool operator == (POINT p1,POINT p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}
bool Cluster::EqualPrevCenter()
{
	return (center == prevCenter ? true : false);
}
double LenthToCluster(POINT c, POINT p)
{
	return (sqrt(pow(c.x - p.x, 2) + pow(c.y - p.y, 2)));
}
void InitialFrstCenters(vector<Cluster> &clusters, vector<POINT> points)
{
	for (size_t i = 0; i < clusters.size(); i++)
	{
		clusters[i].SetCenterHandle(points[i]);
	}
}
void Attach(size_t countClusters, vector<Cluster>& clusters, vector<POINT> points)
{
	double length;
	Cluster* pCluster = &clusters[0];
	for (auto &cl : clusters)
		cl.Clear();
	for (size_t i = 0; i < points.size(); i++)
	{
		length = UINT_MAX;
		for (size_t j = 0; j < clusters.size(); j++) //for (auto &cl : clusters)
		{
			double tmpLength = LenthToCluster(clusters[j].GetCenter(), points[i]);
			if (tmpLength < length)
			{
				length = tmpLength;
				pCluster = &clusters[j];
			}
		}
		pCluster->Add(points[i]);
	}
}
void Start(size_t countClusters, vector<Cluster>& clusters, vector<POINT> points)
{
	size_t check;
	InitialFrstCenters(clusters, points);
	while (true)
	{
		check = 0;
		Attach(countClusters, clusters, points);
		for (size_t i = 0; i < countClusters; i++)
		{
			clusters[i].SetCenter();
			if (clusters[i].EqualPrevCenter())
				check++;
		}
		if (check == countClusters)
			return;
		for (auto cl : clusters)
			cl.PrintCluster();
		PrintLine();
	}
}