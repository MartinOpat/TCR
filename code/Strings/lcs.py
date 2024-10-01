def longestCommonSubsequence(text1, text2):
    n = len(text1)
    m = len(text2)
    prev = [0] * (m + 1)
    cur = [0] * (m + 1)
    for idx1 in range(1, n + 1):
        for idx2 in range(1, m + 1):
            # matching
            if text1[idx1 - 1] == text2[idx2 - 1]:
                cur[idx2] = 1 + prev[idx2 - 1]
            else:
                # not matching
                cur[idx2] = max(cur[idx2 - 1], prev[idx2])
        prev = cur.copy()
    return cur[m]