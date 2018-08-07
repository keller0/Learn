import java.util.HashMap;
import java.util.Map;

public class LongestSubstring {

    private static int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, j = 0; i < n; i++) {
            if (map.containsKey(s.charAt(i))) {
                j = Math.max(map.get(s.charAt(i)), j);
            }
            ans = Math.max(i-j+1, ans);
            map.put(s.charAt(i), i+1);
        }
        return ans;
    }
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("123210"));
        System.out.println(lengthOfLongestSubstring(" "));
        System.out.println(lengthOfLongestSubstring("asjrgapa"));
    }
}
