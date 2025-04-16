def xor(n):
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    else:
        return 0

T = int(input())
for i in range(T):
    S, F = map(int, input().split())
    print(xor(F) ^ xor(S - 1))
