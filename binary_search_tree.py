"""
A balanced BST provides insert/search/lookup in O(log n) time. This
is easy to imagine -- if the central value x is at the top of the 
tree, each traversal decreases the number of possibilities by roughly
half IF the tree is balanced.
"""
class BinarySearchTree:

  # a node in the BST. Contains self value, and references to
  # left and right nodes
  class Node:
    def __init__(self, val, left=None, right=None):
      self.val = val
      self.left = left
      self.right = right

  def __init__(self, root):
    None