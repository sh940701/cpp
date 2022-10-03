       if (nums[j] > nums[j+1]) {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }