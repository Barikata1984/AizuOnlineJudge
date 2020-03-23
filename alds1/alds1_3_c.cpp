#include <algorithm>
#include <iostream>
#include <list>

class list{
private:
    

public:
    

}

int main(){
    int n, val;
    std::cin >> n;

    std::list<int> vec;
    for(int i = 0; i < n; ++i){
        std::string str;
        std::cin >> str;

        if("insert" == str){
            std::cin >> val;
            vec.push_front(val);            
        }else if("delete" == str){
            std::cin >> val;
            auto itr = std::find(vec.begin(), vec.end(), val);
            if(vec.end() != itr){
                vec.erase(itr);
            }
        }else if("deleteFirst" == str){
            vec.pop_front();
        }else if("deleteLast" == str){
            vec.pop_back();
        }
    }
    
    for(auto itr = vec.begin(); vec.end() != itr; ++itr){
        std::cout << *itr;
        if(vec.end() - 2 != itr){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }

    return 0;
}
