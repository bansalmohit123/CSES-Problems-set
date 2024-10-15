#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
    if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j]||grid[i][j]=='#'){
        return;
    }
    vis[i][j]=1;
    dfs(grid,vis,i+1,j);
    dfs(grid,vis,i-1,j);
    dfs(grid,vis,i,j+1);
    dfs(grid,vis,i,j-1);
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int rooms=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&grid[i][j]=='.'){
                rooms++;
                dfs(grid,vis,i,j);
            }
        }
    }
    cout << rooms << endl;
}