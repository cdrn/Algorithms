"""
A linked list has similar properties to an array -- though unlike an array
a linked list does not have to be contiguous memory, or allocated ahead of time.
Because each node contains a pointer to the next node in the list, the data may be
distributed in memory. Unfortunately, this means linked lists have a 
linear lookup time
"""

class LinkedList:

  # Represents a node in the linked list
  class Node:
    def __init__(self, val=None, next=None):
      self.val = val
      self.next = next  # Nothing indicated means end node
    
    def get_next(self):
      return self.next
    
    def get_val(self):
      return self.val


  def __init__(self, val):
    self.first_node = self.Node(val)
    
  def __traverse(self):
    node = self.get_first_node()
    # Traverse the entire linked list to get to the end node
    while node.next:
      print(node.get_val())
      node = node.next
    return node # return when invariant is false (please don't loop a linked list lmao)
      
  def get_first_node(self):
    # Return the first node in the linked list
    return self.first_node

  def add(self, val):
    # Pre: The value to add to the linked list
    # post: The value has been placed at the tail of the list
    if not self.get_first_node():  # If no node exists, make one
      self.first_node = Node(val)
    else:  # else traverse to the final node and add
      node = self.__traverse()
      node.next = Node(value)

  def contains(self, val):
    # Assess whether the linked list contains a given value
    if not self.get_first_node():
      return False
    node = self.get_first_node()
    while node.get_val() is not val:
      node = node.next
    if node.get_val() == val:
      return True
    return False

  def delete(self, val):
    # Don't allow the first node to be deleted
    if not self.get_first_node():
      return False

    node = self.get_first_node()
    while val is not node.get_val():
      node = node.next
    # Handle the case of the node to be deleted being the first node
    if node.get_val() == val:
      if node == self.__traverse()






