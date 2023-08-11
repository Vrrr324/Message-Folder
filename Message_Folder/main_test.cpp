#include <iostream>
#include "Folder.h"
#include "Message.h"

int main()
{
    Folder folders[3];
    
    Message message1("CHINA");
    Message message2("USA");
    Message message3("UK");

    message1.save(folders[0]);
    message2.save(folders[0]);
    message2.save(folders[1]);
    message3.save(folders[0]);
    message3.save(folders[1]);
    message3.save(folders[2]);

    Message message4(message3);

    swap(message3, message2);
    return 0;
}
