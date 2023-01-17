# Backtracking

## Pattern

```javascript
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