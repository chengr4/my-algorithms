# Prefix/Postfix Sum

## When see

- Range query
- Range modification + retrieve the final state

## Classical Case: Leetcode 560

任何一段連續 subarray nums[i...j] 的總和，其實都可以用兩個 prefix sum 相減來表示：

$$Sum(i, j) = PrefixSum[j] - PrefixSum[i-1]$$

> 當 `curr_sum` (`p[j]`) 放進 hash map ，意思是 `curr_sum == PrefixSum[i-1]` (最不容易理解的其實是 p[j] => p[i-1] 這一步)
## train of thought

1. We modify a range of elements
2. It is repeated many times
3. We only care about the result rather than the intermediate state

- Sometimes, we can do bi-direction and add the difference to the start and end of the range

## Classic Problems

- 航班預訂統計
- 區間加法
- 統計範圍內的元素和