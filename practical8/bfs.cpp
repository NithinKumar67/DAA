#include <iostream>
#include <queue>
using namespace std;

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[5] = {0};
    queue<int> q;

    int start = 0;
    q.push(start);
    visited[start] = 1;

    cout << "BFS: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
