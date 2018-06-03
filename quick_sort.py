""" 
1) Pick an element, called a pivot, from the array.
2) Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
3) Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
"""

def QuickSort (input_list, low, high):
  if low < high:
    partition = Partition(input_list, low, high)


def Partition(input_list, low, high):
  # Define a pivot in which to demarcate the sorting of lesser and greater values
  pivot = input_list[high]
  i = low - 1
  for x in range(low, high)
    if input_list[x] < pivot
    i = i + 1
    
  return None