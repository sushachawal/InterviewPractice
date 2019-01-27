import heapq
import sys

def k_largest(l, k):
    h = []
    for i in l:
        if len(h) < k:
            heapq.heappush(h, i)
        elif i > h[0]:
            heapq.heapreplace(h,i)
    return h

def k_smallest(l, k):
    h = []
    for i in l:
        if len(h) < k:
            heapq.heappush(h, -i)
        elif -i > h[0]:
            heapq.heapreplace(h,-i)
    return [-j for j in h]

if __name__ == '__main__':
    unsorted_list = [3, 5, 6, 3, 2, 5, 2, 1, 7, 234, 984, 234]
    print(unsorted_list)
    print(k_largest(unsorted_list, int(sys.argv[1])))
    print(k_smallest(unsorted_list, int(sys.argv[1])))
