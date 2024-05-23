#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <iterator>
#include <map>
#include <utility>

__DEF_NS__(Alan::TypeDecl)

// using __mi32_ = int;
// using __mu32_ = unsigned int;
// using __mi64_ = long long;
// using __mu64_ = unsigned long long;

// using __mf32_ = float;
// using __md32_ = double;

// using __i32_vec_ = std::vector<int >;
// using __i64_vec_ = std::vector<long long >;
// using __f32_vec_ = std::vector<float >;
// using __f64_vec_ = std::vector<double >;

// using __i32_deq_ = std::deque<int >;
// using __i64_deq_ = std::deque<long long >;
// using __f32_deq_ = std::deque<float >;
// using __f64_deq_ = std::deque<double >;

// using __i32_i32_map_ = std::map<int, int >;
// using __i32_str_map_ = std::map<int, std::string >;
// using __str_str_map_ = std::map<std::string, std::string >;
// using __str_i32_map_ = std::map<std::string, int >;

// using __i32_i32_pair_ = std::pair<int, int >;
// using __i32_str_pair_ = std::pair<int, std::string >;
// using __str_str_pair_ = std::pair<std::string, std::string >;
// using __str_i32_pair_ = std::pair<std::string, int >;

// using __i32v_itr_ = std::vector<int >::iterator;
// using __i64v_itr_ = std::vector<long long >::iterator;
// using __f32v_itr_ = std::vector<float >::iterator;
// using __f64v_itr_ = std::vector<double >::iterator;

// using __i32d_itr_ = std::deque<int >::iterator;
// using __i64d_itr_ = std::deque<long long >::iterator;
// using __f32d_itr_ = std::deque<float >::iterator;
// using __f64d_itr_ = std::deque<double >::iterator;

// using __i32v = __i32_vec_;
// using __i32vc = __i32v const;
// using __i32vr = __i32v &;
// using __i32vcr = const __i32vr;

// using __i32vv = std::vector<__i32v >;
// using __i32vvc = __i32vv const;
// using __i32vvr = __i32vvc &;
// using __i32vvcr = const __i32vvr;

#define __decl_type_emb__(__emb_type__, __emb_alias__, \
                        __ori_type__, __ori_alias__) \
        using __ ##__emb_alias__ ##__ori_alias__ ##_ = __ori_type__ < __emb_type__ >; \
        using __ ##__emb_alias__ ##__ori_alias__ ##c ##_ = const __ ##__emb_alias__ ##__ori_alias__ ##_; \
        using __ ##__emb_alias__ ##__ori_alias__ ##r ##_ = __ ##__emb_alias__ ##__ori_alias__ ##_ &; \
        using __ ##__emb_alias__ ##__ori_alias__ ##cr ##_= const __ ##__emb_alias__ ##__ori_alias__ ##_ &

__END_NS__

// std::less partial specialization from <type> to <type pointer>
// need __type has define operator <  
#define __less_ps_type_pointer(__type__) \
		using __type_clean__ = std::remove_cv_t<std::remove_reference_t<__type__>>; \
		__DEF_SHORT__(__tp, __type_clean__); \
		namespace std{ \
			template <> \
			struct less<__tpp> { \
				bool constexpr \
					operator()(__tpp __lhs, __tpp __rhs) \
					const noexcept { \
						return __lhs != nullptr && \
								__rhs != nullptr && \
								*__lhs < *__rhs; \
					} \
				/* \
				bool constexpr \
					operator()(__tpcp __lhs, __tpcp __rhs) \
					const noexcept { \
						return __lhs != nullptr && \
								__rhs != nullptr && \
								*__lhs < *__rhs; \
					} \
				bool constexpr \
					operator()(__tppc __lhs, __tppc __rhs) \
					const noexcept { \
						return __lhs != nullptr && \
								__rhs != nullptr && \
								*__lhs < *__rhs; \
					} \
				bool constexpr \
					operator()(__tpcpc __lhs, __tpcpc __rhs) \
					const noexcept { \
						return __lhs != nullptr && \
								__rhs != nullptr && \
								*__lhs < *__rhs; \
					} \
				*/ \
			}; \
		}

// instance
// __DEF_NS__(std)
// 	template<>
//     struct less<ListNode*> {
//         bool operator()(ListNode* __lhs, ListNode* __rhs) const {
//             return __lhs != nullptr && 
//                     __rhs != nullptr && 
//                     __lhs->val > __rhs->val;
//         }
//     };
// __END_NS__