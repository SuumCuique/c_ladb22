#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)


int main()
{
	int n = 0, m=0, arr1 = -1, arr2 = 0;
	char modificator[100];
	scanf("%d", &n);
	if (n > 0 && n <= 1000000)
	{
		int  mas[1000];// = (int*)malloc(n);

		for (int i = 0; i < n; i++)
		{
			scanf("%i", &mas[i]);
		}

		scanf("%i",&m);

		if (m > 0 && m <= 20000)
		{
			for (int i = 0; i < m; i++)
			{
				scanf("%s%i%i", &modificator, &arr1, &arr2);
				if (arr1 >= 0)
				{
					if (strcmp(modificator, "PEAK") == 0 && arr2>=0)
					{
						int count = 0;
						for (int i = arr1; i <= arr2; i++)
						{
							int prev = 0, next = 0;
							if (i == 0) prev = 0; else prev = i - 1;
							if (i == n) next = i; else next = i + 1;

							if (mas[i] >= mas[prev] && mas[i] >= mas[next]) count++;
						}
						printf("%i\n", count);
					}
					else if (strcmp(modificator, "UPD") == 0)
					{
						mas[arr1] = arr2;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}