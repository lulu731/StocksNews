#ifndef JSON_TREE_HPP
#define JSON_TREE_HPP

#include <istream>
#include <string>

#include <boost/property_tree/ptree.hpp>

// Short alias for this namespace
namespace pt = boost::property_tree;

class JsonTree
{
public:
    JsonTree(std::istream&);
    int GetIntValue(const std::string&);
private:
    pt::ptree _json_root;
};

#endif