class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        length = [1] * n
        count = [1] * n

        maxLen = 1
        result = 0

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if length[i] < length[j] + 1:
                        length[i] = length[j] + 1
                        count[i] = count[j]
                    elif length[i] == length[j] + 1:
                        count[i] += count[j]

            maxLen = max(maxLen, length[i])

        for i in range(n):
            if length[i] == maxLen:
                result += count[i]

        return result