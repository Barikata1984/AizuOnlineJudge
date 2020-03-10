#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        int m, l;
        std::cin >> m >> l;
        for(int j = 0; j < l; ++j){
            int index;
            std::cin >> index;
            ++matrix.at(m - 1).at(index - 1);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            std::cout << matrix.at(i).at(j);
            if(n - 1 != j){
                std::cout << " ";
            }else{
                std::cout << std::endl;
            }
        }
    }

    return 0;
}