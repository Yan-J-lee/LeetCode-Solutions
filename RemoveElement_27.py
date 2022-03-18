# Two Pointers
# Very Similar to remove duplicates in array

# Solution 1
def removeElement(nums, val):
  i = 0  # count the number of elements not equal to val
  for j in range(len(nums)):
    if nums[j] != val:
      nums[i] = nums[j]
      i += 1  
  return i

# Solution 2
def removeElement(nums, val):
  i = 0  # count the number of elements equal to val
  for j in range(len(nums)):
    if nums[j] == val:
      i += 1
    else:
      nums[j - i] = nums[j]
  return len(nums) - i
