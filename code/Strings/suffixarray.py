class Entry:
    def __init__(self, pos, nr):
        self.p = pos
        self.nr = nr

    def __lt__(self, other):
        return self.nr < other.nr
class SA:
    def __init__(self, s):
        self.P = []
        self.n = len(s)
        self.build(s)

    def build(self, s): # n log log n
          n = self.n
          L = [Entry(0, 0) for _ in range(n)]
          self.P = []
          self.P.append([ord(c) for c in s])
          step = 1
          count = 1
  
          # self.P[step][i] stores the position 
          # of the i-th longest suffix
          # if suffixes are sorted according to 
          # their first 2^step characters.
          while count < 2 * n:
              self.P.append([0] * n)
              for i in range(n):
                  nr = (self.P[step - 1][i], 
                        self.P[step - 1][i + count]
                        if i + count < n else -1)
                  L[i].p = i 
                  L[i].nr = nr
              L.sort()
              for i in range(n):
                  if i > 0 and L[i].nr == L[i - 1].nr:
                      self.P[step][L[i].p] = \
                        self.P[step][L[i - 1].p]
                  else:
                      self.P[step][L[i].p] = i
              step += 1
              count *= 2
  
          self.sa = [0] * n
          for i in range(n):
              self.sa[self.P[-1][i]] = i
