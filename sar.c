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
  printf("  Enter the archive string: ");
  scanf("%s", str1);
  fflush(stdin);

  printf("  Enter the query string: ");
  scanf("%s", str2);
  fflush(stdin);

  printf("  Enter the replacement string: ");
  scanf("%s", str3);
  fflush(stdin);
}
