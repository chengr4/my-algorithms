# Tree

## 尋找最後一個節點犯的錯誤

```python
# (X) 錯誤的寫法
while root.left.right:
   # 這裡原本的意圖是「遍歷」到最右邊的節點
   # 但你寫成了「修改結構」，讓 root.left 直接指向下下個節點
   root.left.right = root.left.right.right
```

> `node.next = node.next.next` 是標準的刪除節點操作

```python
# (O) 正確的寫法
# 使用一個暫存變數 tail
tail = root.left
while tail.right:
    tail = tail.right # 只是移動指針，不改變結構
```