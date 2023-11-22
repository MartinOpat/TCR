# Read until EOF
while True:
    try:
        pattern = input()
    except EOFError:
        break
    