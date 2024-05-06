#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

// Graph class using adjacency list representation
class SocialNetwork
{
private:
    int V;                   // Number of users (vertices)
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    SocialNetwork(int users)
    {
        V = users;
        adj.resize(V);
    }

    // Function to add a friendship (edge) between two users
    void addFriendship(int user1, int user2)
    {
        adj[user1].push_back(user2);
        adj[user2].push_back(user1); // Because it's an undirected graph (friendship is mutual)
    }

    // Depth First Search (DFS) to check if there's a path between two users
    bool dfs(int start, int target, vector<bool> &visited)
    {
        if (start == target)
            return true;

        visited[start] = true;

        // Recursively visit all adjacent users
        for (int neighbor : adj[start])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, target, visited))
                    return true;
            }
        }

        return false;
    }

    // Breadth First Search (BFS) to find the shortest path (degrees of separation) between two users
    int bfs(int start, int target)
    {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q; // Queue to maintain users and their distances
        q.push({start, 0});      // Start BFS from 'start' user with distance 0
        visited[start] = true;

        while (!q.empty())
        {
            int user = q.front().first;
            int distance = q.front().second;
            q.pop();

            // If we reach the target user, return the distance
            if (user == target)
                return distance;

            // Visit all adjacent users
            for (int neighbor : adj[user])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push({neighbor, distance + 1});
                }
            }
        }

        return -1; // If no path is found
    }
};

// Example usage
int main()
{
    // Create a social network graph with 6 users
    SocialNetwork network(6);

    // Add friendships (edges)
    network.addFriendship(0, 1);
    network.addFriendship(0, 2);
    network.addFriendship(1, 3);
    network.addFriendship(2, 4);
    network.addFriendship(3, 5);

    // Perform DFS to check if there's a path between two users (0 and 5)
    vector<bool> visitedDFS(6, false);
    bool isConnectedDFS = network.dfs(0, 5, visitedDFS);
    cout << "DFS: Users 0 and 5 are " << (isConnectedDFS ? "connected" : "not connected") << endl;

    // Perform BFS to find the shortest path (degrees of separation) between two users (0 and 5)
    int distanceBFS = network.bfs(0, 5);
    if (distanceBFS != -1)
        cout << "BFS: The distance (degrees of separation) between users 0 and 5 is " << distanceBFS << endl;
    else
        cout << "BFS: There is no path between users 0 and 5" << endl;

    return 0;
}
