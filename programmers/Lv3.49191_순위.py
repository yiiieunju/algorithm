from unittest import result


def win_lose(n,results):
    arr = [[]]*n
    
    for index1, i in enumerate(results):
        win = []
        lose = []
        
        for inedx2,j in enumerate(results):
            
            if i[0] == j[0]: #이긴 위치에 있으면
                win.append(j[1])
            elif i[0] == j[1]: #진 위치에 있으면
                lose.append(j[0])
                
        print('*',results[index1][0],'*')
        print('win',win)
        print('lose',lose)
        print()
        
        if len(win) + len(lose) == n-1:
            arr[i[0]-1] = n - len(win)
            if len(win) == 1:
                c = map(int,win)
                print(c)
                # arr[c] = arr[i[0]-1] - 1
            elif len(lose) == 1:
                c = map(int,lose)
                print(c)
                # arr[c] = arr[i[0]-1] + 1
    print(arr)

n=5
results=[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]    
win_lose(n,results)