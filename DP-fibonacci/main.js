var index = 10;
var f = new Array(index);
f[0] = 0;
f[1] = 1;
f.fill(-1, 2, index);
var fibonacci = function (n, f) {
    if (f[n] == -1)
        f[n] = fibonacci(n - 1, f) + fibonacci(n - 2, f);
    return f[n];
};
fibonacci(index - 1, f);
console.log(f);
