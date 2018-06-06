import pytest
import binary_search_tree

# setup
def init_bst():
  return binary_search_tree.BinarySearchTree(25)
  print(bst.root.value)

def test_bst_init():
  bst = init_bst()
  assert bst.root.value == 25

def test_add_node_bst():
  bst = init_bst()
  bst.insert(bst.root, 10)
  print(bst.root.left)
  assert bst.root.left.value == 10

