class TrieNode {
  Map<Integer, TrieNode> children;
  int countPrefixSuffix;

  TrieNode() {
      this.children = new HashMap<>();
      this.countPrefixSuffix = 0;
  }
}

class Solution {
  TrieNode trie;

  Solution() {
      trie = new TrieNode();
  }

  public long countPrefixSuffixPairs(String[] words) {
      long ans = 0;
      for (String word : words) {
          TrieNode curr = trie;
          int n = word.length();
          for (int i = 0; i < n; i++) {
              int node = word.charAt(i) * 128 + word.charAt(n - 1 - i);
              if (!curr.children.containsKey(node)) {
                  curr.children.put(node, new TrieNode());
              }
              curr = curr.children.get(node);
              ans += curr.countPrefixSuffix;
          }
          curr.countPrefixSuffix++;
      }
      return ans;
  }
}