"""
1.Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
"""


def MergeSort (list):
  print(list)
  # if the list only has one element, it's already sorted
  if len(list) <= 1:
    return list

  left = []
  right = []
  # Split the list in half
  for idx, var in enumerate(list):
    if idx < len(list)/2:
      left.append(var)
    else:
      right.append(var)
  
  # Now recursively sort the list by splitting down and remerging
  left = MergeSort(left)
  right = MergeSort(right)

  return merge(left, right)

  
def merge(left, right):
  result = []
  while left and right:
    if left[0] <= right[0]:
      result.append(left[0])
      del left[0]
    else:
      result.append(right[0])
      del right[0]

  # consume the remaining elements
  while left:
    result.append(left[0])
    del left[0]
  while right:
    result.append(right[0])
    del right[0]

  return result
    
