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
    def __init__(self, value, left=None, right=None):
      self.value = value
      self.left = left
      self.right = right

  # the BST just contains a reference to the root node
  def __init__(self, value):
    self.root = self.Node(value)
  
  # Recurisve binary tree insertion
  def insert(self, root, value):
    node = self.Node(value)
    if root == None:
      self.root = node
    else:
      if node.value > root.value:
        if root.right == None:
          root.right = node
        else:
          # Keep calling on the children until we find the correct node (traversing right node)
          insert(root.right, node)
      # else if smaller or equal, push left node
      else:
        if root.left == None:
          root.left = node
        else:
          insert(root.left, node)


