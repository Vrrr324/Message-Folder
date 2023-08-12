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
	void					add2Folders(const Message&);  // 将该Message添加到指定参数的Folder中
	void					remove2Folders();			  // 从folders中的每个Folder中删除该Message
	void					moveFolders(Message*);

private:
	STD string				contents;
	STD set<Folder*>		folders;
};

