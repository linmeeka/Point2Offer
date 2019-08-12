#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int res = a;
	int tmp = res;
	tmp = a + b + c;
	res = max(res, tmp);
	tmp = a + b * c;
	res = max(res, tmp);
	tmp = a * b + c;
	res = max(res, tmp);
	tmp = a * b * c;
	res = max(res, tmp);
	tmp = a * (b + c);
	res = max(res, tmp);
	tmp = (a + b) * c;
	res = max(res, tmp);
	cout << res << endl;
	return 0;
}