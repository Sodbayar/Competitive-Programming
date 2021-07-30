#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cctype>
#include <bitset>
#include <stack>
#include <iterator>
#include <cctype>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define oo (int)1e9 + 7
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
typedef long long ll;
using namespace std;

//https://leetcode.com/problems/top-k-frequent-words

#define pd pair<int, string>
struct myComp {
	bool operator()(pd const& a, pd const& b)
		const noexcept {

		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first; //esregeer ni
	}
};
vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string> ans;
	unordered_map<string, int> dict;

	for (string word : words) {
		dict[word]++;
	}
	priority_queue<pd, vector<pd>, myComp> pq;
	for (auto it = dict.begin(); it != dict.end(); it++) {
		pq.push({it->second, it->first});
	}

	while (k--) {
		
		ans.push_back(pq.top().second);
		pq.pop();
	}


	return ans;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	vector<int> veci;
	veci.pb(1);
	veci.pb(1);
	veci.pb(2);
	veci.pb(2);
	veci.pb(2);
	veci.pb(2);
	veci.pb(3);
	veci.pb(3);
	veci.pb(3);
	sort(veci.begin(), veci.end(), cmp);
	for (int u : veci) {
		cout << u << ' ';
	}
	//rearrangeBarcodes(veci);
}
