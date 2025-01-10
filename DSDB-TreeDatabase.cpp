/*
	Data Structure Semester Project
	Members:
	Nouman Amjad 21i-0853
	Zain Ul Abideen 21i-0747
	Moeez Muslim 21i-0490
*/
#include<iostream>
#include<fstream>
#include<string>
#include<direct.h>
#include<sstream>
#include"Header.h"
#include<cstdio>
#include<Windows.h>
using namespace std;

AVLnode<int>* searchAVL(AVLnode<int>* root, int s)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root;
	}

	if (root->data == s)
	{
		return root;
	}
	else if (root->data > s)
	{
		if (s > root->left->data)
			return root;
		searchAVL(root->left, s);
	}
	else if (root->data < s)
	{
		if (s < root->right->data)
			return root;
		searchAVL(root->right, s);
	}


}

void updateQuery(AVL<int> t)
{
	int ID;
	bool flag = 0;
	system("cls");

	cout << "\n\n\n\n\n\n\t\t\t\t\t\tUpdate Query\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n\t\t\t\t\t      Enter your ID : ";
	cin >> ID;
	ifstream dataFile;
	string s, ss;
	int x = 0;
	AVLnode<int>* n = searchAVL(t.root, ID);

	//while (n == NULL)
	//{
	//	if()
	//}

	cout << "\n\t\t\t\t\t      Search Done \n" << endl; 
		if (n != NULL)
		{

			dataFile.open(n->DataAdd);
			while (getline(dataFile, s))
			{

				ss = "";
				for (int k = 0; s[k] != ','; k++)
				{
					ss += s[k];
				}
				x = stoi(ss);
				if (x == ID)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				string* data = new string[7];
				bool quotesFlag = false;
				string temp = s, input;
				int commaCounter = 0;

				for (int i = 0; i < temp.length(); i++)
				{
					while (temp[i] != '"' && quotesFlag)
					{
						input += temp[i];
						i++;
					}
					if (quotesFlag)
					{
						quotesFlag = false;
						i++;
					}



					if (temp[i] == ',' && commaCounter == 0)
					{
						data[0] = input;
						commaCounter++;
						input = "";
					}
					else if (temp[i] == ',' && commaCounter == 1)
					{
						data[1] = input;
						input = "";
						commaCounter++;
					}
					else if (temp[i] == '"')
						quotesFlag = true;
					else if (temp[i] == ',' && commaCounter == 2)
					{
						data[2] = input;
						input = "";
						commaCounter++;
					}
					else if (temp[i] == ',' && commaCounter == 3)
					{
						data[3] = input;
						input = "";
						commaCounter++;
					}
					else if (temp[i] == ',' && commaCounter == 4)
					{
						data[4] = input;
						commaCounter++;
						input = "";
					}
					else if (temp[i] == ',' && commaCounter == 5)
					{
						data[5] = input;
						commaCounter++;
						input = "";
					}
					else if (i == temp.length() - 1 && commaCounter == 6)
					{
						input += temp[i];
						data[6] = input;
						commaCounter++;
						input = "";
					}
					else
						input += temp[i];
				}

				for (int i = 0; i < 7; i++)
				{
					cout << data[i] << " ";
				}
				cout << endl;
				//cout << n->DataAdd << endl;
				int choice, inputInt; string inputS;
				cout << "\t\t\t\t\t      What do you want to update:\n\t\t\t\t\t      1: Year\n\t\t\t\t\t      2:113 Cause Name\n\t\t\t\t\t      3: Casue Name\n\t\t\t\t\t      4: State\n\t\t\t\t\t      5: Deaths\n\t\t\t\t\t      6: Age-adjusted Death Rate\n\n\t\t\t\t\t      >>";
				cin >> choice;
				switch (choice)
				{
				case 1: {cout << "\t\t\t\t\t      Year >> "; cin >> inputS; data[1] = inputS; }
					  break;
				case 2: {cout << "\t\t\t\t\t      113 Cause Name >> "; cin >> inputS; data[2] = inputS; }
					  break;
				case 3: {cout << "\t\t\t\t\t      Cause Name >> "; cin >> inputS; data[3] = inputS; }
					  break;
				case 4: {cout << "\t\t\t\t\t      State >> "; cin >> inputS; data[4] = inputS; }
					  break;
				case 5: {cout << "\t\t\t\t\t      Deaths >> "; cin >> inputS; data[5] = inputS; }
					  break;
				case 6: {cout << "\t\t\t\t\t      Age-adjusted Death Rate >> "; cin >> inputS; data[6] = inputS; }
					  break;
				default:cout << "\t\t\t\t\t      default\n";
				}

				cout << "\n\t\t\t\t      Original One:\n";
				cout <<"\n\t\t\t\t      "<< s << endl;

				s = "";
				cout << "\n\t\t\t\t      Updated\n";
				for (int i = 0; i < 7; i++)
				{
					s += data[i];
					if (i < 6)
					{
						s += ',';
					}
				}
				//code here ++++++++++++++++++++++++++++++++++
				cout <<"\n\t\t\t\t      " << s << endl;
				string tss = s;
				dataFile.close();
				dataFile.open(n->DataAdd);
				ofstream tempFile("data/temp.txt");

				while (getline(dataFile, s))
				{
					ss = "";
					for (int k = 0; s[k] != ','; k++)
					{
						ss += s[k];
					}
					x = stoi(ss);
					if (x != ID)
					{
						tempFile << s << endl;
					}
					if (x == ID)
					{
						tempFile << tss << endl;
					}
				}
				tempFile.close();
				dataFile.close();
				const char* ch = n->DataAdd.c_str();
				remove(ch);
				rename("data/temp.txt", ch);


			}

		}
		else
		{
			cout << "\t\t\t\t\t      Not Found " << endl;
		}


}

void Range(AVL<int> t)
{
	int ID1,ID2;
	bool flag = 0;
	system("cls");
	cout << "\n\n\n\n\n\n\t\t\t\t\t\Range Query\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n\t\t\t\t\t      Enter your Starting ID : ";
	cin >> ID1;
	cout << "\n\t\t\t\t\t      Enter the Ending ID: ";
	cin >> ID2;
	ifstream dataFile;
	string s, ss;
	int x = 0;
	AVLnode<int>* n1 = searchAVL(t.root, ID1);
	AVLnode<int>* n2 = searchAVL(t.root, ID2);

	cout << "\n\t\t\t\t\t      Search Done " << endl;

	if (n1 != NULL)
	{
		if (n1->DataAdd == n2->DataAdd)
		{
			//cout << n1->data;
			//cout << endl << n1->DataAdd<<endl;
			dataFile.open(n1->DataAdd);

			while (::getline(dataFile, s))
			{
				ss = "";
				for (int k = 0; s[k] != ','; k++)
				{
					ss += s[k];
				}
				x = stoi(ss);
				if (x >= ID1 && x<= ID2)
				{
					cout << s << endl;
				}
			}

		}
		else
		{
			//cout << n1->data;
			//cout << endl << n2->data << endl;
			//cout << n2->DataAdd;
			//cout << endl << n1->DataAdd << endl;
			dataFile.open(n1->DataAdd);

			while (::getline(dataFile, s))
			{
				ss = "";
				for (int k = 0; s[k] != ','; k++)
				{
					ss += s[k];
				}
				x = stoi(ss);
				if (x >= ID1 && x<=ID2 )
				{
					cout << "\n\t\t\t\t " << s << endl;

					if (x+1 == n2->data)
					{
						dataFile.close();
						dataFile.open(n2->DataAdd);
					}
				}
			}
		}

	}
	else
	{
		cout << "\n\t\t\t\t\t      Not Found " << endl;
	}
}

void remove(AVL<int> t)
{
	int ID;
	bool flag = 0;
	system("cls");

	cout << "\n\n\n\n\n\n\t\t\t\t\t\tDelete Query\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n\t\t\t\t      Enter the ID you want to delete : ";
	cin >> ID;
	ifstream dataFile;
	string s, ss;
	int x = 0;
	AVLnode<int>* n = searchAVL(t.root, ID);

	cout << "\n\n\t\t\t\t      Search Done " << endl;

	if (n != NULL)
	{
		/*cout << n->data;
		cout << endl << n->DataAdd;*/
		dataFile.open(n->DataAdd);
		ofstream tempFile("data/temp.txt");
		//tempFile.open;
		/*if (tempFile.is_open())
			cout << "temp opened" << endl;*/
		while (getline(dataFile, s))
		{
			ss = "";
			for (int k = 0; s[k] != ','; k++)
			{
				ss += s[k];
			}
			x = stoi(ss);
			if (x != ID)
			{
				tempFile << s<<endl;
			}
			if (x == ID)
			{
				flag = 1;
				cout << "\n\n\t\t\t\t      Found " << endl << endl;
			}
		}
		tempFile.close();
		dataFile.close();
		const char* ch = n->DataAdd.c_str();
		remove(ch);
		rename("data/temp.txt", ch);

	}
	else
	{
		cout << "\n\t\t\t\t      Not Found " << endl;
	}
}

AVL<int>* loadAVL(int n)
{
	//if (n == 1)
	//{
	//	//red black 
	//}
	//else if (n == 2)
	//{
	//	//b tree 
	//}
	//else if (n == 3)
	//{
	//	//Avl 
	//}

	cout << "\n\n";
	AVL<int> AVLtree;

	string fileindex = "RBInID/Node", indexFilename,c;
	stringstream ss;
	ss << 1;
	c = ss.str();
	indexFilename = fileindex + c + ".txt";

	ifstream datafile;

	datafile.open(indexFilename);
	//if (datafile.is_open())
	//cout << "Data file opened\n";

	getline(datafile, c);
	//cout << c << endl;
	int startIndex=0,order=0;
	startIndex = stoi(c);
	int st = startIndex;
	

	getline(datafile, c); 
	startIndex = stoi(c);
	startIndex++;
	//cout << c << endl;
	getline(datafile, c); 

	AVLtree.root = AVLtree.insertNode(AVLtree.root,st, c);

	//cout << c<<endl;
	getline(datafile, c);
	getline(datafile, c);
	//cout << c << endl;
	int count = stoi(c);
	//count--;
	//rbtree.insert(startIndex);
	string temp1="";
	for (int i = 2; i < count; i++)
	{
		datafile.close();
		stringstream ss;
		ss << startIndex;
		c = ss.str();
		indexFilename = fileindex + c + ".txt";
		//cout << indexFilename << endl;
		datafile.open(indexFilename);
		//if (!datafile.is_open())
			//cout << "Data file opened\n";

		getline(datafile, temp1);
		st= stoi(temp1);


		//cout << st << endl;
		getline(datafile, temp1);

		startIndex = stoi(temp1);
		startIndex++;
		getline(datafile, temp1);

		AVLtree.root = AVLtree.insertNode(AVLtree.root, st, temp1);

	}

	//AVLtree.levelorder();

	//t->Display();
	
	return &AVLtree;
}

void selectQueryAVL(AVL<int> t)
{
	int ID;
	bool flag = 0;
	system("cls");

	cout << "\n\n\n\n\n\n\t\t\t\t\t\tSelect Query\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n\t\t\t\t\t      Enter your ID : ";
	cin >> ID;
	ifstream dataFile;
	string s,ss;
	int x = 0;
	AVLnode<int>* n = searchAVL(t.root, ID);

	//while (n == NULL)
	//{
	//	if()
	//}

	cout << "\n\n\t\t\t\t\t      Search Done " << endl;
	if (n != NULL)
	{
		/*cout << n->data;
		cout <<endl<< n->DataAdd;*/
		dataFile.open(n->DataAdd);
		while (:: getline(dataFile, s))
		{
			ss = "";
			for (int k = 0; s[k] != ','; k++)
			{
				ss += s[k];
			}
			x = stoi(ss);
			if (x == ID)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << "\n\n\t\t\t\t\t      Found " << endl;
			cout <<"\n\t\t\t\t      "<< s << endl;
		}

	}
	else
	{
		cout << "\n\t\t\t\t\t      Not Found " << endl;
	}


}

void createindexing()
{
	if (_mkdir("data") != 0);
	if (_mkdir("RBInID") != 0);

	int order;
	cout << "\n\t\t\t\t\tOrder of files : ";
	cin >> order;


	string fileName,c,temp;
	stringstream ssc;
	ssc << 1;
	c = ssc.str();
	fileName = c + ".csv";

	ifstream file[10];

	for (int i = 0; i < 10; i++)
	{
		file[i].open(fileName);
		::getline(file[i], temp);
		stringstream ssc;
		ssc << i + 2;
		c = ssc.str();
		fileName = c + ".csv";
		//if (file[i].is_open())
			//cout << i + 1 << " opened"<<endl;
	}

	bool flag = 0;
	string fileindex = "RBInID/Node", indexFilename;

	ofstream IndexFile;

	string file1 = "data/file",nodeFileName;
	int count = 1;

	stringstream ss;
	ss << count;
	c = ss.str();
	nodeFileName = file1 + c + ".txt";


	ofstream datafile;
	datafile.open(nodeFileName);

	//if (!datafile.is_open())
		//cout << " Not opened " << endl;
	int x = 0, y = 0;
	int countFile = 0;
	int numID = 0;
	string numid1 = "";
	while (!file[9].eof())
	{
		for (int i = 0; i < order; i++)
		{
			
			::getline(file[countFile], temp);
			//cout << y << endl;
			datafile << temp;

			if (i == 0 || i+1 == order)
			{
				numid1 = "";
				for (int k = 0; temp[k] != ','; k++)
				{
					numid1 += temp[k];
				}
				numID = stoi(numid1);
				if (i == 0)
				{
					x = numID;
					//cout << x<<endl;
				}
				if (i + 1 == order)
				{
					y = numID;
					//cout << y << endl;
				}
			}

			if (file[countFile].eof())
			{
				countFile++;
				if (countFile >= 10)
				{
					break;
					flag = 1;
				}
				
			}
			else
				datafile << endl;
		}

		if (!flag)
		{
			//cout << countFile << endl;
			datafile.close();

			stringstream ns;
			ns << x;
			c = ns.str();
			indexFilename = fileindex + c + ".txt";
			IndexFile.open(indexFilename);
			IndexFile << x << endl;
			//y = x + order-1;
			IndexFile << y << endl;
			nodeFileName = "./" + nodeFileName;
			IndexFile << nodeFileName << endl;
			IndexFile.close();

			count++;
			stringstream ss;
			ss << count;
			c = ss.str();
			nodeFileName = file1 + c + ".txt";
			datafile.open(nodeFileName);
		}

	}
	cout << "start 1"<<endl;
	stringstream nns;
	nns << 1;
	c = nns.str();
	indexFilename = fileindex + c + ".txt";
	IndexFile.open(indexFilename,ios::app);
	IndexFile << count;
	IndexFile.close();

	cout << "start 1" << endl;
}

bool write()
{
	createindexing();
	Sleep(2000);
	return true;
}

bool read()
{
	Sleep(2000);
	return true;
}


void splitEntityData(string* data, string temp)
{

	bool quotesFlag = false;
	string input;
	int commaCounter = 0;


	for (int i = 0; i < temp.length(); i++)
	{
		while (temp[i] != '"' && quotesFlag)
		{
			input += temp[i];
			i++;
		}
		if (quotesFlag)
		{
			quotesFlag = false;
			i++;
		}


		if (temp[i] == ',' && commaCounter == 0)
		{
			data[0] = input;
			commaCounter++;
			input = "";
		}
		else if (temp[i] == ',' && commaCounter == 1)
		{
			data[1] = input;
			input = "";
			commaCounter++;
		}
		else if (temp[i] == '"')
			quotesFlag = true;
		else if (temp[i] == ',' && commaCounter == 2)
		{
			data[2] = input;
			input = "";
			commaCounter++;
		}
		else if (temp[i] == ',' && commaCounter == 3)
		{
			data[3] = input;
			input = "";
			commaCounter++;
		}
		else if (temp[i] == ',' && commaCounter == 4)
		{
			data[4] = input;
			commaCounter++;
			input = "";
		}
		else if (temp[i] == ',' && commaCounter == 5)
		{
			data[5] = input;
			commaCounter++;
			input = "";
		}
		else if (i == temp.length() - 1 && commaCounter == 6)
		{
			input += temp[i];
			data[6] = input;
			commaCounter++;
			input = "";
		}
		else
			input += temp[i];
	}
}

void whereClause(AVL<int> t)
{
	int ID1, ID2;
	bool flag = 0;
	system("cls");

	cout << "\n\n\n\n\n\n\t\t\t\t\t\tWhere Query\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n\t\t\t\t\t      Enter the Starting ID : ";
	cin >> ID1;
	cout << "\n\t\t\t\t\t      Enter the Ending ID : ";
	cin >> ID2;
	ifstream dataFile;
	string s, ss;
	int x = 0;
	AVLnode<int>* n1 = searchAVL(t.root, ID1);
	AVLnode<int>* n2 = searchAVL(t.root, ID2);

	cout << "\n\n\t\t\t\t\t      Search Done " << endl;

	if (n1 != NULL)
	{
		int choice; string inputS;
		cout << "\n\t\t\t\t\t      What do you want to choose: \n\t\t\t\t\t      1: Year\n\t\t\t\t\t      2:113 Cause Name\n\t\t\t\t\t      3: Casue Name\n\t\t\t\t\t      4: State\n\t\t\t\t\t      5: Deaths\n\t\t\t\t\t      6: Age-adjusted Death Rate\n\n\t\t\t\t\t      >> ";
		cin >> choice;
		switch (choice)
		{
		case 1: {cout << "\n\t\t\t\t\t      Year >> "; cin >> inputS; }
			  break;
		case 2: {cout << "\n\t\t\t\t\t      113 Cause Name >> "; cin >> inputS; }
			  break;
		case 3: {cout << "\n\t\t\t\t\t      Cause Name >> "; cin >> inputS; }
			  break;
		case 4: {cout << "\n\t\t\t\t\t      State >> "; cin >> inputS; }
			  break;
		case 5: {cout << "\n\t\t\t\t\t      Deaths >> "; cin >> inputS; }
			  break;
		case 6: {cout << "\n\t\t\t\t\t      Age-adjusted Death Rate >> "; cin >> inputS; }
			  break;
		default:cout << "\n\t\t\t\t\t      default\n";
		}


		if (n1->DataAdd == n2->DataAdd)
		{/*
			cout << n1->data;
			cout << endl << n1->DataAdd << endl;*/
			dataFile.open(n1->DataAdd);

			cout << "\n\t\t\t\t\t      ==>" << inputS;
			while (::getline(dataFile, s))
			{
				ss = "";
				for (int k = 0; s[k] != ','; k++)
				{
					ss += s[k];
				}
				x = stoi(ss);
				if (x >= ID1 && x <= ID2)
				{
					string* data = new string[7];

					splitEntityData(data, s);
					switch (choice)
					{
					case 1: {
						if (data[1] == inputS)
						{
							cout <<"\n\t\t\t\t\t      "<< s << endl;
						}
					}
						  break;
					case 2: {
						if (data[2] == inputS)
						{
							cout <<"\n\t\t\t\t\t      "<< s << endl;
						}
					}
						  break;
					case 3: {
						if (data[3] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 4: {
						if (data[4] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 5: {
						if (data[5] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 6: {
						if (data[6] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					default:cout << "\n\t\t\t\t\t      " << "default\n";
					}

				}
			}

		}
		else
		{/*
			cout << n1->data;
			cout << endl << n2->data << endl;
			cout << n2->DataAdd;
			cout << endl << n1->DataAdd << endl;*/
			dataFile.open(n1->DataAdd);

			while (::getline(dataFile, s))
			{
				ss = "";
				for (int k = 0; s[k] != ','; k++)
				{
					ss += s[k];
				}
				x = stoi(ss);
				if (x >= ID1 && x <= ID2)
				{
					string* data = new string[7];

					splitEntityData(data, s);
					switch (choice)
					{
					case 1: {
						if (data[1] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 2: {
						if (data[2] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 3: {
						if (data[3] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 4: {
						if (data[4] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 5: {
						if (data[5] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					case 6: {
						if (data[6] == inputS)
						{
							cout << "\n\t\t\t\t\t      " << s << endl;
						}
					}
						  break;
					default:cout << "\n\t\t\t\t\t      " << "default\n";
					}

					if (x + 1 == n2->data)
					{
						dataFile.close();
						dataFile.open(n2->DataAdd);
					}
				}
			}
		}

	}
	else
	{
		cout << "\n\t\t\t\t\t      " << "Not Found " << endl;
	}

}

int main()
{
	
	
		int treeType, ReadOrWrite, query;
		int bTreeways;
		AVL<int>* AVLtree;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------\n";
		cout << "\t\t\t\t\t| DATA BASE MANAGEMENT SYSTEM |\n";
		cout << "\t\t\t\t\t-------------------------------\n";
		cout << "\n\n\t\t\t\t\t\tPLEASE WAIT...\n";
		Sleep(2000);
		system("cls");

		// --------------------- NEXT PAGE ---------------------------------

	
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE SELECT YOUR TREE\n";
		cout << "\t\t\t\t\t\t-----------------------\n\n";
		cout << "\t\t\t\t\t\t   1. RED BLACK TREE\n";
		cout << "\t\t\t\t\t\t   2. B TREE\n";
		cout << "\t\t\t\t\t\t   3. AVL TREE\n\n";
		cout << "\t\t\t\t\t\t-----------------------\n\n";
		cout << "\t\t\t\t\t\t   Enter choice: ";
		cin >> treeType;
		while (treeType < 1 || treeType > 3)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE SELECT YOUR TREE\n";
			cout << "\t\t\t\t\t\t-----------------------\n\n";
			cout << "\t\t\t\t\t\t   1. RED BLACK TREE\n";
			cout << "\t\t\t\t\t\t   2. B TREE\n";
			cout << "\t\t\t\t\t\t   3. AVL TREE\n\n";
			cout << "\t\t\t\t\t\t-----------------------\n\n";
			cout << "\t\t\t\t\t\t   Invalid choice\n";
			cout << "\t\t\t\t\t\t   Enter again: ";
			cin >> treeType;
		}
		system("cls");

		if (treeType == 1)
		{
			cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t   1. Write data in tree\n";
			cout << "\t\t\t\t\t   2. Load data in tree\n\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t      Enter choice: ";
			cin >> ReadOrWrite;

			while (ReadOrWrite < 1 || ReadOrWrite > 2)
			{
				system("cls");

				cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t   1. Write data in tree\n";
				cout << "\t\t\t\t\t   2. Load data in tree\n\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t      Invalid choice\n";
				cout << "\t\t\t\t\t      Enter again:  ";
				cin >> ReadOrWrite;
			}
		}
		else if (treeType == 2)
		{
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t   Enter B-Tree M ways: ";
			cin >> bTreeways;

			system("cls");

			cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t   1. Write data in tree\n";
			cout << "\t\t\t\t\t   2. Load data in tree\n\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t      Enter choice: ";
			cin >> ReadOrWrite;

			while (ReadOrWrite < 1 || ReadOrWrite > 2)
			{
				system("cls");

				cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t   1. Write data in tree\n";
				cout << "\t\t\t\t\t   2. Load data in tree\n\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t      Invalid choice\n";
				cout << "\t\t\t\t\t      Enter again:  ";
				cin >> ReadOrWrite;
			}
		}
		else if (treeType == 3)
		{
			
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t   1. Write data in tree\n";
			cout << "\t\t\t\t\t   2. Load data in tree\n\n";
			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t      Enter choice: ";
			cin >> ReadOrWrite;

			while (ReadOrWrite < 1 || ReadOrWrite > 2)
			{
				system("cls");

				cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t   1. Write data in tree\n";
				cout << "\t\t\t\t\t   2. Load data in tree\n\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t      Invalid choice\n";
				cout << "\t\t\t\t\t      Enter again:  ";
				cin >> ReadOrWrite;
			}
		}

		// -------------------------- QUERY PAGE --------------------------------

		if (ReadOrWrite == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease wait while tree is loading...\n";
			write();
			system("cls");

			if (treeType == 1)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}
			else if (treeType == 2)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}
			else if (treeType == 3)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}

			cout << "\t\t\t\t\t      1. Select Query\n";
			cout << "\t\t\t\t\t      2. Range Query\n";
			cout << "\t\t\t\t\t      3. Update Query\n";
			cout << "\t\t\t\t\t      4. Delete Query\n";
			cout << "\t\t\t\t\t      5. Where Query\n";
			cout << "\t\t\t\t\t      6. Exit\n\n";

			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t      Enter choice: ";
			cin >> query;

			while (query < 1 || query > 6)
			{
				system("cls");

				if (treeType == 1)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}
				else if (treeType == 2)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}
				else if (treeType == 3)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}

				cout << "\t\t\t\t\t      1. Select Query\n";
				cout << "\t\t\t\t\t      2. Range Query\n";
				cout << "\t\t\t\t\t      3. Update Query\n";
				cout << "\t\t\t\t\t      4. Delete Query\n";
				cout << "\t\t\t\t\t      5. Where Query\n";
				cout << "\t\t\t\t\t      6. Exit\n\n";

				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t      Invalid Choice\n";
				cout << "\t\t\t\t\t      Enter again: ";
				cin >> query;
			}
			AVLtree = loadAVL(1);
			if (query == 1)
			{
				selectQueryAVL(*AVLtree);
			}
			else if (query == 2)
			{
				Range(*AVLtree);
			}
			else if (query == 3)
			{
				updateQuery(*AVLtree);
			}
			else if (query == 4)
			{
				remove(*AVLtree);
			}
			else if (query == 5)
			{
				whereClause(*AVLtree);
			}
		}
		else if (ReadOrWrite == 2)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease wait while tree is loading...\n";
			AVLtree = loadAVL(1); 
			system("cls");

			if (treeType == 1)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}
			else if (treeType == 2)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}
			else if (treeType == 3)
			{
				cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
			}

			cout << "\t\t\t\t\t      1. Select Query\n";
			cout << "\t\t\t\t\t      2. Range Query\n";
			cout << "\t\t\t\t\t      3. Update Query\n";
			cout << "\t\t\t\t\t      4. Delete Query\n";
			cout << "\t\t\t\t\t      5. Where Query\n";
			cout << "\t\t\t\t\t      6. Exit\n\n";

			cout << "\t\t\t\t\t   ----------------------\n\n";
			cout << "\t\t\t\t\t      Enter choice: ";
			cin >> query;

			while (query < 1 || query > 6)
			{
				system("cls");

				if (treeType == 1)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\tRED BLACK TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}
				else if (treeType == 2)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\t   B TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}
				else if (treeType == 3)
				{
					cout << "\n\n\n\n\n\n\t\t\t\t\t\t  AVL TREE\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
				}

				cout << "\t\t\t\t\t      1. Select Query\n";
				cout << "\t\t\t\t\t      2. Range Query\n";
				cout << "\t\t\t\t\t      3. Update Query\n";
				cout << "\t\t\t\t\t      4. Delete Query\n";
				cout << "\t\t\t\t\t      5. Where Query\n";
				cout << "\t\t\t\t\t      6. Exit\n\n";

				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\t\t\t\t\t      Invalid Choice\n";
				cout << "\t\t\t\t\t      Enter again: ";
				cin >> query;
			}

			if (query == 1)
			{
				selectQueryAVL(*AVLtree);
			}
			else if (query == 2)
			{
				Range(*AVLtree);
			}
			else if (query == 3)
			{
				updateQuery(*AVLtree);
			}
			else if (query == 4)
			{
				remove(*AVLtree);
			}
			else if (query == 5)
			{
				whereClause(*AVLtree);
			}
		}
	
}

