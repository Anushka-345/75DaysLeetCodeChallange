from collections import defaultdict

class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        # Dictionary to store row index -> bitmask of reserved seats
        # We only care about seats 2 through 9
        occupied_rows = defaultdict(int)
        
        for row, col in reservedSeats:
            if 2 <= col <= 9:
                # Use a bitmask where each bit represents a seat
                # Seat 2 is bit 0, Seat 3 is bit 1, ..., Seat 9 is bit 7
                occupied_rows[row] |= (1 << (col - 2))
        
        # Every row starts with the potential for 2 families
        # For rows with no reservations, they automatically provide 2
        max_families = n * 2
        
        # Masks for the three possible 4-seat blocks:
        # Left block (seats 2,3,4,5): bits 0,1,2,3 -> 15 (00001111)
        # Right block (seats 6,7,8,9): bits 4,5,6,7 -> 240 (11110000)
        # Middle block (seats 4,5,6,7): bits 2,3,4,5 -> 60 (00111100)
        
        left_mask = 15
        right_mask = 240
        mid_mask = 60
        
        for mask in occupied_rows.values():
            can_fit_left = (mask & left_mask) == 0
            can_fit_right = (mask & right_mask) == 0
            
            # If both left and right blocks are free, we fit 2 families (no deduction)
            if can_fit_left and can_fit_right:
                continue
            
            # If we can't fit 2, can we at least fit 1?
            # This is possible if the left, right, OR middle block is free.
            elif can_fit_left or can_fit_right or (mask & mid_mask) == 0:
                max_families -= 1
            
            # If no blocks are free, we can't fit any families in this row.
            else:
                max_families -= 2
                
        return max_families
        