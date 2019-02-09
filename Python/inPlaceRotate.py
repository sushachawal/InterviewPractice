# Could use recursion but this is O(n) space due to the size
# of the recursion stack!

def rotate(lis, k):
    l = len(lis)
    cur = k % l
    while cur != 0 :
        temp = lis[0]
        lis[0] = lis[cur]
        lis[cur] = temp
        cur = (cur + k) % l
    #Need to do this in a for loop or something. Ideally find the lowest common
    #Factor and iterate over this!
    cur = (k+1) % l
    while cur != 1:
        temp = lis[1]
        temp = lis[1]
        lis[1] = lis[cur]
        lis[cur] = temp
        cur = (cur + k) % l

lis = [1,2,3,4,5,6,7,8,9]
k = 6

rotate(lis, k)

print(lis)
