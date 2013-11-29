#include <stdio.h>

void display_help()
{
  system("tput clear");
  puts("\n Welcome to the Search and Replace Program ");
  puts(" This program searches a search string for a query string. ");
  puts(" If the search string contains the entire query string, ");
  puts(" it replaces the query string with the newer string. ");
  puts(" Example:");
  puts(" Search String = \"hello world\" ");
  puts(" Query String = \"world\" ");
  puts(" Newer String  = \"people\" ");
  puts(" Result String = \"hello people\" ");
}

main()
{
  display_help();

  char str1[256], str2[256];

  puts("\n Enter the search string: ");
//  sscanf(%s, str1);
// printf("The original string is: %s", str1);

  puts("\n Enter the query string: ");
  //gets(str2);
  //printf("The query string is: %s", str2);
  //
  puts("\n Enter the newer string: ");

  puts("\n The result string is: FINAL ANSWER HERE ");

}


