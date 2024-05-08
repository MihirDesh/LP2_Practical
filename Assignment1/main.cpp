#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

class SocialNetwork
{
private:
    int V;
    vector<vector<int>> adj;

public:
    SocialNetwork(int users)
    {
        V = users;
        adj.resize(V);
    }

    void addFriendship(int user1, int user2)
    {
        adj[user1].push_back(user2);
        adj[user2].push_back(user1);
    }

    bool dfs(int start, int target, < vector<bool> & visited)
    {
        if (start == target)
            return true;

        visited[start] = true;

        for (int neighbour : adj[start])
        {
            if (!visited[neighbour])
                if (dfs(neighbour, target, visited))
                    return true;
        }
        return false;
    }

    int bfs(int start, int target)
    {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty())
        {
            int user = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (user == target)
                return distance;

            for (int neighbour : adj[user])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push({neighbour, distance + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    SocialNetwork network(6);

    network.addFriendship(0, 1);
    network.addFriendship(0, 2);
    network.addFriendship(1, 3);
    network.addFriendship(2, 4);
    network.addFriendship(3, 5);

    vector<bool> visitedDFS(6, false);
    bool isConnectedDFS = network.dfs(0, 5, visitedDFS);
    cout << "DFS: Users 0 and 5 are " << (isConnectedDFS ? "connected" : "not connected") << endl;

    int distanceBFS = network.bfs(0, 5);
    if (distanceBFS != -1)
    {
        cout << "BFS: Distance between users 0 and 5 is: " << distanceBFS << endl;
    }
    else
    {
        cout << "BFS: There is no path between 0 and 5" << endl;
    }
}