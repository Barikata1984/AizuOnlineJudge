#include <iostream>
#include <vector>

bool linearSearch(std::vector<int> readVec, int key){
    int i = 0, n = readVec.size();
    readVec.push_back(key);
    while(readVec.at(i) != key){
        ++i;
    }
    if(n == i){
        return false;
    }else{
        return true;
    }
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
        ans += linearSearch(s, t.at(i));
    }

    std::cout << ans << std::endl;

    return 0;
}