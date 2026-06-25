#ifndef MAGICIANLIB
#define MAGICIANLIB

#include <bits/stdc++.h>
using namespace std;

vector<int> solveAlice(const vector<vector<int>> &adj);

vector<vector<int>> solveBob(const vector<int> &S);

int main(int argc, char **argv) {

	vector<vector<int>> adj({
		vector<int>({4, 1}), // vertex 0
		vector<int>({}), 	 // vertex 1
		vector<int>({0, 3}), // vertex 2 (root)
		vector<int>({}),	 // vertex 3
		vector<int>({})      // vertex 4
	});

	//the i-th card on the i-th vertex
	vector<string> cards({"4T", "7B", "3B", "5B", "6T"});
	int N = cards.size();

	//Call Alice function
	vector<int> alice = solveAlice(adj);

	//Judge shuffle cards
	auto shuffled_cards = cards;
	auto shuffled_alice = alice;
	vector<pair<int,int>> swaps({make_pair(0, 2), make_pair(1, 4), make_pair(0, 3)});
	for (auto sw : swaps){//more swap if you want...
		swap(shuffled_cards[sw.first], shuffled_cards[sw.second]);
		swap(shuffled_alice[sw.first], shuffled_alice[sw.second]);
	}

	//Call Bob function
	vector<vector<int>> bob = solveBob(shuffled_alice);

	//Check the answer
	//Function: Generate tree with card-vertices
	auto Look = [&](vector<vector<int>> adj, vector<string> cards){
		map<string, vector<string>> ans;
		for (int x=0; x<N; ++x)
			for (int y : adj[x]) ans[cards[x]].push_back(cards[y]);
		return vector<pair<string, vector<string>>>(ans.begin(), ans.end());
	};
	if (Look(adj, cards) == Look(bob, shuffled_cards)) cout << "OK" << endl;
	else cout << "WA" << endl;
}

#endif