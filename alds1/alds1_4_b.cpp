#include <iostream>
#include <vector>

bool meguruSearch(const std::vector<int> &vec, const int v, int ng, int ok){
    int mid = (ng + ok) / 2;
    if(v == vec.at(mid)){
//    std::cout << vec.at(mid) << std::endl;
        return true;
    }else if(1 == std::abs(ok - ng)){
//    std::cout << vec.at(mid) << std::endl;
        return false;
    }

    if(v < vec.at(mid)){ // elements in the right part of vec including vec.at(mid) are set as okay in this code
        return meguruSearch(vec, v, ng, mid);
    }else{
        return meguruSearch(vec, v, mid, ok);
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

    int count = 0;
    for(int i = 0; i < q; ++i){
        if(meguruSearch(s, t.at(i), -1, s.size())){
//            std::cout << t.at(i) << std::endl;
            ++count;
        }
    }

//    std::cout << "------" << std::endl;
    
    std::cout << count << std::endl;

    return 0;
}
