#include "Manager.h"

using namespace std;

// int main() {
// 	Manager manager(3); //value is order of bptree 
// 	manager.run("command.txt");
// 	return 0;
// }

int main()
{
	ofstream fout;
	fout.open("result.txt");
	BpTree btree(&fout);
	string name, author;
	int code, year, num;

	cout << "test num: ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> code >> author >> year;
		LoanBookData *tmp = new LoanBookData;
		tmp->setBookData(name, code, author, year);
		btree.Insert(tmp);
	}
	do
	{
		cout << "search name: ";
		cin >> name;
	} while (btree.searchBook(name));
	cout << "search range(insert two people's name): ";
	cin >> name >> author;
	btree.searchRange(name, author);
	return 0;
}

// int main()
// {
// 	ofstream fout;
// 	SelectionTree st(&fout);
// 	LoanBookData *tmp;
// 	string name;
// 	int code, num;

// 	cout << "test num: ";
// 	cin >> num;

// 	for (int i = 0; i < num; i++)
// 	{
// 		cin >> name >> code;
// 		tmp = new LoanBookData;
// 		tmp->setBookData(name, code, "taewanki", 2000);
// 		st.Insert(tmp);
// 	}
// 	if (!st.printBookData(0))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(100))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(200))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(300))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(400))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(500))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(600))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(700))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	st.Delete();
// 	if (!st.printBookData(0))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(100))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(200))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(300))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(400))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(500))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(600))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(700))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	st.Delete();
// 	st.Delete();
// 	if (!st.printBookData(0))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(100))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(200))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(300))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(400))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(500))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(600))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(700))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	st.Delete();
// 	if (!st.printBookData(0))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(100))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(200))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(300))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(400))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(500))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(600))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	if (!st.printBookData(700))
// 		cout << endl << endl << "NONE" << endl << endl;
// 	return 0;
// }