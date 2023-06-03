 file = fopen("profile.txt" , "r"); 
 while ( fgets (balance_string, 225, file) != NULL ) {
    count_read++;
    if ( count_read == 2 ) {
        puts(balance_string);
        printf("Balance: %s", balance_string);
    }
      } 
   fclose(file);
