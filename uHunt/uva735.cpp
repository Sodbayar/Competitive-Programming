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
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define oo (int)1e9
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
using namespace std;

set<int> scores;
vector<int> possibleScores;
map<int, set<string>> comb;
map<int, int> perm;

void pre() {
	forl(i, 0, 20) {
		scores.insert(i);
		scores.insert(i * 2);
		scores.insert(i * 3);
	}
	scores.insert(50);

	for (auto u : scores)
		possibleScores.pb(u);

	loop(i, possibleScores.size()) {
		loop(j, possibleScores.size()) {
			loop(k, possibleScores.size()) {
				int sum = possibleScores[i] + possibleScores[j] + possibleScores[k];
				perm[sum]++;
				string str = "";
				str += '0' + i;
				str += '0' + j;
				str += '0' + k;
				sort(str.begin(), str.end());
				comb[sum].insert(str);
			}
		}
	}
}



int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/


	pre();
	int n;
	while (cin >> n) {
		if (n <= 0) {
			cout << "END OF OUTPUT\n";
			break;
		}
		else {
			if (comb[n].empty() && !perm[n]) {
				cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
			}
			else {
				cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb[n].size() << ".\n";// << endl;
				cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm[n] << ".\n";// << endl;
			}
			cout << "**********************************************************************\n";

		}
	}

}
