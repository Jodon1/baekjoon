#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house(1000000,0);

void Binary_Serch(){
    int answer = 0;
    int left = 1, right = house[N-1] - house [0];
    
    while(left<=right){
        int d = (left+right)/2;
        int count = 1, last_h = house[0];

        for(int i=0; i<N; i++){
            if(last_h + d <= house[i]){
                last_h = house[i];
                count++;
            }
        }

        if(count >= C){
            answer = max(answer, d);
            left = d+1;
        }
        else if(count < C){
            right = d - 1;
        }
       
    }

    cout << answer;
}

int main() {
    cin >> N >> C;
    for(int i = 0; i<N; i++){
        cin >> house[i];
    }
    sort(house.begin(), house.begin() + N);

    Binary_Serch();
    return 0;
}