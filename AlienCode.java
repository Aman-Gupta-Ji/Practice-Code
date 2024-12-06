public class AlienCode {
    int solution(String alienCode) {
        int count = 0;
        int feq[] = {1, 0, 0};
        int sum = 0;
        boolean isLeadingZero = true;

        for (char ch : alienCode.toCharArray()) {
            if (ch == '0' && isLeadingZero) {
                count++;
                isLeadingZero = true;
                continue;
            }
            
            isLeadingZero = false;
            sum += ch - '0';
            sum %= 3;

            count += feq[sum];
            if(ch != '0')
                feq[sum]++;
        }

        return count;
    }
}
