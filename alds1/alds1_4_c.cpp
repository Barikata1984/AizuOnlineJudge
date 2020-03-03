#include <algorithm>
#include <iostream>
#include <vector>

class dictionary{
private:
    std::vector<std::string> words;

public:
    dictionary(){

    }

    void insert(std::string readStr){
        words.push_back(readStr);
    }

    bool isFound(std::string readStr){
        auto itr = std::find(words.begin(), words.end(), readStr);
        if(words.end() != itr){
            std::cout << "yes" << std::endl;
            return true;
        }else{
            std::cout << "no" << std::endl;
            return false;
        }
    }
};

int main(){
    int n;
    std::cin >> n;

    dictionary dict;

    for(int i = 0; i < n; ++i){
        std::string cmd, str;
        std::cin >> cmd >> str;
        if("insert" == cmd){
            dict.insert(str);
        }else{
            dict.isFound(str);
        }
    }

    return 0;
}