#include<stdio.h>

int main() 
{
	int temp=0;
	while ((temp = getchar())&&temp!=EOF) {
		int pc[32] = { 0 }, acc = 0,i=0, instru = 0,bits=287;
		do
		{
			if (temp == ' ')
			{
				pc[i++] = instru;
				instru = 0;
				temp = '0';
			}
			instru = instru * 2 + temp - '0';
		} while ((temp = getchar()) && (bits--));
		pc[i++] = instru;
		int opcode = 0, data = 0, flag = 1, ptr = 0;
		while (flag)
		{
			opcode = pc[ptr] >> 5;
			data = pc[ptr] & 0x1F;
			switch (opcode)
			{
			case 0:
				pc[data] = acc;
				ptr = (ptr + 1) % 32;
				break;
			case 1:
				acc = pc[data];
				ptr = (ptr + 1) % 32;
				break;
			case 2:
				if (!acc)
					ptr = data;
				else ptr = (ptr + 1) % 32;
				break;
			case 3:
				ptr = (ptr + 1) % 32;
				break;
			case 4:
				acc = (acc - 1) % 256;
				ptr = (ptr + 1) % 32;
				break;
			case 5:
				acc = (acc + 1) % 256;
				ptr = (ptr + 1) % 32;
				break;
			case 6:
				ptr = data;
				break;
			case 7:
				flag = false;
				break;
			default:
				break;
			}
		}
		for (int k = 7;k >= 0;k--)
		{
			printf("%d", ((acc >> k) & 1));
		}
	}
	return 0;
}
