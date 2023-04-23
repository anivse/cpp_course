//int main()
//{
//	int MAX_LENGTH;
//	string filename;
//	cout << "Input length string: ";
//	cin >> MAX_LENGTH;
//	cout << "\nInput filename: ";
//	cin >> filename;
//	ifstream inp(filename);
//	ofstream out("output.txt");
//	if (inp)
//	{
//		string str;
//		vector<string> transfer;
//		vector<string> words;
//		string trans;
//
//		while (getline(inp, str))
//		{
//			vector<string> words;
//
//			istringstream iss(str);
//			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string>>(words));
//			transfer.insert(transfer.end(), words.begin(), words.end());
//			words = transfer;
//			transfer.clear();
//			int strlength = 0;
//			do
//			{
//
//				strlength = 0;
//				for (auto& w : words)
//				{
//					strlength += w.size();
//				}
//				strlength += words.size() - 1;
//				if (strlength > MAX_LENGTH)
//				{
//					if (words[words.size() - 1].size() > MAX_LENGTH)
//					{
//						trans = words[words.size() - 1].substr(MAX_LENGTH);
//						words[words.size() - 1].erase(MAX_LENGTH);
//						vector<string>::iterator it = transfer.begin();
//						transfer.emplace(it, trans);
//					}
//					else
//					{
//						trans = words[words.size() - 1];
//						vector<string>::iterator it = transfer.begin();
//						transfer.emplace(it, trans);
//						words.pop_back();
//					}
//				}
//
//
//			} while (strlength > MAX_LENGTH);
//
//			int numberwhitespace = (MAX_LENGTH - strlength) / 2;
//			for (int i = 0; i < numberwhitespace;i++)
//				out << " ";
//			for (auto& w : words)
//			{
//				out << w;
//				cout << w;
//				out << " ";
//			}
//			for (int i = 0; i < numberwhitespace;i++)
//			{
//				out << " ";
//			}
//			out << "\n";
//
//			while (transfer.size() > 0)
//			{
//				vector<string> words;
//				words = transfer;
//				transfer.clear();
//				int strlength = 0;
//
//				do
//				{
//					strlength = 0;
//					for (auto& w : words)
//					{
//						strlength += w.size();
//					}
//					strlength += words.size() - 1;
//					if (strlength > MAX_LENGTH)
//					{
//						if (words[words.size() - 1].size() > MAX_LENGTH)
//						{
//							trans = words[words.size() - 1].substr(MAX_LENGTH);
//							words[words.size() - 1].erase(MAX_LENGTH);
//							vector<string>::iterator it = transfer.begin();
//							transfer.emplace(it, trans);
//						}
//						else
//						{
//							trans = words[words.size() - 1];
//							vector<string>::iterator it = transfer.begin();
//							transfer.emplace(it, trans);
//							words.pop_back();
//						}
//					}
//
//				} while (strlength > MAX_LENGTH);
//
//				int numberwhitespace = (MAX_LENGTH - strlength) / 2;
//				for (int i = 0; i < numberwhitespace;i++)
//					out << " ";
//				for (auto& w : words)
//				{
//					out << w;
//					cout << w;
//					out << " ";
//				}
//				for (int i = 0; i < numberwhitespace;i++)
//				{
//					out << " ";
//				}
//				out << "\n";
//			}
//		}
//		inp.close();
//		out.close();
//	}
//	return 0;
//}

//while (getline(inp, str))
//{
//	vector<string> words;
//
//	istringstream iss(str);
//	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string>>(words));
//	transfer.insert(transfer.end(), words.begin(), words.end());
//	words = transfer;
//	transfer.clear();
//	int strlength = 0;
//	do
//	{
//
//		strlength = 0;
//		for (auto& w : words)
//		{
//			strlength += w.size();
//		}
//		strlength += words.size() - 1;
//		if (strlength > MAX_LENGTH)
//		{
//			if (words[0].size() > MAX_LENGTH)
//			{
//				trans = words[0].substr(MAX_LENGTH);
//				words[0].erase(MAX_LENGTH);
//				vector<string>::iterator it = transfer.begin();
//				transfer.emplace(it, trans);
//			}
//			else
//			{
//				trans = words[words.size() - 1];
//				vector<string>::iterator it = transfer.begin();
//				transfer.emplace(it, trans);
//				words.pop_back();
//			}
//		}
//
//
//	} while (strlength > MAX_LENGTH);
//
//	int numberwhitespace = (MAX_LENGTH - strlength) / 2;
//	for (int i = 0; i < numberwhitespace;i++)
//		out << " ";
//	for (auto& w : words)
//	{
//		out << w;
//		cout << w;
//		out << " ";
//	}
//	for (int i = 0; i < numberwhitespace;i++)
//	{
//		out << " ";
//	}
//	out << "\n";
//
//}

//while (transfer.size() > 0)
//{
//	vector<string> words;
//	words = transfer;
//	transfer.clear();
//	int strlength = 0;
//
//	do
//	{
//		strlength = 0;
//		for (auto& w : words)
//		{
//			strlength += w.size();
//		}
//		strlength += words.size() - 1;
//		if (strlength > MAX_LENGTH)
//		{
//			if (words[0].size() > MAX_LENGTH)
//			{
//				trans = words[0].substr(MAX_LENGTH);
//				words[0].erase(MAX_LENGTH);
//				vector<string>::iterator it = transfer.begin();
//				transfer.emplace(it, trans);
//			}
//			else
//			{
//				trans = words[words.size() - 1];
//				vector<string>::iterator it = transfer.begin();
//				transfer.emplace(it, trans);
//				words.pop_back();
//			}
//		}
//
//	} while (strlength > MAX_LENGTH);
//
//	int numberwhitespace = (MAX_LENGTH - strlength) / 2;
//	for (int i = 0; i < numberwhitespace;i++)
//		out << " ";
//	for (auto& w : words)
//	{
//		out << w;
//		cout << w;
//		out << " ";
//	}
//	for (int i = 0; i < numberwhitespace;i++)
//	{
//		out << " ";
//	}
//	out << "\n";
//}