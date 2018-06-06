""" 
1) Pick an element, called a pivot, from the array.
2) Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
3) Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
"""

def QuickSort (array):
  if len(array) > 1:
    pivot = array[0]
    less = [i for i in array[1:] if i < pivot]
    greater = [i for i in array[1:] if i >= pivot] # for convenience place equal vals above
    return QuickSort(less) + [pivot] + QuickSort(greater)
  # A single value array is sorted
  else:
    return array
