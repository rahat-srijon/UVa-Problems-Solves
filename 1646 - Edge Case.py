F=[]
F.append(4)
F.append(7)
for i in range(2,10001):
    F.append(F[i-1]+F[i-2])
while True:
    try:
        n=int(input())
        print(F[n-3])
    except EOFError:
        break
