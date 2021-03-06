#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int R, C;
bool visited[110][110];
 
int dr[8] = {0, 0, 1, 1, 1,-1,-1,-1};
int dc[8] = {1, -1, 0, 1,-1,0,-1, 1};

vector <string> M;

bool valid(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}
 
int dfs(int r, int c){
    visited[r][c] = 1;
    int cnt = 1;
    for(int k=0; k<8; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(valid(nr, nc) && M[r][c] == M[nr][nc] && !visited[nr][nc])
            cnt += dfs(nr, nc);
    }
    return cnt;
}
 
int main(){
	while(cin>>R>>C){
		if(R==0 && C==0) break;
		
		M = vector <string> (R);
		for(int i=0; i<R; i++)
			cin>>M[i];
			 
		memset(visited, 0, sizeof(visited));
			 
		vector <int> V;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(!visited[i][j] && M[i][j] !='.'){
					V.push_back(dfs(i, j));
				}
			}
		}
		
		int contador =0;
		for(int j= 0; j<V.size();j++){
			if(V[j] == 1) contador++;
		}
		cout<<contador<<endl;
	}
    return 0;
}