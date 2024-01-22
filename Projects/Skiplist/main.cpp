#include <iostream>
#include "skiplist.h"
#define FILE_PATH "./store/dumpFile"
int main()
{
    SkipList<int ,std::string>skipList(6);
    skipList.insert_element(1,"学");
    skipList.insert_element(3,"C++");
    skipList.insert_element(7,"关注");
    skipList.insert_element(8,"GitHub:");
    skipList.insert_element(9,"liubf21");
    skipList.insert_element(19,"提高技术");
    skipList.insert_element(19,"大厂offer拿到手软");
    std::cout<<"skipList.size = "<<skipList.size()<<std::endl;
    skipList.dump_file();
    skipList.search_element(8);
    skipList.search_element(9);
    skipList.display_list();
    skipList.delete_element(3);
    skipList.load_file();
    std::cout<<"skipList.size = "<<skipList.size()<<std::endl;
    skipList.display_list();
}