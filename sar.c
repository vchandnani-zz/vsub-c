#include <stdio.h>
#include <string.h>

main()
{
	char str1[32], str2[4], str3[8];

  display_help();
  get_strings(str1, str2, str3);
}

display_help()
{
  system("tput clear");
  puts("  Welcome to the String Search and Replace Program.");
  puts("  Inputs:  Archive String, Query String and Replacement String.");
  puts("  Outputs: Result String.");
  puts("  The Search and Replace Program searches the archive string for a query string.");
  puts("  If the archive string contains the entire query string, it replaces the query");
  puts("  string with the replacement string and displays the final result string.");
  puts("  Example:");
  puts("  Archive String:     \"hello world\"");
  puts("  Query String:       \"world\"");
  puts("  Replacement String: \"people\"");
  puts("  Result String:      \"hello people\"");
  puts("");
}

get_strings(str1, str2, str3)
char str1[32], str2[4], str3[8];
{
	get_string(str1, "archive", 32);
	get_string(str2, "query", 4);
	get_string(str3, "replacement", 8);
}

get_string(str, name, max_len)
char str[32], name[16];
int max_len;
{
	for(;;)
	{
		printf("  Enter the %s string (Maximum length = %d characters): ", name, max_len);
		scanf("%s", str);
		fflush(stdin);
		if( strlen(str) <= max_len )
		{
			break;
		}
	}
}
