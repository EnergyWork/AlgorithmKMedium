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
	prevCenter = center;
	center.human = "not human";
	center.x = tmpX / points.size(); 
	center.y = tmpY / points.size();
}
void Cluster::SetCenterHandle(POINT point)
{
	center = point;
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

void InitialFrstCenters(vector<Cluster> clusters, vector<POINT> points)
{
	for (size_t i = 0; i < clusters.size(); i++)
	{
		clusters[i].SetCenterHandle(points[i]);
	}
}
void Attach(int countClusters, vector<Cluster> clusters, vector<POINT> points)
{
	for (auto cl : clusters)
		cl.Clear();
	for (size_t i = 0; i < points.size(); i++)
	{

	}
}
void Start(int countClusters, vector<Cluster> clusters, vector<POINT> points)
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
	}
}