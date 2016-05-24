//some includes (libraries)
#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

//(other includes)
#include "db.h"
#include "bstrlib.h"
#include "dbg.h"

//DB_open function that returns a file and opens the file depending on the mode arg
static FILE *DB_open(const char *path, const char *mode) {
	return fopen(path, mode);
}

//closes the database
static void DB_close(FILE *db) {
	fclose(db);
}


//function that loads in the database
static bstring DB_load() {
	FILE *db = NULL;
	bstring data = NULL;

	db = DB_open(DB_FILE, "r");
	check(db, "Failed to open database: %s", DB_FILE);

	data = bread((bNread)fread, db);
	check(data, "Failed to read from db file: %s", DB_FILE);

	DB_close(db);
	return data;

error:
	if(db) DB_close(db);
	if(data) bdestroy(data);
	return NULL;
}

//updates the database at the url
int DB_update(const char *url) {
	if(DB_find(url)) {
		log_info("Already recorded as installed: %s", url)
	}

	FILE *db = DB_open(DB_FILE, "a+");
	check(db, "Failed to open db file: %s", DB_FILE);

	bstring line = bfromcstr(url);
	bconchar(line, '\n');
	int rc = fwrite(line->data, blength(line), 1, db);
	check(rc == 1, "Failed to append to the db.");

	return 0;

error:
	if(db) DB_close(db);
	return -1;
}

//find the db at the url
int DB_find(const char *url) {
	bstring data = NULL;
	bstring line = bfromcstr(url);
	int res = -1;

	data = DB_load();
	check(data, "Failed to load: %s", DB_FILE);

	if(binstr(data, 0, line) == BSTR_ERR) {
		res = 0;
	} else {
		res = 1;
	}

error:
	if(data) bdestroy(data);
	if(line) bdestroy(line);

	return res;
}

//sets up the database
int DB_init() {
	apr_pool_t *p = NULL; //make a pool type
	apr_pool_initialize(); //initialise the pool
	apr_pool_create(&p, NULL); //create the pool

	if(access(DB_DIR, W_OK | X_OK) == -1) { //set up the error status var
		apr_status_t rc = apr_dir_make_recursive(DB_DIR,
			APR_UREAD | APR_UWRITE | APR_UEXECUTE | 
			APR_GREAD | APR_GWRITE | APR_GEXECUTE, p);
		check(rc == APR_SUCCESS, "Failed to make database directory: %s", DB_DIR);

	}

	if(access(DB_FILE, W_OK) == -1) {
		FILE *db = DB_open(DB_FILE, "w");
		check(db, "Cannot open database: %s", DB_FILE);
		DB_close(db);
	}

	apr_pool_destroy(p); //once opened free all memory space (with apr)
	return 0;

error:
	apr_pool_destroy(p);
	return -1;
}


//list all the rows in the database
int DB_list() {
	bstring data = DB_load();
	check(data, "Failed to read load: %s", DB_FILE);

	printf("%s", bdata(data));
	bdestroy(data);
	return 0;

error:
	return -1;
}







