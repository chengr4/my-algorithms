

def fibbU(n):
    a, b = 1, 1
    for _ in range(2, n):
        a, b = b, a + b
    
    return b

def fibTd(n):
    cache = {1:1, 2:1}

    def fib(n):
        if n not in cache:
            cache[n] = fib(n-1) + fib(n-2)
        
        return cache[n]
    
    return fib(n)

if __name__ == "__main__":
    print(fibbU(10))  # Output: 55
    print(fibTd(10))  # Output: 55