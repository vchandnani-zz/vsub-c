#include <stdio.h>
#include <string.h>

main()
{
  char *search_strings();
	char *copy_strings();

	char str1[32], str2[4], str3[8], str4[1024];
  char *ptr1, *ptr2, *ptr3, *ptr4;;
	char *start_ptr, *match_ptr, *copy_ptr;
	int match_ctr;

	ptr1 = ptr2 = ptr3 = NULL;
	start_ptr = match_ptr = copy_ptr = NULL;
	match_ctr = 0;

  display_help();
  get_strings( str1, str2, str3 );

	ptr1 = str1;
	ptr2 = str2;
	ptr3 = str3;

	start_ptr = str1;
	copy_ptr = str4;

//	while( *start_ptr != '\0' )
	while( start_ptr <= ( str1 + strlen( str1 ) ) ) 
	{
printf( "\n START ptr = %c", *start_ptr );
  	match_ptr = search_strings( str1, str2, start_ptr );
		if( match_ptr )
		{ 
			match_ctr ++;
printf( "\n if - MATCH ctr %d: need to start copy/replace", match_ctr );
			// RESULT STRING: copy from archive string start location to match location
			copy_strings( start_ptr, match_ptr, str4, copy_ptr );
			copy_ptr += match_ptr - start_ptr;
			// RESULT STRING: copy entire replacement string, i.e. replace query string
			copy_strings( ptr3, ptr3 + strlen( str3 ), str4, copy_ptr );
printf( "\n MATCH: RESULT STR4: %s", str4 );
			start_ptr = match_ptr + strlen(str2);
			copy_ptr += strlen( str3 );
printf( "\n continue searching from %c", *start_ptr );
		}
		else
		{
printf("\n else - match ctr = %d", match_ctr);
			if( match_ctr != 0)
			{
				// RESULT STRING: copy from archive string last match location until end
printf( "\n NO MATCH: copy from last match start ptr %c until end", *start_ptr );
				copy_strings( start_ptr, str1 + strlen( str1 ), str4, copy_ptr );
printf( "\n NO MATCH: RESULT STR4: %s", str4 );
				break;
			}
			else
			{
				printf( "\n The archive string does not contain the query string." );
				strcpy( str4, "N/A" );
				break;
			}
			start_ptr ++;
		}
	}

	display_results( str1, str2, str3, str4 );
} // end main()

display_help()
{
  system( "tput clear" );
  puts( "  Welcome to the String Search and Replace Program."  );
  puts( "  The Search and Replace Program searches the archive string for a query string." );
  puts( "  If the archive string contains the entire query string, it replaces the query" );
  puts( "  string with the replacement string and displays the final result string." );
  puts( "  Inputs:  Archive String, Query String and Replacement String." );
  puts( "  Outputs: Result String" );
  puts( "  Example:" );
  puts( "  --------" );
  puts( "  Archive String:     \"abcd\"" );
  puts( "  Query String:       \"bc\"" );
  puts( "  Replacement String: \"1234\"" );
  puts( "  Result String:      \"a1234d\"" );
  puts( "" );
}

get_strings( str1, str2, str3 )
char str1[32], str2[4], str3[8];
{
	get_string( str1, "archive", 32 );
	get_string( str2, "query", 4 );
	get_string( str3, "replacement", 8 );
}

get_string( str, name, max_len )
char str[32], name[16];
int max_len;
{
	for(;;)
	{
		printf( "  Enter the %s string (Maximum length = %d characters): ", name, max_len );
		scanf( "%s", str );
		fflush( stdin );
		if( strlen( str ) <= max_len )
		{
			break;
		}
	}
}

char *search_strings( str1, str2, start_ptr )
char str1[32], str2[4];
char *start_ptr;
{
	char *ptr1, *ptr2, *match_ptr1;
	int ctr1, ctr2, match_ctr1;

	ptr1 = ptr2 = match_ptr1 = NULL;
	ctr1 = ctr2 = match_ctr1 = 0;

  for( ptr1=start_ptr, ptr2=str2, ctr1=0; *ptr1!='\0'; ptr1++, ctr1++ )
  {
printf( "\n array index %d - comparing STR1: %c with STR2: %c", ctr1, *ptr1, *ptr2);
    if( *ptr1 == *ptr2 )
    {
      match_ptr1 = ptr1;
      match_ctr1++;
			ptr2++;
      ctr2++;
      if( *ptr2 == '\0' )
      {
				// calculate match start location 
				match_ptr1 = match_ptr1 - strlen( str2 ) + 1;
printf( "\n MATCH: STR1 contains STR2 at character %c", *match_ptr1 );
				ptr2 = str2;
				ctr2 = 0;
				return match_ptr1;
			}
		}
    else
    {
printf( "\n search_strings: NO MATCH ");
      match_ptr1 = NULL;
      ptr2 = str2;
      ctr2 = 0;
    }
	}
// printf( "\n search_strings: match_ptr1 = %c", *match_ptr1 );
	return match_ptr1;
}

char *copy_strings( start_ptr, end_ptr, dest_str, dest_copy_ptr )
char dest_str[1024];
char *start_ptr, *end_ptr, *dest_copy_ptr;
{
	char *ptr1, *ptr2;

	for( ptr1 = start_ptr, ptr2 = dest_copy_ptr; ptr1 < end_ptr; ptr1 ++, ptr2 ++ )
	{
		*ptr2 = *ptr1;
printf( "\n DEST STR: copied %c to %c", *ptr1, *ptr2 ); 
	}
}

display_results( str1, str2, str3, str4 )
char str1[32], str2[4], str3[8], str4[1024];
{
  printf( "\n  Archive String: %s", str1 );
  printf( "\n  Query String: %s", str2 );
  printf( "\n  Replacement String: %s", str3 );
  printf( "\n  Final Result String: %s", str4 );
  printf( "\n" );
}
