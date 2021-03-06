#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class TapeMeasure {
public:
	vector <string> draw(int leftMark, int rightMark) {
		string a = "####################";
		string b = "# # # # # # # # # # ";
		string c = "#         #         ";
		string d = "#                   ";
		string e = "                    ";
		
	
		vector<string> V(5, "");
		vector<string> ans(5, "");
		
		int i = 0;
		int num = 0;
		while(num < 1005){
			int ind = i % 20;
			V[0] += a[ind];
			V[1] += b[ind];
			V[2] += c[ind];
			V[3] += d[ind];
			if(ind == 0) {
				stringstream in;
				in<<num;
				string aux = in.str();
				V[4] += aux;
				V[4] += e.substr(aux.size());
			}
			
			i++;
			if(i % 2 == 0) num++;  
		}
		
		int init = 2*leftMark;
		int end  = 2*rightMark;
		
		for(int i = 0; i < V.size(); i++) {
			ans[i] = V[i].substr(init, end - init + 1);
		}
		
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	TapeMeasure *obj;
	vector <string> answer;
	obj = new TapeMeasure();
	clock_t startTime = clock();
	answer = obj->draw(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	vector <string> p2;
	
	{
	// ----- test 0 -----
	p0 = 0;
	p1 = 25;
	string t2[] = {"###################################################","# # # # # # # # # # # # # # # # # # # # # # # # # #","#         #         #         #         #         #","#                   #                   #          ","0                   10                  20         "};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 981;
	p1 = 990;
	string t2[] = {"###################","# # # # # # # # # #","        #         #","                  #","0                 9"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = 20;
	string t2[] = {"#","#","#","#","2"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 31;
	p1 = 38;
	string t2[] = {"###############","# # # # # # # #","        #      ","               ","               "};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
