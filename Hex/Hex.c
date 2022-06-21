#include "hex.h"
static char h2d(char h)//'0'-'F'=>0-15
{
	char ret = 16;
	if (h >= '0' && h <= '9')
	{
		ret = h - '0';
	}
	else if ((h >= 'A' && h <= 'F'))
	{
		ret = h + 10 - 'A';
	}
	else if (h >= 'a' && h <= 'f')
	{
		ret = h + 10 - 'a';
	}
	return ret;
}

static  char d2h(char d)//0-15=>'0'-'F'
{
	return (d >= 0 && d <= 9) ? d + '0' : d + 'A' - 10;
}

unsigned int Hex_Encode(char* destination,const char* source,unsigned int length)
{	
	unsigned char v;	
	unsigned int cnt = 0;	
	while ((v = *source++) && cnt<length-1)
	{
		*destination++ = d2h(v / 16);
		*destination++ = d2h(v % 16);
		cnt+=2;
	}
	*destination = 0;
	return cnt;
}

unsigned int Hex_Decode(char* destination,const char* source,unsigned int length)
{	
	char c1, c2, v1, v2;
	unsigned int cnt = 0;	
	while (cnt < length - 1)
	{
		if (c1 = *source++)
		{
			if (c2 = *source++)
			{
				if ((v1 = h2d(c1)) < 16)
				{
					if ((v2 = h2d(c2)) < 16)
					{
						v1 = v1 * 16 + v2;
						if(c1!= ' ' && v1 !='\t' && v1!='\n' && v1!='\"' && v1!='}' && v1!='{' )//Ignore whitespace characters.
						{
							*destination++=v1;
							cnt++;
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	*destination = 0;
	return cnt;
}