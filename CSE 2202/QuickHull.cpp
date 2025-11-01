#include "bits/stdc++.h"
using namespace std;

#define int long long
#define dub long double
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef unordered_map<int,int> umap;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define all(a) a.begin(),a.end()
#define endl '\n'
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e5 + 10, Mod = 1e9 + 7;
int n,m;
int findDistance(pii p, pii p1, pii p2)
{
    return abs((p2.first - p1.first) * (p.second - p1.second) -
               (p2.second - p1.second) * (p.first - p1.first));
}
int findSide(pii p, pii p1, pii p2)
{
    int res = (p2.first - p1.first) * (p.second - p1.second) -
              (p2.second - p1.second) * (p.first - p1.first);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}
vii findHull(vii &points, pii leftPoint, pii rightPoint)
{
    if (points.empty()) return {};

    int maxDist = -1;
    int idx = -1;
    for (int i = 0; i < (int)points.size(); i++)
    {
        int d = findDistance(points[i], leftPoint, rightPoint);
        if (d > maxDist)
            maxDist = d, idx = i;
    }

    pii farthestPoint = points[idx];

    vii leftSet, rightSet;
    for (int i = 0; i < (int)points.size(); i++)
    {
        if (points[i] == leftPoint || points[i] == rightPoint || points[i] == farthestPoint)
            continue;
        if (findSide(points[i], leftPoint, farthestPoint) == 1)
            leftSet.push_back(points[i]);
        if (findSide(points[i], rightPoint, farthestPoint) == -1)
            rightSet.push_back(points[i]);
    }

    vii leftHull = findHull(leftSet, leftPoint, farthestPoint);
    vii rightHull = findHull(rightSet, farthestPoint, rightPoint);

    vii result;
    result.insert(result.end(), leftHull.begin(), leftHull.end());
    result.push_back(farthestPoint);
    result.insert(result.end(), rightHull.begin(), rightHull.end());
    return result;
}

vii quickHull(vii &points)
{
    if (points.size() < 3) return points;

    pii leftPoint = points[0], rightPoint = points[0];
    for (int i = 1; i < (int)points.size(); i++)
    {
        if (points[i].first < leftPoint.first)
            leftPoint = points[i];
        if (points[i].first > rightPoint.first)
            rightPoint = points[i];
    }

    vii leftSet, rightSet;
    for (int i = 0; i < (int)points.size(); i++)
    {
        int side = findSide(points[i], leftPoint, rightPoint);
        if (side == 1) leftSet.push_back(points[i]);
        else if (side == -1) rightSet.push_back(points[i]);
    }

    vii leftHull = findHull(leftSet, leftPoint, rightPoint);
    vii rightHull = findHull(rightSet, rightPoint, leftPoint);

    vii hull;
    hull.push_back(leftPoint);
    hull.insert(hull.end(), leftHull.begin(), leftHull.end());
    hull.push_back(rightPoint);
    hull.insert(hull.end(), rightHull.begin(), rightHull.end());
    return hull;
}

void solve() {
    vii points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0},
                  {0, 0}, {3, 3}, {4, 2}, {2, 4}, {1, 3}};

    vii hull = quickHull(points);
    cout << "Convex Hull:\n";
    for (auto &p : hull)
    {
        cout << "(" << p.first << ", " << p.second << "), ";
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
