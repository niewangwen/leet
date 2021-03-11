1. ALWAYS NOTICE THAT WHEN `right == left + 1`, `mid == left == (left + right) / 2`

2. MIND THE CORNER CASE!!! `target < nums[0]` AND `target > nums[nums.size() - 1]`

3. STRUCTURE for original binary search:
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

4. STRUCTURE for binary search WITH "ROTATED ARRAY":
   ```c
   int left = 0, right = len - 1;
   while (left <= right) {
       int mid = (left + right) / 2;
       //sometimes the below branch can be omitted according to the problem
       if (nums[mid] == target) {
          ....
       }
       //below is the KEY structure
       //DETERMINE THE ASCENDING SIDE
       //left->mid is ascending
       if (nums[left] < nums[mid]){
           //left is the minimum of [left, mid]
           //determine if the target appaer in [left, mid]
           left = mid + 1; OR right = mid - 1;
       }
       //IF ALL THE VALUE IS DISTINCT IN ARRAY, THIS BRANCH MEANS right == left + 1, mid == left == (left + right) / 2
       //IF THERE'RE DUPLICATES IN ARRAY, THIS BRANCH MEANS THERE MIGHT CONTAIN A MINIMUM IN (left, mid),
       //                                 SO WE ONLY RECORD nums[left], AND ONLY MAKE left++,
       //                                 AND WE WILL GET nums[left] < nums[mid] AFTER SOME LOOPS
       else if (nums[left] == nums[mid]) {
           //record left
           left++;
       }
       //mid->right is ascending
       else{
           //mid is the minimum of [mid, right]
           //determine if the target appaer in [mid, right]
           left = mid + 1; OR right = mid - 1;
       }
   }
   ```
