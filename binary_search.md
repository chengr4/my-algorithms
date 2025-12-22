# Binary Search

- A search algorithm that finds the position of a target value within **a sorted array**
- Linear search O(n) => better solution O(log(n))
- Two pointers
 
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
