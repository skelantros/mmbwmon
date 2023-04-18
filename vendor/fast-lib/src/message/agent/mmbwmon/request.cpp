#include <fast-lib/message/agent/mmbwmon/request.hpp>

namespace fast {
namespace msg {
namespace agent {
namespace mmbwmon {

request::request(const std::vector<size_t> &_cores, std::string &_id) : cores(_cores), id(_id)
{
}

YAML::Node request::emit() const
{
	YAML::Node node;
	node["cores"] = cores;
	node["id"] = id;
	return node;
}

void request::load(const YAML::Node &node)
{
	fast::load(cores, node["cores"]);
	fast::load(id, node["id"]);
}

}
}
}
}
