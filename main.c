#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "libasm.h"

int		main()
{
	char short_string[4] = "abc";
	char long_string[30] = "abcdefg1234567891012321345355";
	char original_copy_short_string[4];
	char fake_copy_short_string[4];
	char original_copy_long_string[30];
	char fake_copy_long_string[30];
	char string_for_cmp[4] = "ab ";
	char string_for_cmp1[4] = "azz";
	char empty_string[11];
	char empty_string_2[3];
	char *str;
	empty_string[10] = '\0';
	empty_string_2[2] = '\0';

	printf("CHECKING FT_STRLEN:\n");
	printf("________________\nShort string\n________________\n");
	printf("string:|%s|\n", short_string);
	printf("original strlen:|%lu|\n",strlen(short_string));
	printf("my ft_strlen:|%lu|\n",ft_strlen(short_string));
	printf("________________\nLong string\n________________\n");
	printf("string:|%s|\n", long_string);
	printf("original strlen:|%lu|\n",strlen(long_string));
	printf("my ft_strlen:|%lu|\n",ft_strlen(long_string));
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");

	printf("CHECKING FT_STRCPY:\n");
	printf("Short string\n________________\n");
	printf("string:|%s|\n", short_string);
	printf("original strcpy:|%s|\n", strcpy(original_copy_short_string, short_string));
	printf("my ft_strcpy:|%s|\n", ft_strcpy(fake_copy_short_string, short_string));
	printf("________________\nLong string\n");
	printf("string:|%s|\n", long_string);
	printf("original strcpy:|%s|\n", strcpy(original_copy_long_string, long_string));
	printf("my ft_strcpy:|%s|\n", ft_strcpy(fake_copy_long_string, long_string));
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");

	printf("CHECKING FT_STRCMP:\n");
	printf("________________\nEqual strings\n________________\n");
	printf("string1:|%s|, string2:|%s|\n", short_string, short_string);
	printf("original strcmp:|%d|\n",strcmp(short_string, short_string));
	printf("my ft_strcmp:|%d|\n",ft_strcmp(short_string, short_string));
	printf("________________\nCharacter in first string is bigger\n________________\n");
	printf("string1:|%s|, string2:|%s|\n", short_string, string_for_cmp);
	printf("original strcmp:|%d|\n",strcmp(short_string, string_for_cmp));
	printf("my ft_strcmp:|%d|\n",ft_strcmp(short_string, string_for_cmp));
	printf("________________\nCharacter in second string is bigger\n________________\n");
	printf("string1:|%s|, string2:|%s|\n", short_string, string_for_cmp1);
	printf("original strcmp:|%d|\n",strcmp(short_string, string_for_cmp1));
	printf("my ft_strcmp:|%d|\n",ft_strcmp(short_string, string_for_cmp1));
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");

	printf("CHECKING FT_WRITE:\n");
	printf("________________\nWrite short string 'abc' to standart output:\n");
	ft_write(1, short_string, ft_strlen(short_string));
	printf("\n________________\nWrite long string to standart output:\n");
	ft_write(1, long_string, ft_strlen(long_string));
	printf("\n________________\nSending incorrect fd to write (errno before = %d):\n", errno);
	ft_write(-1, short_string, ft_strlen(short_string));
	printf("\nErrno after = %d\n", errno);
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");

	printf("CHECKING FT_READ:\n");
	printf("________________\nPlease, write 2 symbols to standart input and press ctl+D:\n");
	ft_read(1, empty_string_2, 3);
	printf("\nreaded line:|%s|\n", empty_string_2);
	printf("________________\nPlease, write 9 symbols to standart input and press ctl+D:\n");
	ft_read(1, empty_string, 10);
	printf("\nreaded line:|%s|\n", empty_string);
	errno = 0;
	printf("________________\nSending incorrect fd to read (errno before = %d):\n", errno);
	ft_read(-1, short_string, ft_strlen(short_string));
	printf("\nErrno after = %d\n", errno);
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");

	printf("CHECKING FT_STRDUP:\n");
	printf("________________\n");
	str = ft_strdup("abcdefgh");
	printf("strdup string:%s\n", str);
	printf("________________\n");
	printf("END OF CHECKING\n\n\n");
	return (0);
}