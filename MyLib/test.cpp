#include <bits/stdc++.h>
#include <D:\Competitive_Programming\MyLib\MyLib.h>
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    generate_graph graph;
    cout << "hi";
    auto edge = graph.output(10, 33);
    for (auto e : edge) {
        auto vertex = e.first;
        ll cost = e.second;
        cout << vertex.first << " " << vertex.second << " " << cost << endl;
    }
    
    

}