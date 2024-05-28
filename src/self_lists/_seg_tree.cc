#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::SelfList::Inst)

void TestSegTree()
{   
    using ll = long long;
    __seg_tree<ll> st(__seg_tree<ll>::sum_fn, __seg_tree<ll>::sum_fn);
    std::cin >> st;
    // std::cout << st;
    int szq = st.GetSZQ(), q, l, r; 
    while(szq--) 
    { 
        q = __i32_read(), l = __i32_read(), r = __i32_read();  
        switch (q)
        {
        case 0:
            std::cout << st;
            break;

        case 1:
            st.Update(l, r, __i64_read());
            break;

        case 2:
            std::cout << st.Query(l, r) << '\n'; 
            break;

        default:
            return;   
        }
    } 

}

    // #if DEBUG_MODE == 1
    //     PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
    //     PRINT(" in "),
    //     PRINT_DETAIL(s),PRINT(", "),PRINTLN_DETAIL(t);
    // #endif

    // #if DEBUG_MODE == 1
    //     PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
    //     PRINT(" left union "),
    //     PRINT_DETAIL(s),PRINT(", "),PRINTLN_DETAIL(m);
    // #endif

    // #if DEBUG_MODE == 1
    //     PRINT_DETAIL(l),PRINT(", "),PRINT_DETAIL(r),
    //     PRINT(" right union "),
    //     PRINT_DETAIL(m+1),PRINT(", "),PRINTLN_DETAIL(t);
    // #endif

__END_NS__