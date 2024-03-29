// group project - EV charging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//#define infinity = 99;

//Graph Variables

int numberofVertices = 23;
int currentVertices;
int distanceMatrix[23][23]; //Representation of the graph and it's paths/distances
string startingPoint;
int distanceArray[23]; //Storing the distance values for the number of nodes, with respect to the starting point
int parentArray[23]; //Index represents key for the node, value represents the parent
bool nodeVisited[23] = {0}; // Has a node been visited? Here we initialize it to 0
int chargeStation[4] = { 7, 10, 16, 19 };

string locationName(int value) {
    switch (value)
    {
    case 0:
        return "A";
    case 1:
        return "B";
    case 2:
        return "C";
    case 3:
        return "D";
    case 4:
        return "E";
    case 5:
        return "F";
    case 6:
        return "G";
    case 7:
        return "H";
    case 8:
        return "I";
    case 9:
        return "J";
    case 10:
        return "K";
    case 11:
        return "L";
    case 12:
        return "M";
    case 13:
        return "N";
    case 14:
        return "O";
    case 15:
        return "P";
    case 16:
        return "Q";
    case 17:
        return "R";
    case 18:
        return "S";
    case 19:
        return "T";
    case 20:
        return "U";
    case 21:
        return "V";
    case 22:
        return "W";
    }
}
string toLowercase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
              [](unsigned char c) { return tolower(c); });
    return lowerStr;
}
int location(string name) {
    if (toLowercase(name) == "a") {
        return 0;
    }
    if (toLowercase(name) == "b") {
        return 1;
    }
    if (toLowercase(name) == "c") {
        return 2;
    }
    if (toLowercase(name) == "d") {
        return 3;
    }
    if (toLowercase(name) == "e") {
        return 4;
    }
    if (toLowercase(name) == "f") {
        return 5;
    }
    if (toLowercase(name) == "g") {
        return 6;
    }
    if (toLowercase(name) == "h") {
        return 7;
    }
    if (toLowercase(name) == "i") {
        return 8;
    }
    if (toLowercase(name) == "j") {
        return 9;
    }
    if (toLowercase(name) == "k") {
        return 10;
    }
    if (toLowercase(name) == "l") {
        return 11;
    }
    if (toLowercase(name) == "m") {
        return 12;
    }
    if (toLowercase(name) == "n") {
        return 13;
    }
    if (toLowercase(name) == "o") {
        return 14;
    }
    if (toLowercase(name) == "p") {
        return 15;
    }
    if (toLowercase(name) == "q") {
        return 16;
    }
    if (toLowercase(name) == "r") {
        return 17;
    }
    if (toLowercase(name) == "s") {
        return 18;
    }
    if (toLowercase(name) == "t") {
        return 19;
    }
    if (toLowercase(name) == "u") {
        return 20;
    }
    if (toLowercase(name) == "v") {
        return 21;
    }
    if (toLowercase(name) == "w") {
        return 22;
    }
}
void initializeDistances() //Function to initialize distance values
{
    for (int i = 0; i < numberofVertices; i++)
    {
        parentArray[i] = i;
        //distanceArray[i] = infinity;
        distanceArray[i] = 99;
    }
    distanceArray[location(startingPoint)] = 0;
}


int getClosestNode() //Returns the closest unvisited node
{
    //int minimumDistanceValue = infinity;
    int minimumDistanceValue = 99;
    int closestNode = 0;

    for (int i = 0; i < 23; i++)
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

        for (int nearbyNode = 0; nearbyNode < 23; nearbyNode++)
        {
            //If the closest node is not 99, it is nearby. Updates distance only if the newer distance of the node is lesser than.
            if (distanceMatrix[closestUnvisitedNode][nearbyNode] != 0 &&  distanceArray[nearbyNode] > distanceArray[closestUnvisitedNode] + distanceMatrix[closestUnvisitedNode][nearbyNode])
            {
                distanceArray[nearbyNode] = distanceArray[closestUnvisitedNode] + distanceMatrix[closestUnvisitedNode][nearbyNode]; //Updating the distance of a nearby node to the distance of the closest node
                parentArray[nearbyNode] = closestUnvisitedNode;
            }
        }
    }

}

void showGraph()
{
    /*for (int i = 0; i < 23; i++)
    {
        cout << locationName(i) << "\t\t\t" << distanceArray[i] << "\t\t\t" << " ";

        cout << locationName(i) << " ";
        int parentNode = parentArray[i];

        while (parentNode != location(startingPoint))
        {
            cout << " --> " << locationName(parentNode) << " ";
            parentNode = parentArray[parentNode];
        }
        cout << " --> " << locationName(location(startingPoint));
        cout << endl;
    }*/
    int shortest = 0;
    for (int i = 0; i < 4; i++) {
        cout << distanceArray[chargeStation[i]] << " " << locationName(chargeStation[i]) << " ";
        int parentNode = parentArray[chargeStation[i]];

        while (parentNode != location(startingPoint))
        {
            cout << " --> " << locationName(parentNode) << " ";
            parentNode = parentArray[parentNode];
        }
        cout << " --> " << locationName(location(startingPoint)) << endl;

        if (distanceArray[chargeStation[i]] < distanceArray[chargeStation[shortest]]) {
            shortest = i;
        }
    }
    cout << locationName(chargeStation[shortest]) << " got the shortest distance\n";
}


int main()
{
    string myText;
    string file_contents;
    ifstream MyReadFile("EVChargeStation.csv");

    if (MyReadFile.is_open()) {
            int numRows = 0;
            while (getline(MyReadFile, myText) && numRows < 23) {
                stringstream ss(myText);
                int col = 0;

                while (getline(ss, myText, ',') && col < 23) {
                    // Convert string to integer
                    distanceMatrix[numRows][col] = stoi(myText);
                    col++;
                }

                numRows++;
            }

        MyReadFile.close();
    }

    //Taking User Input to build the graph
    cout << "Start:\t\t" << "Destination:\n";
    for (int i = 0; i < 23; i++) {
        cout << locationName(i) << ": \t\t";
        for (int j = 0; j < 23; ++j) {
            if (distanceMatrix[i][j] > 0) {
                cout << "--> " << locationName(j) << "(" << distanceMatrix[i][j] << ")";
            }
        }
        cout << endl;
    }
    cout << "Please input the Starting Node: A to W" << endl;
    cin >> startingPoint;
    initializeDistances();
    dijkstraAlgorithm();

    showGraph();

}
