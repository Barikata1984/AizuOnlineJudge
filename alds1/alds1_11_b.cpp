#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void dfs(std::vector<bool> &seen, Graph &g, int v, int &time, std::vector<int> &preOrder, std::vector<int> &postOrder){
    preOrder.at(v) = time;
    ++time;

    seen.at(v) = true;
    for(auto nextV : g.at(v)){
        if(seen.at(nextV)){
            continue;
        }
        dfs(seen, g, nextV, time, preOrder, postOrder);
    }

    postOrder.at(v) = time;
    ++time;
}

int main(){
    int n;
    std::cin >> n;

    Graph g(n);
    std::vector<int> preOrder(n), postOrder(n);
    for(int i = 0; i < n; ++i){
        int m, l;
        std::cin >> m >> l;
        for(int j = 0; j < l; ++j){
            int k;
            std::cin >> k;

            g.at(i).push_back(k - 1); 
            g.at(k - 1).push_back(i); 
        }
    }

    std::vector<bool> seen(n, false);
    int time = 1;
    
    dfs(seen, g, 0, time, preOrder, postOrder); 
    for(int i= 0; i < n; ++i){
        std::cout << i + 1 << " " << preOrder.at(i) << " " << postOrder.at(i) << std::endl;
    }

    return 0;
}