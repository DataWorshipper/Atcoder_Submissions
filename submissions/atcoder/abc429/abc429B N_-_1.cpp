#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    
    sort(A.begin(), A.end()); 
    
    long long target = sum - M;
    
    if(binary_search(A.begin(), A.end(), target))
        cout << "Yes\n";
    else
        cout << "No\n";
}
