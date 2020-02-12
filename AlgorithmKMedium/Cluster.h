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
	void SetCenterHandle(POINT);
	size_t Size();
	bool EqualPrevCenter();
	POINT& at(unsigned i);
};

bool operator == (POINT, POINT);
double LenthToCluster(POINT, POINT);
void InitialFrstCenters(vector<Cluster>&, vector<POINT>);
void Attach(size_t, vector<Cluster>&, vector<POINT>);
void Start(size_t, vector<Cluster>&, vector<POINT>);