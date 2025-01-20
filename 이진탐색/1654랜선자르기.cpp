#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<int> lan(1000000,0);

void Binary_Serch(){
    long long answer = 0;
    long long left = 1, right = *max_element(lan.begin(), lan.end());
    
    while(left<=right){
        long long mid = (left+right)/2;
        int lans = 0;

        for(auto l : lan){
            lans += l/mid;
        }

        if(lans >= N){
            answer = max(answer,mid);
            left = mid+1;
        }
        else{
            right  = mid-1;
        }
    }

    cout << answer;
}

int main() {
    cin >> K >> N;
    for(int i = 0; i<K; i++){
        cin >> lan[i];
    }

    Binary_Serch();
    return 0;
}