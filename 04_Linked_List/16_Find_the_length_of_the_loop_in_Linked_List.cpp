int countNodesinLoop(Node *head) {
  map<Node*,int> mp;
  int timer = 1;
  Node* temp = head;
  while(temp!=NULL){
      if(mp.find(temp)!=mp.end()){
          int cycleLen = timer-mp[temp];
          return cycleLen;
      }
      mp[temp] = timer++;
      temp = temp->next;
  }
  return 0;
}
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

int findLoopLen(Node* slow,Node* fast){
  int cnt = 1;
  fast = fast->next;
  while(fast!=slow){
      cnt++;
      fast = fast->next;
  }
  return cnt;
}
int countNodesinLoop(Node *head) {
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){
          return findLoopLen(slow,fast);
      }
  }
  return 0;
}
// Time Complexity : O(N)
// Space Complexity : O(1)