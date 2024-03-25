#include <iostream>
#include <vector>
#include<queue>
using namespace std;

void BFSRecursive(const vector<vector<pair<int, int>>> &graph, queue<int> &q,
                  vector<bool> &discovered) {
  if (q.empty())
    return;
  int v = q.front();
  q.pop();
  cout << v << " ";
  for(auto u : graph[v]) {
    if (!discovered[u.first])
      discovered[u.first] = true;
    q.push(u.first);
  }
  BFSRecursive(graph, q, discovered);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n, vector<pair<int, int> >(m));
    // undirected graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    // directed graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    queue<int> q;
    vector<bool> discovered;
    BFSRecursive(graph, q, discovered);
}
