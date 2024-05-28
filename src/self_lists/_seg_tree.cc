#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::SelfList::Inst)

// [l, r]
int __seg_tree::build(int id, int l, int r) {
    if (l == r)
        return rg[id] = a[l];
    
    int m = __imid(l, r);
    int p = __pow2(id);
    return rg[id] = bfn(
        rg[p] = build(p, l, m),
        rg[p+1] = build(p+1, m+1, r)
    );      
}

// [l, r] range add val
void __seg_tree::update(int l, int r, int val, int, int) {
} 

int __seg_tree::Query(int l, int r) {
    return query(l, r, rid, start, end);
}

// [l, r] query in [s, t] 
// confirm l<=r && s<=t
int __seg_tree::query(int l, int r, int id, int s, int t) {
    if(l<=s && t<=r)
    {
    #if DEBUG_MODE == 1
        PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
        PRINT(" in "),
        PRINT_DETAIL(s),PRINT(", "),PRINTLN_DETAIL(t);
    #endif
    return rg[id];
    }
        
    int m = __imid(s, t);
    int p = id<<1;
    int v = 0;
    if(l <= m)
    {
    #if DEBUG_MODE == 1
        PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
        PRINT(" left union "),
        PRINT_DETAIL(s),PRINT(", "),PRINTLN_DETAIL(m);
    #endif
    v = bfn(v, query(l, r, p, s, m));
    }
        
    if(r > m)
    {
    #if DEBUG_MODE == 1
        PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
        PRINT(" right union "),
        PRINT_DETAIL(m+1),PRINT(", "),PRINTLN_DETAIL(t);
    #endif
    v = bfn(v, query(l, r, p+1, m+1, t));
    }

    return v;
}

std::istream& 
    operator >> (std::istream& __is, __seg_tree & _s) {
    // _s.a.push_back(0); // _s.a[0] is unused
    // Alan::SeqIterInput(_s.a, __is);
    // _s.szn = _s.a.size()-1;

    __is >> _s.szn;
    _s.rid = 1, _s.start = 1, _s.end = _s.szn;
    __is_arr(__is, _s.a, _s.start, _s.end);
    _s.build(_s.rid, _s.start, _s.end);
    return __is;
}

std::ostream& 
    operator << (std::ostream& __os, const __seg_tree & _s) {
        __os_arr(__os, _s.a, _s.start, _s.end);
        __os_arr(__os, _s.rg, _s.start, __pow2(_s.szn)-1);
    return __os;
}

void TestSegTree()
{
    __seg_tree st(
        [](int a, int b) -> int {
            return a + b;
        }
    );
    std::cin >> st;
    // std::cout << st;
    int q, l, r; 
    while(std::cin>>q) 
    {
        switch (q)
        {
        case 0:
            std::cout << st;
            break;

        case 1:
            std::cin >> l >> r;
            std::cout << st.Query(l, r) << '\n'; 
            break;

        default:
            return;   
        }
    } 

}

__END_NS__