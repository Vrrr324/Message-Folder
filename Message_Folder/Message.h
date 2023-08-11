#pragma once
#include "stdafx.h"
#include "Folder.h"

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	Message(const Message&);
	~Message();
	explicit				Message(const STD string& str = "");
	Message&				operator=(const Message&);
	void					save(Folder&);
	void					remove(Folder&);
	
private:
	void					add2Folders(const Message&);  // ����Message��ӵ�ָ��������Folder��
	void					remove2Folders();			 // ��folders�е�ÿ��Folder��ɾ����Message

private:
	STD string				contents;
	STD set<Folder*>		folders;
};

