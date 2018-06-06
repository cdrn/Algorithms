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
      root = node
    else:
      if node.value > root.value:
        if root.right == None:
          root.right = node
        else:
          # Keep calling on the children until we find the correct node (traversing right node)
          self.insert(root.right, value)
      # else if smaller or equal, push left node
      else:
        if root.left == None:
          root.left = node
        else:
          self.insert(root.left, value)

  # recursively search the bst to see if it contains a value
  def contains(self, root, value):
    if root is None:
      print('root is none')
      return False
    print('contains: ', root.value, value)

    if root.value == value:
      print('returned true')
      return True
    elif value > root.value:
      return self.contains(root.right, value)
    else:
      return self.contains(root.left, value)

  # return a pointer to the parent node
  def find_parent(self, root, value):
    if value == root.value:
      return root
    if value > root.value:
      if root.right == None:
        return None
      elif root.right.value == value:
        return root
      # recursively traverse the tree until we find our shit
      else:
        return self.find_parent(root.right, value)
    else:
      if root.left == None:
        return None
      elif root.left.value == value:
        return root
      else:
        return self.find_parent(root.left, value)

  # return a pointer to the actual node
  def find_node(self, root, value):
    if not root:
      return None
    if root.value == value:
      return root
    elif value > root.value:
      self.find_node(root.right, value)
    else:
      self.find_node(root.left, value)


