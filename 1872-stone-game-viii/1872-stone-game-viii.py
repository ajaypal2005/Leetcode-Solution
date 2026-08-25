class Solution:
    def stoneGameVIII(self, stones):
        n = len(stones)
        
        # Step 1: Compute prefix sums
        prefix = [0] * n
        prefix[0] = stones[0]
        for i in range(1, n):
            prefix[i] = prefix[i-1] + stones[i]
        
        # Step 2: Initialize dp with last prefix
        dp = prefix[-1]
        
        # Step 3: Iterate backward from n-2 to 1
        for i in range(n-2, 0, -1):
            dp = max(dp, prefix[i] - dp)
        
        return dp
