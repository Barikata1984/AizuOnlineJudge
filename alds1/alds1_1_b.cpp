#include <iostream>

int gcd(int readVal1, int readVal2){
    if(0 == readVal1 % readVal2){
        return readVal2;
    }else{
        return gcd(readVal2, readVal1 % readVal2);
    }
}

int main(){
    int x, y;
    std::cin >> x >> y;

    std::cout << gcd(x, y) << std::endl;

    return 0;
}