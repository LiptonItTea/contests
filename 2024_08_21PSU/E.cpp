#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dist2(long long x1, long long y1, long long x2, long long y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool compareEdges(long long* e1, long long* e2){
    return e1[2] < e2[2];
}

bool compareQueries(long long* q1, long long* q2){
    return q1[1] < q2[1];
}

class DSU {
    public:
        int n;
        long long** parents;

        DSU (int n){
            this->n = n;
            parents = new long long*[n];
            for (int i = 0; i < n; i++){
                parents[i] = new long long[2];
                parents[i][0] = i;
                parents[i][1] = 1;
            }
        }

        int getParent(int u){
            return (parents[u][0] == u) ? (u) : (parents[u][0] = getParent(parents[u][0]));
        }

        void unionParents(int u, int v){
            int parentU = getParent(u);
            int parentV = getParent(v);

            if(parentU == parentV){
                return;
            }

            parents[parentU][0] = parentV;
            parents[parentV][1] += parents[parentU][1];
        }
};

int main () {
    int n;
    cin >> n;

    long long** coords = new long long*[n];
    for (int i = 0; i < n; i++){
        coords[i] = new long long[2];
        cin >> coords[i][0] >> coords[i][1];
    }

    long long** edges = new long long*[n * (n - 1) / 2];
    int edgeCounter = 0;
    for (int i = 0; i < n - 1; i++){
        long long x = coords[i][0],
            y = coords[i][1];
        for (int j = i + 1; j < n; j++){
            long long ax = coords[j][0],
                ay = coords[j][1];

            long long d2 = dist2(x, y, ax, ay);

            edges[edgeCounter] = new long long[3];
            edges[edgeCounter][0] = i;
            edges[edgeCounter][1] = j;
            edges[edgeCounter][2] = d2;
            edgeCounter++;
        }
    }
    sort(edges, edges + edgeCounter, compareEdges);
    // for (int i = 0; i < edgeCounter; i++){
    //     cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << "\n";
    // }

    int m;
    cin >> m;
    long long** queries = new long long*[m];
    for (int i = 0; i < m; i++){
        long long k, r;
        cin >> k >> r;
        r *= r;

        queries[i] = new long long[3];
        queries[i][0] = k;
        queries[i][1] = r;
        queries[i][2] = i;
    }
    sort(queries, queries + m, compareQueries);

    DSU dsu (n);
    int smallestEdge = 0;
    vector<long long> answers;
    answers.reserve(m);
    for (int i = 0; i < m; i++){
        long long k = queries[i][0];
        long long r2 = queries[i][1];
        long long index = queries[i][2];

        while(smallestEdge < edgeCounter && edges[smallestEdge][2] <= r2){
            dsu.unionParents(edges[smallestEdge][0], edges[smallestEdge][1]);
            smallestEdge++;
        }

        int parent = dsu.getParent(k - 1);
        answers[index] = dsu.parents[parent][1];
    }

    for (int i = 0; i < m; i++)
        cout << answers[i] << "\n";
}