# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        LL=list()
        while head:
            LL.append(head.val)
            head=head.next
        nxt=[0]*len(LL)
        pl=0
        cn=1
        while (cn<len(LL)):
            if (LL[pl]==LL[cn]):
                pl+=1
                nxt[cn]=pl
                cn+=1
            else:
                if pl==0:
                    cn+=1
                else:
                    pl=nxt[pl-1]
        def preorder(root,idx):
            if idx==len(LL):
                return True
            if not root:
                return False
            if (root.val==LL[idx]):
                idx+=1
                return preorder(root.left,idx) or preorder(root.right,idx)
            else:
                if idx==0:
                    return preorder(root.left,0) or preorder(root.right,0)
                else:
                    return preorder(root,nxt[idx-1])
        return preorder(root,0)
        
        
