/*
 * An implementation of Ford-Fulkerson algorithm to find a maximum flow in a network. The input network is assumed to have NO PARALLEL ARCS.
 
 * Warning: this implementation is not fully tested, use at your own risk.
 * See http://www.giaithuatlaptrinh.com/?p=1483 for more details.
 *
 *  Created on: Sept 30, 2016
 *  Author: Hung Le
 */   
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define INFTY 100000000
#define TRUE 1
#define FALSE 0

int **C;	// the capacity matrix of the input graph
int **CF;	// the weighted adjacency matrix of the residual graph
int **F;	// the flow
int n,m;	// the number of vertices and arcs of the graph
int s,t;	// the source and the sink of the network

int *P;	   // the agumenting path, P[u] = v if u->v is in the path  and we set P[t] = t
int *Q;			// the reversal path of P
int *visited;	// to mark visited vertices by DFS

void Read();
void Print(int **A, int n);
void FordFulkerson();
void BuildResidualGraph();
void FindAugmentingPath();
void DFS(int v);
void Augment(int delta);
int GetFlowValue();

int main(){
	Read();
	FordFulkerson();
	printf("Flow Value: %d\t", GetFlowValue());
}

// read the input 
void Read(){
	n = 6;	m = 10;
	s = 0;  t = 5;
	// allocate memory for C and CF
	C = (int **)malloc(n*sizeof(int *));
	CF = (int **)malloc(n*sizeof(int *));
	int i = 0;
	for(; i < n ; i++){
		C[i] = (int *)malloc(n*sizeof(int));
		memset(C[i],0 , n*sizeof(int));
		CF[i] = (int *)malloc(n*sizeof(int));
	}
	// allocate memory for P, Q and visited
	P = (int *)malloc(n*sizeof(int));
	visited  = (int *)malloc(n*sizeof(int));	
	Q = (int *)malloc(n*sizeof(int));
	
	// read the arcs of the graph
	for(i = 0; i < m; i++){
		C[0][1] = 5;
		C[0][3] = 15;
		C[1][2] = 10;;
		C[1][4] = 5;
		C[2][3]= 3;
		C[2][5] = 20;
		C[3][1] = 5;
		C[3][4] = 5;
		C[4][2] = 2;
		C[4][5]= 5;
	}
}

void FordFulkerson(){
	// initialize the flow
	F = (int **)(malloc(n*sizeof(int*)));
	int i = 0;
	for(i = 0; i < n; i++){
		F[i]  = (int *)malloc(n*sizeof(int));
		memset(F[i], 0 , n*sizeof(int));
	}
	while(1){
		BuildResidualGraph();
		FindAugmentingPath();
		if (P[s] == -1){// there is no augmenting path
				break;
		}
		// find delta
		int delta = INFTY;
		int v = s;
		while(P[v] != v){ // note that P[t] = t
			delta = (CF[v][P[v]] < delta? CF[v][P[v]] : delta);
			v = P[v];
		}
		Augment(delta);		
	}
}

void BuildResidualGraph(){
	int i = 0;
	for(i = 0; i < n; i++){
		memset(CF[i],0 , n*sizeof(int)); // clear CF
	}
	int u = 0, v = 0;
	for(u = 0;u < n; u++){
		for(v = 0; v < n; v++){
			if(C[u][v] > 0){
				CF[u][v] = C[u][v] - F[u][v];
				if(F[u][v] > 0) CF[v][u] = F[u][v];
			}
		}
	}
}

void FindAugmentingPath(){
	// using DFS to find an augmenting path
	memset(visited, 0, n*sizeof(int));
	memset(Q,-1,n*sizeof(int));
	memset(P,-1,n*sizeof(int));	
	visited[s] = 1;
	Q[s] = s;
	DFS(s);
	// conver the path Q from t to s to the path P from s to t
	P[t] = t;	// t is the end of the path
	int v = t;
	while(Q[v] != v && Q[v] != -1){
		P[Q[v]] = v;
		v = Q[v];
	}
	if(v != s){		// there is no agumenting path
		P[s] = -1;	// mark P[s] = -1	
	}
}

void DFS(int v){
	int i = 0;
	for(i = 0; i < n; i++){
		if(i != v && visited[i] == 0 && CF[v][i] > 0){
			Q[i] = v;
			visited[i] = 1;
			DFS(i);			
		}
	}
}

void Augment(int delta){
	int i = 0;
	// augment
	int v = s;
	while(P[v] != v){
		if(C[v][P[v]] > 0) F[v][P[v]] += delta;
		else F[P[v]][v] -= delta;
		v = P[v];
	}
	
}

int GetFlowValue(){
	int f = 0;
	int i = 0;
	for(i = 0; i < n; i++){
		f+= F[s][i];
	}
	return f;		
}
void Print(int **A, int n){
		int i = 0; 
		int j = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("%d\t", A[i][j]);
			}
			printf("\n");
		}
}