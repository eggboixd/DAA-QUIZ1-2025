#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

vector<ull> sequence;
unordered_map<ull, pair<int, int>> indexToPair;  

void generateSequence(int requiredK) {
    set<ull> values;
    int m = 0, n = 1;
    
    while ((int)values.size() < requiredK) { 
        for (m = 0; m < n; ++m) {
            ull num = (1ULL << m) + (1ULL << n);
            values.insert(num);
            indexToPair[num] = {m, n};
        }
        ++n;
    }

    sequence.assign(values.begin(), values.end());
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    int maxK = 0;
    vector<int> queries(T);
    for (int i = 0; i < T; ++i) {
        cin >> queries[i];
        maxK = max(maxK, queries[i]);
    }

    generateSequence(maxK);  

    for (int k : queries) {
        --k;
        if (k >= (int)sequence.size()) {
            cout << "-1 -1\n";  
        } else {
            pair<int, int> p = indexToPair[sequence[k]];  
            cout << p.first << " " << p.second << "\n";   
        }
    }
    return 0;
}
