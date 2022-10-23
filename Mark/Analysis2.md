# Binary Search
Given an integer $X$ and integers $A_0, A_1, ...,A_N-1$, which are presorted and already in memory, find $i$ s.t. $A_i = X$, or return -1 if $X$ is not in the input
```cpp
template <typename C> 
int binarySearch(const vector<C> &a, const C &x) {
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] < x) {
            low = mid + 1;
        } else if (a[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
```
For reaching one element from <u>a set of 16 elements</u>, we had to divide the array <u>4 times</u>.
We can say that:
$$ 16 . (1/2)^4 = 1 $$
Similarity for N elements:
$$ N(1/2)^k = 1 $$
We need to find the actual value of $k$.
Clearly:
$$ N = 2^k $$
Then:
$$ \log N = k $$

> It takes $O(\log N)$

# Euclid's Algorithm
Thm:

If $M > N$, then ${M}\mod{N} < M / 2 $
> It takes $O(\log N)$

# Exponentiation