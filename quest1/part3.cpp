#include <bits/stdc++.h>
using namespace std;

string fileInput() {
	
	ifstream file("everybody_codes_e2026_q01_p3.txt");
	
	if(!file.is_open()) {
		cout << "Could not open file!" << endl;
		return "";
	}
	
	string line;
	getline(file, line);
	
	file.close();
	
	return line;
		
}

vector<int> toVector(string inputString){
	vector<int> elements;
	string ele;
	stringstream ss(inputString);
	
	while(getline(ss, ele, ',')){
		int x = stoi(ele);
		elements.emplace_back(x);
	}
	
	return elements;
	
}

int main(){
	
	string inputString;
	
	inputString = fileInput();
	
	vector<int> elements = toVector(inputString);
	
	long long ans = 0;
	
	for(int i = 0; i < elements.size(); i++){
		int num = elements[i];
		int rootNum = 1;
		int hollowSquare = 0;
		while(hollowSquare < num){
			rootNum += 2;
			hollowSquare = rootNum*rootNum - 1;
		}
		
		int req = hollowSquare - num;
		
		ans += req;
	}
	
	cout << ans << endl;
	
	return 0;
}

