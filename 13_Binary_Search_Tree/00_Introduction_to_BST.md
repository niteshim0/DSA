# Introduction to Binary Search Trees (BST)

## 1. What is a Binary Search Tree?

A **Binary Search Tree** is a type of binary tree where each node follows these properties:

1. **Left Subtree Property** – All values in the left subtree are **less** than the node's value.
2. **Right Subtree Property** – All values in the right subtree are **greater** than the node's value.
3. **Recursive Structure** – Both the left and right subtrees must also be binary search trees.

---

## 2. Structure of a BST Node

A BST node contains:
- **Data** (value)
- **Pointer to Left Child**
- **Pointer to Right Child**

Example in C++:
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

## 3. Example of a BST

    8
   / \
  3   10
 / \    \
1   6    14
   / \   /
  4   7 13


- All nodes in the **left subtree** of `8` are `< 8`  
- All nodes in the **right subtree** of `8` are `> 8`  

## 4. Common Operations

### a) Insertion
Insert by comparing the new value to the current node:
- If **smaller**, go to the left.
- If **greater**, go to the right.
- If the position is empty, insert there.

### b) Search
Traverse:
- If the value is found, return it.
- If **smaller**, go left.
- If **greater**, go right.

### c) Deletion
Three cases:
1. **Leaf node** – Remove directly.
2. **One child** – Replace with the child.
3. **Two children** – Replace with the in-order successor (smallest in right subtree).

---

## 5. Traversals in BST

- **Inorder (LNR)** – Produces sorted order for a BST.
- **Preorder (NLR)** – Useful for tree copying.
- **Postorder (LRN)** – Useful for deleting a tree.

## 6. Time Complexity (Average Case)

| Operation | Time Complexity |
|-----------|----------------|
| Search    | O(log n)       |
| Insert    | O(log n)       |
| Delete    | O(log n)       |

⚠ **Worst Case** – `O(n)` if the tree becomes skewed (like a linked list).  
Use **AVL** or **Red-Black Trees** for balancing.

## 7. Advantages
- Easy to implement.
- Efficient searching in sorted data.
- Inorder traversal gives elements in ascending order.

---

## 8. Disadvantages
- Can degrade to `O(n)` if not balanced.
- No automatic balancing unless using special BST types.

---

## 9. Applications
- Searching and sorting
- Implementing sets and maps
- Database indexing
- Range queries

