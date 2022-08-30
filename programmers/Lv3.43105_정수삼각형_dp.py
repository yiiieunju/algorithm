def solution(triangle):
    answer = 0
    height = len(triangle)
    dp = [[0]*50 for i in range(500)]
    
    dp[0][0] = triangle[0][0]
    
    for i in range(1,height):
        for j in range(len(triangle[i])):
            if j==0:
                dp[i][j] = dp[i-1][j]+triangle[i][j]
            elif i==j:
                dp[i][j] = dp[i-1][j-1]+triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]

    answer = max(dp[height-1])

    return answer

triangle = [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]

result = 30

print(solution(triangle))