t = int(input())
def merge(arr,l,m,r):
    a1 = m-l+1
    a2 = r-m
    t1,t2 = [],[] # temporary array
    for i in range(a1):
        t1.append(arr[l+i])
    for i in range(a2):
        t2.append(arr[m+1+i])
    i = 0
    j = 0
    k = l
    while i<a1 and j<a2:
        if t1[i]<t2[j]:
            arr[k]=t1[i]
            i+=1
        else:
            arr[k]=t2[j]
            j+=1

        k+=1
    while i<a1:
        arr[k]=t1[i]
        i+=1
        k+=1
    while j<a2:
        arr[k]=t2[j]
        j+=1
        k+=1

def mergeSort(arr,l,r):
    if l < r:
        m = l+(r-l)//2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)


for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    mergeSort(l,0,n-1)
    print(l)
