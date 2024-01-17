 public static int[] kmpAlgo(String s) {
        int n = s.length();
        int[] lps = new int[n];

        for (int i = 1; i < n; i++) {
            int prevIdx = lps[i - 1];

            while (prevIdx > 0 && s.charAt(i) != s.charAt(prevIdx)) {
                prevIdx = lps[prevIdx - 1];
            }

            lps[i] = prevIdx + (s.charAt(i) == s.charAt(prevIdx) ? 1 : 0);
        }

        return lps;
    }