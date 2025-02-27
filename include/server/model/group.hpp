#ifndef GROUP_H
#define GROUP_H

#include "groupuser.hpp"
#include <string>
#include <vector>
using namespace std;

class Group
{
public:
    Group(int id = -1, string name = "", string desc = "")
    {
        this->_id = id;
        this->_name = name;
        this->_desc = desc;
    }
    void setId(int id) { this->_id = id; }
    void setName(string name) { this->_name = name; }
    void setDesc(string desc) { this->_desc = desc; }

    int getId() { return this->_id; }
    string getName() { return this->_name; }
    string getDesc() { return this->_desc; }
    vector<GroupUser> &getUsers() { return this->users; }

private:
    int _id;
    string _name;
    // 群组描述
    string _desc;
    vector<GroupUser> users;
};

#endif
