#ifndef _db_h //check if already compiled
#define _db_h //if not then compile

//some constants for the database location
#define DB_FILE "/usr/local/.kcpkg/db" 
#define DB_DIR "/usr/local/.kcpkg"

//forward declaration of functions
int DB_init();
int DB_list();
int DB_update(const char *url);
int DB_fin(const char *url);

#endif