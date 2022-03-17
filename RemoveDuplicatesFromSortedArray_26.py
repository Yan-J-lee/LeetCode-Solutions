# Two Pointer Approach 1
class Solution:
  def removeDuplicates(self, nums):
    i, j = 0, 1
    while j < len(nums):
      if nums[i] == nums[j]:
        del nums[j]
      else:
        i += 1
        j += 1
    return len(nums)

# Two Pointer Approach 2
def removeDuplicates(nums):
  i = 0
  for j in range(1, len(nums)):
    if nums[i] != nums[j]:
      i += 1
      nums[i] = nums[j]
  return i + 1
