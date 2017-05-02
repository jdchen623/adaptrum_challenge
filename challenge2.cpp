#include <iostream>
#include <vector>
#include <set>

using namespace std;
//defines edges

#define edge1 {"S1", "A", "-2"}
#define edge2 {"S1", "B", "-3"}
#define edge3 {"A", "C", "-1"}
#define edge4 {"A","B", "-9"}
#define edge5 {"B", "S2", "-8"}
#define edge6 {"C", "S2", "-1"}

//struct that holds the path and money earned on a specific route
struct route {
    vector<string> path;
    int money;
};

//finds the best path home by recursively calling find path after traversing each possible edge
route findPath(string start, string end, int nCities,int nEdges,
              vector<string> cities, vector<int> M_i, vector< vector<string> > edges,
              set<string> visited, vector<string> path, int money, int index,route &bestRoute) {
    visited.insert(start);
    path.push_back(start);
    money += M_i[index];

    //base case: if path has reached the destination S2, then check if path makes the most money
    if(start == end) {
        if(money > bestRoute.money) {
            bestRoute.path = path;
            bestRoute.money = money;
            return bestRoute;
        }
    }
    //checks each edge to find the each possible next city in path
    for(vector<string> eachEdge : edges) {
        if(visited.find(eachEdge[1]) ==  visited.end() && eachEdge[0] == start) {   //if edge starts with current city and ends with a city that has not been visited

            //finds the index of the city that the edge points to
            for(int nextIndex = 0; nextIndex < nCities; nextIndex++) {
                if(eachEdge[1] == cities[nextIndex] ){
                    int nextMoney = money + atoi(eachEdge[2].c_str()); //decrements the cost of travel

                    bestRoute = findPath(eachEdge[1], end, nCities, nEdges,
                                            cities, M_i, edges, visited, path, nextMoney, nextIndex, bestRoute);  //recursively calls current function with a different start and money parameter
                }
            }
        }
    }

    return bestRoute;
}

//calls a recursive function with the provided parameters
int goHome(int nCities,int nEdges, vector<string> cities, vector<int>M_i,vector< vector<string> > edges) {
    string start = cities[0];
    string end = cities[cities.size() - 1];
    set<string> visited;
    vector<string> path;
    int money = 0;
    int index = 0;
    route bestRoute; //struct that will hold the path and money earned from the best route
    bestRoute.money = 0;
    findPath(start, end, nCities, nEdges, cities, M_i, edges, visited, path, money, index, bestRoute);  //function that returns the maximum money to be earned
    return bestRoute.money;
}


//main function I used for testing
int main()
{
    int nCities = 5;
    int nEdges = 6;
    vector<string> cities {"S1", "A", "B", "C", "S2"};
    vector<int> M_i {5, 15, 16, -1, 0};
    vector< vector<string> > edges {edge1, edge2, edge3, edge4, edge5, edge6};
    cout << goHome(nCities, nEdges, cities, M_i, edges) << endl;
    return 0;
}

