# Binary Search

def searchInsert(nums, target):
  low, high = 0, len(nums) - 1
  while low <= high:
    mid = (low + high) // 2
    if nums[mid] == target:
      return mid  # target found and return the position
    elif nums[mid] > target:
      high = low - 1
    else:
      low = mid + 1
  return low  # target not found and return the position to be inserted
