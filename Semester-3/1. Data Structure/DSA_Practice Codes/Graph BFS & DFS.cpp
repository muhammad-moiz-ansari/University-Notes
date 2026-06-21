#include <iostream>
#include <queue>
#include <stack>
using namespace std;


///////////////////////////////  Graph with Adj Matrix  ///////////////////////////////

class Graph
{
private:
    int vertices; // Number of vertices in the graph
    int** adjMatrix; // Adjacency matrix

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix = new int* [v];
        for (int i = 0; i < v; ++i)
        {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; ++j)
                adjMatrix[i][j] = 0;
        }
    }

    // Destructor
    ~Graph()
    {
        for (int i = 0; i < vertices; ++i)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    // Add edge to the graph (undirected)
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // BFS traversal
    void BFS(int start)
    {
        bool* visited = new bool[vertices]; // Keep track of visited nodes
        for (int i = 0; i < vertices; ++i)
            visited[i] = false;

        queue<int> q; // Queue for BFS

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < vertices; ++i)
            {
                if (adjMatrix[node][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;

        delete[] visited;
    }

    // DFS traversal (recursive helper)
    void DFSUtil(int node, bool* visited)
    {
        visited[node] = true;


        for (int i = 0; i < vertices; ++i)
        {
            if (adjMatrix[node][i] == 1 && !visited[i])
                DFSUtil(i, visited);
        }
        cout << node << " ";
    }

    // DFS traversal
    void DFS(int start)
    {
        bool* visited = new bool[vertices]; // Keep track of visited nodes
        for (int i = 0; i < vertices; ++i)
            visited[i] = false;

        cout << "DFS Traversal starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    Graph g(9); // Create a graph with 9 nodes (0 to 8)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 0);
    g.addEdge(3, 7);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 2);
    g.addEdge(5, 8);
    g.addEdge(6, 2);
    g.addEdge(6, 4);
    g.addEdge(7, 3);
    g.addEdge(7, 8);
    g.addEdge(8, 4);
    g.addEdge(8, 5);
    g.addEdge(8, 7);


    // Perform BFS and DFS traversals
    g.BFS(1);
    g.DFS(1);

    return 0;
}


///////////////////////////////  Graph with Adj List  ///////////////////////////////

//
//#include <iostream>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//class Graph {
//private:
//    int vertices; // Number of vertices in the graph
//    int** adjList; // Adjacency list implemented using arrays
//    int* listSizes; // Sizes of each adjacency list
//
//public:
//    // Constructor
//    Graph(int v) {
//        vertices = v;
//        adjList = new int* [v];
//        listSizes = new int[v];
//
//        for (int i = 0; i < v; ++i) {
//            adjList[i] = nullptr;
//            listSizes[i] = 0;
//        }
//    }
//
//    // Destructor
//    ~Graph() {
//        for (int i = 0; i < vertices; ++i) {
//            delete[] adjList[i];
//        }
//        delete[] adjList;
//        delete[] listSizes;
//    }
//
//    // Add edge to the graph (undirected)
//    void addEdge(int u, int v) {
//        // Add v to u's list
//        int* newUList = new int[listSizes[u] + 1];
//        for (int i = 0; i < listSizes[u]; ++i) {
//            newUList[i] = adjList[u][i];
//        }
//        newUList[listSizes[u]] = v;
//        delete[] adjList[u];
//        adjList[u] = newUList;
//        ++listSizes[u];
//
//        // Add u to v's list
//        int* newVList = new int[listSizes[v] + 1];
//        for (int i = 0; i < listSizes[v]; ++i) {
//            newVList[i] = adjList[v][i];
//        }
//        newVList[listSizes[v]] = u;
//        delete[] adjList[v];
//        adjList[v] = newVList;
//        ++listSizes[v];
//    }
//
//    // BFS traversal
//    void BFS(int start) {
//        bool* visited = new bool[vertices]; // Keep track of visited nodes
//        for (int i = 0; i < vertices; ++i)
//            visited[i] = false;
//
//        queue<int> q; // Queue for BFS
//
//        visited[start] = true;
//        q.push(start);
//
//        cout << "BFS Traversal starting from node " << start << ": ";
//
//        while (!q.empty()) {
//            int node = q.front();
//            q.pop();
//            cout << node << " ";
//
//            for (int i = 0; i < listSizes[node]; ++i) {
//                int neighbor = adjList[node][i];
//                if (!visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push(neighbor);
//                }
//            }
//        }
//        cout << endl;
//
//        delete[] visited;
//    }
//
//    // DFS traversal (recursive helper)
//    void DFSUtil(int node, bool* visited)
//    {
//        visited[node] = true;
//        cout << node << " ";
//
//        for (int i = 0; i < listSizes[node]; ++i)
//        {
//            int neighbor = adjList[node][i];
//            if (!visited[neighbor])
//                DFSUtil(neighbor, visited);
//        }
//    }
//
//    // DFS traversal
//    void DFS(int start) {
//        bool* visited = new bool[vertices]; // Keep track of visited nodes
//        for (int i = 0; i < vertices; ++i) {
//            visited[i] = false;
//        }
//
//        cout << "DFS Traversal starting from node " << start << ": ";
//        DFSUtil(start, visited);
//        cout << endl;
//
//        delete[] visited;
//    }
//};
//
//int main() {
//    Graph g(5); // Create a graph with 5 nodes (0 to 4)
//
//    // Add edges
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 3);
//    g.addEdge(1, 4);
//    g.addEdge(2, 4);
//
//    // Perform BFS and DFS traversals
//    g.BFS(0);
//    g.DFS(0);
//
//    return 0;
//}
