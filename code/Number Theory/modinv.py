def modinv(a, b):
  if b == 1: return 1
  b0, x0, x1 = b, 0, 1
  while a > 1:
    q, a, b = a//b, b, a%b
    x0, x1 = x1 - q * x0, x0
  if x1 < 0: x1 += b0
  return x1