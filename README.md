# Longest Common Subsequence (LCS) Using Dynamic Programming

## Aim

To implement the Longest Common Subsequence (LCS) problem using Dynamic Programming and find the longest subsequence common to two given strings.

## Problem Statement

Given two strings, find the longest subsequence that is common to both strings while maintaining the relative order of characters.

A subsequence is a sequence obtained by deleting zero or more characters from a string without changing the order of the remaining characters.

The characters do not need to be contiguous.

## Case Study

### Comparing Student Records or Text Data

Suppose a college needs to compare two versions of a student's document, assignment, or textual record to identify the longest sequence of characters that appears in both versions while maintaining the same order.

The Longest Common Subsequence algorithm can be used to identify the common sequence between the two strings.

For example:

```text
String 1 = ABCDGH
String 2 = AEDFHR
```

The longest common subsequence is:

```text
ADH
```

The length of the LCS is:

```text
3
```

## Dynamic Programming Approach

The LCS problem has overlapping subproblems and optimal substructure, making it suitable for Dynamic Programming.

A two-dimensional DP table is created:

`dp[i][j]`

where:

* `i` represents the first `i` characters of String 1.
* `j` represents the first `j` characters of String 2.
* `dp[i][j]` represents the length of the LCS of the first `i` characters of String 1 and the first `j` characters of String 2.

For every pair of characters, there are two cases.

### Case 1: Characters Match

If:

```text
X[i-1] == Y[j-1]
```

then:

```text
dp[i][j] = dp[i-1][j-1] + 1
```

### Case 2: Characters Do Not Match

If:

```text
X[i-1] != Y[j-1]
```

then:

```text
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

## Recurrence Relation

```text
If X[i-1] == Y[j-1]:

dp[i][j] = dp[i-1][j-1] + 1

Otherwise:

dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

## Algorithm

1. Read the first string.
2. Read the second string.
3. Find the lengths of both strings.
4. Create a DP table of size `(m+1) × (n+1)`.
5. Initialize the first row and first column with zero.
6. Compare characters of both strings.
7. If the characters match, add 1 to the diagonal value.
8. Otherwise, take the maximum of the top and left values.
9. Store the result in the DP table.
10. The value at `dp[m][n]` gives the length of the LCS.
11. Trace the DP table backwards to reconstruct the actual LCS.
12. Display the DP table.
13. Display the LCS and its length.

## Program

The implementation is provided in `LCS_DP.cpp`.

## Sample Input

```text
ABCDGH
AEDFHR
```

Where:

* `ABCDGH` = First string
* `AEDFHR` = Second string

## Sample DP Table

```text
      A E D F H R
    0 0 0 0 0 0 0
A   0 1 1 1 1 1 1
B   0 1 1 1 1 1 1
C   0 1 1 1 1 1 1
D   0 1 1 2 2 2 2
G   0 1 1 2 2 2 2
H   0 1 1 2 2 3 3
```

## Sample Output

```text
String 1: ABCDGH
String 2: AEDFHR

DP Table:

      A E D F H R
    0 0 0 0 0 0 0
A   0 1 1 1 1 1 1
B   0 1 1 1 1 1 1
C   0 1 1 1 1 1 1
D   0 1 1 2 2 2 2
G   0 1 1 2 2 2 2
H   0 1 1 2 2 3 3

Longest Common Subsequence: ADH
LCS Length: 3
```

## Complexity Analysis

Let:

* `m` = length of the first string
* `n` = length of the second string

### Time Complexity

The DP table contains `m × n` states and each state takes constant time.

**Time Complexity = O(m × n)**

### Space Complexity

The two-dimensional DP table requires:

**Space Complexity = O(m × n)**

The additional space required to store the resulting LCS is `O(min(m,n))` in the usual reconstruction output.

## Advantages

* Produces the correct longest common subsequence.
* Avoids repeated computation of overlapping subproblems.
* Clearly represents the solution using a DP table.
* Can be used for text comparison and sequence analysis.

## Limitations

* The DP table requires `O(m × n)` memory.
* For very large strings, the memory requirement can become significant.

## Why Dynamic Programming Works

The LCS problem has optimal substructure and overlapping subproblems.

The LCS of two strings can be determined using solutions to smaller prefixes of those strings. Dynamic Programming stores the results of these smaller problems in a table so that they do not need to be calculated repeatedly.

## Applications

LCS is used in:

* Text comparison
* File comparison
* Version control systems
* DNA and biological sequence analysis
* Document similarity
* Data comparison

## Technologies Used

* C++
* Data Structures and Algorithms
* Dynamic Programming

## Key Concepts

* Longest Common Subsequence
* Dynamic Programming
* DP Table
* String Processing
* Recurrence Relation
* Optimal Substructure
* Overlapping Subproblems
* Sequence Reconstruction
* Time and Space Complexity

## Result

The Longest Common Subsequence problem was successfully implemented using Dynamic Programming. The program displays the complete DP table and reconstructs the longest common subsequence from the table.
