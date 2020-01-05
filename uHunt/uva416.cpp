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

int num[20], n;
vector<int> vec;

void pre() {
	//Zero
	num[0] = (1 << 6) - 1;

	//One
	num[1] |= (1 << 1);
	num[1] |= (1 << 2);

	//Two
	num[2] = (1 << 7) - 1;
	num[2] &= ~(1 << 2);
	num[2] &= ~(1 << 5);

	//Three
	num[3] = (1 << 7) - 1;
	num[3] &= ~(1 << 4);
	num[3] &= ~(1 << 5);

	//Four
	num[4] = (1 << 7) - 1;
	num[4] &= ~(1 << 0);
	num[4] &= ~(1 << 3);
	num[4] &= ~(1 << 4);

	//Five
	num[5] = (1 << 7) - 1;
	num[5] &= ~(1 << 1);
	num[5] &= ~(1 << 4);

	//Six
	num[6] = (1 << 7) - 1;
	num[6] &= ~(1 << 1);

	//Seven
	num[7] = 1;
	num[7] |= (1 << 1);
	num[7] |= (1 << 2);

	//Eight
	num[8] = (1 << 7) - 1;

	//Nine
	num[9] = (1 << 7) - 1;
	num[9] &= ~(1 << 4);
}


bool solve(int pos, int countDown, int off) {
	//cout << pos << "  " << countDown << "  " << off << endl;
	if (pos == n) return 1;

	if (countDown < 0) return 0;

	int newOff = off;
	if ((num[countDown] | vec[pos]) == num[countDown]) {
		loop(j, 7) {
			if (off & (1 << j)) {
				if (vec[pos] & (1 << j)) {
					return 0;
				}
			}
		}
		loop(j, 7) {
			if ((num[countDown] & (1 << j)) && ((vec[pos] & (1 << j)) == 0)) {
				newOff |= (1 << j);
			}
		}
		return solve(pos + 1, countDown - 1, newOff);
	}
	return false;
}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	pre();
	while (cin >> n, n) {
		vec.clear();
		loop(i, n) {
			string in; cin >> in;
			//getline(cin, in);
			int number = 0;
			loop(i, in.size()) {
				if (in[i] == 'Y') number |= (1 << i);
			}
			vec.pb(number);
		}
		bool flag = 0;
		for (int i = 9; i >= 0; i--) {
			if ((num[i] | vec[0]) == num[i]) {
				int off = 0;
				loop(j, 7) {
					if ((num[i] & (1 << j)) && ((vec[0] & (1 << j)) == 0)) {
						off |= (1 << j);
					}
				}
				//cout << "OFF : " << off << endl;
				if (solve(1, i - 1, off)) {
					flag = 1;
					cout << "MATCH\n";
					break;
				}

			}
		}

		if (!flag) {
			cout << "MISMATCH\n";
		}

	}
}
