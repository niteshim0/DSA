def kmp_algo(s):
    n = len(s)
    lps = [0] * n

    for i in range(1, n):
        prev_idx = lps[i - 1]

        while prev_idx > 0 and s[i] != s[prev_idx]:
            prev_idx = lps[prev_idx - 1]

        lps[i] = prev_idx + (s[i] == s[prev_idx])

    return lps