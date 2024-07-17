n=int(input())
if n<2:
    print(n)
else:
    a,b=0,1
    for i in range(2,n+1):
        a,b=b,b+a
    print(b)