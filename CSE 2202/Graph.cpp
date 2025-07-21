#include "bits/stdc++.h"
using namespace std;

vector<int> dfs_traversal_list;
vector<int> dfs_traversal_list_st;
void dfs(int node, vector<vector<int>> &g, bool *visited)
{
    dfs_traversal_list.push_back(node);
    visited[node] = true;
    for (auto to : g[node])
    {
        if (visited[to]) continue;
        dfs(to,g,visited);
    }
}
void dfs_stack(int root, vector<vector<int>> &g, int n)
{
    stack<int> st;
    st.push(root);
    bool visited[n+1] = {false};
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (visited[node]) continue;
        dfs_traversal_list_st.push_back(node);
        visited[node] = true;
        for (auto to : g[node])
        {
            if (!visited[to])
                st.push(to);
        }
        // if (is_leaf) st.pop();
    }

}
void bfs(int root, vector<vector<int>> &g,int n)
{
    vector<vector<int>> level(n+1);
    queue<int> q;
    vector<int> level_of(n+1);
    bool visited[n+1] = {false};
    q.push(root);
    level[0].push_back(root);
    visited[root] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto to : g[node])
        {
            if (!visited[to])
            {
                visited[to] = true;
                q.push(to);
                level_of[to] = level_of[node] + 1;
                level[level_of[to]].push_back(to);
            }
        }
    }
    for (int v = 0; v < n; v++)
    {
        if (level[v].empty()) continue;
        cout << "Level " << v << ": ";
        for (auto i : level[v])
        {
            cout << i << " ";
        }
        cout  << endl;
    }
    cout << "End of BFS\n";
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> adj(n+1,vector<int>(n+1));
    for (int i = 0;i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    bfs(1,g,n);
    dfs_stack(1,g,n);
    bool visited[n+1] = {false};
    dfs(1,g,visited);

    cout << "\nPrinting DFS Traversal List Using Stack\n";
    for (auto i : dfs_traversal_list_st) cout << i << " ";
    cout << endl;
    cout << "\nPrinting DFS Traversal List Using Recursion\n";
    for (auto i : dfs_traversal_list) cout << i << " ";
    cout << endl;
}
