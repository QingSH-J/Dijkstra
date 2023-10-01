//
//  main.cpp
//  最短路径算法
//
//  Created by 金心羽 on 2023/9/30.
//

#include<iostream>
#define MAXN 20
int n;
int Edge[MAXN][MAXN];
int S[MAXN];
int dist[MAXN];
int path[MAXN];

void Dijkstra(int v0){
    int i, j, k;
    for(i = 0; i < n; i ++)
    {
        dist[i] = Edge[v0][i]; S[i] = 0;
        if(i != v0 && dist[i] < INT_MAX){
            path[i] = v0;
        }
        else path[i] = -1;
    }
    S[v0] = 1; dist[v0] = 0;
    for(i = 0; i < n - 1; i ++){
        int min = INT_MAX;
        int u = v0;
        for(j = 0; j < n; j ++)
        {
            if(!S[j] && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
        }
        S[u] = 1;
        for(k = 0; k < n; k ++){
            if(!S[k] && Edge[u][k] < INT_MAX && dist[u] + Edge[u][k] < dist[k]){
                dist[k] = dist[u] + Edge[u][k];
                path[k] = u;
            }
        }
    }
}
