#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


typedef struct Coodinate {
	int x;
	int y;
	int z;
	int planetNum;
}Coord;


typedef struct Edge {
	int A;
	int B;
	int cost;
	Edge(int A, int B, int cost) : A(A), B(B), cost(cost) {};
}Edge;

int parent[100000];

bool compareX(Coord a, Coord b)
{
	return a.x < b.x;
}

bool compareY(Coord a, Coord b)
{
	return a.y < b.y;
}

bool compareZ(Coord a, Coord b)
{
	return a.z < b.z;
}

bool compareCost(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int find(int n)
{
	if (parent[n] == n)
		return n;

	return parent[n] = find(parent[n]);	//����
}

void init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
}


void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	parent[a] = b;
}


//������ ����� ���� �����׷����̹Ƿ� N(N-1)/2     N^2
//�༺�� �ִ� 10���� �̹Ƿ� 10��*10�� = 100��.. + �޸��ʰ�
//sort�� �ð����⵵ nlogn�� �̿�
int main()
{
	int n;
	int cnt = 0;
	int totalCost = 0;
	Coord temp;
	vector<Coord> planet;
	vector<Edge> edge;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp.x >> temp.y >> temp.z;
		temp.planetNum = i;
		planet.push_back(temp);
	}

	// x�� ���� �������� ����
	sort(planet.begin(), planet.end(), compareX);
	for (int i = 0; i < planet.size() - 1; i++)
		edge.push_back(Edge(planet.at(i).planetNum, planet.at(i + 1).planetNum, abs(planet.at(i).x - planet.at(i + 1).x)));

	// y�� ���� �������� ����
	sort(planet.begin(), planet.end(), compareY);
	for (int i = 0; i < planet.size() - 1; i++)
		edge.push_back(Edge(planet.at(i).planetNum, planet.at(i + 1).planetNum, abs(planet.at(i).y - planet.at(i + 1).y)));

	// z�� ���� �������� ����
	sort(planet.begin(), planet.end(), compareZ);
	for (int i = 0; i < planet.size() - 1; i++)
		edge.push_back(Edge(planet.at(i).planetNum, planet.at(i + 1).planetNum, abs(planet.at(i).z - planet.at(i + 1).z)));

	// = ������ �������� n-1��,  edge���Ϳ� �ִ� ���� 3(n-1)��

	//edge ���� 
	sort(edge.begin(), edge.end(), compareCost);

	//parent �ʱ�ȭ
	init(n);

	for (int i = 0; i < edge.size(); i++)
	{

		if (find(edge.at(i).A) == find(edge.at(i).B))
			continue;

		merge(edge.at(i).A, edge.at(i).B);
		totalCost += edge.at(i).cost;

		cnt++;

		if (cnt == n - 1)
			break;

	}

	printf("%d", totalCost);

	return 0;
}
