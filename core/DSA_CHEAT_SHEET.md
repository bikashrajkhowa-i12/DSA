# 🚀 DSA QUICK REVISION CHEAT SHEET (Interview & Practice)

_Designed for 15–30 min rapid recall before interviews_

---

## 1. Time & Space Complexity

- **Big-O**: O(1), O(log n), O(n), O(n log n), O(n²)
- **Rule**: Drop constants, keep worst term
- **Tip**: Always say complexity even if solution is wrong

---

## 2. Arrays

- Contiguous memory, fast access
- **Patterns**: Two pointers, Sliding window, Prefix sum
- **Tip**: Most array problems are pointer problems

---

## 3. Strings

- Array of characters
- **Patterns**: Frequency map, Sliding window, Palindrome
- **Tip**: Adjacent check ≠ uniqueness check

---

## 4. Linked List

- Non-contiguous memory
- **Techniques**: Slow–fast pointer, Dummy node, Reverse
- **Tip**: Draw pointers before coding

---

## 5. Stack

- LIFO
- **Use cases**: Parentheses, Expression eval, Monotonic stack
- **Tip**: Previous/Next greater → Stack

---

## 6. Queue / Deque

- FIFO
- **Use cases**: BFS, Sliding window max/min
- **Tip**: Deque optimizes sliding window problems

---

## 7. Hashing (Map / Set)

- Avg O(1) lookup
- **Use cases**: Frequency, Duplicates, Fast search
- **Tip**: Space for speed trade-off

---

## 8. Recursion

- Function calls itself
- **Must have**: Base case
- **Tip**: Trust recursion, but trace stack

---

## 9. Backtracking

- Explore all possibilities
- **Steps**: Choose → Explore → Unchoose
- **Tip**: Undo step is mandatory

---

## 10. Sorting

- **Fast**: Merge, Quick, Heap
- **Stable**: Merge, Insertion
- **Tip**: Sorting simplifies logic

---

## 11. Binary Search

- Works on sorted or monotonic space
- **Variants**: First/Last, Lower/Upper bound
- **Tip**: Answer space can be binary searched

---

## 12. Trees

- Hierarchical structure
- **Traversals**: Inorder, Preorder, Postorder, Level
- **Tip**: Inorder of BST = sorted

---

## 13. Heaps / Priority Queue

- Min-heap / Max-heap
- **Use cases**: Top-K, Kth element
- **Tip**: Repeated min/max → Heap

---

## 14. Graphs

- Nodes + edges
- **Traversals**: BFS, DFS
- **Algorithms**: Dijkstra, Topo sort
- **Tip**: BFS = shortest path (unweighted)

---

## 15. Greedy

- Local optimum → global optimum
- **Examples**: Activity selection, Huffman
- **Tip**: Always justify correctness

---

## 16. Dynamic Programming

- Overlapping subproblems
- **Steps**:
  1. Define state
  2. Recurrence
  3. Base case

- **Tip**: Recursion + memo = DP

---

## 17. Bit Manipulation

- &, |, ^, <<, >>
- **Tricks**: XOR cancels duplicates
- **Tip**: Low-level but very powerful

---

## 18. Mathematical Algorithms

- GCD, Sieve, Fast power
- **Tip**: Math can remove brute force

---

## 19. Two Pointers

- Left & right pointers
- **Use cases**: Sorted arrays, Palindromes
- **Tip**: Reduces O(n²) → O(n)

---

## 20. Sliding Window

- Dynamic range maintenance
- **Use cases**: Subarrays, substrings
- **Tip**: Maintain window validity

---

## 21. Divide & Conquer

- Split → Solve → Merge
- **Examples**: Merge sort, Quick sort
- **Tip**: Watch recursion depth

---

## 22. Trie

- Prefix tree
- **Use cases**: Dictionary, Auto-complete
- **Tip**: Prefix problems scream Trie

---

## 23. Disjoint Set (Union-Find)

- Connectivity problems
- **Optimizations**: Path compression
- **Tip**: Graph connectivity made easy

---

## 24. Interview Golden Rules

- Start with brute force
- Optimize step by step
- Think aloud
- Handle edge cases

---

## command: g++ [options] filename.cpp -o executable_name && ./executable_name
