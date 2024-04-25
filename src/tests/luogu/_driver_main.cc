#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template < typename _Seq_Container, 
            typename _Istream >
void SeqIterInput(_Seq_Container &__container,
                    _Istream &__istream)
{   
    using __value_type_ = typename _Seq_Container::value_type;
    std::copy(std::istream_iterator<__value_type_>(__istream),
                std::istream_iterator<__value_type_>(),
                std::back_inserter(__container));
}

template < typename _Container, 
            typename _Ostream >
void IterOutput(const _Container &__container,
                _Ostream &__ostream,
                const char* __delimiter)
{
    using __value_type_ = typename _Container::value_type;
    std::copy(__container.cbegin(), __container.cend(),
                std::ostream_iterator< __value_type_ >
                    (__ostream, __delimiter)
                );
}

template < typename _Iter >
void MergeSortHelper(_Iter __dest_first, _Iter __dest_last, 
                    _Iter __src_first)
{
    if(__dest_last - __dest_first == 1)
        return;
    
    size_t __sz = __dest_last - __dest_first;
    auto __dest_mid = __dest_first + (__sz >> 1);

    MergeSortHelper(__dest_first, __dest_mid, 
                    __src_first);
    MergeSortHelper(__dest_mid, __dest_last, 
                    __src_first + (__sz >> 1));

    std::merge(__dest_first, __dest_mid, 
                __dest_mid, __dest_last, 
                __src_first);
    
    std::copy(__src_first, __src_first+__sz, 
                __dest_first);
}

template < typename _Container >
void MergeSort(_Container & __container)
{
    auto __helper_con = _Container(__container.size());
    MergeSortHelper(__container.begin(), __container.end(), 
                    __helper_con.begin());
}

// input
void Alan_Driver()
{   
    size_t _n;
    std::cin >> _n;
    auto i32v = std::vector<int>();
    i32v.reserve(_n);
    SeqIterInput(i32v, std::cin);
    MergeSort(i32v);
    IterOutput(i32v, std::cout, " ");
}

int main()
{
Alan_Driver();
return 0;
}