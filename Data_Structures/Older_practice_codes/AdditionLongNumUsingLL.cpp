#include<iostream>
#include<string>

using namespace std;

namespace nmLongNum
{

	class AddLong {
		string no1;
		string no2;
		string res;

	public:
		string reverse(string st) {
			string x = "";
			for (int i = st.length() - 1; i >= 0; i--) {
				x += st[i];
			}
			return x;
		}

		string AddL(string st1, string st2) {

			int carry = 0;
			if (st2.length() > st1.length()) {
				swap(st1, st2);
			}

			st1 = reverse(st1);
			st2 = reverse(st2);

			for (int i = 0; i <= st2.length() - 1; i++) {
				int y = (st1[i] - '0') + (st2[i] - '0') + carry;
				carry = y / 10;
				y = y % 10;
				res.push_back(y + '0');
			}
			for (int i = st2.length(); i <= st1.length() - 1; i++) {
				int y = (st1[i] - '0') + carry;
				carry = y / 10;
				y = y % 10;
				res.push_back(y + '0');
			}
			return reverse(res);
		}

	};

	int main() {
		AddLong a;
		string x = a.AddL("1", "1111999999999999999999999999999999999999999");
		cout << x;

		return 0;
	}

}