#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        std::cout << vec.at(i);
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

auto meguruSearch(const std::vector<int> &vec, const int val, int ng, int ok){
    int mid = ng - (ng - ok) / 2;
    if(val == vec.at(mid)){
        return std::begin(vec) + mid;
    }

    if(1 == std::abs(ok - ng)){
        return std::end(vec);
    }

    if(val < vec.at(mid)){
        return meguruSearch(vec, val, ng, mid);
    }else{
        return meguruSearch(vec, val, mid, ok);
    }
}

class List{
private:
    std::vector<int> data;

public:
    void show(){
        print(data);
    }

    void insert(int val){
        data.insert(std::begin(data), val);
//        show();
    }

    void deleteElem(int val){
        auto itr = meguruSearch(data, val, -1, data.size());
        if(std::end(data) != itr){
            data.erase(itr);
        }
//        show();
    }

    void deleteFirst(){
        data.erase(std::begin(data));
//        show();
    }

    void deleteLast(){
        data.erase(std::end(data) - 1);
//        show();
    }
};

int main(){
    int n;
    std::cin >> n;

    List list;
    std::string s;
    for(int i = 0; i < n; ++i){
        std::cin >> s;
        if("insert" == s){
            int val;
            std::cin >> val;
//            std::cout << s << ", " << val << ": ";
            list.insert(val);
        }else if("delete" == s){
            int val;
            std::cin >> val;
//            std::cout << s << ", " << val << ": ";
            list.deleteElem(val);
        }else if("deleteFirst" == s){
//            std::cout << s << ": ";
            list.deleteFirst();
        }else if("deleteLast" == s){
//            std::cout << s << ": ";
            list.deleteLast();

        }
    }

    list.show();

    return 0;
}
