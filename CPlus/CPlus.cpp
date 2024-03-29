﻿// CPlus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include<string>
#include<thread>
#include <map>
#include <set>
#include <unordered_map>
#include<math.h>
#include<limits>
#include <unordered_set>
#include "ListNode.cpp"
#include "Review230806.cpp"

using namespace std;
bool FindLast(vector<vector<int>>& maze, vector < vector<bool>>& path, vector<vector<int>>& list, int x, int y, int dir[4][2], int target[2]);
bool Is7(int num);
bool IsPrime(int num);
void Show(vector<vector<int>> nums);
bool judgePoint24DFS(vector<double> list);
vector<double> judgePoint24DFSCalc(double a, double b);
bool CanPartition(vector<int>& nums, int t, int k, vector<int>& bucket);


int main()
{
#pragma region MyRegion

	/*double num;
	vector<double> list;
	while (cin >> num)
	{
		list.push_back(num);
	}
	if (judgePoint24DFS(list))
		cout << "true";
	else
		cout << "false";*/

#pragma endregion

	int n;
	cin >> n;
	vector<int> list;
	vector<int> bucket(2,0);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		sum += tmp;
		if (tmp % 5 == 0)
		{
			bucket[0] -= tmp;
		}
		else if (tmp % 3 == 0)
			bucket[1] -= tmp;
		else
			list.push_back(tmp);
	}
	if (sum % 2 != 0)
	{
		cout << "false";
		return 0;
	}
	int target = sum / 2;
	for (int i = 0; i < 2; ++i)
		bucket[i] += target;
	sort(list.begin(),list.end(),greater<int>());
	bool res=CanPartition(list,0,2,bucket);
	if (res)
		cout << "true";
	else
		cout << "false";
	return 0;
}

bool CanPartition(vector<int>& nums, int t, int k, vector<int>& bucket)
{
	if (t == nums.size())
		return true;
	else
	{
		for (int i = 0; i < k; ++i)
		{
			if (i > 0 && bucket[i - 1] == bucket[i])
				continue;
			if (bucket[i] >= nums[t])
			{
				bucket[i] -= nums[t];
				if (CanPartition(nums, t + 1, k, bucket))
					return true;
				bucket[i] += nums[t];
			}
		}
		return false;
	}

}

bool judgePoint24DFS(vector<double> list)
{
	if (list.size() == 1)
	{
		if (abs(list[0] - 24) < 0.001)
			return true;
	}
	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = i + 1; j < list.size(); ++j)
		{
			for (auto num : judgePoint24DFSCalc(list[i], list[j]))
			{
				vector<double> tmp;
				tmp.push_back(num);
				for (int k = 0; k < list.size(); ++k)
				{
					if (k == i || k == j)
						continue;
					tmp.push_back(list[k]);
				}
				if (judgePoint24DFS(tmp))
					return true;
			}

		}
	}
	return false;
}
vector<double> judgePoint24DFSCalc(double a, double b)
{
	vector<double> list;
	list.push_back(a+b);
	list.push_back(a-b);
	list.push_back(b-a);
	list.push_back(a*b);
	list.push_back(a/b);
	list.push_back(b/a);
	return list;
}


#pragma region main


//int main()
//{
#pragma region MyRegion

	/*int len = 0, wid = 0;
	cin >> len >> wid;
	vector<vector<int>> maze;
	vector < vector<bool>> path;
	int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	for (int i = 0; i < len; ++i)
	{
		vector<int> tmpvec;
		for (int j = 0; j < wid; ++j)
		{
			int tmp = 0;
			cin >> tmp;
			tmpvec.push_back(tmp);
		}
		maze.push_back(tmpvec);
		vector<bool> tmppath;
		tmppath.assign(wid, false);
		path.push_back(tmppath);
	}
	vector<vector<int>> list;
	list.push_back({0,0});
	int target[] = {len-1,wid-1};

	if (FindLast(maze,path,list, 0, 0, dir, target))
	{
		for (auto num : list)
		{
			cout << "(" << num[0] << "," << num[1] << ")"<<endl;
		}
	}*/

#pragma endregion
#pragma region MyRegion

	/*int n = 0;
	cin >> n;
	cin.ignore();
	vector<string> list;
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		list.push_back(str);
	}
	for(auto str:list)
	{

		vector<int> chara(26, 0);
		for (int i = 0; i < str.size(); ++i)
		{
			if (isalpha(str[i]))
			{
				chara[tolower(str[i]) - 'a'] += 1;
			}
		}
		sort(chara.begin(), chara.end(), greater<int>());
		int max = 26;
		int res = 0;
		for (int num : chara)
		{
			if (num == 0)
				break;
			res += num * max;
			max--;
		}
		cout << res<<endl;
	}*/

#pragma endregion
#pragma region MyRegion

	/*string str;
	vector<int> list;
	while (getline(cin, str, ' '))
	{
		list.push_back(stoi(str));
	}
	unordered_map<int, int> map;
	auto ptr = map.find(-1);
	for (int i = 2; i < list.size() - 1; ++i)
	{
		int cur = list[i+1];
		int next = list[i];
		i = i + 1;
		if (map.find(cur) != map.end())
		{
			int num = map[cur];
			map[cur] = next;
			map[next] = num;
		}
		else
		{
			map[cur] = next;
		}
	}
	int n = list.size()-1;
	map[-1] = list[1];
	ptr = map.find(-1);
	while (ptr != map.end())
	{
		if (ptr->second == list[n])
		{
			if (map.find(list[n]) != map.end())
			{
				map[ptr->first] = map[list[n]];
			}
			else
			{
				map.erase(ptr->first);
			}
			break;
		}
		else
		{
			ptr = map.find(ptr->second);
		}
	}
	ptr = map.find(-1);
	while (ptr != map.end())
	{
			cout << ptr->second << " ";
			ptr = map.find(ptr->second);
	}*/

#pragma endregion
#pragma region MyRegion

	/*int count = 0;
	cin >> count;
	ListNode *head=nullptr;
	ListNode *tmpHead = nullptr;
	for (int i = 0; i < count; ++i)
	{
		int tmpNum = 0;
		cin >> tmpNum;
		if (head == nullptr)
		{
			head = new ListNode();
			head->m_nKey = tmpNum;
			tmpHead = head;
		}
		else
		{
			tmpHead->m_pNext = new ListNode();
			tmpHead->m_pNext->m_nKey = tmpNum;
			tmpHead = tmpHead->m_pNext;
		}
	}

	int n = 0;
	tmpHead = head;
	while (tmpHead != nullptr)
	{
		n++;
		tmpHead = tmpHead->m_pNext;
	}
	int k = 0;
	cin >> k;
	int index = n - k + 1;
	n = 0;
	tmpHead = head;
	while (true)
	{
		n++;
		if (n == index)
		{
			cout << tmpHead->m_nKey << endl;
			break;
		}
		tmpHead = tmpHead->m_pNext;
	}*/





	/*
	tmpHead = head;
	while (tmpHead != nullptr)
	{
		cout << tmpHead->m_nKey << endl;
		tmpHead = tmpHead->m_pNext;
	}
	while (head != nullptr)
	{
		tmpHead = head;
		head = head->m_pNext;
		delete tmpHead;
	}*/

#pragma endregion
#pragma region MyRegion

	/*int num = 0;
	cin >> num;
	int res = 0;
	for (int i = 1; i <= num; ++i)
	{
		if (Is7(i))
		{
			res++;
		}
	}
	cout << res;*/

#pragma endregion

#pragma region MyRegion

	/*int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		unordered_set<int> set;
		for (int j = 1; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				set.insert(j);
				set.insert(i/j);
			}
		}
		int value=0;
		for (int num : set)
		{
			if (num != i)
				value += num;
		}
		if (value == i)
			count++;
	}
	cout << count;*/

#pragma endregion
#pragma region MyRegion

	/*string str;
	getline(cin,str);
	vector<int> num;
	num.assign(128,0);
	for (auto s : str)
		num[s] += 1;
	char c;
	bool flag = false;
	for (auto s : str)
	{
		if (num[s] == 1)
		{
			c = s;
			flag = true;
			break;
		}
	}
	if (flag)
		cout << c;
	else
		cout << -1;*/

#pragma endregion
#pragma region MyRegion

		/*int num;
		cin >> num;
		int value=2000;
		int first = 0, sec = 0;
		for (int i = 2; i <= num/2; ++i)
		{
			if (IsPrime(i) && IsPrime(num - i))
			{
				if (num - i - i < value)
				{
					value = num - i - i;
					first = i;
					sec = num - i;
				}
			}
		}
		cout << first<<endl<<sec;*/

#pragma endregion
#pragma region MyRegion

		/*int dp[11][11];
		int a, b;
		cin >> a >> b;
		for (int i = 0; i <= a; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				if (i == 0)
					dp[i][j] = 1;
				else if (j == 1)
					dp[i][j] = 1;
				else if (i < j)
					dp[i][j] = dp[i][i];
				else if (i >= j)
					dp[i][j] = dp[i - j][j] + dp[i][j - 1];
			}
		}
		cout << dp[a][b];*/
#pragma endregion
#pragma region MyRegion

		/*int num = 0;
		while (cin >> num)
		{
			int count = 0;
			while (num)
			{
				count++;
				num = num & (num - 1);
			}
			cout << count << endl;
		}*/

#pragma endregion
#pragma region MyRegion
		/*string str;
		cin >> str;
		int len;
		cin >> len;
		double rate=0;
		int front = 0, back = len-1;
		int l = 0, r = len - 1;
		int count=0;
		for (int i = front; i <= back; ++i)
		{
			if (str[i] == 'G' || str[i] == 'C')
				count++;
		}
		int tmpCount = count;
		while (r < str.size()-1)
		{
			l++;
			r++;
			if (str[l-1] == 'G' || str[l-1] == 'C')
				tmpCount--;
			if (str[r] == 'G' || str[r] == 'C')
				tmpCount++;
			if (tmpCount > count)
			{
				front = l;
				back = r;
				count = tmpCount;
			}
			if (count == len)
				break;
		}

		for (int i = front; i <= back; ++i)
		{
			cout << str[i];
		}*/

#pragma endregion
#pragma region MyRegion

	/*string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size())
		swap(s1,s2);
	int index = 0;
	int max = 0;
	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				index = i - max;
			}
		}
	}
	cout << s1.substr(index,max);*/
#pragma endregion

	

//	return 0;
//}
#pragma region MyRegion

//string getComSubstr(string& str1, string& str2)
//{
//	if (str1.size() > str2.size())
//		swap(str1, str2);      //保证str1是最短的字符串
//	int len1 = str1.size();
//	int len2 = str2.size();
//	vector<vector<int>> MSC(len1 + 1, vector<int>(len2 + 1, 0));
//	int start = 0, max_size = 0;
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (str2[j - 1] == str1[i - 1])
//			{
//				MSC[i][j] = MSC[i - 1][j - 1] + 1;
//			}
//			if (MSC[i][j] > max_size)
//			{
//				max_size = MSC[i][j];
//				start = i - max_size;
//			}
//		}
//	}
//	return str1.substr(start, max_size);
//}
//int main() {
//	string str1, str2;
//	string str;
//	while (cin >> str1 >> str2) { // 注意 while 处理多个 case
//		str = getComSubstr(str1, str2);
//		cout << str << endl;
//	}
//}
#pragma endregion

#pragma endregion

void Show(vector<vector<int>> nums)
{
	for (auto item1 : nums)
	{
		for (auto item2 : item1)
		{
			cout << item2 << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool IsPrime(int num)
{
	bool res = true;
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			res = false;
			break;
		}
	}
	return res;
}
bool Is7(int num)
{
	if (num % 7 == 0)
		return true;
	string str = to_string(num);
	if (str.find("7") != string::npos)
		return true;
	return false;
}

bool FindLast(vector<vector<int>>& maze, vector < vector<bool>>& path, vector<vector<int>>& list, int x, int y, int dir[4][2], int target[2])
{
	if (x == target[0] && y == target[1])
		return true;
	for (int i = 0; i < 4; ++i)
	{
		int tmpX = x + dir[i][0];
		int tmpY = y + dir[i][1];
		if (tmpX<0 || tmpX>target[0] || tmpY<0 || tmpY>target[1])
			continue;
		if (maze[tmpX][tmpY] == 1 || path[tmpX][tmpY])
			continue;
		path[tmpX][tmpY] = true;
		list.push_back({ tmpX,tmpY });
		if (FindLast(maze, path, list, tmpX, tmpY, dir, target))
			return true;
		list.pop_back();
		path[tmpX][tmpY] = false;

	}
	return false;
}






#pragma region MyRegion

#pragma region MyRegion
/*ifstream reader("D:/test.txt");
vector<int> list;
string str;
while (getline(reader, str))
{
	string num;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '-')
		{
			if (num.length() == 1 && num[0] == '-')
				continue;
			if (num.length() > 0)
			{
				list.push_back(stoi(num));
				num.clear();
			}
			num += '-';
		}
		else if (isdigit(str[i]))
		{
			num += str[i];
			if(i==str.length()-1)
				list.push_back(stoi(num));
		}
		else
		{
			if (num.length() == 1 && num[0] == '-' || num.length() == 0)
			{
				num.clear();
			}
			else
			{
				list.push_back(stoi(num));
				num.clear();
			}
		}
	}
}
sort(list.begin(), list.end());
int sum = 0;
string res;
for (int n : list)
{
	sum += n;
	if (n >= 0)
	{
		res += "+";
	}
	res += to_string(n);
}
std::cout << res<<"="<<sum; */
#pragma endregion

#pragma region MyRegion
/*MySqlModel sqlModel;
sqlModel.connect();*/
#pragma endregion

#pragma region vector
//front back
//begin end
//cbegin cend
//crbegin crend
//rbegin rend
//push_back pop_back
//vector<int> ve;
//ve.assign(6,6);
///*for (auto num : ve)
//{
//	cout << num << endl;
//}*/
//vector<int>::iterator beg;
//vector<int>::const_reverse_iterator crbeg;
//for (crbeg = ve.crbegin(); crbeg != ve.crend(); crbeg++)
//{
//	cout << *crbeg << endl;
//}
#pragma endregion

#pragma region 1
/*string s1;
getline(cin, s1);
int res = 0;
for (int i = s1.size() - 1; i >= 0; i--)
{
	if (s1[i] == ' ')
	{
		break;
	}
	else
	{
		res++;
	}

}
cout << res;*/
#pragma endregion

#pragma region 2
/*string str;
getline(cin, str);
char tar, low, up;
cin >> tar;
int res = 0;
low = tolower(tar);
up = toupper(tar);
for (int i = 0; i < str.size(); ++i)
{
	if (str[i] == low || str[i] == up)
		res++;
}
cout << res;*/
#pragma endregion

#pragma region 3
//int nums[501];
	//int count;
	//cin >> count;
	//int num;
	//vector<int> vec;
	//vec.assign(501,0);

	////map<int, int> map1;
	//map<int, int, std::greater<int>> map1;
	//set<int, less<int>> map2;
	//for (int i = 0; i < count; ++i)
	//{
	//	cin >> num;
	//	map2.insert(num);
	//	/*auto ite = map2.find(num);
	//	if (ite == map1.end() && map1[num] == 0)
	//	{
	//		map1[num] = 1;
	//	}*/
	//}
	//for (auto tmp : map2)
	//{
	//	cout << tmp << endl;
	//}
	///*for (int i = 0; i < 501; ++i)
	//{
	//	if (vec[i] != 0)
	//	{
	//		cout << i << endl;
	//	}
	//}*/
#pragma endregion

#pragma region 4
/*string src;
	getline(cin,src);
	int rep = 0;
	string str;
	for (int i = 0; i < src.size(); ++i)
	{

		str.push_back(src[i]);
		rep++;
		if (rep == 8)
		{
			rep = 0;
			cout << str << endl;
			str.clear();
		}
	}
	if (str.size() != 0)
	{
		for (int i = 0; i < 8 - rep; ++i)
		{
			str.push_back('0');
		}
		cout << str;
	}*/
#pragma endregion

#pragma region 5
	/*string str;
		getline(cin,str);
		unordered_map<char, int> unmap;
		unmap['0'] = 0;
		unmap['1'] = 1;
		unmap['2'] = 2;
		unmap['3'] = 3;
		unmap['4'] = 4;
		unmap['5'] = 5;
		unmap['6'] = 6;
		unmap['7'] = 7;
		unmap['8'] = 8;
		unmap['9'] = 9;
		unmap['A'] = 10;
		unmap['B'] = 11;
		unmap['C'] = 12;
		unmap['D'] = 13;
		unmap['E'] = 14;
		unmap['F'] = 15;
		int res = 0;
		int pow1 = 0;
		for (int i = str.size() - 1; i > 1; --i)
		{
			res = unmap[str[i]] * pow(16, pow1++) + res;
		}
		cout << res;*/
#pragma endregion

#pragma region 6
		/*int num = 0;
			cin >> num;
			int target = num;
			string res;
			for (int i = 2; i <= sqrt(num); ++i)
			{
				while (target % i == 0)
				{
					res =res+ to_string( i)+" ";
					target /= i;
				}
			}
			if (target != 1)
				res+= to_string(target);
			cout << res;*/
#pragma endregion

#pragma region 8
			/*map<int, int> tablemap;
				int count;
				cin >> count;
				string inputStr;
				for (int i = 0; i < count; ++i)
				{
					getline(cin,inputStr);
					int a, b;
					cin >> a >> b;
					tablemap[a]+=b;
				}
				for (pair<int, int> tmp : tablemap)
				{
					cout << tmp.first << " " << tmp.second << endl;
				}*/
#pragma endregion

#pragma region 9
				/*set<char> HashSet;
					string num;
					getline(cin,num);

					for (int i = num.size() - 1; i >= 0; --i)
					{
						auto ite = HashSet.find(num[i]);
						if (ite == HashSet.end())
						{
							HashSet.insert(num[i]);
							cout << num[i];
						}
					}*/
#pragma endregion

#pragma region MyRegion
					/*vector<int> numSet;
						numSet.assign(128,0);
						string str;
						getline(cin, str);
						int res = 0;
						for (int i = 0; i < str.size(); ++i)
						{
							if (str[i] >= 0 && str[i] <= 127 && numSet[str[i]] == 0)
							{
								res += 1;
								numSet[str[i]] += 1;
							}
						}
						cout << res;*/
#pragma endregion

#pragma region MyRegion
						/*string str;
							getline(cin,str);
							for (int i = str.size()-1; i >=0; --i)
							{
								cout << str[i];
							}*/
#pragma endregion

#pragma region MyRegion
							/*string str;
								while (getline(cin, str))
								{
									vector<string> list1;
									string tmp;
									for (int i = 0; i < str.size(); ++i)
									{
										if (str[i] == ' ')
										{
											list1.push_back(tmp);
											tmp.clear();
										}
										else
										{
											tmp.push_back(str[i]);
										}
									}
									if (!tmp.empty())
										list1.push_back(tmp);
									for (int i = list1.size() - 1; i >= 0; i--)
									{
										if (i == 0)
										{
											cout << list1[i];
										}
										else
										{
											cout << list1[i] << " ";
										}
									}
								}*/
#pragma endregion

#pragma region MyRegion
								/*int count = 0;
									cin >> count;
									vector<string> list;
									for (int i = 0; i < count; ++i)
									{
										string tmp;
										cin >> tmp;
										list.push_back(tmp);
									}
									sort(list.begin(),list.end());
									for (string s : list)
										cout << s<<endl;*/
#pragma endregion

#pragma region MyRegion
										/*int num;
											cin >> num;
											int res = 0;
											while (num != 0)
											{
												if ((num & 1) == 1)
												{
													res++;
												}
												num >>= 1;
											}
											cout << res;*/
#pragma endregion

#pragma region 16 未完成
											/*int totalMon,count;
												cin >> totalMon >> count;
												vector<int[]> list;
												vector<int> dp;
												vector<int> select;
												dp.assign(totalMon+1,0);
												select.assign(count,0);
												for (int i = 0; i < count; ++i)
												{
													int v, p, q;
													cin >> v >> p >> q;
													list.push_back({v,p,q});
												}

												for (int i = 1; i <= count; ++i)
												{
													if (list[i - 1][2] == 0)
													{
														for (int j = totalMon; j >= list[i - 1][0]; j--)
														{
															if (dp[j] < dp[j - list[i - 1][0]])
															{
																select[i - 1] = 1;
															}
														}
													}
												}*/
#pragma endregion

#pragma region MyRegion
												/*string str;
													int x = 0, y = 0;
													string tmp;
													while (getline(cin, str, ';'))
													{
														if (str.size() >= 2 && str.size() <= 3&&(str[0]=='A'||str[0]=='D'||str[0]=='W'||str[0]=='S'))
														{
															bool res = false;
															int step = 0;
															if (str.size() == 2 && str[1] >= '1' && str[1] <= '9')
															{
																res = true;
																step = str[1] - '0';
															}
															else if (str.size() == 3 && str[1] >= '1' && str[1] <= '9' && str[2] >= '0' && str[2] <= '9')
															{
																res = true;
																step = (str[1] - '0') * 10 + str[2] - '0';
															}
															if (res)
															{
																if (str[0] == 'A')
																{
																	x -= step;
																}
																else if (str[0] == 'D')
																{
																	x += step;
																}
																else if (str[0] == 'W')
																{
																	y += step;
																}
																else if (str[0] == 'S')
																{
																	y -= step;
																}
															}

														}
													}
													cout << x << "," << y;*/
#pragma endregion

#pragma region MyRegion
													/*string pwd;
														while (getline(cin, pwd))
														{
															if (pwd.size() <= 8)
															{
																cout << "NG" << endl;
																continue;
															}
															vector<bool> conditions;
															conditions.assign(4, false);
															int res = 0;
															for (int i = 0; i < pwd.size(); ++i)
															{
																if (pwd[i] >= 'A' && pwd[i] <= 'Z')
																{
																	if (!conditions[0])
																		res += 1;
																	conditions[0] = true;
																}
																else if (pwd[i] >= 'a' && pwd[i] <= 'z')
																{
																	if (!conditions[1])
																		res += 1;
																	conditions[1] = true;
																}
																else if (pwd[i] >= '0' && pwd[i] <= '9')
																{
																	if (!conditions[2])
																		res += 1;
																	conditions[2] = true;
																}
																else if (pwd[i] != ' ' && pwd[i] != '\n')
																{
																	if (!conditions[3])
																		res += 1;
																	conditions[3] = true;
																}
																if (res >= 3)
																	break;
															}
															if (res < 3)
															{
																cout << "NG" << endl;
																continue;
															}
															bool res1 = true;
															for (int i = 0; i < pwd.size() - 3; i++)
															{
																for (int j = i + 1; j < pwd.size() - 2; j++)
																{
																	if (pwd[j] == pwd[i] && pwd[j + 1] == pwd[i + 1] && pwd[i + 2] == pwd[j + 2])
																	{
																		res1 = false;
																		break;
																	}
																}
															}
															if (!res1)
															{
																cout << "NG" << endl;

																continue;
															}
															cout << "OK" << endl;
														}*/
#pragma endregion

#pragma region MyRegion




														/*unordered_map<char, int> unMap;
														unMap['1']=1;
														unMap['a']=2;
														unMap['b']=2;
														unMap['c']=2;
														unMap['d']=3;
														unMap['e']=3;
														unMap['f']=3;
														unMap['g']=4;
														unMap['h']=4;
														unMap['i']=4;
														unMap['j']=5;
														unMap['k']=5;
														unMap['l']=5;
														unMap['m']=6;
														unMap['n']=6;
														unMap['o']=6;
														unMap['p']=7;
														unMap['q']=7;
														unMap['r']=7;
														unMap['s']=7;
														unMap['t']=8;
														unMap['u']=8;
														unMap['v']=8;
														unMap['w']=9;
														unMap['x']=9;
														unMap['y']=9;
														unMap['z']=9;
														unMap['0']=0;
														string str;
														string res;
														getline(cin,str);
														for (int i = 0; i < str.size(); ++i)
														{
															auto ite = unMap.find(str[i]);
															if (ite != unMap.end())
															{
																res += to_string(ite->second);
															}
															else
															{
																if (str[i] >= 'A' && str[i] <= 'Z')
																{
																	if (str[i] == 'Z')
																		res += 'a';
																	else
																	{
																		res += str[i] + 33;
																	}
																}
																else
																{
																	res += str[i];
																}
															}
														}
														cout << res;*/
#pragma endregion

#pragma region MyRegion
														//while (1)
														//{
														//	int count = 0;
														//	cin >> count;
														//	if (count == 0)
														//	{
														//		break;
														//	}
														//	cout << count / 2 << endl;
														//}
#pragma endregion

#pragma region MyRegion



	/*unordered_map<char, int> unMap;
	string str;
	getline(cin,str);
	for (int i = 0; i < str.size(); ++i)
	{
		unMap[str[i]] += 1;
	}
	int min = 21;
	char minchar;
	for (auto tmp : unMap)
	{
		if (tmp.second < min)
		{
			min = tmp.second;
		}
	}
	string res;
	for (int i = 0; i < str.size(); ++i)
	{
		if (unMap[str[i]] == min)
			continue;
		res += str[i];
	}
	cout << res;*/
#pragma endregion

#pragma region MyRegion
	/*int count = 0;
	cin >> count;
	int tmp = 0;
	vector<int> list,frontList,backList;
	while (cin >> tmp)
	{
		list.push_back(tmp);
	}
	frontList.assign(count,0);
	backList.assign(count,0);
	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if (list[i] > list[j])
			{
				frontList[i] = max(frontList[i],frontList[j]+1);
			}
		}
	}
	for (int i = count - 2; i >= 0; i--)
	{
		for (int j = count - 1; j > i; j--)
		{
			if (list[i] > list[j])
			{
				backList[i] = max(backList[i], backList[j] + 1);
			}
		}
	}
	int max = -1;
	for (int i = 0; i < count; ++i)
	{
		if (frontList[i] + backList[i]+1 > max)
		{
			max = frontList[i] + backList[i] + 1;
		}
	}
	cout << count - max;*/
#pragma endregion

#pragma region MyRegion


	/*string str;
	getline(cin,str);
	for (int i = 0; i < str.size()-1; ++i)
	{
		int step = 1;
		for (int j = 0; j < str.size() - 1 - i; ++j)
		{
			if (!(str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z'))
				continue;
			int k = j + 1;
			for (k = j + 1; k < str.size(); k++)
			{
				if (str[k] >= 'a' && str[k] <= 'z' || str[k] >= 'A' && str[k] <= 'Z')
					break;
			}
			if (k >= str.size())
				continue;
			if (tolower(str[j]) > tolower(str[k]))
			{
				auto temp = str[j];
				str[j] = str[k];
				str[k] = temp;
			}
		}
	}
	cout << str;*/
#pragma endregion

#pragma region MyRegion


	/*int count = 0;
	cin >> count;
	vector<string> vec;
	vector<string> bro;

	string target;
	int next = 0;
	for (int i = 0; i < count; ++i)
	{
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	cin >> target;
	cin >> next;
	for (int i = 0; i < count; ++i)
	{
		if (vec[i].size() == target.size() && vec[i] != target)
		{
			string str1 = vec[i];
			string str2 = target;
			sort(str1.begin(),str1.end());
			sort(str2.begin(),str2.end());
			if (str1 == str2)
			{
				bro.push_back(vec[i]);
			}
		}

	}
	sort(bro.begin(),bro.end());
	cout << bro.size() << endl;
	if (next <= bro.size())
	{
		cout << bro[next - 1];
	}*/
#pragma endregion
#pragma region MyRegion

	/*string str;
	cin >> str;
	string tar;

	string EncyStr;
	cin >> EncyStr;
	string Encytar;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] == '9')
				tar += '0';
			else
				tar += str[i] + 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] == 'z')
				tar += 'A';
			else
				tar += str[i] - 31;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] == 'Z')
				tar += 'a';
			else
				tar += str[i] + 33;
		}
		else
			tar += str[i];
	}

	for (int i = 0; i < EncyStr.size(); ++i)
	{
		if (EncyStr[i] >= '0' && EncyStr[i] <= '9')
		{
			if (EncyStr[i] == '0')
				Encytar += '9';
			else
				Encytar += EncyStr[i] - 1;
		}
		else if (EncyStr[i] >= 'a' && EncyStr[i] <= 'z')
		{
			if (EncyStr[i] == 'a')
				Encytar += 'Z';
			else
				Encytar += EncyStr[i] - 33;
		}
		else if (EncyStr[i] >= 'A' && EncyStr[i] <= 'Z')
		{
			if (EncyStr[i] == 'A')
				Encytar += 'z';
			else
				Encytar += EncyStr[i] + 31;
		}
		else
			Encytar += EncyStr[i];
	}


	cout << tar<<endl;
	cout << Encytar;*/
#pragma endregion

#pragma region MyRegion

	/*string str;
	getline(cin,str);
	string temp;
	vector<string> list;
	for (int i = 0; i < str.size(); ++i)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			temp += str[i];
		}
		else
		{
			if (temp.size() != 0)
			{
				list.push_back(temp);
				temp.clear();
			}
		}
	}
	if (temp.size() != 0)
	{
		list.push_back(temp);
		temp.clear();
	}
	for (int i = list.size() - 1; i >= 0; --i)
	{
		cout << list[i] << " ";
	}*/

#pragma endregion
#pragma region MyRegion
	/*string str;
	cin >> str;
	vector<vector<bool>> dp;
	for (int i = 0; i < str.size(); ++i)
	{
		vector < bool> tmp;
		tmp.assign(str.size(), false);
		dp.push_back(tmp);
	}
	int max = -1;
	for (int j = 0; j < str.size(); ++j)
	{
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == str[j])
			{
				if (j - i < 2)
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && j - i + 1 > max)
					max = j - i + 1;
			}
			else
			{
				dp[i][j] = false;
			}
		}
	}
	cout << max;*/
#pragma endregion
#pragma region MyRegion

	/*string str;
	cin >> str;
	auto array=str.c_str();
	for (int i = 0; i < str.size() - 1; ++i)
	{
		for (int j = 0; j < str.size() - 1 - i; ++j)
		{
			if (str[j] > str[j+1])
			{
				char tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
			}
		}
	}
	cout << str;*/
#pragma endregion
#pragma region MyRegion

	/*int count = 0;
	cin >> count;
	int begin = 1;
	vector<int> list;
	for (int i = 0; i < count; ++i)
	{
		if (i == 0)
		{
			int tmp = 1;
			int add = 2;
			for (int j = 0; j < count; j++)
			{
				list.push_back(tmp);
				cout << tmp << " ";
				tmp = tmp + add;
				add += 1;
			}
			cout << endl;
		}
		else
		{
			int num = list[i - 1]+1;
			int numAdd = i + 2;
			for (int j = 0; j < count - i; j++)
			{
				cout << num << " ";
				num += numAdd;
				numAdd += 1;
			}
			cout << endl;
		}
	}*/

#pragma endregion
#pragma region MyRegion

	/*string str,msg;
	cin >> str;
	cin >> msg;
	char character[26];
	bool exit[26];
	string uniqueStr;
	for (int i = 0; i < 26; ++i)
	{
		exit[i] = false;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (exit[str[i] - 'a'])
			continue;
		uniqueStr += str[i];
		exit[str[i] - 'a'] = true;
	}
	int index = 0;
	for (int i = 0; i < uniqueStr.size(); ++i)
	{
		character[i] = uniqueStr[i];
	}
	index = uniqueStr.size();
	for (int i = 0; i < 26; ++i)
	{
		if (!exit[i])
		{
			character[index++] = 'a'+i;
		}
	}
	string res;
	for (int i = 0; i < msg.size(); ++i)
	{
		res += character[msg[i]-'a'];
	}
	cout << res;*/

#pragma endregion
#pragma region MyRegion

	/*double height = 0;
	cin >> height;

	double total = height, lastHeight = 0,curHeight= height;
	for (int i = 0; i < 4; ++i)
	{
		curHeight /= 2;
		total += curHeight * 2;
	}
	cout << total << endl << curHeight / 2;*/

#pragma endregion
#pragma region MyRegion

	/*string str;
	getline(cin,str);
	int chara = 0, space = 0, num = 0, other = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			chara += 1;
		else if (str[i] == ' ')
		{
			space += 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			num += 1;
		else
			other += 1;
	}
	cout << chara << endl << space << endl << num << endl << other;*/
#pragma endregion
#pragma region MyRegion

	/*int n;
	cin >> n;
	vector<int> weight;
	vector<int> count;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		for(int j=0;j< tmp;++j)
			count.push_back(weight[i]);
	}
	unordered_set<int> set;
	set.insert(0);
	for (int i = 0; i < count.size(); ++i)
	{
		unordered_set<int> tmp(set);
		for (int num : tmp)
		{
			set.insert(num+count[i]);
		}
	}
	cout << set.size();*/

#pragma endregion

#pragma endregion

	// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
	// 调试程序: F5 或调试 >“开始调试”菜单

	// 入门使用技巧: 
	//   1. 使用解决方案资源管理器窗口添加/管理文件
	//   2. 使用团队资源管理器窗口连接到源代码管理
	//   3. 使用输出窗口查看生成输出和其他消息
	//   4. 使用错误列表窗口查看错误
	//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
	//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
