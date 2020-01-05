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
#define oo (int)1e9 + 42
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
using namespace std;



int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int lis[] = {0, 12, 4, 2, 6, 9};

	int len[101], idx[101];
	loop(i, 100) len[i] = 1;
	memset(idx, 0, sizeof idx);

	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < i; j++) {
			if (lis[i] > lis[j] && len[i] < len[j] + 1) {
				len[i] = len[j] + 1;
				idx[i] = j;
			}
		}
	}
	loop(i, 6) {
		cout << len[i] << ' ';
	}cout << endl;
	loop(i, 6) {
		cout << idx[i] << ' ';
	}
}
