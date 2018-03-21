#ifndef JSON_TREE_HPP
#define JSON_TREE_HPP

#include <boost/property_tree/ptree.hpp>
#include <istream>
#include <string>

// Short alias for this namespace
namespace pt = boost::property_tree;

class json_tree
{
public:
    json_tree(std::istream&);
    //	~json_tree();
    int get_int_value(const std::string&);

private:
    pt::ptree _json_root;
};

#endif