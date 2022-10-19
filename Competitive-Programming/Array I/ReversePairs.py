'''
Problem: 
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

'''
#Solve with Merge sorting Algorithm  
def merge(nums,low,mid,high):
    cnt=0
    j=mid+1
    for i in range(low,mid+1):
        while j<=high and nums[i]>2*(nums[j]):
            j+=1
        cnt+=(j-(mid+1))
    temp=[]
    left=low
    right=mid+1
    while left<=mid and right<=high:
        if nums[left]<=nums[right]:
            temp.append(nums[left])
            left+=1
        else:
            temp.append(nums[right])
            right+=1
    while left <=mid:
        temp.append(nums[left])
        left+=1
    while right<= high:
        temp.append(nums[right])
        right+=1
    
    for i in range(low,high+1):
        nums[i]=temp[i-low]
    return cnt
        
def  mergesort(nums,low,high):
    if low>=high:
        return 0
    mid=(low+high)//2
    inv=mergesort(nums,low,mid)
    inv+=mergesort(nums,mid+1,high)
    inv+=merge(nums,low,mid,high)
    return inv
nums = [40,25,19,12,9,6,2]
print(mergesort(nums,0,len(nums)-1))
