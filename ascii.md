# ASCII

```
numInt = 0
get numString
for numChar in numString:
    if 48 <= numChar <= 57:
        numInt = 10 * numInt + (numChar - 48)
    else:
        break
```

- `48` is `0`, while `57` is `9` in ASCII.