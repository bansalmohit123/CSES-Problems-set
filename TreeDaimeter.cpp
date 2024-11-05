#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i = 0; i < n-1; i++){

        int  a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    vector<int> vis(n+1, 0);
    vector<int> dis(n+1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                dis[it] = dis[node] + 1;
            }
        }
    }
    int maxDis = 0, node = 0;
    for(int i = 1; i <= n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            node = i;
        }
    }
    vector<int> dis1(n+1, 0);
    vector<int> vis1(n+1, 0);
    q.push(node);
    vis1[node] = 1;
    while(!q.empty()){
        int node1 = q.front();
        q.pop();
        for(auto it: adj[node1]){
            if(!vis1[it]){
                vis1[it] = 1;
                q.push(it);
                dis1[it] = dis1[node1] + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dis1[i]);
    }
    cout << ans << endl;
    return 0;
    




}