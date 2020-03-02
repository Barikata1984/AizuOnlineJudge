#include <iostream>
#include <vector>

bool binarySearch(std::vector<int> readVec, int key){
    int n = readVec.size(), left = 0, right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(key == readVec.at(mid)){
            return mid;
        }else if(key < readVec.at(mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return false;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for(int i = 0; i < n; ++i){
        std::cin >> s.at(i);
    }

    int q;
    std::cin >> q;
    std::vector<int> t(q);
    for(int i = 0; i < q; ++i){
        std::cin >> t.at(i);
    }

    int ans = 0;
    for(int i = 0; i < q; ++i){
        if(binarySearch(s, t.at(i))){
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
