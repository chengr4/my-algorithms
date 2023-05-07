# Backtracking

## Patterns

```javascript
// javascript
function backtracking(currIndex) {
  // ...

  sides[i] += matchsticks[currIndex];

  // find the solution
  if(backtracking(currIndex + 1)) {
    return true;
  }
  
  // do not find the solution => backtrack the decision
  sides[i] -= matchsticks[currIndex];
  
  // ...
}
```

```golang
// golang
var dfs func(currIndex int)
	dfs = func(currIndex int) {
		if currIndex == len(inputArray) {
      // copy to result
			return
		}

		// add
		currArr = append(currArr, inputArray[currIndex])
		dfs(currIndex + 1)
		currArr = currArr[:len(currArr)-1]
		// not add
		dfs(currIndex + 1)
	}
```
