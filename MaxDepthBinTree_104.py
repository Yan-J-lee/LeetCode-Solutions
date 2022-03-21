# Recursion
def maxDepth(root):
  if root:
    LD = maxDepth(root.left)
    RD = maxDepth(root.right)
    return max(LD, RD) + 1
  else:
    return 0
