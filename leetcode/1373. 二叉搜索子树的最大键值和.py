# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        res=0
        
        def sol(root):
            if not root:
                return True,0x3f3f3f3f,-0x3f3f3f3f,0 #最小值 最大值
            else:
                l_isBST, l_min, l_max, l_sum=sol(root.left)
                r_isBST, r_min, r_max, r_sum=sol(root.right)
                if l_isBST and r_isBST and root.val>l_max and root.val<r_min:
                    ans=root.val+l_sum+r_sum
                    nonlocal res
                    res=max(ans,res)
                    return True,min(root.val,l_min),max(root.val,r_max),ans
                else:
                    return False,0,0,0
        sol(root)
        return max(0,res)
            
