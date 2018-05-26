import pytest
import singly_linked_list

def init_linked_list():
  # Helper method to return an initialised linked list
  return singly_linked_list.LinkedList(20)

def test_linked_list_initialised():
  linked_list = init_linked_list()
  assert linked_list.get_first_node().get_val()== 20

def test_linked_list_add():
  linked_list = init_linked_list()
  linked_list.add(500)
  assert linked_list.contains(500)

