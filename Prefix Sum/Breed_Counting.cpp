#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("bcount.in"); 
ofstream fout("bcount.out");



void setPrefixSum(vector<int>& cowArr, vector<int>& pSum, int num) {
	int count = 0; 
	for (int i = 0; i < cowArr.size(); i++) {
		if (cowArr[i] == num) pSum[i] = ++count;
		else {
			if (i == 0) pSum[i] = 0;
			else pSum[i] = pSum[i - 1];
		}
	}
}

int main() {
	int n, q; fin >> n >> q;
	vector<int> one(n);
	vector<int> two(n);
	vector<int> three(n);
	vector<int> cowArr(n);

	for (int i = 0; i < n; i++) {
		int x; fin >> x;
		cowArr[i] = x; 
	}
	//calculate prefix sums 
	setPrefixSum(cowArr, one, 1);
	setPrefixSum(cowArr, two, 2);
	setPrefixSum(cowArr, three, 3);



	for (int i = 0; i < q; i++) {
		int q1, q2; fin >> q1 >> q2; q1--; q2--; 
		int ans1, ans2, ans3;
		//one
		if (cowArr[q1] == 1) fout << one[q2] - one[q1] + 1 << " "; 
		else fout << one[q2] - one[q1] << " ";
		//2
		if (cowArr[q1] == 2) fout << two[q2] - two[q1] + 1 << " ";
		else fout << two[q2] - two[q1] << " ";
		//3
		if (cowArr[q1] == 3) fout << three[q2] - three[q1] + 1;
		else fout << three[q2] - three[q1];

		fout << '\n';
	}

	return 0; 

}
