# Solution 1: Brute Force
class Solution:
  def twoSum(self, nums, target):
    """
    nums: List[int]
    target: int
    return: List[int]
    """
    for i in range(len(nums)):
      for j in range(i + 1, len(nums)):
        if nums[i] + nums[j] == target:
          return [i, j]
 
# Solution 2: Hash Table
class Solution:
  def twoSum(self, nums, target):
    hash_table = {}
    for i in range(len(nums)):
      hash_table[nums[i]] = i
    for i in range(len(nums)):
      complement = target - nums[i]
      if complement in hash_table and hash_table[complement] != i:
        return [i, hash_table[complement]]
        
