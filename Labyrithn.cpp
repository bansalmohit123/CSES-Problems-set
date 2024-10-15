#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = {i, j};
                q.push(start);
                vis[i][j] = 1;
            }
            if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1}; 
    char dir[] = {'U', 'R', 'D', 'L'};

    bool found = false;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != '#') {
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {row, col};

                if (grid[nrow][ncol] == 'B') {
                    end = {nrow, ncol};
                    found = true;
                    break;
                }
                
                q.push({nrow, ncol});
            }
        }
        
        if (found) break;
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

       
        string path = "";
        pair<int, int> cur = end;

        while (cur != start) {
            pair<int, int> prev = parent[cur.first][cur.second];
            if (cur.first == prev.first + 1) path += 'D';
            else if (cur.first == prev.first - 1) path += 'U';
            else if (cur.second == prev.second + 1) path += 'R';
            else if (cur.second == prev.second - 1) path += 'L';
            cur = prev;
        }

        reverse(path.begin(), path.end()); 
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}
