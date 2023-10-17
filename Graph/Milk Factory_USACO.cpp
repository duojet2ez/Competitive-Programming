#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("factory.in");
ofstream fout("factory.out");

vector<int> adjList[101];
int allVisited = 0; 

void dfs(int node, int destination) {
	if (node == destination) { allVisited++; return; }
	for (int i = 0; i < adjList[node].size(); i++) {
		int neighbor = adjList[node][i]; 
		dfs(neighbor, destination); 
	}
}


int main() {	
	int n; fin >> n;

	for (int i = 1; i < n; i++) {
		int a, b; fin >> a >> b;
		adjList[a].push_back(b); 
	}

	//go through check range of adjList (size of n) for a size = 0  and then run dfs on every node to that making sure all connect if they do return i if not return -1
	for (int i = 1; i <= n; i++) {
		if (adjList[i].size() == 0) {
			//run dfs on everything that is not i
			for (int j = 1; j <= n; j++) {
				if (j == i) continue;
				dfs(j, i); 
			}
			if (allVisited == n - 1) { fout << i << '\n';  return 1; }
			else break; 
		}
	}
	fout << -1 << '\n';    

	return 0;
}


//for usaco grading don't need to reset globals same for CF. Leetcode must reset
