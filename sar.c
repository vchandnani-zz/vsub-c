#include <stdio.h>
#include <string.h>

main()
{
  char str1[256], str2[256], str3[256];
  char *ptr1, *ptr2, *ptr3;
  char *match_ptr1;

  int ctr1, ctr2;
  int match_ctr1;

  display_help();

  printf("  Enter the archive string: ");
  scanf("%s", str1);
  fflush(stdin);

  for( ptr1=str1; *ptr1!='\0'; ptr1++ )
    printf("char is %c", *ptr1);

  printf("  Enter the query string: ");
  scanf("%s", str2);
  fflush(stdin);

  printf("  Enter the replacement string: ");
  scanf("%s", str3);
  fflush(stdin);

  // search_string_for_query_string()
  // replace_search_string_with_query_string()
  // display_result_string()

  printf("\n Archive String: %s", str1);
  printf("\n Query String: %s", str2);
  printf("\n Replacement String: %s", str3);
  printf("\n Result String: COMING SOON \n");

  ctr2 = 0;
  match_ctr1 = 0;

  for( ptr1=str1, ptr2=str2, ctr1=0; ctr1<strlen(str1); ptr1++, ctr1++ )
//  for( ptr1=str1, ptr2=str2, ctr1=0; *ptr1!='\0'; ptr1++, ctr1++ )
  {
    printf("\n archive string array index %d, comparing %c with %c", ctr1, *ptr1, *ptr2);
    if( *ptr1 == *ptr2 )
    {
      match_ptr1 = ptr1;
      ptr2++;
      ctr2++;
      if( ctr2 == strlen(str2) )
      {
	printf("\n MATCH: archive string array index %d, character %c", ctr1, *match_ptr1);
	ptr2 = str2;
	match_ctr1++;
	ctr2 = 0;
      }
    }
    else
    {
      ptr2 = str2;
      ctr2 = 0;
    }
  } 
  if( match_ctr1 == 0)
  {
    printf("\n NO MATCH: archive string does not contain query string");
  }

}

display_help()
{
  system("tput clear");
  puts("  Welcome to the Search and Replace Program.");
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
}
