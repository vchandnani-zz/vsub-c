#include <stdio.h>
#include <string.h>

main()
{
  // TO DO: string length limits and validations
  char str1[128], str2[32], str3[32], str4[1024];
  char *ptr1, *ptr2, *ptr3, *ptr4, *ptr5;
  char *start_ptr1, *match_ptr1;
  int ctr1, ctr2;
  int match_ctr1;

  ptr1 = ptr2 = ptr3 = ptr4 = ptr5 = NULL;
  start_ptr1 = match_ptr1 = NULL;
  ctr1 = ctr2 = 0;
  match_ctr1 = 0;

  display_help();
  get_strings(str1, str2, str3);

  ptr4 = str4;
  start_ptr1 = str1;

  for( ptr1=str1, ptr2=str2, ctr1=0; *ptr1!='\0'; ptr1++, ctr1++ )
  {
    printf("\n  archive string array index %d, comparing %c with %c", ctr1, *ptr1, *ptr2);
    if( *ptr1 == *ptr2 )
    {
      match_ctr1++;
      match_ptr1 = ptr1;
      ptr2++;
      ctr2++;
      if( *ptr2 == '\0' )
      {
	match_ptr1 = match_ptr1 - strlen(str2) + 1;
	printf("\n  MATCH: archive string contains query string at array index %d, character %c", ctr1-1, *match_ptr1);

	// copy characters from beginning of archive string str1 until match location
	for( ptr5=start_ptr1; ptr5<match_ptr1; ptr4++, ptr5++ ) 
	{
	  *ptr4 = *ptr5;
          printf("\n  STR1: COPY %c to %c", *ptr5, *ptr4);
	}
        start_ptr1 = match_ptr1 + strlen(str2);

	// copy characters from replacement string str3 (replacing query string str2)
	for( ptr5=str3; *ptr5!='\0'; ptr4++, ptr5++ )
	{
          *ptr4 = *ptr5;
	  printf("\n  STR3: COPY %c to %c", *ptr5, *ptr4);
	}

	ptr2 = str2;
	ctr2 = 0;
      }
    }
    else
    {
      ptr2 = str2;
      ctr2 = 0;
    }
  } 

  // copy remaining characters from archive to result string (after last match)
  for( ptr5=start_ptr1; *ptr5!='\0'; ptr4++, ptr5++ )
  {
    *ptr4 = *ptr5;
    printf("\n  AFTER LAST MATCH STR1: COPY %c to %c", *ptr5, *ptr4);
  }

  // terminate final result string
  *ptr4 = '\0';

  if(match_ctr1 == 0)
  {
    sprintf(str4, "The archive string \"%s\" does not contain query string \"%s\".", str1, str2);
  }

  display_results(str1, str2, str3, str4);
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

get_strings(str1, str2, str3)
char str1[128], str2[32], str3[32];
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

display_results(str1, str2, str3, str4)
char str1[128], str2[32], str3[32], str4[1024];
{
  printf("\n  Archive String: %s", str1);
  printf("\n  Query String: %s", str2);
  printf("\n  Replacement String: %s", str3);
  printf("\n  Final Result String: %s", str4);
  printf("\n");
}
