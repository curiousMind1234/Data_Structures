In backtracking, we generate all solutions one element at a time. This problem is asking us to generate all possible permutations, 
so we will generate permutations one element at a time.
To generate a permutation one element at a time, we will use an array res that represents the current permutation we are building.
To start, we add the first element in nums. We have res = [nums[0]]. We are locking in this first value and we will now find all permutations that start with nums[0].
To find all permutations that start with nums[0], we start by adding the next element, which is nums[1]. We now have res = [nums[0], nums[1]].
We are locking in this second element and we will now find all permutations that start with nums[0], nums[1].
This continues until we use all elements, i.e. res.length == nums.length. 
Let's say that we have finished finding all permutations that start with [nums[0], nums[1]]. Now what?
We backtrack by removing the nums[1], and we have res = [nums[0]] again. Now, we add the second element that comes after nums[0], which is nums[2]. We have curr = [nums[0], nums[2]], and now we need to find all permutations that start with [nums[0], nums[2]].
Once we find all the permutations that start with [nums[0]], we backtrack by removing nums[0] from res and adding the next element.
We have res = [nums[1]], and now we need to find all permutations that start with nums[1].
This process is very recursive in nature. Each time we add an element, we solve a new version of the problem (find all permutations that start with res). 
The initial version of the problem is to find all permutations that start with [], which represents all possible permutations.

TC : O(n*n!)
Given a set of length n, the number of permutations is n! (n factorial). There are n options for the first number, n−1 for the second, and so on.

SC: O(n)
The extra space we use here is for res and the recursion call stack. The depth of the call stack is equal to the length of res, which is limited to n.
