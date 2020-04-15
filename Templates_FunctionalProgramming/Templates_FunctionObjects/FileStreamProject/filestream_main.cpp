#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <set>
#include <memory>
using namespace std;

void fun()
{
	ifstream file_input("input.txt", ios::in);  // reading
	if (file_input.is_open())
		cout << "File is opened" << endl;
	else
		cout << "File couldn't be opened " << endl;
}

void fun1()
{
	ofstream file_output("input.txt", ios::app);  // writing to a file
	if (!file_output)
		cout << "File couldn't be opened " << endl;
	else
		cout << "File is opened" << endl;
	file_output << "last lien in the file appeneded " << endl;
	file_output << "very last line in this file" << endl;
	//file_output.close();
}

void GetAllObjects(string &line, set<string> &objects)
{
	cout << line << endl;
	int pos, colonPos;
	if ((pos = line.find(' ')) != string::npos)
	{
		colonPos = line.find(':');
		printf("ColonPosition is: %d\n", colonPos);
		//int noOfCharsToRead = colonPos - pos;  // from pos + 1 location
		string objectName;
		for (int i = pos + 1; i < colonPos; ++i)
			objectName += line[i];
		cout << "ObjectName: " << objectName << endl;
		objects.insert(objectName);
	}
}

void GetObjectsIds()
{

}
int main()
{
	ifstream file_input("input.txt", ios::in);  // reading
	string line;
	if (file_input.is_open())
		cout << "File is opened" << endl;
	else
		cout << "File couldn't be opened " << endl;
	set<string> objects;  // we are using sets to store distinct object names beacuse searching is fast in set.
	set<string> objectIds;
	while (getline(file_input, line)) {
		GetAllObjects(line, objects);
		int colonPos, equalPos, slashPos;
		int commaPos = line.find(',');
		colonPos = line.find(':');
		if (((equalPos = line.find('=', colonPos + 1)) != string::npos) && (equalPos < commaPos))
		{
			string objectIdName;
			colonPos = line.find(':', equalPos + 1);
			cout << "colonPos " << colonPos << endl;
			//cout << "equalPos " << equalPos << endl;
			for (int i = equalPos + 1; i < colonPos; ++i)
				objectIdName += line[i];
			cout << "ObjectId: " << objectIdName << endl;
			objectIds.insert(objectIdName);
		}
		while (((slashPos = line.find('/', colonPos + 1)) != string::npos) && (slashPos < commaPos))
		{
			string objectIdName;
			colonPos = line.find(':', slashPos + 1);
			cout << "colonPos " << colonPos << endl;
			//cout << "equalPos " << equalPos << endl;
			for (int i = slashPos + 1; i < colonPos; ++i)
				objectIdName += line[i];
			cout << "ObjectId: " << objectIdName << endl;
			objectIds.insert(objectIdName);
		}

	} // end of while
	
	ofstream *out = new ofstream[objects.size()];
	auto itr = objects.begin();
	for (int i = 0; i < objects.size(); ++i,++itr)
	{
		out[i].open((*itr + ".txt").c_str(), ios::out);
	}
	itr = objects.begin();
	for (int i = 0; i < objects.size(); ++i, ++itr)
	{
		out[i].close();
	}
	delete[] out;
	system("pause");
	return 0;
}