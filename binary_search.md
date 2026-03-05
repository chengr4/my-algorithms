# Binary Search

- A search algorithm that finds the position of a target value within **a sorted array**
- Linear search O(n) => better solution O(log(n))
- Two pointers

## 該用 `l < r` 還是 `l <= r`?

1. 尋找特定值: `l <= r`
    - 思考邏輯：因為左右邊界都需要檢查，當 `l == r` 時，仍需檢查該位置的值是否為目標值。
    - 結束狀態: `l > r`。
2. 尋找邊界值: `l < r`
    - 第一個目標的數，當 `l == r` 時，就是答案。(Note: 常用 `r = mid`)
    - 結束狀態: `l == r`。

## 如何避免無限迴圈: 相鄰兩數測試法

**確保每次迭代搜尋區間都會縮小!**

設 `l = 2`, `r = 3` ，根據 `mid = l + (r - l) / 2` ，`mid` 會等於 `2`，此時 `l` 與 `mid` 會重疊。若 if-else 有 `l = mid` ，則 `l` 不會前進，導致無限迴圈。
 
## Steps

1. Find middle index
2. Move left pointer to M + 1 or right pointer to M - 1
3. Recursive 1-2

E.g.:

```javascript
// javascript
let l = 0;
let r = nums.length - 1;
while (l <= r) {
  currIndex = Math.trunc((r + l) / 2);
  if (nums[currIndex] === target) {
      break;
    } else if (nums[currIndex] < target) {
      l = currIndex + 1;
    } else {
      r = currIndex - 1;
    }
  }
```

```golang
// golang
l := 0
r := len(nums) - 1
for l <= r {
	mid := (l + r) / 2
	
	if target > nums[mid] {
		l = mid + 1
	} else if target < nums[mid] {
		r = mid - 1
	} else {
		return true
	}
}
```

## References

1. [CS Dojo; Introduction to Binary Search (Data Structures & Algorithms #10) (202008)](https://youtu.be/6ysjqCUv3K4)
