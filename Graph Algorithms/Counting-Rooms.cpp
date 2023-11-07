#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 1e5+1;
vector<vector<int>>adj(maxN+1);
vector<int>colors(maxN+1);

bool dfs(int node, int color)
{
  colors[node] = color;
  for (int neighbor : adj[node])
  {
    if (colors[neighbor] == color)
      return false;
    if (colors[neighbor] == 0 && !dfs(neighbor, 3-colors[node]))
      return false;
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i=1; i<=m; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=1; i<=n; i++)
  {
    if (colors[i] == 0 && !dfs(i, 1))
    {
      cout << "IMPOSSIBLE\n";
      return 0; 
    }
  }

  for (int i=1; i<=n; i++)
    cout << colors[i] << " ";
  
  return 0;
}