#include <bits/stdc++.h>
using namespace std;


struct subsets{
	int parent;
	int rank;
};

int find(subsets sub[], int x){
	if (x != sub[x].parent){
		sub[x].parent = find(sub, sub[x].parent);
	}

	return sub[x].parent;
}

void Union(subsets sub[], int x, int y){
	int xroot = find(sub, x);
	int yroot = find(sub, y);
	if (sub[xroot].rank < sub[yroot].rank){
		sub[xroot].parent = yroot;
	}else if (sub[xroot].parent > sub[yroot].parent)
		sub[yroot].parent = xroot;
	else{
		sub[yroot].parent = xroot;
		sub[xroot].rank++;
	}
}

int T, M;

int main() {
	freopen("input.in", "r", stdin);
	// freopen("output1.txt", "w", stdout);
	
	cin >> T >> M;
	subsets *sub = new subsets[T + 1];
	for (int i = 1; i <= T; i++){
		sub[i].parent = i;
		sub[i].rank = 0;
	}

	for (int i = 0; i < M; ++i){
		int a, b;
		cin >> a >> b;
		Union(sub, a, b);
	}

	int count = 0;
	for (int i = 1; i <= T; ++i){
		int tem = 1;
		for (int j = i + 1; j <= T; ++j){
			if (find(sub, i) == find(sub, j))
				tem++;
			else{
				i = j - 1;
				break;
			}
		}
		count += tem;
	}

	cout << count << endl;
	return 0;
}