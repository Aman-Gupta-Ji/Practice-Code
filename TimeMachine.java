public class TimeMachine {
    int solution(int[] years ) {
        int n = years.length;
        if(n < 2)
            return 0;
        int time = 0;
        int prev = years[0];
        for(int i = 1; i < n; i++) {
            if(prev == years[i])
                continue;
            if(prev < years[i])
                time++;
            else
                time+=2;
            prev = years[i];
        }
        return time;

    }
}
