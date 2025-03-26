#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, int> findPair(ll k) {
    ll count = 0;
    for (int n = 1; ; ++n) {
        ll m_start = 0;
        ll m_end = n - 1;
        ll numPairs = (m_end - m_start + 1);  
        
        if (count + numPairs >= k) {  
            int m = m_start + (k - count - 1);
            return {m, n};
        }
        count += numPairs;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    vector<ll> queries(T);
    for (int i = 0; i < T; ++i) {
        cin >> queries[i];
    }

    for (ll k : queries) {
        pair<int, int> result = findPair(k);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
