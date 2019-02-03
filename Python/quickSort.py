import random

def quickSortrec(l, lo, hi):
    if lo < hi:
        j = partition(l, lo, hi)
        quickSortrec(l, j+1, hi)
        quickSortrec(l, lo, j-1)


def partition(l, lo, hi):
    i = lo
    j = hi
    pivot = l[i]
    while j > i:
        while l[i] <= pivot and i < hi:
            i += 1
        while l[j] > pivot:
            j -= 1
        if j > i:
            l[i], l[j] =  l[j], l[i]
    l[lo], l[j] = l[j], l[lo]
    return j

def quickSort(l):
    quickSortrec(l, 0, len(l) - 1)

print(lis)
quickSort(lis)
print(lis)
