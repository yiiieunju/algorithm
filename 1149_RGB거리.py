if __name__=="__main__":
    N= int(input())

    arr = [[0 for _ in range(0,3)] for i in range(0,N)]
    dp = [[0 for _ in range(0,3)] for i in range(0,N)]

    for i in range(0,N):
        arr[i][0],arr[i][1],arr[i][2] = list(map(int,input().split()))

    dp[0][0] = arr[0][0]
    dp[0][1] = arr[0][1]
    dp[0][2] = arr[0][2]

    for i in range(1, N):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2]

    ans = min(dp[N-1][0], dp[N-1][1])
    ans = min(ans, dp[N-1][2])

    print(ans)