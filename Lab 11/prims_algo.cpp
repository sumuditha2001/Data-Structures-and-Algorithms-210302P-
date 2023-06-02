#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>

using namespace std;

void print_MST(vector<vector<int>> MST,vector<vector<int>> graph){    //function for printing the MST
    cout<<" edge "<<"    "<<"      weight"<<endl;    //printing the header
    for (auto edge : MST){     //iterating over the MSt and printing the edges with their weights
        cout<<edge[0]<<" - "<<edge[1]<<"     =>      "<<graph[edge[0]][edge[1]]<<endl;
    }
}

vector<vector<int>> prims_algo(vector<vector<int>> graph,int start){
    vector<int> inside_vertices;   //for storing the vertices which are currently inside the MST
    vector<int> outside_vertices;   //for storing the vertices which are currently outside the MST
    vector<vector<int>> MST;      //for storing the MSt with corresponding weight values
    int size =graph.size();   //how many vertices are there

    inside_vertices.push_back(start);  //enter the start vertex in to the MST by inserting it to the inside vertices list
    for (int i=0;i<size;i++){   //enter the other vertices in to the outside vertices list
        if(i!=start){
        outside_vertices.push_back(i);
        }
    }
    int min;  //for storing the min weight at each iteration 
    int min_vertex;  //for storing the vertex connrcting the minimum edge
    int source_vertex;   //for storing the other vertex connecting the minimum weighted edge
    while (inside_vertices.size()<size){  //checking whether the current tree is connecting all the vertices or not
        min=INT_MAX;
    for (int in_vertex : inside_vertices){   //iterating over the eges to find the minimum
        for (int out_vertex : outside_vertices){
            if ((graph[in_vertex][out_vertex] <=min) && graph[in_vertex][out_vertex] !=0){   //checking for minimum for existing edges
                min = graph[in_vertex][out_vertex];
                min_vertex =out_vertex;
                source_vertex=in_vertex;
            }
        }
    }
    
    MST.push_back({source_vertex,min_vertex});   //adding the minimum weighted edge to the MST
    inside_vertices.push_back(min_vertex);   //updating the vertices which are currently inside the MST 
    outside_vertices.erase(remove(outside_vertices.begin(), outside_vertices.end(), min_vertex), outside_vertices.end());  //updating the vertices which are currently outside the MST
    }
    return MST;  //returning the calculated MST
}

int main(){

    vector<vector<int>> Adj_matrix={{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};    //Adj matrix for the given problem
    vector<vector<int>> MST =prims_algo(Adj_matrix,0);   //calling the prims algorithm
    print_MST(MST,Adj_matrix);   //printing the result
} 