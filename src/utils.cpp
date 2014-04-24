#include "utils.h"
using namespace boost::filesystem;

std::string find_file(const std::string& fileroot, const std::string& filename){

    path p(fileroot.c_str());
    path fn(filename.c_str());
    if( !exists(p)){
        throw std::runtime_error("file not found");
    }
    std::string realname = fn.filename().string();

    recursive_directory_iterator end_itr;
    recursive_directory_iterator itr(p);
    for( ; itr != end_itr; ++itr){
        if(realname.compare(itr->path().filename().string()) == 0){
            return itr->path().string();
        }
    }
    throw std::runtime_error("file not found");
}
