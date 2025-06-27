def spiralOrder(matrix):
    my_list=[]
    rows=len(matrix)
    cols=len(matrix[0])
    left=0
    right=cols-1
    top=0
    bottom=rows-1
    while left<=right and top<=bottom:
        for i in range(left, right+1):
            my_list.append(matrix[top][i])
        top+=1
        for j in range(top, bottom+1):
            my_list.append(matrix[j][right])
        right-=1
        if top<=right:
            for k in range(right, left-1, -1):
                my_list.append(matrix[bottom][k])
            bottom-=1
        if left<=right:
            for l in range(bottom, top-1, -1):
                my_list.append(matrix[l][left])
            left+=1
    return my_list

matrix=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
ans=spiralOrder(matrix)
print(ans)

