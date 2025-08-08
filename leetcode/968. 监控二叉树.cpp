# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:

        if not root: return 0

        def f(node):
            if not node:
                return 0,0,1 #沒有被監控 被監控 自己放監控

            a1,a2,a3=f(node.left)
            b1,b2,b3=f(node.right)
            A=min(a2,a3)+min(b2,b3)
            B=min(min(a2,a3)+b3,a3+min(b2,b3))
            C=min(a1,a2,a3)+min(b1,b2,b3)+1
            return A,B,C
        
        x,y,z=f(root)
        return min(y,z)
