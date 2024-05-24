// https://www.luogu.com.cn/problem/P1379
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <cstring>

class Node {
public:
    std::string sta; 
    int v;
    int zerox, zeroy;
    explicit Node(std::string _sta = "", int _v = 0)
        : sta(_sta), v(_v) { zerox = 0, zeroy = 0; }
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    Node makeExte(int ax, int ay){
        Node newNode = *this;
        newNode.sta[zerox*3+zeroy] = newNode.sta[ax*3+ay];
        newNode.sta[ax*3+ay] = '0';
        newNode.zerox = ax; newNode.zeroy = ay;
        newNode.v = this->v + 1;
        return newNode;
    }

    int diff(const Node & _n)
        const noexcept {
            int dF = 0;
            for(int i=0;i<9;i++)
                dF += (this->sta[i] != _n.sta[i]);
            
            return dF;
        }

    bool operator == (const Node & _n) 
        const noexcept {
        return this->sta == _n.sta;
    }

    friend std::istream& operator >> (std::istream& _is, Node & _n){
        std::string ssta;
        _is >> ssta;
        for(int i=0;i<9;++i)
            if(ssta[i]=='0')
                _n.zerox = i/3, _n.zeroy = i%3;
        _n.v = 0;
        _n.sta = std::move(ssta);
        return _is;
    }
};

class NCmp {
public:
    Node ed;
    explicit NCmp(const Node & _n) 
        : ed(_n) { }
    bool operator() (const Node & _n1, const Node & _n2) 
        const noexcept {
        int cost1 = _n1.diff(ed);
        int cost2 = _n2.diff(ed);
        // if(cost1 == cost2)
        //     return _n1.v > _n2.v;
        // return cost1 > cost2;
        return _n1.v + cost1 > _n2.v + cost2;
    }
};

class eNum {
public: 
    Node st, ed;
    int ans = 0;

    using pq = std::priority_queue<Node, std::vector<Node>, NCmp>;

    /* 
        2 8 3    1 2 3
        1 0 4 -> 8 0 4    
        7 6 5    7 6 5
    */
    std::set<std::string> vis;
    int pxy[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid1(int x, int y){
        return x>=0 && x<3 && y>=0 && y<3;
    }

    void bfs(){
        ans = -1;
        auto q = pq(NCmp(ed));
        q.push(st);

        while(!q.empty()){
            auto ele = q.top(); q.pop();
            if(ele == ed){
                ans = ele.v;
                return;
            }
            vis.insert(ele.sta);
            int xof = ele.zerox, yof = ele.zeroy;
            for(int i=0;i<4;++i){
                int newX = xof+pxy[i][0];
                int newY = yof+pxy[i][1];
                if(valid1(newX, newY)){
                    auto nt = ele.makeExte(newX, newY);
                    if(vis.find(nt.sta) == vis.end()){
                        q.push(nt);
                        vis.insert(nt.sta);
                    }
                }
            }

        }
    }
};


int main()
{
    eNum eN;
    std::cin >> eN.st;
    eN.ed.sta = "123804765";
    eN.bfs();
    std::cout << eN.ans << '\n';
    return 0;
}