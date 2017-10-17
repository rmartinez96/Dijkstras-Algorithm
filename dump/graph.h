#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include "minheap.h"
using namespace std;

class directedGraph
{
private:
	class vertex;
	class edge;

	class vertex
	{
	public:
		int data;
		vector<edge> adjList;
		bool visited;
		vertex * pred;
		double weight;
		int index;

		vertex(int x)
		{
			data = x;
			weight = 0;
			pred = NULL;
		}
	};
	class edge
	{
	public:
		vertex * start;
		vertex * end;
		double weight;
		edge(vertex * v, vertex * u, double w)
		{
			start = v;
			end = u;
			weight = w;
		}
	};

	vector<vertex*> vertexList; //should really use.. hash table, or AVL-tree

	vertex * findvertex(int x)
	{
		return vertexList[x];
	}
public:
	~directedGraph()
	{
		//free all the (dynamically allocated) vertices.
	}

	void addVertex(int x)
	{
		vertexList.push_back(new vertex(x));
	}

	void addDirectedEdge(int x, int y, double w)
	{
		vertex * v = findvertex(x);
		vertex * u = findvertex(y);
		if (v == NULL || u == NULL)
		{
			cout << "Bleh" << endl;
		}
		edge e(v, u, w);
		v->adjList.push_back(e);
	}
	
	void addEdge(int x, int y, double w)
	{
		addDirectedEdge(x, y, w);
		addDirectedEdge(y, x, w);
	}

	void testDisplay()
	{
		for(int i = 0; i < vertexList.size(); i++)
		{
			cout << vertexList[i];
		}
	}

	void dijkstra(vertex * s)
	{
		initializeVertexVariables();
		s->weight = 0;
		minHeap<vertex*> MH;
		for (vector<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			MH.insert((*itr));
		}
		while (!MH.empty())
		{
			vertex * v = MH.extractMin();
			for (vector<edge>::iterator itr = v->adjList.begin(); itr != v->adjList.end(); itr++)
			{
				relax(*itr, MH);
			}
		}
	}

	void relax(edge e, minHeap<vertex*> &mh)
	{
		vertex * v = e.start;
		vertex * u = e.end;
		if (v->weight + e.weight < u->weight)
		{
			u->weight = v->weight + e.weight;
			u->pred = v;
			mh.fix(u);
		}
	}

	void initializeVertexVariables()
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			vertexList[i]->weight = INFINITY;
		}
	}
	
	double shortestPath(int a, int b)
	{
		vertex * tmp1 = findvertex(a);
		vertex * tmp2 = findvertex(b);
		clock_t startTime = clock();
		dijkstra(tmp1);
		clock_t endTime = clock();
		cout << "D's ALg took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " Seconds " << endl;
		return displayPath(a, b);
	}

	double displayPath	(int a, int b)
	{
		vertex * tmp1 = findvertex(a);
		vertex * tmp2 = findvertex(b);
		stack<vertex*> tmpstack;
		double c = 0;
		while (tmp1->data != tmp2->data)
		{
			tmpstack.push(tmp2);
			tmp2 = tmp2->pred;
		}
		//s.push(tmp1);
		while (!tmpstack.empty())
		{
			vertex * hold = tmpstack.top();
			cout << hold->data << " ";
			tmpstack.pop();
			if (tmpstack.empty())
			{
				c = hold->weight;
			}	
		}
		return c;
	}
};