#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        unsigned long long n;
        cin >> n;
        
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        
        int k = 0;
        while(true){
            unsigned long long representable = (unsigned long long)(k + 1) * (1ULL << (k + 1)) - 1;
            if(representable >= n){
                cout << k << "\n";
                break;
            }
            k++;
        }
    }
    
    return 0;
}
