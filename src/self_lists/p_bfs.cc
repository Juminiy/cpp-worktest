#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <iostream>
#include <queue>

__DEF_NS__(Alan::SelfAlgo::Inst::PBFS)

class Node {
public:
    int x,y,pass,val;
    explicit Node(int _x = 0, int _y = 0, int _v = 0) 
        : x(_x), y(_y), pass(0), val(_v) { }
    
    bool operator < (const Node & _rhs) 
        const noexcept {
            if(this->pass == _rhs.pass)
                return this->val < _rhs.val;
            else if (this->pass)
                return true;
            else 
                return false;
        }

    Node operator + (int _a[2])
    {
        auto newNode = Node(x+_a[0], y+_a[1], val);
        newNode.pass = this->pass;
        return newNode;
    }

    int manH(const Node & _rhs)
    const 
    {
        int dx = (this->x - _rhs.x);
        int dy = (this->y - _rhs.y);
        return std::abs(dx) + std::abs(dy);
    }

    int olaH(const Node & _rhs)
    const 
    {
        int dx = (this->x - _rhs.x);
        int dy = (this->y - _rhs.y);
        return dx*dx + dy*dy;
    }

};

typedef int (*fnH)(const Node &, const Node & );

int manF(const Node & _lhs, const Node & _rhs)
{
    return _lhs.val + _lhs.manH(_rhs);
}

int olaF(const Node & _lhs, const Node & _rhs)
{
    return _lhs.val + _lhs.olaH(_rhs);
}

    struct CompFnH {
        Node ed;
        explicit CompFnH(const Node & _ed) : ed(_ed) { }
        bool operator () (const Node &_lhs, const Node &_rhs)
        {
            int res1 = manF(_lhs, ed);
            int res2 = manF(_rhs, ed);
            if (res1 == res2)
                return _lhs < _rhs;
            else 
                return res1 < res2;
        }
    };

class Sol {
public:
    int n,m;
    std::string gra[250][250] = {};
    bool vis[250][250] = {};
    Node st, ed;
    std::priority_queue<int, std::vector<int>, std::greater<int> > anss;
    int pxy[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    inline bool valid1(int x, int y)
    {
        return I32_IN_RANGE(x, 0, n-1) && 
                I32_IN_RANGE(y, 0, m-1) && 
                gra[x][y] != "B";
    }

    inline bool valid2(int x, int y)
    {
        return !vis[x][y];
    }

    void bfs()
    {
        auto comp = CompFnH(ed);
        auto q = std::priority_queue<Node, std::vector<Node>, CompFnH>(comp);
        q.push(st);

        while(!q.empty()){
            auto ele = q.top(); q.pop();
            vis[ele.x][ele.y] = 1;
            for(int pro=0;pro<4;++pro)
            {
                auto ppt = ele+pxy[pro];
                if(valid1(ppt.x, ppt.y)){
                    if(gra[ppt.x][ppt.y] == "E" && ppt.pass)
                        anss.push(ppt.val);
                    else if(gra[ppt.x][ppt.y] == "C") 
                        ppt.pass = 1;
                    else 
                        ppt.val += std::strtol(gra[ppt.x][ppt.y].data(), nullptr, 10);
                    if(valid2(ppt.x, ppt.y))
                    {
                        q.push(ppt);
                    }
                }
            }
        }
    }

    friend std::istream& operator >> (std::istream& _is, Sol & sol) {
        _is >> sol.n >> sol.m;
        for(int i=0;i<sol.n;++i)
        for(int j=0;j<sol.m;++j){
            _is >> sol.gra[i][j];
            if(sol.gra[i][j]=="S")
                sol.st = Node(i,j,0);
            else if(sol.gra[i][j]=="E")
                sol.ed = Node(i,j,0);
        }
        return _is;
    }

    friend std::ostream& operator << (std::ostream& _os, const Sol & sol) {
        if(sol.anss.empty())
            _os << -1 << '\n';
        else 
            _os << sol.anss.top() << '\n';
        return _os;
    }

};

void TestPBFS()
{
    Sol sol;
    std::cin >> sol;
    sol.bfs();
    std::cout << sol;
}

__END_NS__