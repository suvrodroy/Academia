#include "bits/stdc++.h"
using namespace std;
int n,m;
vector<int> parent, Rank;
void make_set(int v) {
    parent[v] = v;
    Rank[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
signed main(){
    cin >> n;
    parent.resize(n+1);
    Rank.resize(n+1);
    for (int i = 0; i <= n; i++)
        make_set(i);
    vector<Edge> edges;
    int a,b,c;
    while (m--){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    int cycleCnt = 0;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            union_sets(e.u, e.v);
        }
        else
            cycleCnt++;
    }
    cout << "Total cycles = " << cycleCnt << endl;
}