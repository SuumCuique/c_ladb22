#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int  mas1[250000];
int  mas2[250000];
int  mas3[250000];
int  mas4[250000];

int mas(int index)
{
	if (index >= 0 && index < 250000)
	{
		return mas1[index];
	}
	else if (index >= 250000 && index < 500000)
	{
		index -= 250000;
		return mas2[index];
	}
	else if (index >= 500000 && index < 750000)
	{
		index -= 500000;
		return mas3[index];
	}
	else if (index >= 750000 && index < 1000000)
	{
		index -= 750000;
		return mas4[index];
	}
}

int main()
{
	int n = 0, m=0, arr1 = -1, arr2 = 0;
	char modificator[100];
	scanf("%d", &n);
	if (n > 0 && n <= 1000000)
	{
		for (int i = 0; i < n; i++)
		{
			if(i<250000) 	scanf("%i", &mas1[i]);
			else if (i>=250000 && i< 500000) 	scanf("%i", &mas2[i - 250000]);
			else if (i >= 500000 && i < 750000) 	scanf("%i", &mas3[i - 500000]);
			else if (i >= 750000 && i < 1000000) 	scanf("%i", &mas2[i - 750000]);
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
							if (i == n-1) next = i; else next = i + 1;

							if (mas(i) >= mas(prev) && mas(i) >= mas(next)) count++;
						}
						printf("%i\n", count);
					}
					else if (strcmp(modificator, "UPD") == 0)
					{
						if (arr1 < 250000) mas1[arr1] = arr2;
						else if (arr1 >= 250000 && arr1 < 500000) mas2[arr1 - 250000] = arr2;
						else if (arr1 >= 500000 && arr1 < 750000) mas3[arr1 - 500000] = arr2;
						else if (arr1 >= 750000 && arr1 < 1000000) mas2[arr1 - 750000] = arr2;						
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}