#include <iostream>
#include <vector>
using namespace std;

const int N = 30;
int ans;
bool vis[N];
vector<int> g[N];

void dfs(int u, int dep, vector<int>& cnt) {
    cnt[s[u] - 'A']++;
    vis[u] = true;
    if (g[u].empty()) {
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) odd++;
        }
        if (odd <= 1) ans++;
    }
    else {
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, dep + 1, cnt);
                cnt[s[v] - 'A']--;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x != -1) g[i].push_back(x);
        if (y != -1) g[i].push_back(y);
    }
    for (int i = 0; i < n; i++) {
        if (!g[i].empty()) {
            vector<int> cnt(26, 0);
            dfs(i, 0, cnt);
            for (int j = 0; j < N; j++) vis[j] = false;
        }
    }
    cout << ans << endl;
    return 0;
}
