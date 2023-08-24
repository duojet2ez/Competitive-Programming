#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream fin("factory.in");
ofstream fout("factory.out"); 

//use a stack for O(n) time complexity insert at start is costly for vector

int main() {

	int n; 
	fin >> n;
	vector<int> adjList[101]; 
	for (int i = 0; i < 101; i++)
	{
		adjList[i].push_back(-1); 
	}
	for (int i = 0; i < n - 1; i++) {
		int first; int second; fin >> first >> second;
		adjList[first].insert(adjList[first].begin(), second); 
	}

	int ans = -1; 
	for (int i = 1; i <= n; i++) {
		if (adjList[i][0] == -1) {
			ans = i; 
			break;
		}
	}
	fout << ans << '\n';
	return 0; 
}