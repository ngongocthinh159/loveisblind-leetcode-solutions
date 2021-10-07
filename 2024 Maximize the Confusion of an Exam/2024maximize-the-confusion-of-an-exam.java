class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int maxf = 0;
        int[] count = new int[128];
        int windows_length = 0;
        for (int i = 0; i < answerKey.length(); i++) {
            count[answerKey.charAt(i)]++;
            maxf = Math.max(maxf, count[answerKey.charAt(i)]);
            if (windows_length < maxf + k) {
                windows_length++;
            } else {
                count[answerKey.charAt(i - windows_length)]--;
            }
        }

        return windows_length;
    }
}