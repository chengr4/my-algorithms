# Comparison

Check if subString is a substring of mainString:

```kotlin
// Time: O(n * m)
fun main() {
    val mainString = "Hello, Kotlin!"
    val subString = "Kotlin"

    // Check if subString is a substring of mainString
    val isSubstring = mainString.contains(subString)
}
```

Function to check if subArray is a subarray of mainArray:

```kotlin
fun isSubarray(mainArray: Array<Int>, subArray: Array<Int>): Boolean {
    // Get the lengths of both arrays
    val mainLength = mainArray.size
    val subLength = subArray.size
    // Check each possible starting position in the main array
    for (i in 0..mainLength - subLength) {
        var j = 0
        // Check if the subarray matches starting from position i
        while (j < subLength && mainArray[i + j] == subArray[j]) {
            j++
        }
        // If we matched the entire subarray, return true
        if (j == subLength) {
            return true
        }
    }
    // If no match was found, return false
    return false
}
```