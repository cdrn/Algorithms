import pytest
import binary_search_tree

# setup
def init_bst():
  bst = binary_search_tree.BinarySearchTree(25)
  bst.insert(bst.root, 10)
  bst.insert(bst.root, 15)
  bst.insert(bst.root, 500)
  bst.insert(bst.root, 1000)
  bst.insert(bst.root, 4)
  return bst

def test_bst_init():
  bst = init_bst()
  assert bst.root.value == 25

def test_add_node_bst():
  bst = init_bst()
  bst.insert(bst.root, 10)
  print(bst.root.left)
  assert bst.root.left.value == 10

def test_bst_contains():
  bst = init_bst()
  assert bst.contains(bst.root, 500)
  
def test_bst_contains_false():
  bst = init_bst()
  print(bst.contains(bst.root, 12512))
  assert bst.contains(bst.root, 12512) == False

def test_bst_get_parent():
  bst = init_bst()
  assert bst.find_parent(bst.root, 1000).value == 500
