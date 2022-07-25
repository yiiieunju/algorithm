def solve(N,K, vv):
    # print(vv)
    
    dp = [[0 for _ in range(K+1)] for _ in range(N+1)]
    
    # for i in range(0,len(dp)):
    #     for j in range(0,len(dp[0])):
    #         print(dp[i][j], end=' ')
    #     print()

    for i in range(1,N+1):
        for j in range(1, K+1):
            w = vv[i][0]
            v = vv[i][1]
            
            # 담을 수 있는 무게보다 작으면 메모이제이션 된 값 가져오기
            if j < w:
                dp[i][j] = dp[i-1][j]
            # 담을 수 있는 무게면
            # 메모이제이션 중 현재 무게를 안 담았을 때 최대 가치인 무게 값에다가  
            # 현재 가치 더하기
            else:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v)

    return dp[N][K]

if __name__=="__main__":
    N, K = map(int, input().split())

    vv = list()
    vv.append([0,0])
    for i in range(0,N):
        tmp = list(map(int,input().split()))
        vv.append(tmp)
    # print(vv)

    ans = solve(N,K, vv)
    print(ans)