def general_chinese_remainder(a,b,m,n):
  g = gcd(m,n)

  if a == b and m == n:
    return a, m
  if (a % g) != (b % g): 
    return None, None

  u,v = bezout_id(m,n)
  x = (a*v*n + b*u*m) // g
  return int(x) % lcm(m,n), int(lcm(m,n))
