# Dynamic Programming

> Dynamic "programming" came from the term "mathematic programming" => 最佳化的意思

## Key for DP

DP can be used if the problem satisfies the following properties:

- A polynomial number of subproblems not exponential (?)
- 最大的解是由比較小的解組成
- (Important!) 有一個自然的計算順序

## Memoization Pattern

E.g. in Java

```java
class Solution {
    private int dfs(int currIndex, HashMap<Integer, Integer> memo) {
        if (memo.containsKey(currIndex)) {
            return memo.get(currIndex);
        }
        
        // do something with currIndex
        
        memo.put(currIndex, result);
        return result;

    }
}
```
