/*************************************************************
* Author: James Nordquist
* Filename: stub.cpp
* Date Created: 3/11/19
* Modifications:
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 5 – Dijkstra minimal spanning tree
*
* Overview:
* This program is an application of the Dijkstra algorithim on a graph
*
* Input:
* The input is a map from Text.txt
*
* Output:
* The output of this program will be the distance between two cities,
* the time it takes to travel that distance, and the route to 
* get to those two cities
*
************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <crtdbg.h>
#include "Edge.h"
#include "Graph.h"
#include "Vertice.h"
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;
using std::strtok;
using std::getline;
using std::vector;
using std::find;
using std::queue;

/**********************************************************************
* Purpose: application of Dijkstra algorithim
*
* Precondition:
* tospan - graph filled with map data
*
* Postcondition:
* Outputs the distance between two vertexs on the graph, the time it takes to
* travel that distance, and the route to take. Exits once the user enters
* a city that is not in the graph
*
************************************************************************/
void dijkstraGraph(Graph<string, string> &tospan);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const int MAX_SIZE = 150;
	char buffer[MAX_SIZE];
	char *token;
	int weight;
	string vert1;
	string vert2;
	string edge;
	ifstream fin;
	Graph<string, string> map;
	fin.open("Text.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, 150);
			token = strtok(buffer, ",");
			vert1 = token;
			map.InsertVertex(vert1);
			token = strtok(nullptr, ",");
			vert2 = token;
			map.InsertVertex(vert2);
			token = strtok(nullptr, ",");
			edge = token;
			token = strtok(nullptr, ",");
			weight = atoi(token);
			map.InsertEdge(vert1, edge, vert2, weight);
		}
		fin.close();
	}
	dijkstraGraph(map);
	return 0;
}

void dijkstraGraph(Graph<string, string>& tospan)
{
	const int MAX_SIZE = 24901; //circumfrence of the earth, for safety reasons

	list<Vertice<string, string>> graphlist = tospan.GetVertices();
	list<Edge<string, string>> edges;
	list<Edge<string, string>>::iterator eitor;
	vector<Vertice<string,string>> verticesnon;
	Vertice<string, string> *current;
	vector<Edge<string, string>> hwy;
	Edge<string, string> edge;
	bool exists = true;
	int pro;
	vector<int> distance;
	vector<int> predecessor;
	string start;
	string end;

	while (exists)
	{
		pro = 0;
		predecessor.clear();
		distance.clear();
		hwy.clear();
		verticesnon.clear();

		cout << "Enter Start: ";
		getline(cin, start);

		if (find(graphlist.begin(), graphlist.end(), start) != graphlist.end())
		{
			list<Vertice<string, string>>::iterator liter = graphlist.begin();
			while (liter != graphlist.end())
			{
				verticesnon.push_back(*liter);
				liter++;
			}

			liter = graphlist.begin();
			int startindex = 0;

			while (liter->GetData() != start)
			{
				startindex++;
				liter++;
			}

			while (distance.size() != verticesnon.size())
			{
				Edge<string, string> temp("temp");
				distance.push_back(-1);
				predecessor.push_back(-1);
				hwy.push_back(temp);
			}

			distance[startindex] = 0;
		}
		else
		{
			cout << "Place not found" << endl;
			exists = false;
		}

		if (exists)
		{
			cout << "Enter End: ";
			getline(cin, end);
		}

		if (find(graphlist.begin(), graphlist.end(), end) == graphlist.end() && exists)
		{
			cout << "Place not found" << endl;
			exists = false;
		}

		while (pro < verticesnon.size() && exists)
		{
			int prevdist = MAX_SIZE;
			int index;
			int saveindex;

			for (index = 0; index < verticesnon.size(); index++)
			{
				if (distance[index] != -1 && distance[index] < prevdist && verticesnon[index].GetProcessed() == false)
				{
					saveindex = index;
					prevdist = distance[index];
					current = &verticesnon[index];
				}
			}

			index = saveindex;
			current->SetProcessed(true);
			edges = current->GetEdges();
			eitor = edges.begin();

			while (eitor != edges.end())
			{
				if (find(verticesnon.begin(), verticesnon.end(), eitor->GetDest()->GetData())->GetProcessed() == false)
				{
					vector<Vertice<string, string>>::iterator viter = verticesnon.begin();
					int startindex = 0;
					while (viter->GetData() != eitor->GetDest()->GetData())
					{
						viter++;
						startindex++;
					}
					if (distance[startindex] == -1 || distance[startindex] > (distance[index] + eitor->GetWeight()))
					{
						distance[startindex] = distance[index] + eitor->GetWeight();
						predecessor[startindex] = index;
						hwy[startindex] = *eitor;
					}
				}

				eitor++;
			}

			pro++;
		}

		if (exists)
		{
			int index = 0;
			double time = 0;
			int edistance = 0;
			double dtemp;

			while (verticesnon[index].GetData() != end)
			{
				index++;
			}

			stack<Edge<string, string>> hwytakenback;
			queue<Edge<string, string>> hwytakenfwrd;
			hwytakenback.push(hwy[index]);

			while (predecessor[index] != -1)
			{
				index = predecessor[index];
				hwytakenback.push(hwy[index]);
			}

			hwytakenback.pop();

			while (hwytakenback.empty() == false)
			{
				if (hwytakenback.top().GetData() == "I-5")
				{
					dtemp = hwytakenback.top().GetWeight();
					edistance += hwytakenback.top().GetWeight();
					hwytakenfwrd.push(hwytakenback.top());
					time += (dtemp / 65);
					hwytakenback.pop();
				}
				else
				{
					dtemp = hwytakenback.top().GetWeight();
					edistance += hwytakenback.top().GetWeight();
					hwytakenfwrd.push(hwytakenback.top());
					time += (dtemp / 55);
					hwytakenback.pop();
				}
			}

			cout << endl;
			cout << "Traveling from " << start << " to " << end << " will be a distance of " << edistance << " miles" << endl;
			cout << "It will take at least " << time << " hours" << endl;
			cout << "Route from " << start << " to " << end << endl;

			if (hwytakenfwrd.empty() == false)
			{
				string prevhwy = hwytakenfwrd.front().GetData();
				cout << prevhwy;
				hwytakenfwrd.pop();

				while (hwytakenfwrd.empty() == false)
				{
					if (prevhwy != hwytakenfwrd.front().GetData())
					{
						cout << ",";
						cout << hwytakenfwrd.front().GetData();
						prevhwy = hwytakenfwrd.front().GetData();
					}

					hwytakenfwrd.pop();

					if (hwytakenfwrd.empty() == true)
					{
						cout << endl;
					}
				}
			}
		}

		cout << endl;
	}
}