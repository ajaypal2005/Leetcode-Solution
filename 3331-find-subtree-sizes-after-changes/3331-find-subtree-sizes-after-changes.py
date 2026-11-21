class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)

        # Original tree
        tree = [[] for _ in range(n)]
        for i in range(1, n):
            tree[parent[i]].append(i)

        # Compute new parents
        new_parent = parent[:]
        last = [-1] * 26

        def dfs(u):
            ch = ord(s[u]) - ord("a")

            prev = last[ch]
            last[ch] = u

            if u != 0 and prev != -1:
                new_parent[u] = prev

            for v in tree[u]:
                dfs(v)

            last[ch] = prev  # backtrack

        dfs(0)

        # Build modified tree
        new_tree = [[] for _ in range(n)]
        for i in range(1, n):
            new_tree[new_parent[i]].append(i)

        # Compute subtree sizes
        ans = [1] * n

        def dfs2(u):
            for v in new_tree[u]:
                dfs2(v)
                ans[u] += ans[v]

        dfs2(0)
        return ans
