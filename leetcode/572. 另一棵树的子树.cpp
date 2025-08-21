# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        s1=list()
        s2=list()
        def preorder(root,s):
            if root==None:
                s.append(None)
                return
            s.append(root.val)
            preorder(root.left,s)
            preorder(root.right,s)
            return
        preorder(root,s1)
        preorder(subRoot,s2)
        PMT=[0]*len(s2)
        pl,i=0,1
        while (i<len(s2)):
            if s2[pl]==s2[i]:
                pl+=1
                PMT[i]=pl
                i+=1
            else:
                if pl==0:
                    i+=1
                else:
                    pl=PMT[pl-1]
        i,j=0,0
        while (i<len(s1)):
            if s1[i]==s2[j]:
                i+=1
                j+=1
            elif j==0:
                i+=1
            else:
                j=PMT[j-1]
            
            if j==len(s2):
                return True

        return False

        
