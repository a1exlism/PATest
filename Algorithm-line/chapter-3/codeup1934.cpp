/**
 *  0<num<201
 *  find X
 * 
 *  Error: 测试数据有多组
 */

#include <cstdio>
int main()
{
    int num = 0;
    int arr[200] = {0};
    int x = 0;
    int index = 0;
    //  multiple data correct coding way
    while (scanf("%d", &num) != EOF)
    {

        for (int i = 0; i < num; i++)
        {
            scanf("%d", arr + i);
        }
        scanf("%d", &x);
        for (index = 0; index < num; index++)
        {
            if (arr[index] == x)
            {
                printf("%d\n", index);
                break;
            }
        }
        if (index == num)
        {
            printf("-1\n");
        }
    }
    return 0;
}