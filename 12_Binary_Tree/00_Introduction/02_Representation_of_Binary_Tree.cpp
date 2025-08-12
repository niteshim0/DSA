struct Node{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int val){
    data = val;
    left = right = NULL;
  }
};