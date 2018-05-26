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
    def __init__(self, val, next=None):
      self.val = val
      self.next = next  # Nothing indicated end node
    
    def get_next(self):
      return self.next
    
    def get_val():
      return self.val


  def __init__(val):
    self.first_node = new Node(val=val)
    
  def __traverse(linked_list):
    node = linked_list.
    # Traverse the entire linked list to get to the end node
    while node.next:
      node = node.next
    return node # return when invariant is false (please don't loop a linked list lmao)
      
  def get_first_node():
    # Return the first node in the linked list
    return self.first_node

  def add(value):
    # Pre: The value to add to the linked list
    # post: The value has been placed at the tail of the list







