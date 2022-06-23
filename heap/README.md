# Heap

- 概念用 tree 表示 (Complete BT) => 實際用 array
- 屬 Complete BT

> Complete BT: 由上至下，由左至右編號的樹，並且，除了最後一層，所以層都必須填滿

- Delete 從 root 開始 => 刪除從根開始雖然很快，但是要調整其他 node 的位置，所以時間複雜度為 O(log(n))
- Parent node must always be more/less than child => if conflicting, swap
- Every insert, delete should check

## Deletion

Flow:

Delete element from min heap eg

1. Remove the element at the top
2. Move the latest inserted element to the top
3. Compare from top to bottom, if conflicting, swap (swap with the smallest one)

## Heapify

- O(n)

## References

1. 
