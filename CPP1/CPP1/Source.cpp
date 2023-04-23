
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <vector>
 
using namespace std;



int main()
{
	int MAX_LENGTH;
	string filename;
	cout << "Input length string: ";
	cin >> MAX_LENGTH;
	cout << "\nInput filename: ";
	cin >> filename;
	ifstream inp(filename);
	ofstream out("output.txt");
	if (inp)
	{
		string str;
		vector<string> words;
		string trans;
		int strlength = 0;

		while (getline(inp, str))
		{
			vector<string> words;

			istringstream iss(str);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string>>(words));
			int strlen = 0;
			int k = 0;
			for (auto& w : words)
			{
				strlen += w.size() + 1;
				if (strlen > MAX_LENGTH)
				{
					strlen -= w.size();
					break;
				}
			}
			strlen -= 1;
			int len = 0;
			int numberspace = (MAX_LENGTH - strlen) / 2;
			for (int i = 0; i < numberspace;i++)
			{
				out << " ";
				cout << " ";
			}
			k = 0;
			for (auto& w : words)
			{
				strlength += w.size() + 1;
				if (strlength > MAX_LENGTH)
				{
					out << "\n";
					cout << "\n";
					if (w.size() <= MAX_LENGTH)
					{
						len = 0;
						for (int q = k;q < words.size();q++)
						{
							len += words[q].size();
							if (len > MAX_LENGTH)
							{
								len -= words[q].size();
								break;
							}
						}
						numberspace = (MAX_LENGTH - len) / 2;
						for (int j = 0; j < numberspace;j++)
						{
							out << " ";
							cout << " ";
						}
					}
				
					strlength = w.size() + 1;
				}
				if (w.size() > MAX_LENGTH)
				{
					strlength = 0;
					for (int i = 0; i < w.size(); i++)
					{
						cout << w[i];
						out << w[i];
						if (strlength == MAX_LENGTH - 1)
						{
							cout << "\n";
							out << "\n";
							if (w.size() - i < MAX_LENGTH)
							{
								numberspace = (MAX_LENGTH - w.size()+i) / 2;
								for (int j = 0; j < numberspace;j++)
								{
									out << " ";
									cout << " ";
								}
							}
							strlength = 0;
						}
						strlength++;
					}
				}
				else
				{
					out << w;
					cout << w;
					out << " ";
					cout << " ";
					k++;
				}
			}
			cout << "\n";
			out << "\n";
			strlength = 0;
		}
		inp.close();
		out.close();
	}
	return 0;
}


