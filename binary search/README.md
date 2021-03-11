1. ALWAYS NOTICE THAT WHEN `right == left + 1`, `mid == left == (left + right) / 2`

2. MIND THE CORNER CASE!!! `target < nums[0]` AND `target > nums[nums.size() - 1]`

3. STRUCTURE:
   ```c
   int left = 0, right = len - 1;
   while(left <= right) {
       int mid = (left + right) / 2;
       if (nums[mid] == target) {
           return ...;
       }
       else if (nums[mid] > target) {
           right = mid - 1;
       }
       else {
           left = mid + 1;
       }
   }
   ```
