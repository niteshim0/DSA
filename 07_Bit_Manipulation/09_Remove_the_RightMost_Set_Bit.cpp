int removeRightMostSetBit(int n) {
  // Code here
  return n&(n-1);
}