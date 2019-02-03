def merge(l1, l2):
    len1 = len(l1)
    len2 = len(l2)
    target = len1 + len2
    ans = []
    while l1 and l2:
        if l1[0] <= l2[0]:
            ans.append(l1.pop(0))
        else:
            ans.append(l2.pop(0))
    ans.extend(l1)
    ans.extend(l2)
    print(ans)
    return ans

def mergesortrec(l, lo, hi):
    if hi == lo:
        return [l[hi]]
    mid = (hi + lo)//2
    return merge(mergesortrec(l, lo, mid), mergesortrec(l, mid+1, hi))

def mergesort(l):
    return mergesortrec(l, 0, len(l) - 1)

l = [4, 5, 2, 3, 7, 2, 8, 9]
print(l)
print(mergesort(l))
