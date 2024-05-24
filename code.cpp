#include "code.h"
string g_id = "\0";
int g_count = 0;

void start()
{
	ShowWindow(GetConsoleWindow(), 3);
	ifstream m("start.txt");
	char c;
	cout.width(48);
	while (!(m.eof()))
	{
		m.get(c);
		if (!(m.eof()))
		{
			cout << c;
			if (c == '\n')
			{
				cout.width(48);
			}
		}
	}
	m.close();
	cout << endl;
	system("pause");
	system("cls");
}

// user class definition.
user::user()
{
	first_name = "\0";
	last_name = "\0";
	id = "\0";
	password = "\0";
	for (int i = 0; i < 11; i++)
	{
		users[i] = "-1";
	}
	count = 0;
}
void user::ask()
{
	char select;
	ifstream c("count.txt");
	c >> count;
	c.close();
	cout.width(78);
	cout << "R3X" << endl;
	cout.width(90);
	cout << "What do you want to do: " << endl;
	cout.width(82);
	cout << "1. Login. " << endl;
	cout.width(86);
	cout << "2. Create account." << endl;
	cin >> select;
	cout << endl;

	for (int i = 0; i < 1;)
	{
		try
		{
			if (select != '1' && select != '2')
			{
				throw "qwerty";
			}
			break;
		}
		catch (const char* p)
		{
			system("cls");
			cout.width(78);
			cout << "R3X" << endl;
			cout.width(98);
			cout << "Please select from the following option: " << endl;
			cout.width(82);
			cout << "1. Login. " << endl;
			cout.width(86);
			cout << "2. Create account." << endl;
			cin >> select;
		}
	}
	if (select == '1')
	{
		if (count == 0)
		{
			cout << "You cannot login, first create account." << endl;
			create_account();
		}
		else
		{
			login();
		}
	}
	else if (select == '2')
	{
		create_account();
	}
}

void user::login()
{
	int no_yes = 0;
	string id_check;
	string password_check;
	ifstream user_file("user_id.txt");
	for (int i = 0; i < count; i++)
	{
		getline(user_file, users[i]);
	}
	user_file.close();
	cin.ignore();
	cout << "Enter your ID: ", getline(cin, id_check);
	for (int i = 0; i < count; i++)
	{
		if (id_check == users[i])
		{
			no_yes = 0;
			ifstream User(users[i] + ".txt");
			cout << "Enter your password: ", getline(cin, password_check);
			string read_check;
			while (!User.eof())
			{
				getline(User, read_check);
				if (read_check == "p250")
				{
					getline(User, read_check);
					break;
				}
			}
			while (1)
			{
				if (read_check == password_check)
				{
					g_id = id_check;
					system("cls");
					cout.width(85);
					cout << "Logging in..." << endl;
					sleep_for(1.7s);
					system("cls");
					cout.width(78);
					cout << "R3X" << endl;
					break;
				}
				else
				{
					cout << "Your password is incorrect." << endl;
					cout << "Enter password again: ";
					getline(cin, password_check);
				}
			}
			User.close();
			break;
		}
		else
		{
			no_yes = -1;
		}
	}
	if (no_yes == -1)
	{
		cout << "There is no user with this ID." << endl;
		ask();
	}
	g_count = count;
}

void user::create_account()
{
	if (count < 11)
	{
		ifstream User_file("user_id.txt");
		for (int i = 0; i < count; i++)
		{
			getline(User_file, users[i]);
		}
		User_file.close();
		string Password;
		cin.ignore();
		cout << "Enter your first name: ", getline(cin, first_name);
		cout << "Enter your last name: ", getline(cin, last_name);
		cout << "Enter your phone number: ";
		while (1)
		{
			try
			{
				while (!(cin >> phone))
				{
					cin.clear();
					cin.ignore();
					throw 5;
				}
				break;
				while (phone < 11 || phone>11)
				{
					cin.clear();
					cin.ignore();
					throw "querty";
				}
			}
		
			catch (int xyz)
			{
				cout << "Please enter only numbers: " << endl;
			}
			catch (const char* ptr)
			{
				cout << "please enter 11 digits only" << endl;
			}
		}
		cin.ignore();
		string a;
		long long int b;
		if (count != 0)
		{
			for (int i = 0; i < count;)
			{
				ifstream check(users[i] + ".txt");
				if (!(check.is_open()))
				{
					cout << "File does not open." << endl;
				}
				while (!(check.eof()))
				{
					getline(check, a);
					if (a == "phone")
					{
						check >> b;
						if (b == phone)
						{
							cout << "This phone number has already in use, try another one: " << endl;
							cout << "Enter your phone number: ", cin >> phone; cin.ignore();
							i = 0;
							break;
						}
						else
						{
							i++;
						}
					}
				}
				check.close();
			}
		}
		cout << "Enter your user id (through which you will login): ", getline(cin, id);
		for (int i = 0; i < count;)
		{
			if (users[i] == id)
			{
				cout << "This ID has been used by another user, try another ID." << endl;
				getline(cin, id);
				i = 0;
			}
			else
			{
				i++;
			}
		}
		ofstream user_file;
		user_file.open("user_id.txt", ios::app);
		if (!(user_file.is_open()))
		{
			cout << "File does not open." << endl;
		}
		user_file << id << endl;
		user_file.close();
		users[count] = id;
		ofstream make_file;
		make_file.open(users[count] + ".txt");  // making of file for every user.
		if (!(make_file.is_open()))
		{
			cout << "File does not open." << endl;
		}
		for (int i = 0; i < 1;)
		{
			cout << "Enter password for your account: ", getline(cin, password);  // condition ligani hai k password more than 4 characters hona chahye.
			while (1)
			{
				try
				{
					if (password.length() <= 4)
					{
						throw "error";
					}
					break;
				}
				catch (const char* p)
				{
					cout << "Password length must be greater then 4 characters." << endl;
					cout << "Enter password for your account: ", getline(cin, password);
				}
			}
			cout << "Enter password again for confirmation: ", getline(cin, Password);
			if (Password == password)
			{
				ofstream c("count.txt");
				if (!(c.is_open()))
				{
					cout << "File does not open." << endl;
				}
				cout << "Your account has been made." << endl;
				sleep_for(1.5s);
				count++;
				c << count << endl;
				c.close();
				break;
			}
			else
			{
				cout << "Password does not match!" << endl;
				cout << "Enter again." << endl;
			}
		}
		make_file << "id" << endl << id << endl << "p250" << endl << password << endl << "first name" << endl << first_name << endl << "last name" << endl << last_name << endl;
		make_file << "phone" << endl << phone << endl;
		make_file.close();
		system("cls");
		ask();
	}
	else
	{
		cout << "Only 11 user can make their accounts. " << endl;
		ask();
	}
	// data in file
}
user::~user() {}

// Friend class implementation

void Friend::add()
{
	ifstream f(g_id + "_friends.txt");
	if (f.is_open())
	{
		while (!(f.eof()))
		{
			if (!(f.eof()))
			{
				getline(f, id);
				nooffriends++;
			}
		}
		f.close();
	}
	if (nooffriends <= 10)
	{
		ofstream friends(g_id + "_friends.txt", ios::app);
		if (!(friends.is_open()))
		{
			cout << "File is not open!" << endl;
		}
		cin.ignore();
		cout << "Enter id of user, you want to make friend: ", getline(cin, id);
		ifstream User_file("user_id.txt");
		for (int i = 0; i < g_count; i++)
		{
			getline(User_file, users[i]);
		}
		User_file.close();
		int yes_no = 0;
		for (int i = 0; i < g_count; i++)
		{
			if (id == users[i])
			{
				yes_no = 0;
				friends << id << endl;
				cout << "You have added " << id << ". " << endl;
				break;
			}
			else
			{
				yes_no = 1;
			}
		}
		if (yes_no == 1)
		{
			cout << "There is no user with this id." << endl;
		}
		friends.close();
	}
	else
	{
		cout << "You cannot add more friends, limit is of 10." << endl;
	}
}

void Friend::show()
{
	cout << "Friend List: " << endl;
	ifstream f(g_id + "_friends.txt");
	if (f.is_open())
	{
		while (!(f.eof()))
		{
			getline(f, id);
			if (!(f.eof()))
			{
				cout << id << endl;
			}
		}
		f.close();
	}
}

Friend::~Friend() {}

// post class implementation

void post::add()
{
	string check;
	ifstream p1(g_id + "_post.txt");
	if (p1.is_open())
	{
		while (!(p1.eof()))
		{
			getline(p1, check);
			if (!(p1.eof()))
			{
				listofposts[noofposts] = check;
				noofposts++;
			}
		}
		p1.close();
	}
	if (noofposts <= 10)
	{
		ofstream p(g_id + "_post.txt", ios::app);
		if (!(p.is_open()))
		{
			cout << "File is not open!" << endl;
		}
		p << g_id << "~" << noofposts << endl;
		noofposts++;
		p.close();
		ifstream p11(g_id + "_post.txt");
		for (int i = 0; i < noofposts; i++)
		{
			getline(p11, check);
			listofposts[i] = check;
		}
		p11.close();

		ofstream w(check + ".txt");
		if (!(w.is_open()))
		{
			cout << "File is not open!" << endl;
		}
		ifstream p2(g_id + ".txt");
		while (check != "first name")
		{
			getline(p2, check);
		}
		getline(p2, check);
		w << check << " ";
		while (check != "last name")
		{
			getline(p2, check);
		}
		getline(p2, check);
		p2.close();
		w << check << " says: ";
		cout << "Enter description of your post: " << endl;
		cin.ignore();
		getline(cin, check);
		w << "\"" << check << "\"" << endl;
		w.close();
	}
	else
	{
		cout << "You can not add more posts, limit is of 10." << endl;
	}
}

void post::show()  // timeline.
{
	int yes_no = 0;
	for (int i = 0; i < 11; i++)
	{
		file_data[i] = "-1";
	}
	system("cls");
	cout << "USER ID: " << g_id;
	cout.width(76);
	cout << "R3X" << endl << endl;
	string check;

	cout << "User Name: ";
	ifstream p12(g_id + ".txt");
	while (!(p12.eof()))
	{
		getline(p12, check);
		if (!(p12.eof()))
		{
			if (check == "first name")
			{
				getline(p12, check);
				cout << check << " ";
			}
			if (check == "last name")
			{
				getline(p12, check);
				cout << check << ". " << endl;
			}
		}
	}

	ifstream p1(g_id + "_post.txt");
	if (p1.is_open())
	{
		while (!(p1.eof()))
		{
			getline(p1, check);
			if (!(p1.eof()))
			{
				listofposts[noofposts] = check;
				noofposts++;
			}
		}
		p1.close();
		for (int i = 0; i < noofposts; i++)
		{
			ifstream w(listofposts[i] + ".txt");
			if (w.is_open())
			{
				cout << "Post id: " << listofposts[i] << endl;
				while (!(w.eof()))
				{
					getline(w, check);
					if (!(w.eof()))
					{
						cout << check << endl;
					}
				}
				w.close();
			}
			cout << endl;
		}
		char select = '\0';
		cout << "IF you want to delete any comment enter 'y' or 'Y', any other character will be consider no:" << endl;
		cin >> select;
		int i = 0;
		if (select == 'y' || select == 'Y')
		{
			cin.ignore();
			cout << "Enter id of post to delete its comment: ", getline(cin, id);
			ifstream op(g_id + "_post.txt");
			if (op.is_open())
			{
				while (!(op.eof()))
				{
					getline(op, check);
					if (check == id)
					{
						yes_no = -1;
						ifstream op1(id + ".txt");
						while (!(op1.eof()))
						{
							getline(op1, check);
							if (!(op1.eof()))
							{
								file_data[i] = check;
								i++;
							}
						}
						op1.close();
					}
				}
			}
			if (yes_no == -1)
			{
				op.close();
				int a;
				cout << "Enter number of comment you want to delete: "; cin >> a;
				// exception handling lalgani hai idhar.
				if (a == 0 || a > i)
				{
					throw 5;
				}
				file_data[a] = "-1";
				ofstream s(id + ".txt");
				if (s.is_open())
				{
					for (int j = 0; j < i; j++)
					{
						if (file_data[j] != "-1")
						{
							s << file_data[j] << endl;
						}
					}
					s.close();
				}
			}
			else
			{
				cout << "There is no post with this id." << endl;
			}
		}
	}

	else
	{
		cout << "There is no post added yet." << endl;
	}
}

void post::show1()
{
	string check = "\0";
	string input = "\0";
	int yes_no = 0;
	cout << "Enter id of post, you want to see: " << endl;
	cin.ignore();
	getline(cin, input);
	ifstream sab("user_id.txt");
	if (sab.is_open())
	{
		for (int i = 0; i < g_count; i++)
		{
			getline(sab, users[i]);
		}
		sab.close();
	}
	for (int i = 0; i < g_count; i++)
	{
		ifstream p1(users[i] + "_post.txt");
		if (p1.is_open())
		{
			while (!(p1.eof()))
			{
				getline(p1, check);
				if (!(p1.eof()))
				{
					if (check == input)
					{
						yes_no = -1;
						ifstream p2(input + ".txt");
						while (!(p2.eof()))
						{
							getline(p2, check);
							if (!(p1.eof()))
							{
								cout << check << endl;
							}
						}
						p2.close();
						cout << endl;
					}
				}
			}
		}
		p1.close();
	}
	if (yes_no == 0)
	{
		cout << "There is no post with this id." << endl;
	}
}

void post::muft_salah()
{
	string check = "\0", input = "\0";
	int yes_no = 0;
	int noofcomments = 0;
	cout << "Enter id of post on which you want to add comment: " << endl;
	cin.ignore();
	getline(cin, input);

	ifstream sab("user_id.txt");
	if (sab.is_open())
	{
		for (int i = 0; i < g_count; i++)
		{
			getline(sab, users[i]);
		}
		sab.close();
	}
	for (int i = 0; i < g_count; i++)
	{
		ifstream p1(users[i] + "_post.txt");
		if (p1.is_open())
		{
			while (!(p1.eof()))
			{
				getline(p1, check);
				if (!(p1.eof()))
				{
					if (check == input)
					{
						ifstream counting(input + ".txt");
						getline(counting, check);
						while (!(counting.eof()))
						{
							getline(counting, check);
							if (!(counting.eof()))
							{
								noofcomments++;
							}
						}
						counting.close();
						if (noofcomments < 10)
						{
							yes_no = -1;
							ofstream p2(input + ".txt", ios::app);
							cout << "Enter your comment: " << endl;
							getline(cin, check);
							ifstream data(g_id + ".txt");
							while (!(data.eof()))
							{
								getline(data, input);
								if (!(data.eof()))
								{
									if (input == "first name")
									{
										getline(data, input);
										p2 << "\t~" << input << " ";
									}
									if (input == "last name")
									{
										getline(data, input);
										p2 << input << " wrote: " << "\"" << check << "\"" << endl;
									}
								}
							}
							data.close();
							p2.close();
							cout << "Your comment has added. " << endl;
						}
						else
						{
							yes_no = -1;
							cout << "You cannot add more comments, limit is of 10." << endl;
						}
					}
				}
			}
		}
		p1.close();
	}
	if (yes_no == 0)
	{
		cout << "There is no post with this id." << endl;
	}
}

void post::like()
{
	string check = "\0", input = "\0";
	int yes_no = 0;
	int nooflikes = 0;
	cout << "Enter id of post, you want to like: " << endl;
	cin.ignore();
	getline(cin, input); 

	ifstream sab("user_id.txt");
	if (sab.is_open())
	{
		for (int i = 0; i < g_count; i++)
		{
			getline(sab, users[i]);
		}
		sab.close();
	}
	for (int i = 0; i < g_count; i++)
	{
		ifstream p1(users[i] + "_post.txt");
		if (p1.is_open())
		{
			while (!(p1.eof()))
			{
				getline(p1, check);
				if (!(p1.eof()))
				{
					if (check == input)
					{
						ifstream counting(input + "_like.txt");
						if (counting.is_open())
						{
							while (!(counting.eof()))
							{
								getline(counting, check);
								if (!(counting.eof()))
								{
									nooflikes++;
								}
							}
							counting.close();
						}
						if (nooflikes < 10)
						{
							yes_no = -1;
							ifstream p21(input + "_like.txt");
							ofstream p2(input + "_like.txt", ios::app);
							for (int i = 0; i < nooflikes; i++)
							{
								getline(p21, check);
								if (g_id == check)
								{
									yes_no = 1;
								}
							}
							if (yes_no != 1)
							{
								p2 << g_id << endl;
								cout << "You have successfully liked the post." << endl;
							}
							else
							{
								cout << "You have already liked this post." << endl;
							}
							p2.close();
							p21.close();
						}
						else
						{
							yes_no = -1;
							cout << "You cannot like this post, limit is of 10." << endl;
						}
					}
				}
			}
		}
		p1.close();
	}
	if (yes_no == 0)
	{
		cout << "There is no post with this id." << endl;
	}
}

void post::like_list()
{
	string check = "\0", input = "\0";
	int yes_no = 0;
	cout << "Enter id of post to see the list of people who liked that post: " << endl;
	cin.ignore();
	getline(cin, input);

	ifstream sab("user_id.txt");
	if (sab.is_open())
	{
		for (int i = 0; i < g_count; i++)
		{
			getline(sab, users[i]);
		}
		sab.close();
	}
	for (int i = 0; i < g_count; i++)
	{
		ifstream p1(users[i] + "_post.txt");
		if (p1.is_open())
		{
			while (!(p1.eof()))
			{
				getline(p1, check);
				if (!(p1.eof()))
				{
					if (check == input)
					{
						yes_no = -1;
						cout << "List of users: " << endl;
						ifstream counting(input + "_like.txt");
						if (counting.is_open())
						{
							while (!(counting.eof()))
							{
								getline(counting, check);
								if (!(counting.eof()))
								{
									ifstream qwerty(check + ".txt");
									while (!(qwerty.eof()))
									{
										getline(qwerty, check);
										if (!(qwerty.eof()))
										{
											if (check == "first name")
											{
												getline(qwerty, check);
												cout << check << " ";
											}
											if (check == "last name")
											{
												getline(qwerty, check);
												cout << check << "." << endl;
											}
										}
									}
									qwerty.close();
								}
							}
							counting.close();
						}
					}
				}
			}
		}
		p1.close();
	}
	if (yes_no == 0)
	{
		cout << "There is no post with this id." << endl;
	}
}

void post::share()
{
	string check = "\0", input = "\0";
	int yes_no = 0;
	int nooflikes = 0;
	cout << "Enter id of post, you want to share: " << endl;
	cin.ignore();
	getline(cin, input);

	ifstream sab("user_id.txt");
	if (sab.is_open())
	{
		for (int i = 0; i < g_count; i++)
		{
			getline(sab, users[i]);
		}
		sab.close();
	}
	for (int i = 0; i < g_count; i++)
	{
		ifstream p1(users[i] + "_post.txt");
		if (p1.is_open())
		{
			while (!(p1.eof()))
			{
				getline(p1, check);
				if (!(p1.eof()))
				{
					if (check == input)
					{
						yes_no = -1;
						ifstream po(input + ".txt");
						ifstream st(g_id + ".txt");
						ofstream sh("share.txt", ios::app);
						if (st.is_open())
						{
							while (!(st.eof()))
							{
								getline(st, check);
								if (!(st.eof()))
								{
									if (check == "first name")
									{
										getline(st, check);
										sh << check << " ";
									}
									if (check == "last name")
									{
										getline(st, check);
										sh << check << " shared post: " << endl;
									}
								}
							}
							st.close();
						}
						sh << "Post id: " << input << endl;
						while (!(po.eof()))
						{
							getline(po, check);
							if (!(po.eof()))
							{
								sh << check << endl;
							}
						}
						sh << endl;
						sh << "-----------------------------------------------------------------" << endl << endl;
						sh.close();
						po.close();
					}
				}
			}
		}
		p1.close();
	}
	if (yes_no == 0)
	{
		cout << "There is no post with this id." << endl;
	}
	cout << "Posts has shared." << endl;
}

void post::home()
{
	ifstream s("share.txt");
	if (s.is_open())
	{
		while (!(s.eof()))
		{
			getline(s, id);
			if (!(s.eof()))
			{
				cout << id << endl;
			}
		}
	}
	s.close();
}

void post::page()
{
	int yes_no = 0;
	cin.ignore();
	string check;
	cout << "Enter the id of page: ", getline(cin, id);
	ifstream p("page.txt");
	while (!(p.eof()))
	{
		if (!(p.eof()))
		{
			getline(p, check);
			if (check == id)
			{
				yes_no = -1;
				system("cls");
				ifstream p1(id + ".txt");
				while (!(p1.eof()))
				{
					getline(p1, check);
					if (!(p1.eof()))
					{
						cout << check << endl;
					}
				}
				p1.close();
			}
		}
	}
	if (yes_no == 0)
	{
		cout << "There is no page with this id." << endl;
	}
	p.close();
}

post::~post() {}

// simple functions implementation
void menu()
{
	ifstream m("menu.txt");
	char c;
	cout.width(26);
	while (!(m.eof()))
	{
		m.get(c);
		if (!(m.eof()))
		{
			cout << c;
			if (c == '\n')
			{
				cout.width(26);
			}
		}
	}
	m.close();
	cout << endl << endl;
}

void select_option()
{
	int select;
	avee* ptr = 0;
	post obj;
	cout << "Select any of the above option: " << endl;
	while (1)   // exception handling
	{
		try
		{
			while (!(cin >> select))
			{
				cin.clear();
				cin.ignore();
				throw 5;
			}
			if (select < 1 || select>12)
			{
				throw "error";
			}
			break;
		}
		catch (int a)
		{
			cout << "Please enter only numbers: " << endl;
		}
		catch (const char* p)
		{
			cout << "Please select from the above options: " << endl;
		}
	}
	switch (select)
	{
	case 1:
	{
		system("cls");
		obj.home();
		break;
	}
	case 2:
	{
		ptr = new Friend();
		ptr->add();
		delete ptr;
		ptr = nullptr;
		break;
	}
	case 3:
	{
		ptr = new Friend();
		ptr->show();
		delete ptr;
		ptr = nullptr;
		break;
	}
	case 4:
	{
		ptr = new post();
		ptr->add();
		delete ptr;
		ptr = nullptr;
		break;
	}
	case 5:
	{
		obj.show1();
		break;
	}
	case 6:
	{
		obj.like();
		break;
	}
	case 7:
	{
		obj.like_list();
		break;
	}
	case 8:
	{
		obj.muft_salah();
		break;
	}
	case 9:
	{
		obj.share();
		break;
	}
	case 10:
	{
			ptr = new post();
		try
		{
			ptr->show();
		}
		catch (int abc)
		{
			cout << "Invalid input." << endl;
		}
		delete ptr;
		ptr = nullptr;
		break;
	}
	case 11:
	{
		obj.page();
		break;
	}
	case 12:
	{
		int sasta = 0;
		cout << "Do you want to continue: " << endl << endl;
		cout << "1.yes.                      2.No." << endl;
		while (1)
		{
			try
			{
				while (!(cin >> sasta))
				{
					cin.clear();
					cin.ignore();
					throw 5;
				}
				if (sasta != 1 && sasta != 2)
				{
					throw "a";
				}
				break;
			}
			catch (int a)
			{
				cout << "Please enter only numbers." << endl;
			}
			catch (const char* p)
			{
				cout << "Please select 1 or 2 only. " << endl;
			}
		}
		if (sasta == 1)
		{
			system("cls");
			OP();
		}
		else if (sasta == 2)
		{
			break;
		}
		break;
	}
	}
}

void OP()
{
	start();
	user a;
	a.ask();
	while (1)
	{
		menu();
		select_option();
		system("pause");
		system("cls");
	}
}