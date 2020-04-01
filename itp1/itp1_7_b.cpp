#include <iostream>

int main(){
    int n, x; 
    while(std::cin >> n >> x){
      	if(0 == n && 0 == x){
          return 0;
        }
      
        int count = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                for(int k = j + 1; k <= n; ++k){
                    if(x == i + j + k){
                        ++count;
                    }
                }
            }
        }

        std::cout << count << std::endl;
    }
  
    return 0;
}
