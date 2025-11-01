#include "bits/stdc++.h"
using namespace std;
int n,m;
vector<int> parent, Size;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
signed main(){
    cin >> n >> m;
    vector<Edge> edges;
    int a,b,c;
    while (m--){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    int cost = 0;
    vector<Edge> result;
    parent.resize(n+1);
    Size.resize(n+1);
    for (int i = 0; i <= n; i++)
        parent[i] = i, Size[i] = 0;
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    cout << "Edges in MST:\n";
    for (auto i : result) cout << i.u << " " << i.v << endl;
}