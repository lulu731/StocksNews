#include "json_tree.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <istream>
#include <string>

// Short alias for this namespace
namespace pt = boost::property_tree;

json_tree::json_tree(std::istream& stream)
{
    // Load the json file in this ptree
    pt::read_json(stream, _json_root);
}

int json_tree::get_int_value(const std::string& path)
{
    return _json_root.get<int>(path, 0);
}
