# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], t: int) -> int:
        
        res=0
        
        def f(node,sums,hashmap):
            nonlocal res
            if not node:
                return 0
            sums+=node.val
            #print(node.val,sums)
            #print(hashmap,res)

            if sums-t in hashmap:
                res+=hashmap[sums-t]

            if sums in hashmap:
                hashmap[sums]+=1
            else:
                hashmap[sums]=1

            f(node.left,sums,hashmap)
            f(node.right,sums,hashmap)
            hashmap[sums] -= 1
            
        f(root,0,{0:1})
        return res
