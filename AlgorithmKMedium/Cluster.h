#include <vector>
#include <string>
using namespace std;

struct POINT {
	string human;
	double x, y;
};

class Cluster {
	vector<POINT> points;
	POINT center;
	POINT prevCenter;
public:
	Cluster()
	{
		center = {"null", NULL, NULL};
	}
	Cluster(POINT firstCenter)
	{
		center = firstCenter;
		prevCenter = firstCenter;
	}
	~Cluster()
	{
		Clear();
	}
	void Clear();
	void Add(POINT);
	POINT GetCenter();
	POINT GetPrevCenter();
	void SetCenter();
	size_t Size();
	bool EqualPrevCenter();
	POINT& at(unsigned i);
};

bool operator == (POINT, POINT);
void InitialFrstCenters(vector<Cluster> clusters, vector<POINT> points);
void Attach(int countClusters, vector<Cluster> clusters, vector<POINT> points);
void Start(int countClusters, vector<Cluster> clusters, vector<POINT> points);