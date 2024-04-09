#define __RD_X_NUM__(__g_tp_, __num_tp_, __num_rg1_, __num_rg2_) \
        std::random_device _Rand_Dev; \
        std::mt19937       _Rand_Gen(_Rand_Dev()); \
        std::uniform_ ##__g_tp_ ##_distribution<__num_tp_ > \
            UNUSED _Uid_Gen_Dev(__num_rg1_, __num_rg2_)

#define __RD_I_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(int, __num_tp_, __num_rg1_, __num_rg2_)

#define __RD_R_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(real, __num_tp_, __num_rg1_, __num_rg2_)

#define __RD_I_LAM__(__num_tp_) \
        [&_Rand_Gen, &_Uid_Gen_Dev] \
        () -> __num_tp_ \
        { return _Uid_Gen_Dev(_Rand_Gen); }

template <typename _Num_Tp >
static inline _Num_Tp _Gen_Num
(_Num_Tp const &__range_1, _Num_Tp const &__range_2)
{   
    const std::string _num_tp_str 
        = Alan::__cpp_tid_<_Num_Tp>();
    #ifdef DEBUG_MODE
        PRINTLN_DETAIL("["<<_num_tp_str<<"]");
    #endif 
    if (_sfind_any(_num_tp_str, 3, "long", "int", "unsigned"))
    {
        __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
        return _Uid_Gen_Dev(_Rand_Gen);
    } else if (_sfind_any(_num_tp_str, 2, "double", "float"))
    {
        __RD_R_NUM__(_Num_Tp, __range_1, __range_2);
        return _Uid_Gen_Dev(_Rand_Gen);
    }
    else 
    {
        _COLOR_START(_COLOR_RED);
            ERRLN("SFINAE error occurs!");
        _COLOR_RECOVER;
        assert(0);
    }
}
