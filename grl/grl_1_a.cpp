#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using Graph = std::vector<std::unordered_map<long long, long long>>;
using PairLL = std::pair<long long, long long>;

#define INF (long long)(1e18 + 7)

void print(std::vector<long long> vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        if((long long)5e10 < vec.at(i)){
            std::cout << "INF" << std::endl;
        }else{
            std::cout << vec.at(i) << std::endl;
        } 
    }
}

int main(){
    long long v, e, r;
    std::cin >> v >> e >> r;

    Graph g(v);
    long long s, t, d;
    while(std::cin >> s >> t >> d){
        g.at(s).insert(std::make_pair(t, d));
    }

    auto compare = [](PairLL &lhs, PairLL &rhs){
        return lhs.second < rhs.second;
    }; 
   
    std::priority_queue<
        long long,
        std::vector<PairLL>,
        decltype(compare) 
    > pq(compare);
    pq.push(std::make_pair(r, 0));

    std::vector<long long> dist(v, INF);
    dist.at(r) = 0;

    while(!pq.empty()){
        auto from = pq.top();
        pq.pop();
        
        if(dist.at(from.first) < from.second){
            continue;
        }

        for(auto to : g.at(from.first)){
            auto len = dist.at(from.first) + to.second;
            if(len < dist.at(to.first)){
                dist.at(to.first) = len;
                pq.push(std::make_pair(to.first, dist.at(to.first)));
            }
        }
    }

    print(dist);

    return 0;
}
