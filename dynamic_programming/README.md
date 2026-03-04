# Dynamic Programming

> Dynamic "programming" came from the term "mathematic programming" => 最佳化的意思

## Keys for DP

DP can be used if the problem satisfies the following properties:

- A polynomial number of subproblems not exponential (?)
- 最大的解是由比較小的解組成
- (Important!) 有一個自然的計算順序
- Overlapping subproblems

## Classical Case: Edit Distance

`dp[i][j]` ==`$dp[i][j]` 代表將 word1 的前 i 個字元，轉換成 word2 的前 j 個字元所需要的「最小操作數」。**也就是說在 `dp[i][j]` 時，兩個 string 會一模一樣 (這是思考的關鍵)**

Assuming that word1 = "CAT" and word2 = "CA",

`dp[3][2]`就是把 "CAT" 變成 "CA" 的最小操作數。若我們執行 deletion。
我們就要去看 `dp[2][2]` (`dp[3-1][2]`)，也就是把 "CA" 變成 "CA" 的最小操作數。 => `dp[3][2] = dp[2][2] + 1`。

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
