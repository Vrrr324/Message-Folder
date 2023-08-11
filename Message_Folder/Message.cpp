#include "Message.h"

Message::Message(const Message& rm):contents(rm.contents),folders(rm.folders)
{
	add2Folders(rm);
}

Message::~Message()
{
	remove2Folders();
}

Message::Message(const STD string& str):contents(str)
{
}

Message& Message::operator=(const Message& rm)
{
	remove2Folders();
	folders = rm.folders;
	contents = rm.contents;
	add2Folders(rm);
	return *this;
}

void Message::save(Folder& rf)
{
	folders.insert(&rf);
	rf.addMsg(this);
}

void Message::remove(Folder& rf)
{
	folders.erase(&rf);
	rf.remMsg(this);
}

void Message::add2Folders(const Message& rm)
{
	for(auto f:rm.folders)
	{
		f->addMsg(this);
	}
}

void Message::remove2Folders()
{
	for (auto f : folders) 
	{
		f->remMsg(this);
	}
}

void swap(Message& lm, Message& rm) {
	for (auto f : lm.folders) 
	{
		f->remMsg(&lm);
	}
	for(auto f:rm.folders)
	{
		f->remMsg(&rm);
	}
	swap(rm.contents, lm.contents);
	swap(rm.folders, lm.folders);
	for (auto f : lm.folders) 
	{
		f->addMsg(&lm);
	}
	for (auto f : rm.folders) 
	{
		f->addMsg(&rm);
	}
}
