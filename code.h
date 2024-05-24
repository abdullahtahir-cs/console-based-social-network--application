#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>

using namespace std;
using namespace this_thread;

void start();

class user
{
protected:
	string first_name;
	string last_name;
	string id;
	string password;
	long long int phone;
	int count;
	string users[11];
public:
	user();
	void ask();
	void login();
	void create_account();
	~user();
};

class avee :public user
{
protected:
	string listoffriends[10];
	string listofposts[10];
	int noofposts;
	int nooffriends;
public:
	virtual void add() = 0;
	virtual void show() = 0; // view friend and posts lists,	
};

class Friend: public avee
{
public:
	void add();
	void show();
	~Friend();
};

class post : public avee
{
protected:
	string file_data[11];
public:
	void add();
	void show();
	void show1();
	void muft_salah();
	void like();
	void like_list();
	void share();
	void home();
	void page();
	~post();
};

void menu();
void select_option();
void OP();