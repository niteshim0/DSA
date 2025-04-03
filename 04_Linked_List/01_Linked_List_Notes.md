# Linked List
A linked list is a data structure used for storing collections of data.
It consists of a sequence of nodes, where each node contains a value and a reference (or pointer) to the next node in the sequence. This allows for efficient insertion and deletion of elements, as well as dynamic resizing of the list.

## Difference between Array and Linked List

| Feature               | Array                          | Linked List                     |
|-----------------------|--------------------------------|----------------------------------|
| Memory Allocation      | Contiguous memory allocation   | Non-contiguous memory allocation |
| Size                  | Fixed size                     | Dynamic size                    |
| Access Time           | O(1)                           | O(n)                            |
| Insertion/Deletion     | O(n) (due to shifting elements)| O(1) (if pointer is known)      |
| Traversal             | O(n)                           | O(n)                            |
| Memory Overhead       | Low (only data)               | High (data + pointers)          |
| Cache Locality        | Good                           | Poor                            |
| Data Structure Type   | Homogeneous                   | Homogeneous or Heterogeneous    |
| Implementation         | Simple                        | More complex                    |
| Use Cases             | Static collections             | Dynamic collections              |


## Types of Linked List

1. **Singly Linked List**: Each node contains a value and a pointer to the next node.
   - **Advantages**: Simple implementation, efficient memory usage.
   - **Disadvantages**: Cannot traverse backward, requires more memory for pointers.

2. **Doubly Linked List**: Each node contains a value, a pointer to the next node, and a pointer to the previous node.
    - **Advantages**: Can traverse both forward and backward, easier to delete nodes.
    - **Disadvantages**: More memory usage due to additional pointer, more complex implementation.

3. **Circular Linked List**: The last node points back to the first node, forming a circle.
    - **Advantages**: Can traverse the list from any node, useful for circular data structures.
    - **Disadvantages**: More complex implementation, can lead to infinite loops if not handled properly.

4. **Circular Doubly Linked List**: A combination of circular and doubly linked lists, where each node has pointers to both the next and previous nodes, and the last node points back to the first node.
    - **Advantages**: Can traverse both forward and backward, can start from any node.
    - **Disadvantages**: More memory usage due to additional pointers, more complex implementation.

5. **Skip List**: A linked list with multiple levels of pointers, allowing for faster search times.
    - **Advantages**: Faster search times compared to regular linked lists.
    - **Disadvantages**: More complex implementation, requires additional memory for multiple levels of pointers.

## Application of Linked List

1. **Dynamic Memory Allocation**: Linked lists can be used to implement dynamic memory allocation, allowing for efficient use of memory.
2. **Implementing Stacks and Queues**: Linked lists can be used to implement stacks and queues, allowing for efficient insertion and deletion of elements.
3. **Graph Representation**: Linked lists can be used to represent graphs, allowing for efficient traversal and manipulation of graph data.
4. **Hash Tables**: Linked lists can be used to handle collisions in hash tables, allowing for efficient storage and retrieval of data.
5. **Sparse Matrices**: Linked lists can be used to represent sparse matrices, allowing for efficient storage and manipulation of matrix data.
6. **Text Editors**: Linked lists can be used to implement text editors, allowing for efficient insertion and deletion of characters.
7. **Music Playlists**: Linked lists can be used to implement music playlists, allowing for efficient insertion and deletion of songs.
8. **Memory Management**: Linked lists can be used to manage memory in operating systems, allowing for efficient allocation and deallocation of memory.
9. **Undo/Redo Functionality**: Linked lists can be used to implement undo/redo functionality in applications, allowing for efficient tracking of changes.
10. **Image Processing**: Linked lists can be used to represent images, allowing for efficient manipulation of pixel data.

