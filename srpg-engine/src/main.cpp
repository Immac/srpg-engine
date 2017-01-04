#include <lua.hpp>
#include <iostream>
#include "luautil.hpp"
#include "sqlite3.h"

using std::string;
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
	  printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


//using SrpgEngine::Framework::Lua::LuaScript;
int main(){
	sqlite3 *db;
	char *zErrMsg = 0;
	int  rc;
	string sql;

	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if( rc ){
	   fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	   return(0);
	}else{
	   fprintf(stdout, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE COMPANY("  \
		  "ID INT PRIMARY KEY     NOT NULL," \
		  "NAME           TEXT    NOT NULL," \
		  "AGE            INT     NOT NULL," \
		  "ADDRESS        CHAR(50)," \
		  "SALARY         REAL );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
	fprintf(stderr, "SQL error: %s\n", zErrMsg);
	   sqlite3_free(zErrMsg);
	}else{
	   fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;
//	LuaScript script("srpg-engine.config");
//	float posX = script.get<float>("player.position.x");
//	float posY = script.get<float>("player.position.y");
//	std::string filename = script.get<std::string>("player.filename");
//	int hp = script.get<int>("player.HP");

//	std::cout<<"Position X = "<<posX<<", Y = "<<posY<<std::endl;
//	std::cout<<"Filename:"<<filename<<std::endl;
//	std::cout<<"HP:"<<hp<<std::endl;

//	// getting arrays
//	std::vector<int> v = script.GetIntVector("array");
//	std::cout<<"Contents of array:";
//	for(std::vector<int>::iterator it = v.begin();
//			it != v.end();
//			it++) {
//			std::cout<<*it<<",";
//	}
//	std::cout<<std::endl;

//	// getting table keys:
//	std::vector<std::string> keys = script.GetTableKeys("player");
//	std::cout<<"Keys of [player] table:";
//	for(std::vector<std::string>::iterator it = keys.begin();
//			it != keys.end();
//			it++) {
//			std::cout<<*it<<",";
//	}
//	std::cout<<std::endl;
	return 0;
}
