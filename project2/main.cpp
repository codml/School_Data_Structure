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
	SelectionTree seltree(&fout);
	LoanBookData *tmp;
	string name;
	int code, num;

	seltree.Setting();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> code;
		tmp = new LoanBookData;
		tmp->setBookData(name, code, "a", 2000);
		seltree.Insert(tmp);
	}
	if (!(seltree.printBookData(000)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(100)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(200)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(300)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(400)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(500)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(600)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(700)))
		cout << "failed" << endl;
	seltree.Delete();
	if (!(seltree.printBookData(000)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(100)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(200)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(300)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(400)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(500)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(600)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(700)))
		cout << "failed" << endl;
	seltree.Delete();
	seltree.Delete();
	if (!(seltree.printBookData(000)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(100)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(200)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(300)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(400)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(500)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(600)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(700)))
		cout << "failed" << endl;
	seltree.Delete();
	seltree.Delete();
	seltree.Delete();
	seltree.Delete();
	seltree.Delete();
	seltree.Delete();
	seltree.Delete();
	if (!(seltree.printBookData(000)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(100)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(200)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(300)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(400)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(500)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(600)))
		cout << "failed" << endl;
	if (!(seltree.printBookData(700)))
		cout << "failed" << endl;
	return 0;
}