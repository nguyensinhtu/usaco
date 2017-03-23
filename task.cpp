/*
ID: nguyens1
LANG: C++
TASK: sort3
*/


#include <bits/stdc++.h>
using namespace std;

int N;
int *Array;

int main(){
	ifstream fpin("sort3.in");
	ofstream fpout("sort3.out");
	fpin >> N;
	Array = new int[N];

	for (int i = 0; i < N; ++i){
		fpin >> Array[i];
	}

	//int *Array1 = new int[N];
	int MinimumExchange = 0;
	int Max = Array[0];
	for (int i = 1; i < N; ++i){
		if (Max > Array[i]){
			if (Max == Array[i-1])
				MinimumExchange++;
			else
				MinimumExchange += Max - Array[i];
		}else if (Max < Array[i])
			Max = Array[i];

	}


	fpout << MinimumExchange << endl;
	return 0;
}
