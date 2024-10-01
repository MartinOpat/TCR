def chinese_remainder(ys, ms):
  N, x = 1, 0
  for m in ms: N*=m
  for y,m in zip(ys,ms):
    n = N // m
    x += n * y * modinv(n, m)
  return x % N