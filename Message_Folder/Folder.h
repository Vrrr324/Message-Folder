#pragma once
#include "stdafx.h"

class Message;

class Folder
{
public:
	Folder();
	~Folder();
	Folder(const Folder&);
	void					addMsg(Message*);
	void					remMsg(Message*);
	int						getNum();

private:
	void					add2Msg(const Folder&);
	void					remove2Msg();

private:
	int						msg_num = 0;
	STD set<Message*>		messages;

};

