import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

class Two{
    public static int[] twoSum(int[] nums, int target) {
	Map<Integer, Integer> map = new HashMap<>();
	for (int i = 0; i < nums.length; i++) {
	    int complement = target - nums[i];
	    if (map.containsKey(complement)) {
		return new int[] { map.get(complement), i };
	    }
	    map.put(nums[i], i);
	}
	throw new IllegalArgumentException("No two sum solution");
    }

    
    public static void main(String[] args) {
	int arr[] = {9,2,3,4};
	int res[] = twoSum(arr, 5);

	System.out.println(Arrays.toString(res));
    }
}

