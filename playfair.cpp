#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_set>
using namespace std;


void removeSpaces(string &s) {
	auto it = s.begin();
	while (it != s.end()) {
		*it == ' ' ? s.erase(it) : it++;
	}
}

void lowerCase(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += ('a' - 'A');
		}
	}
}
void evenString(string &s) {
	if (s.length() % 2 != 0) {
		s += 'z';
	}
}

void generate(string &key, string* keyTable) {
	unordered_set<char> st(key.begin(), key.end());
	if (st.find('j') == st.end()) {
		st.insert('j');
	}
	char x = 'a';
	for (int i = 0, k = 0; i < 5; i++) {
		for (int j = 0; j < 5 ; j++) {
			if (k < key.size()) {
				keyTable[i][j] = key[k++];
			}
			else {
				while (st.find(x) != st.end()) {
					x++;
				}
				keyTable[i][j] = x;
				x++;
			}
		}
	}
}

vector<int> search(string* table, char a, char b) {
	vector<int> ans(4);
	if (a == 'j')
		a = 'i';
	if (b == 'j')
		b = 'i';

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (table[i][j] == a) {
				ans[0] = i;
				ans[1] = j;
			}
			else if (table[i][j] == b) {
				ans[2] = i;
				ans[3] = j;
			}
		}
	}
	return ans;
}
void encrypt(string &s, string* keyTable) {
	for (int i = 0; i < s.size(); i = i + 2) {
		vector<int> ans = search(keyTable, s[i], s[i + 1]);

		if (ans[0] == ans[2]) {
			s[i] = keyTable[ans[0]][(ans[1] + 1) % 5];
			s[i + 1] = keyTable[ans[0]][(ans[3] + 1) % 5];
		}
		else if (ans[1] == ans[3]) {
			s[i] = keyTable[(ans[0] + 1) % 5][ans[1]];
			s[i + 1] = keyTable[(ans[2] + 1) % 5][ans[1]];
		}
		else {
			s[i] = keyTable[ans[0]][ans[3]];
			s[i + 1] = keyTable[ans[2]][ans[1]];
		}
	}
}
void encryption(string &s, string &key) {
	removeSpaces(s);
	lowerCase(s);
	evenString(s);

	removeSpaces(key);
	lowerCase(key);

	string keyTable[5];
	generate(key, keyTable);
	encrypt(s, keyTable);
}
int main()
{
	string key, s;
	cin >> key >> s;
	encryption(s, key);
	cout << "Encrypted message: " << s << endl;
}

