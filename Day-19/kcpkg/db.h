#ifndef _db_h
#define _db_h

#define DB_FILE "/usr/local/.kcpkg/db"
#define DB_DIR "/usr/local/.kcpkg"

int DB_init();
int DB_list();
int DB_update(const char *url);
int DB_fin(const char *url);

#endif