#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<pair<int, int>>> adjList;
int radius = 0;

void DFS(vector<bool>& visited, int current, int weight)
{
    visited[current] = true;
    radius = max(weight, radius);

    for(auto p : adjList[current])
    {
        int node = p.first;
        int w = p.second;

        if(!visited[node])
            DFS(visited, node, weight + w);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    adjList.resize(N+1);

    for(int i = 0; i < N-1; ++i)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adjList[n1].push_back({n2, w});
        adjList[n2].push_back({n1, w});
    }

    for(int i = 1; i < N+1; ++i)
    {
        vector<bool> visited(N+1);
        DFS(visited, i, 0);
    }

    cout << radius;
}