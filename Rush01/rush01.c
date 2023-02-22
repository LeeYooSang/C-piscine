#include <stdio.h>
#include <stdlib.h>

void ck(int arr[][6])
{
    for(int i = 1; i<5; i++){
        for(int j = 1; j < 5; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void c(int **arr)
{
    for(int i = 0; i<6; i++){
        for(int j = 0; j < 4; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int	calc_up(int *arr)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	calc_down(int *arr)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			cnt++;
		}
		i--;
	}
	return (cnt);
}

int	check_cond(int mat[][6])
{
	int		i;
	int		j;
	int		up;
	int		down;
	int		arr[4];

	i = 1;
	j = 1;
	while (i < 5)
	{
		while (j < 5)
		{
			arr[j - 1] = mat[j][i];
			j++;
		}
		up = calc_up(arr);
		down = calc_down(arr);
		if (up != mat[0][i] || down != mat[5][i])
			return (0);
		i++;
		j = 1;
	}
	return (1);
}

int	check_col(int mat[][6])
{
	int		i;
	int		j;
	int		check[5];

	j = 1;
	i = 1;
	while (i < 5)
	{
		while (j < 5)
			check[j++] = 0;
		j = 1;
		while (j < 5)
		{
			if (check[mat[j][i]] != 0)
				return (0);
			else
				check[mat[j][i]]++;
			j++;
		}
		i++;
		j = 1;
	}
	return (check_cond(mat));
}

int **init_outputline(int caseArr[][6], int left_case, int right_case, int **arr)
{
    int i;
    int j;
    int cnt;

    arr = (int **) malloc(6 * sizeof(int *));
    i = 0;
    while (i < 6)
    {
        arr[i] = (int *) malloc(sizeof(int) * 4);
        arr[i][0] = 0;
        i++;
    }
    j = 0;
    cnt = 0;
    while (j < 24)
    {
        if(caseArr[j][0]== left_case && caseArr[j][1] == right_case)
        {
            i = 0;
            while (i < 4)
            {
                arr[cnt][i] = caseArr[j][i + 2];
                i++;
            }
            cnt++;
        }
        j++;
    }
    return (arr);
}

void print_arr(int arr[][6])
{
    int i = 1;
    int j = 1;

    while(i <= 4){
        while(j <= 4){
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

int mk_arr(int arr[][6], int p[], int q[], int r[], int s[])
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if(p[i] == 0)
            return 0;
        arr[1][i + 1] = p[i];
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if(p[i] == 0)
            return 0;
        arr[2][i + 1] = q[i];
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if(p[i] == 0)
            return 0;
        arr[3][i + 1] = r[i];
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (p[i] == 0)
            return 0;
        arr[4][i + 1] = s[i];
        i++;
    }
    return 1;
}

void find_outputArr(int arr[][6], int caseArr[][6])
{
    int **arr1, **arr2, **arr3, **arr4;
    int cnt = 0;
    int *p;
    int *q;
    int *r;
    int *s;

    arr1 = init_outputline(caseArr, arr[1][0], arr[1][5], arr1); // 해당 행에 가능한 조합을 arr1에 저장 (4 x 4)
    arr2 = init_outputline(caseArr, arr[2][0], arr[2][5], arr2);
    arr3 = init_outputline(caseArr, arr[3][0], arr[3][5], arr3);
    arr4 = init_outputline(caseArr, arr[4][0], arr[4][5], arr4);

    p = &arr1[0][0];
    while(p < arr1[0] + 24)
    {
        if (*p == 0)
            break;
        q = &arr2[0][0];
        while(q < arr2[0] + 24)
        {
            if (*q == 0)
                break;
            r = &arr3[0][0];
            while(r < arr3[0] + 24)
            {
                if (*r == 0)
                    break;
                s = &arr4[0][0];
                while(s < arr4[0] + 24)
                {
                    if (*s == 0)
                        break;
                    int err = mk_arr(arr, p, q, r, s);
                    int check = check_col(arr);
                    if(check == 1)
                    {
                        ck(arr);
                        return;
                    }
                    s = s + 4;
                }
                r = r + 4;
            }
            q = q + 4;
        }
        p = p + 4;
    }
    printf("error\n");
}

int main(void)
{
    int arr[6][6] = {
        {0, 2, 1, 2, 4, 0},
        {2, 0, 0, 0, 0, 3},
        {3, 0, 0, 0, 0, 2},
        {1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 1},
        {0, 2, 3, 3, 1, 0}
    };
    
	int caseArr[24][6] = {
		{4,1,1,2,3,4}, {3,2,1,2,4,3},
		{3,2,1,3,4,2}, {3,2,2,3,4,1},
		{3,1,2,1,3,4}, {3,1,2,3,1,4},
		{3,1,1,3,2,4}, {2,2,3,4,1,2},
		{2,2,2,4,1,3}, {2,2,1,4,2,3},
		{2,2,3,1,4,2}, {2,2,2,1,4,3},
		{2,2,3,2,4,1}, {2,1,3,1,2,4},
		{2,1,3,2,1,4}, {1,4,4,3,2,1},
		{2,3,3,4,2,1}, {2,3,2,4,3,1},
		{2,3,1,4,3,2}, {1,3,4,3,1,2},
		{1,3,4,1,3,2}, {1,3,4,2,3,1},
		{1,2,4,2,1,3}, {1,2,4,1,2,3}
	};

    find_outputArr(arr, caseArr);
    

}
