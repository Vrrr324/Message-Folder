#include "Folder.h"
#include "Message.h"

Folder::Folder()
{
}

Folder::~Folder()
{
	remove2Msg();
}

Folder::Folder(const Folder& rf)
{
	msg_num = rf.msg_num;
	messages = rf.messages;
	add2Msg(rf);
}

void Folder::addMsg(Message* rm)
{
	messages.insert(rm);
	++msg_num;
}

void Folder::remMsg(Message* rm)
{
	messages.erase(rm);
	--msg_num;
}

int Folder::getNum()
{
	return msg_num;
}

void Folder::add2Msg(const Folder& rf)
{
	for (auto m : rf.messages)
	{
		m->save(*this);
	}
}

void Folder::remove2Msg()
{
	for(auto m:messages)
	{
		m->remove(*this);
	}
}
