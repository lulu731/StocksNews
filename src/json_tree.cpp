#include "json_tree.hpp"

#include <iostream>
#include <istream>
#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

// Short alias for this namespace
namespace pt = boost::property_tree;

JsonTree::JsonTree(std::istream& stream)
{
    // Load the json file in this ptree
    pt::read_json(stream, _json_root);
}

int JsonTree::GetIntValue(const std::string& path)
{
    return _json_root.get<int>(path, 0);
}
