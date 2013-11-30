#include <stdio.h>

void display_help()
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

char str1[256], str2[256], str3[256];

char *get_archive_string()
{
  puts("  Enter the archive string: ");
  scanf("%s", str1);
  return str1;
}

char *get_query_string()
{
  puts("  Enter the query string: ");
  scanf("%s", str2);
  return str2;
}

char *get_replacement_string()
{
  puts("  Enter the replacement string: ");
  scanf("%s", str3);
  return str3;
}

main()
{
  char *ptr1, *ptr2, *ptr3;
//  bool match;

  display_help();

  str1[256] = get_archive_string();
  str2[256] = get_query_string();
  str3[256] = get_replacement_string();

  // search_string_for_query_string()
  // replace_search_string_with_query_string()
  // display_result_string()

//  for( ptr1=str1; ptr1; ptr1++ )
 //   printf("char is %s", ptr1 );

  printf("\n Archive String: %s", str1);
  printf("\n Query String: %s", str2);
  printf("\n Replacement String: %s", str3);
  printf("\n Result String: COMING SOON \n");

//  match = false;
  ptr2 = str2;
/*
  for( ptr1=str1; ptr1; ptr1++ )
  {
    printf("\n comparing %c with %c", *ptr1, *ptr2);
    if( *ptr1 == *ptr2 )
    {
      ptr2++;
      if( *ptr2 == "\0" )
      {
//	match = true;
	printf("\n match!");
      }
    }
    else
    {
      ptr2 = str2;
    }
  } // end for() loop through str1
*/

} // end main
