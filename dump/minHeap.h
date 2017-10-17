#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class thing>
class minHeap
{
private:
	vector<thing> item;


	int parent(int i)
	{
		if (i == 0)
			return i;
		else if (i % 2 == 0)
			return(i - 1) / 2;
		else
			return i / 2;
	}
	int lchild(int i)
	{
		return i + (i + 1);
	}

	int rchild(int i)
	{
		return (i * 2) + 2;
	}

	void heapinsert(double x)
	{
		item.push_back(x);
		bubbleUp(item.size() - 1);
	}

	void bubbleDown(int i)
	{
		int left = lchild(i);
		int right = rchild(i);

		int small = i;

		if (left < item.size() && item[left]->weight < item[i]->weight)
		{
			item[i]->index = left;
			item[left]->index = i;
			small = left;
		}
		if (right < item.size() && item[right]->weight < item[small]->weight)
		{
			item[i]->index = right;
			item[right]->index = i;
			small = right;
		}

		if (small != i)
		{
			//item[i]->index = small;
			//item[small]->index = i;
			swap(item[i], item[small]);
			bubbleDown(small);
		}



		//if (lchild(i) > item.size() - 1)
		//{
		//	return;
		//}
		//else if (rchild(i) > item.size() - 1)
		//{
		//	if (item[i]->weight > item[lchild(i)]->weight)
		//	{
		//		item[i]->index = lchild(i);
		//		item[lchild(i)]->index = i;
		//		swap(item[i], item[lchild(i)]);
		//		bubbleDown(lchild(i));
		//	}
		//	//return;
		//}
		//else
		//{
		//	if (item[i]->weight > item[rchild(i)]->weight || item[i]->weight > item[lchild(i)]->weight)
		//	{
		//		if (item[lchild(i)]->weight < item[rchild(i)]->weight && item[i]->weight >item[lchild(i)]->weight)
		//		{
		//			item[i]->index = lchild(i);
		//			item[lchild(i)]->index = i;
		//			swap(item[i], item[lchild(i)]);
		//			bubbleDown(lchild(i));
		//		}
		//	}
		//	else //if (item[rchild(i)]->weight > item[lchild(i)]->weight)
		//	{
		//		if (item[i]->weight > item[rchild(i)]->weight)
		//		{
		//			item[i]->index = rchild(i);
		//			item[rchild(i)]->index = i;
		//			swap(item[i], item[rchild(i)]);
		//			bubbleDown(rchild(i));
		//		}
		//	}
		//}
	}



public:
	minHeap()
	{

	}
	void insert(thing x)
	{
		item.push_back(x);
		int last = item.size() - 1;
		bubbleUp(last);
	}

	void display()
	{
		for (int i = 0; i < item.size(); i++)
		{
			cout << item[i] << endl;
		}
	}

	thing extractMin()
	{
		thing x;
		x = item[0];
		item[item.size() - 1]->index = 0;
		swap(item[0], item[item.size() - 1]);
		//x = item[item.size() - 1; ]
		item.pop_back();
		bubbleDown(0);
		return x;
	}

	bool empty()
	{
		if (item.size() == 0)
		{
			return true;
		}

		return false;
	}


	void bubbleUp(int i)
	{
		if (item[parent(i)]->weight > item[i]->weight)
		{
			item[i]->index = parent(i);
			item[parent(i)]->index = i;
			swap(item[i], item[parent(i)]);
			bubbleUp(parent(i));
		}
		else
		{
			item[i]->index = i;
		}
	}

};
