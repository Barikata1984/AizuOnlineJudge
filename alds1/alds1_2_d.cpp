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

int insertionSort(std::vector<int>& readVec, int span = 1){
    int n = readVec.size(), count = 0;
    for(int i = span; i < n; ++i){
        int val = readVec.at(i), j = i - span;
        while(0 <= j && val < readVec.at(j)){
            readVec.at(j + span) = readVec.at(j);
            j -= span;
            ++count;
        }

        readVec.at(j + span) = val;
    }

    return count;
}

int shellSort(std::vector<int>& readVec){
    int n = readVec.size();
    std::vector<int> spans;
    while(0 != n){
        spans.push_back(n);
        n /= 2;
    }

    int m = spans.size();
    std::cout << m << std::endl;
    print(spans);

    int count = 0;
    for(int i = 0; i < m; ++i){
        count += insertionSort(readVec, spans.at(i)); 
    }

    return count;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    std::cout << shellSort(a) << std::endl;

    for(int i = 0; i < n; ++i){
        std::cout << a.at(i) << std::endl;
    }

    return 0;
}