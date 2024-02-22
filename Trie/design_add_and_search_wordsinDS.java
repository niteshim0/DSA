class Node {
  private Node[] links = new Node[26];
  private boolean isCompleted = false;

  public void put(char c, Node node) {
      this.links[c - 'a'] = node;
  }

  public Node get(char c) {
      return this.links[c - 'a'];
  }

  public boolean doesNotContainsKey(char c) {
      return this.links[c - 'a'] == null;
  }

  public boolean isEnd() {
      return this.isCompleted;
  }

  public void setEnd() {
      this.isCompleted = true;
  }

  public boolean search(String word, int index, Node node) {
      if (index == word.length()) return node.isEnd();
      char c = word.charAt(index);
      if (c == '.') {
          for (Node child : node.links)
              if (child != null && child.search(word, index + 1, child)) return true;
          return false;
      } else {
          if (node.doesNotContainsKey(c)) return false;
          return search(word, index + 1, node.get(c));
      }
  }
};
class WordDictionary {
  private final Node root;

  public WordDictionary() {
      root = new Node();
  }

  public void addWord(String word) {
      Node node = this.root;
      for (char c : word.toCharArray()) {
          assert node != null;
          if (node.doesNotContainsKey(c)) node.put(c, new Node());
          node = node.get(c);
      }
      node.setEnd();
  }

  public boolean search(String word) {
      return root.search(word, 0, root);
  }
}

