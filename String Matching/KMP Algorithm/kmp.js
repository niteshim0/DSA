function kmpAlgo(s) {
  const n = s.length;
  const lps = new Array(n).fill(0);

  for (let i = 1; i < n; i++) {
      let prevIdx = lps[i - 1];

      while (prevIdx > 0 && s[i] !== s[prevIdx]) {
          prevIdx = lps[prevIdx - 1];
      }

      lps[i] = prevIdx + (s[i] === s[prevIdx] ? 1 : 0);
  }

  return lps;
}