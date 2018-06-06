import quick_sort


pre_sorted_list = [5, 2, 1, 5, 9, 2]
print(quick_sort.QuickSort(pre_sorted_list))

def test_merge_sort():
  sorted_list = quick_sort.QuickSort(pre_sorted_list)
  assert sorted_list == [1, 2, 2, 5, 5, 9]