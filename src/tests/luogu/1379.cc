#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

class Node {
public:
    int sta;
    int v;
    int zerox, zeroy;
    explicit Node(int _sta = 0, int _v = 0)
        : sta(_sta), v(_v) { zerox = 0, zeroy = 0; }
    
    Node makeExte(int ax, int ay){
        Node newNode = this;
        
        newNode.zerox = ax; newNode.zeroy = ay;
        newNode.v = this->v + 1;
        return newNode;
    }

    int diff(const Node & _n)
        const noexcept {
            int c1 = this->sta;
            int c2 = _n.sta;
            int dF = 0;
            while(c1 && c2){
                
            }
            return dF;
        }

    bool operator == (const Node & _n) 
        const noexcept {
        return this->sta == _n.sta;
    }

    friend std::istream& operator >> (std::istream& _is, Node & _n){
        _is >> _n.sta;

           
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
        if(cost1 == cost2)
            return _n1.v > _n2.v;
        return cost1 > cost2;
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
    std::set<int> vis;
    int ans;
    int pxy[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid1(int x, int y){
        return x>=0 && x<3 && y>=0 && y<3;
    }

    void bfs(){
        auto q = pq();
        q.push(st);

        while(!q.empty()){
            auto ele = q.top(); q.pop();
            if(ele == ed){
                ans = ele.v;
                return;
            }
            vis.insert(ele.compress());
            int xof = ele.zerox, yof = ele.zeroy;
            for(int i=0;i<4;++i){
                int newX = xof+pxy[i][0];
                int newY = yof+pxy[i][1];
                if(valid1(newX, newY)){
                    auto nt = ele.makeExte(newX, newY);
                    if(nt == ed){
                        ans = nt.v;
                        return;
                    }
                    if(vis.find(nt.compress()) == vis.end()){
                        q.push(nt);
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
    eN.ed.sta = {{'1','2','3'},{'8','0','4'},{'7','6','5'}};
    eN.bfs();
    std::cout << eN.ans << '\n';
    return 0;
}