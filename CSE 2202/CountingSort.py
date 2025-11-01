def counting_sort():
    n = int(input())
    arr = list(map(int, input().split()))
    mn = None
    mx = None

    fre = [0]*100
    lst = []
    for i in range(n):
        fre[arr[i]] += 1
    for i in range(100):
        if fre[i] == 0 : continue
        for j in range (fre[i]):
            lst.append(i)
    print(lst)
counting_sort()

