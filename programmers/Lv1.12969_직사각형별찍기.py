a, b = map(int, raw_input().strip().split(' '))
for j in range(0,b):
    print("".join(['*' for i in range(0,a)]))