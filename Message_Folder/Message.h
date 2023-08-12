#pragma once
#include "stdafx.h"
#include "Folder.h"

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);

public:
	explicit				Message(const STD string& str = "");
	~Message();
	Message(const Message&);
	Message&				operator=(const Message&);
	Message(Message&&);
	Message&				operator=(Message&&);
	void					save(Folder&);
	void					remove(Folder&);
	
private:
	void					add2Folders(const Message&);  // ����Message��ӵ�ָ��������Folder��
	void					remove2Folders();			  // ��folders�е�ÿ��Folder��ɾ����Message
	void					moveFolders(Message*);

private:
	STD string				contents;
	STD set<Folder*>		folders;
};

