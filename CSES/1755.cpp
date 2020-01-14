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

#define modulo (int)1e9 + 7


int main() {

	string str; cin >> str;

	int alphabet[26] = { 0, };

	for (auto& c : str) {
		alphabet[c - 'A']++;
	}

	bool flag = false;
	char oddChar = '*';

	int st = 0, en = str.size() - 1;
	loop(i, 26) {
		if (alphabet[i] % 2) {
			if (flag) {
				cout << "NO SOLUTION\n";
				return 0;
			}
			flag = true;
			oddChar = 'A' + i;
		}
		else {
			while (alphabet[i]) {
				alphabet[i] -= 2;
				str[st++] = 'A' + i;
				str[en--] = 'A' + i;
			}
		}
	}

	if (flag) {
		while (st <= en) {
			str[st++] = oddChar;
		}
	}
	cout << str << endl;
}
