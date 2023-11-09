#include "Manager.h"

using namespace std;

// int main() {
// 	Manager manager(3); //value is order of bptree 
// 	manager.run("command.txt");
// 	return 0;
// }

// int main()
// {
// 	ofstream fout;
// 	BpTree btree(&fout);
// 	string name, author;
// 	int code, year, num;

// 	cout << "test num: ";
// 	cin >> num;
// 	for (int i = 0; i < num; i++)
// 	{
// 		cin >> name >> code >> author >> year;
// 		LoanBookData *tmp = new LoanBookData;
// 		tmp->setBookData(name, code, author, year);
// 		btree.Insert(tmp);
// 	}
// 	do
// 	{
// 		cout << "search name: ";
// 		cin >> name;
// 	} while (btree.searchBook(name));
// 	cout << "search range(insert two people's name): ";
// 	cin >> name >> author;
// 	btree.searchRange(name, author);
// 	return 0;
// }

int main()
{
	ofstream fout;
	SelectionTree st(&fout);
	LoanBookData *tmp;
	string name;
	int code, num;

	cout << "test num: ";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> name >> code;
		tmp = new LoanBookData;
		tmp->setBookData(name, code, "taewanki", 2000);
		st.Insert(tmp);
	}
	st.printBookData(0);
	st.printBookData(100);
	st.printBookData(200);
	st.printBookData(300);
	st.printBookData(400);
	st.printBookData(500);
	st.printBookData(600);
	st.printBookData(700);
	st.Delete();
	st.printBookData(0);
	st.printBookData(100);
	st.printBookData(200);
	st.printBookData(300);
	st.printBookData(400);
	st.printBookData(500);
	st.printBookData(600);
	st.printBookData(700);
	st.Delete();
	st.Delete();
	st.printBookData(0);
	st.printBookData(100);
	st.printBookData(200);
	st.printBookData(300);
	st.printBookData(400);
	st.printBookData(500);
	st.printBookData(600);
	st.printBookData(700);
	st.Delete();
	st.Delete();
	st.Delete();
	st.Delete();
	st.Delete();
	st.Delete();
	st.Delete();
	st.Delete();
	st.printBookData(0);
	st.printBookData(100);
	st.printBookData(200);
	st.printBookData(300);
	st.printBookData(400);
	st.printBookData(500);
	st.printBookData(600);
	st.printBookData(700);
	return 0;
}