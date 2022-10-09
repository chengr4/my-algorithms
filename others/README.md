# Others

## Floyd's (Tortoise & Hare)


```javascript
// In JS

var hasCycle = function (head) {
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
    if (slow === fast) return true;
  }

  return false;
};
```


### Applications

- Check whether a linked list a cycle has
- Find the duplicate number in array (leetcode 287)