Step 1: Linearly traverse the array from backwards so that the array's ith index value is less than the array's (i+1)th index value. Store that index into a variable.
Step 2: If the index value obtained in step 1 is less than zero. This indicates that the given input array has already been sorted in descending order. Simply reverse the given array to obtain the next permutation. Otherwise, simply traverse the array backwards to find the index that has a value greater than the previously found index. Store index in another variable.
Step 3: Swap values present in indices found in the above two steps.
Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.
​
​