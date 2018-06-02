import merge_sort


pre_sorted_list = [5, 2, 1, 5, 9, 2]
print(merge_sort.MergeSort(pre_sorted_list))

def test_merge_sort():
  sorted_list = merge_sort.MergeSort(pre_sorted_list)
  assert sorted_list == [1, 2, 2, 5, 5, 9]