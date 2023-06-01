#include <iostream>
#include <limits>

using namespace std;

void dijkstas (int Adj_matrix [6][6],int start){   //dijksta's algo for 6 by 6 graph
    bool visited[6]={false};   //declaring an array to store the visited vertices and initiallizing all the vertices to not visited(false)
    int minimum_time[6];   //array to update the minimum time values
    for (int i=0;i<6;i++){    //initializing the times between other vertices to infinity(very large value)
        minimum_time[i]=INT_MAX;
    }
    minimum_time[start]=0;   //as no time is taken to travel from start vertex to itself set it as to 0
    
    
    for(int x=0;x<5;x++){   //iterating for 5 times to calculate the minimum times.
        int min_index;
        int min=INT_MAX;
        for (int i=0;i<6;i++){
            if (visited[i]==false  &&  minimum_time[i] <= min) {
                min =minimum_time[i];
                min_index=i;  //calculating the index of the vertex with minimum time
            }   
        }
       
        visited[min_index]=true;   //updating the vertex as to visited
        for (int j=0 ; j<6 ;j++){
            bool is_edge = Adj_matrix[min_index][j] ;   //finding is there exists an edge
            bool is_visited = visited[j];   //finding whether the vertex is visited before
            if((minimum_time[min_index]+Adj_matrix[min_index][j] <=minimum_time[j]) && (is_edge) && (!is_visited)){ //if the vertex is not visited and there exists an edge s.t.min time from source to the vertex is less than the current min time of the vertex update it
                minimum_time[j]=minimum_time[min_index]+Adj_matrix[min_index][j];
            }
        }
    }
    for (int i=0;i<6;i++){   //providing the output
        if (start !=i){
        cout << "minimum time from city " << start << " to " << i << " => " << minimum_time[i] << endl;
        }
    }
}  

int main(){     //representatiion of the graph as a adjacent matrix
    int Adj_matrix[6][6] ={{0,10,0,0,15,5},{10,0,10,30,0,0},{0,10,0,12,5,0},{0,30,12,0,0,20},{15,0,5,0,0,0},{5,0,0,20,0,0}};
    dijkstas (Adj_matrix,5);

    return 0;
}

