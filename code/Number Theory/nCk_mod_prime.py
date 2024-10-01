def fermat_binom(n, k, p):
    if k > n:
        return 0
    num = 1
    for i in range(n-k+1, n+1):
        num *= i % p
    num %= p
    denom = 1
    for i in range(1,k+1):
        denom *= i % p
    denom %= p
    # numerator * denominator^(p-2) (mod p)
    return (num * pow(denom, p-2, p)) % p
