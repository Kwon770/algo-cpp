// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner scanner = new Scanner(System.in);

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());

        for (int t = 0; t < testcase; t++) {
            int n = Integer.parseInt(br.readLine());
            int[][] arr = new int[n + 1][2];
            int[][] dp = new int[n + 1][2];

            for (int i = 0; i < 2; i++) {
                String[] str = br.readLine().split(" ");
                for (int j = 1; j <= n; j++) {
                    arr[j][i] = Integer.parseInt(str[j - 1]);
                }
            }

            dp[1][0] = arr[1][0];
            dp[1][1] = arr[1][1];
            for (int i = 2; i <= n; i++) {
                dp[i][0] = Math.max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
                dp[i][1] = Math.max(dp[i - 1][0], dp[i - 2][0]) + arr[i][1];
            }
            System.out.println(Math.max(dp[n][0], dp[n][1]));
        }
    }
}
