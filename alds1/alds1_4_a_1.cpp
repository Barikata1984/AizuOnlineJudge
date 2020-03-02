#include <iostream>
#include <vector>

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
        for(int j = 0; j < n; ++j){
            if(s.at(j) == t.at(i)){
                ++ans;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}