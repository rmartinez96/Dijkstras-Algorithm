// Raul Martinez
// raul.martinez01@utrgv.edu

#include "linkedList.h"
#include <string>
#include <iostream>
#include <cmath>
#include "directedWeightGraph.h"

using namespace std;

class chainingTable
{
private:
	//hash table conists of a table of lists
	LL * <vertex>table;

	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

public:
	//use this to measure how good your
	//hash function is.
	double averageSearchCost()
	{
		double sumSquares = 0;
		for (int i = 0; i<capacity; i++)
		{
			sumSquares += (table[i].size()*table[i].size());
		}
		return sumSquares / numItems;
	}

	chainingTable();
	int hash(string x);
	void insert(string x);
	bool contains(string x);
};

chainingTable::chainingTable()
{
	capacity = 10000003;
	table = new LL[capacity];
	numItems = 0;
}

int chainingTable::hash(string x)
{
	unsigned int hash = 11;
	for (int i = 0; i < x.length(); i++)
	{
		hash = hash * 41 + x[i];
	}
	return hash % capacity;
}

void chainingTable::insert(vertex * x)
{
	table[hash(x)].insert(x);
	numItems++;
}

bool chainingTable::contains(string x)
{
	return table[hash(x)].search(x);
}