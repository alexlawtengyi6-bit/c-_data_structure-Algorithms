#include <iostream>
#include <vector>
#include <queue> // For BFS

// DFS Function (using a queue for iterative implementation)
void dfs(const std::vector<std::vector<int>>& adjList, int startNode, std::vector<bool>& visited) {
    std::queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// BFS Function (using a queue)
void bfs(const std::vector<std::vector<int>>& adjList, int startNode) {
    std::queue<int> q;
    std::vector<bool> visited(adjList.size(), false); // Track visited nodes

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void TopUpSystem::analyzeUserRelationships() {
    // Assuming the 'users' database contains user IDs and a list of related users.
    // The adjacency list represents these relationships.

    // Example Adjacency List (Replace with actual database data retrieval)
    std::vector<std::vector<int>> adjList(10); // User IDs from 0 to 9
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[3].push_back(1);
    adjList[3].push_back(4);
    adjList[4].push_back(3);

    std::cout << "DFS traversal: ";
    std::vector<bool> visitedDFS(adjList.size(), false);
    dfs(adjList, 0, visitedDFS);
    std::cout << std::endl;

    std::cout << "BFS traversal: ";
    bfs(adjList, 0);
    std::cout << std::endl;
}