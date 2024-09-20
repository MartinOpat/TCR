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