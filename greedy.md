# Greedy

- 用於解決最佳化問題 (與 Dynamic Programming 類似)
- 在每一個步驟中，它都會選擇當前情況下最好的選擇，而不考慮未來可能的後果
- 目標找到一個最優解，且該最優解是由一系列「子問題」的最優解構成的

## How to Test

After each step, ask: "If I make this choice now, will it hurt my chances of achieving the global optimum?" => If the answer is no, the problem likely supports a greedy approach.
- Sorting or repeatedly choosing the maximum/minimum element is often a good indicator that a greedy approach is appropriate.

## Greedy 和 Dynamic Programming 關係

- Greey Algorithm 通常用於求解那些具有"最佳子結構性質"的問題，這意味著整體最佳解可以通過選擇局部最佳解而獲得。
- DP 則通常用於求解具有"重疊子問題性質"的問題，這意味著問題可以被分解為子問題，而這些子問題的解可以被重複利用。
- Once you make a decision, it should not depend on future decisions or require you to backtrack. If backtracking is necessary, the problem might need dynamic programming instead.