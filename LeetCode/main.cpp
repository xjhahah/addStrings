#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	//char& operator[] (size_t pos)
	//{
	//	cout << _str[pos] << endl;
	//	return _str[pos];
	//}
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;

		//创进一个新的数组来保存结果
		string retstr;
		retstr.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
		//进位
		char next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			char value1 = 0;
			char value2 = 0;
			if (end1 >= 0)
			{
				value1 = num1[end1] - '0';
			}
			if (end2 >= 0)
			{
				value2 = num2[end2] - '0';
			}
			char ret = value1 + value2 + next;
			if (ret > 9)
			{
				next = 1;
				ret -= 10;
			}
			else
				next = 0;
			retstr += (ret + '0');
			--end1;
			--end2;
		}
		if (next == 1)
		{
			retstr += '1';
		}
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
private:
	char* _str;
};

int main()
{
	Solution s;
	s.addStrings("0", "0");
	return 0;
}