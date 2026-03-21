import heapq

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # A custom wrapper or a tuple (val, index, node) is needed 
        # because ListNode objects aren't directly comparable in Python 3.
        # The 'index' acts as a tie-breaker.
        min_heap = []
        
        for i, l in enumerate(lists):
            if l:
                heapq.heappush(min_heap, (l.val, i, l))
        
        dummy = ListNode(0)
        current = dummy
        
        while min_heap:
            val, i, node = heapq.heappop(min_heap)
            
            # Attach the smallest node found to our result list
            current.next = node
            current = current.next
            
            # If there is a next node in the list we just popped from, 
            # push it into the heap
            if node.next:
                heapq.heappush(min_heap, (node.next.val, i, node.next))
                
        return dummy.next
        