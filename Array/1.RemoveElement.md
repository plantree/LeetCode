### 1、Array-RemoveElement

> Given an array *nums* and a value *val*, remove all instances of that value [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) and return the new length.
>
> Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with O(1) extra memory.
>
> The order of elements can be changed. It doesn't matter what you leave beyond the new length.

根据语言的不同，大致可以有两种解法：

1. C++本身提供的`vector`数据结构对于处理这个问题，十分的方便，仅用到`erase`这一个方法，就可以按需要清除数据，注意该方法返回的是指向该数据的`iterator`的下一个`iterator`。

   ```c++
   class Solution {
   public:
       int removeElement(vector<int>& nums, int val) {
           for (auto begin = nums.begin(); begin != nums.end(); ) {
               if (*begin == val) {
                   begin = nums.erase(begin);
               } else {
                   ++begin;
               }
           }
           return nums.size();
       }
   };
   ```

2. 更常规的思路，处理的是一个普通的数组，这就需要两个游标，一个负责指向待删除的数据，一个负责指向有效数据。

   ```c++
   class Solution {
   public:
       int removeElement(int A[], int n, int elem) {
           int i = 0, j = 0;
           for (i = 0; i < n; ++i) {
               if (A[i] == elem) {
                   continue;
               }
               A[j] = A[i];
               j++;
           }
           return j;
       }
   };
   ```

具体的代码记录在[Github](https://github.com/plantree/LeetCode/blob/master/Array/RemoveElement.cc)。