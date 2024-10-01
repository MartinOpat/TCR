def bezout_id(a, b):
    r,x,s,y,t,z = b,a,0,1,1,0
    while r:
        q = x // r
        x, r = r, x % r
        y, s = s, y - q * s
        z, t = t, z - q * t
    return y % (b // x), z % (-a // x)