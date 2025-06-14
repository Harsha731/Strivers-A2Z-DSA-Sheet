```cpp
Min possible distance: 0 (all stations at one point).
Max possible distance: max gap between consecutive stations.
The answer lies in [0, max_gap], which is a sorted, real-number space.

while(low <= high): The condition 'while(low <= high)' inside the 'while' loop won't work for decimal answers, and using it might lead to a TLE error. To avoid this, we can modify the condition to 'while(high - low > 10^(-6))'. This means we will only check numbers up to the 6th decimal place. Any differences beyond this decimal precision won't be considered, as the question explicitly accepts answers within 10^-6 of the actual answer.

1. You may never hit exact equality due to small rounding errors.
E.g., low might be 0.3333333 and high might be 0.3333334, but low != high, and due to rounding, they never converge in exact binary terms.

2. Tiny differences could cause infinite loop or excessive iterations.
The condition low <= high might be true for a long time, but the difference between them could be meaningless — like 1e-12, which is way smaller than what's required.

low = mid+1: We have used this operation to eliminate the left half. But if we apply the same here, we might ignore several decimal numbers and possibly our actual answer. So, we will use this: low = mid.
similarly high = mid-1

We count the required no. of new gas stations to make maximum distance between 2 gas stations in future as cnt, and compare cnt, k and adjust low, high

For each section between i and i-1, we will do the following:
No. of stations = (arr[i]-arr[i-1]) / dist

Let's keep in mind a crucial edge case: if the section_length (arr[i] - arr[i-1]) is completely divisible by 'dist', the actual number of stations required will be one less than what we calculate.
if (arr[i]-arr[i-1] == (No. of stations*dist): No. of stations -= 1.

mid = (low+high) / 2.0 
Not simple 2  ??
Using **2.0** ensures that the division is done in floating-point (decimal) arithmetic, not integer division.
But actually not a big issue
```
