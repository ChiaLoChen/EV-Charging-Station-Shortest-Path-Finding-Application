// group project - EV charging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
//#define infinity = 99;

//Graph Variables

int numberofVertices;
int distanceMatrix[23][23]; //Representation of the graph and it's paths/distances
int startingPoint;
int distanceArray[23]; //Storing the distance values for the number of nodes, with respect to the starting point
int parentArray[100]; //Index represents key for the node, value represents the parent
bool nodeVisited[100] = {0}; // Has a node been visited? Here we initialize it to 0


void initializeDistances() //Function to initialize distance values
{
    for (int i = 0; i < numberofVertices; i++)
    {
        parentArray[i] = i;
        //distanceArray[i] = infinity;
        distanceArray[i] = 99;
    }
    distanceArray[startingPoint] = 0;
}

int getClosestNode() //Returns the closest unvisited node
{
    //int minimumDistanceValue = infinity;
    int minimumDistanceValue = 99;
    int closestNode = 0;

    for (int i = 0; i < numberofVertices; i++)
    {
        if (!nodeVisited[i] && distanceArray[i] < minimumDistanceValue)
        { //If a node is unvisited and its distance is less than current minimum value, update the current minimum value to a lower distance, as well as the value of the closest node
            minimumDistanceValue = distanceArray[i];
            closestNode = i;
        }
    }
    return closestNode;
}

void dijkstraAlgorithm()
{
    for (int i = 0; i < numberofVertices; i++) //Should run until all nodes are visited
    {
        int closestUnvisitedNode = getClosestNode();
        nodeVisited[closestUnvisitedNode] = true; //Marking the closest unvisited node as visited

        for (int nearbyNode = 0; nearbyNode < numberofVertices; nearbyNode++)
        {
            //If the closest node is not 99, it is nearby. Updates distance only if the newer distance of the node is lesser than.
            if (distanceMatrix[closestUnvisitedNode][nearbyNode] != 99 &&  distanceArray[nearbyNode] > distanceArray[closestUnvisitedNode] + distanceMatrix[closestUnvisitedNode][nearbyNode])
            {
                distanceArray[nearbyNode] = distanceArray[closestUnvisitedNode] + distanceMatrix[closestUnvisitedNode][nearbyNode]; //Updating the distance of a nearby node to the distance of the closest node
                parentArray[nearbyNode] = closestUnvisitedNode;
            }
        }
    }
}

void showGraph()
{
    cout << "Node: \t\t\t Closest Distance: \t\t\t Closest Node";

    for (int i = 0; i < numberofVertices; i++)
    {
        cout << i << "\t\t\t" << distanceArray[i] << "\t\t\t" << " ";

        cout << i << " ";
        int parentNode = parentArray[i];

        while (parentNode != startingPoint)
        {
            cout << " <-- " << parentNode << " ";
            parentNode = parentArray[parentNode];
        }
        cout << endl;
    }
}

class nodes {

};

int main()
{
   /* string myText;
    string file_contents;
    ifstream MyReadFile("");
    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            stringstream ss(myText);
            string token;

            getline(ss, token, ',');
            id = stoi(token);

            getline(ss, token, ',');
            name = trim(token);

            getline(ss, token, ',');
            price = stof(token);

            getline(ss, token, ',');
            category = trim(token);

            ss >> id >> name >> price >> category;
            products.push_back(Product(id, name, price, category));
        }
    }*/

    //Taking User Input to build the graph
    cout << "Please input the number of vertices: " << endl;
    cin >> numberofVertices;
    for (int i = 0; i < numberofVertices; i++)
    {
        for (int j = 0; j < numberofVertices; j++)
        {
            cin >> distanceMatrix[i][j];
        }
    }

    cout << "Please input the Starting Node: " << endl;
    cin >> startingPoint;
    initializeDistances();
    dijkstraAlgorithm();
    showGraph();

}
