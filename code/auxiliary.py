from functools import lru_cache

# Read until EOF
while True:
    try:
        pattern = input()
    except EOFError:
        break
    
@lru_cache(maxsize=None)
def smth_memoi(i, j, s):
    # Example in-built cache
    return "sol"

# Fast I
import io, os
def fast_io(): 
    finput = io.BytesIO(os.read(0,
        os.fstat(0).st_size)).readline
    s = finput().decode() 
    return s

# Fast O 
import sys
def fast_out(): 
    n = 5
    sys.stdout.write(str(n)+"\n") 
