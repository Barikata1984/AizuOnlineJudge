    #include <iostream>
    #include <cmath>

    bool isPrime(int readVal){
        bool flg = true;
        int i = 2, lim = std::sqrt(readVal);
        while(flg && i <= lim){
            flg = 0 != readVal % i;
            ++i;
        }

        return flg;
    }

    int main(){
        int n;
        std::cin >> n;

        int count = 0;
        for(int i = 0; i < n; ++i){
            int val;
            std::cin >> val;
            if(isPrime(val)){
                ++count;
            }
        }

        std::cout << count << std::endl;

        return 0;
    }