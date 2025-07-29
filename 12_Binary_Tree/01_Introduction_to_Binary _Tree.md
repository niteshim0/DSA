# Tree
- A tree is a data structure similar to a linked list but instead of each node pointing simply to the next node in a linear fashion, each node points to a number of nodes.
- A tree is an example of a nonlinear data structure. A tree structure is a way of representing the hierarchical nature of a structure in a graphical form.

# Terminology
- **Node**: A node is a basic unit of a data structure, such as a tree or linked list.
- **Root**: The top node in a tree is called the root. It is the only node in the tree that has no parent.
- **Leaf**: A node that has no children is called a leaf node.
- **Edge**: An edge is a connection between two nodes.
- **Subtree**: A subtree is a tree formed by a node and all its descendants.
- **Height**: The height of a tree is the length of the longest path from the root to a leaf node.
- **Depth**: The depth of a node is the length of the path from the root to that node.
- **Degree**: The degree of a node is the number of children it has.  
- **Sibling**: Nodes that share the same parent are called siblings.
- **Ancestor**: A node is an ancestor of another node if it is on the path from the root to that node.
- **Descendant**: A node is a descendant of another node if it is on the path from that node to a leaf node.

## Binary Tree
- A binary tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child.
- The topmost node in a binary tree is called the root node.
- A binary tree can be empty, meaning it has no nodes, or it can have one or more nodes.
- The maximum number of nodes at level `l` of a binary tree is `2^l`, where `l` is the level number starting from 0 for the root.
- The maximum number of nodes in a binary tree of height `h` is `2^(h + 1) - 1`, where `h` is the height of the tree.
- The minimum number of nodes in a binary tree of height `h` is `h + 1`, which occurs when the tree is skewed (i.e., all nodes have only one child).
- A binary tree can be classified into different types based on its structure:  
  - **Full Binary Tree**: Every node other than the leaves has two children.
  - **Complete Binary Tree**: All levels are fully filled except possibly for the last level, which is filled from left to right.
  - **Perfect Binary Tree**: All internal nodes have two children and all leaf nodes are at the same level.
  - **Balanced Binary Tree**: The height of the left and right subtrees of any node differ by at most one.
  - **Degenerate (or pathological) Tree**: Each parent node has only one child, making it essentially a linked list.