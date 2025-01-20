#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> wood(1000000,0);

void Binary_Serch(){
    int awnser = -1;
    int left = 0, right = *max_element(wood.begin(), wood.end());
    
    while(left<=right){

        int H = (left+right)/2;
        long long sum = 0;
        for(auto w : wood){
            int buffer = w - H;
            if(buffer < 0){
                buffer = 0;
            }
            sum += buffer;
        }

        if(M <= sum){
            awnser = max(awnser, H);
            left = H+1;
        }
        else if(M > sum){
            right = H-1;
        }
    }

    cout << awnser;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> wood[i];
    }

    Binary_Serch();
    return 0;
}