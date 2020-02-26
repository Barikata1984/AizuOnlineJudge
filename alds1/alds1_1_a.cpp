#include <iostream>
#include <vector>

void print(std::vector<int>& readVec){
    int n = readVec.size();
    for(int i = 0; i < n; ++i){
        std::cout << readVec.at(i);
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

void insertionSort(std::vector<int>& readVec){
    print(readVec);
    int n = readVec.size();
    for(int i = 1; i < n; ++i){
        int val = readVec.at(i), j = i - 1;
        while(0 <= j && val < readVec.at(j)){
            readVec.at(j-- + 1) = readVec.at(j);
        }
        readVec.at(j + 1) = val;

        print(readVec);
    }
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    insertionSort(a);

    return 0;
}