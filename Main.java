// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
// StringBuilder sb = new StringBuilder();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int INF = Integer.MAX_VALUE - 100_0000;
    static int n;
    static int[][] map = new int[16][16];
    static int[][] dp = new int[16][1 << 16];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            int[] inp = parseIntArr(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = inp[j];
            }
        }

        System.out.println(tsp(0, 1));
        br.close();
    }

    static int tsp(int current, int visited) {
        // 모두 방문
        if ((visited == (1 << n) - 1)) {
            // 마지막 도시에서 0번 도시로 돌아갈 수 없을 경우
            if (map[current][0] == 0)
                return INF;

            return map[current][0];
        }

        // 이미 방문한 적이 있는 경우
        if (dp[current][visited] != 0)
            return dp[current][visited];

        dp[current][visited] = INF;
        for (int i = 0; i < n; i++) {
            int next = 1 << i;
            // 갈 수 없거나, 방문했다면 건너뜀
            if (map[current][i] == 0 || (visited & next) > 0)
                continue;

            // 현재 도시에서 방문한 도시들일때 도시 전체를 순회한 최소 비용
            dp[current][visited] = Math.min(dp[current][visited], tsp(i, visited | next) + map[current][i]);
        }

        return dp[current][visited];
    }

    static int[] parseIntArr(String input) {
        return Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}
