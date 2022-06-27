#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

// works just like STL set, but has two additional functions:
// - s.find_by_order(k) - iterator to the k-th (0th = first) element in set, e.g. if our set is {3, -1, 2, 0}, then *s.find_by_order(1) = 0
// - s.order_of_key(x) - number of elements smaller than x, e.g. if our set is {3, -1, 2, 0}, then s.order_of_key(2) = 2
