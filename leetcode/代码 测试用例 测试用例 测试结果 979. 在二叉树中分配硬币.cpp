# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        

        def sol(root):

            if not root:
                return 0,0,0 # 子樹節點數 硬幣數 移動數
            else:
                lnums,lcoins,lmoves=sol(root.left)
                rnums,rcoins,rmoves=sol(root.right)
                nums = lnums+rnums+1
                coins = lcoins+rcoins+root.val
                moves = lmoves+rmoves+abs(lnums-lcoins)+abs(rnums-rcoins)
                return nums,coins,moves
        return sol(root)[2] if root else 0
