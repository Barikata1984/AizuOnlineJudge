#include <iostream>
#include <vector>
#include <queue>

using Graph = std::vector<std::vector<int>>;

int main(){
    int n;
    std::cin >> n;

    Graph g(n);
    for(int i = 0; i < n; ++i){
        int u, k;
        std::cin >> u >> k;
        --u;
        for(int j = 0; j < k; ++j){
            int v;
            std::cin >> v;
            --v;
            g.at(u).push_back(v);            
            //g.at(v).push_back(u); 
        }
    }

    std::vector<int> dist(n, -1);
    std::queue<int> queue;
    dist.at(0) = 0;
    queue.push(0);

    while(!queue.empty()){
        int v = queue.front();
        queue.pop();

        for(auto nextV : g.at(v)){
//            if(-1 != dist.at(nextV)){
//                continue;
//            }
//            queue.push(nextV);
//            dist.at(nextV) = dist.at(v) + 1;
            if(-1 == dist.at(nextV)){
                queue.push(nextV);
                dist.at(nextV) = dist.at(v) + 1;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        std::cout << i + 1 << " " << dist.at(i) << std::endl;
    }

    return 0;
}