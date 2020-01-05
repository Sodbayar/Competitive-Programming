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


int solve(string str, int n) {

	int count = 1;
	string prev = str.substr(0, n);
	string tmp;
	string ret = "";
	int i = n;
	for (i = n; i + n - 1 < str.size(); i+=n) {
		tmp = str.substr(i, n);
		if (tmp == prev) {
			count++;
		}
		else {
			if (count == 1) {
				ret += prev;
			}
			else {
				ret += to_string(count);
				ret += prev;
			}
			prev = tmp;
			count = 1;
		}

		if (i + n + n - 1 >= str.size()) {
			if (count > 1)
				ret += to_string(count);
			ret += tmp;
		}
	}
	while (i < str.size()) {
		ret += str[i++];
	}
	//cout << ret << endl;
	return ret.size();
}


int solution(string s) {
	int answer = oo;
	if (s.size() == 1) return 1;
	forl(i, 1, s.size() / 2) {
		answer = min(answer, solve(s, i));
	}


	return answer;
}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	//cout << solve("ababcdcdababcdcd", 2) << endl;
	cout << solution("xx") << endl;
}


//3
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

int bigLock[200][200];
int num = 100;

int N = 0, M = 0;


void copier(vector<vector<int>>& lock) {
	memset(bigLock, 0, sizeof bigLock);
	loop(i, N) {
		loop(j, N) {
			bigLock[i + num][j + num] = lock[i][j];
		}
	}
}

bool checker() {
	loop(i, N) {
		loop(j, N) {
			if (!bigLock[i + num][j + num]) return 0;
		}
	}
	return 1;
}

bool drawLock(int x, int y, vector<vector<int>>& key, int dir) {
	if (dir == 0) {
		int row = x;
		int col = y;
		loop(i, M) {
			col = y;
			loop(j, M) {
				if (key[i][j]) {
					if (!bigLock[row][col]) {
						bigLock[row][col] = 1;
					}
					else return 0;
				}
				col++;
			}
			row++;
		}
	}
	else if (dir == 1) {
		int row = x;
		int col = y;
		for (int i = M - 1; i >= 0; i--) {
			col = y;
			for (int j = 0; j < M; j++) {
				if (key[j][i]) {
					if (!bigLock[row][col]) {
						bigLock[row][col] = 1;
					}
					else return 0;
				}
				col++;
			}
			row++;
		}

	}
	else if (dir == 2) {
		int row = x;
		int col = y;
		for (int i = M - 1; i >= 0; i--) {
			col = y;
			for (int j = M - 1; j >= 0; j--) {
				if (key[i][j]) {
					if (!bigLock[row][col]) {
						bigLock[row][col] = 1;
					}
					else return 0;
				}
				col++;
			}
			row++;
		}
	}
	else {
		int row = x;
		int col = y;
		for (int i = 0; i < M; i++) {
			col = y;
			for (int j = M - 1; j >= 0; j--) {
				if (key[j][i]) {
					if (!bigLock[row][col]) {
						bigLock[row][col] = 1;
					}
					else return 0;
				}
				col++;
			}
			row++;
		}
	}
	return 1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	N = lock.size();
	M = key.size();

	for (int dir = 0; dir < 4; dir++) {
		for (int i = num - M + 1; i < num + N; i++) {
			for (int j = num - M + 1; j < num + N; j++) {

				copier(lock);
				if (drawLock(i, j, key, dir)) {
					if (checker()) return 1;
				}
			}
		}
	}
	return 0;
}

//4
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

unordered_map<int, vector<string>> dict;
map<string, int> dp;


vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (auto u : words) {
		dict[u.size()].pb(u);
	}

	for (auto u : queries) {
		int cnt = 0;

		if (dict[u.size()].empty()) {
			answer.pb(0);
			continue;
		}

		if (dp[u] != 0) {
			if (dp[u] == -1) answer.pb(0);
			else answer.pb(dp[u]);
			continue;
		}




		int idx = 0;
		bool flag = 0;

		if (u[0] == '?') {
			flag = 1;
			while (idx < u.size() && u[idx] == '?') idx++;

		}
		else {
			while (idx < u.size() && u[idx] != '?') idx++;
		}


		if (idx == u.size()) {
			cnt = dict[u.size()].size();
		}
		else {
			cnt = 0;
			for (auto v : dict[u.size()]) {
				if (flag) {
					int i = idx;
					for (i = idx; i < v.size(); i++) {
						if (v[i] != u[i]) break;
					}
					if (i == v.size()) cnt++;


				}
				else {
					int i = 0;
					for (i = 0; i < idx; i++) {
						if (v[i] != u[i]) break;
					}
					if (i == idx) cnt++;

				}

			}
		}
		answer.pb(cnt);
		dp[u] = cnt;
		if (cnt == 0) dp[u] = -1;
	}

	return answer;
}



int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	map<int, int> sda;
	vector<string> words;
	words.pb("frodo");
	words.pb("front");
	words.pb("frost");
	words.pb("frozen");
	words.pb("frame");
	words.pb("kakao");
	vector<string> query;
	query.pb("fro??");
	query.pb("????o");
	query.pb("fr???");
	query.pb("fro???");
	query.pb("pro?");
	vector<int> ret = solution(words, query);

	for (auto u : ret) {
		cout << u << " ";
	}
}


//5
