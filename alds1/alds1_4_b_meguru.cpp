#include <iostream>
#include <vector>

std::vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// whether the index meets the condition or not
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cout << binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10 (場外)
}






// universal template for binary search
int binary_search(int key) {
    int left = -1; // set "-1" as the initial value since the index "0" can also meet the condition
    int right = (int)a.size(); // set "n" as the initial value since the index "n-1" can not meet the condition

    // any kinds of binary searches can be written in the following style
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    // after the "while" loop complete, 
    // "left" is the greatest value which does not meet the condition 
    // and "right" becomes the least value which meet the consition.
    return right;
}

int main() {
    cout << binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10 (場外)
}