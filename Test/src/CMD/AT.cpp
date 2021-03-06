/*
 * AT.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: sgeorgiadis
 */
#include <iostream>
#include <ctime>
using namespace std;

#include "../CMD/AT.h"

const string AT::PREF = "AT";
const char AT::DELIM = ',';

AT::~AT() {
	// TODO Auto-generated destructor stub
}

bool AT::parse(const string& input,
		string& command, vector<string>& params){

	if(std::equal(PREF.begin(), PREF.end(), input.begin())){
		unsigned int n = PREF.size();
		unsigned int ei = 0;

		string com = "";
		while(input[n]!='\r'
				&& n<20
				&& n<input.size()){
			if(input[n]=='='){
				ei = n;
				break;
			}
			com += input[n];
			n++;
		}
		if(ei>0){
			string s = input.substr(ei+1, input.size()-1);
			int found = s.find(&DELIM);
			if(found!=-1){
				split(s, params);
			}
			else{
				params.push_back(
						input.substr(ei+1, input.size()-1));
			}
		}
		if(com.size()>0)
			command = com.substr(1, com.size()-1);
		return true;
	}
	else{
		// NO AT COMMAND
		return false;
	}
}

CMD* AT::toCMD(const string& at){
	string command = "";
	vector<string> params;
	CMD* cmd = new CMDErrorReport();
	bool res = parse(at, command, params);

	if(res){

		//string& s = ATCommands::AT_BT;
		if(command.compare(ATCMDs::AT_BT)==0){
			cmd = new CMDBatteryReport(params);
		}
		else if(command.compare(ATCMDs::AT_SET)==0){
			cmd = new CMDSettings(params);
		}
		else if(command.compare(ATCMDs::AT_TLS)==0){

		}

		cmd->setParams(params);
	}
	return cmd;
}

void AT::split(const string& s, vector<string>& v) {
    auto i = 0;
    auto pos = s.find(DELIM);
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(DELIM, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

long AT::toLong(string str){
	return atol(str.c_str());
}

/*void AT::print(){
	cout << "AT[" << command << " params:" ;
	for(std::vector<string>::iterator it = params.begin();
			it != params.end(); ++it) {
		cout << *it ;
		if(it!=params.end()-1)
			cout << " ";
	}
	cout << "]" << endl;
}*/

