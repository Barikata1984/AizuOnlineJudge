#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        std::cin >> vec.at(i);
    }

    std::vector<int> buf;
    for(int bits = 1; bits < (1 << n); ++bits){
        int val = 0;
        for(int i = 0; i < n; ++i){
            if(bits & (1 << i)){
                val += vec.at(i);
            }
        }
        
        buf.push_back(val);
    }

    int q;
    std::cin >> q;
    for(int i = 0; i < q; ++i){
        int val;
        std::cin >> val;
        if(buf.end() != std::find(buf.begin(), buf.end(), val)){
                std::cout << "yes" << std::endl;
        }else{
                std::cout << "no" << std::endl;
        }
    }

    return 0;
}
