#include <fast-lib/message/agent/mmbwmon/reply.hpp>

namespace fast {
namespace msg {
namespace agent {
namespace mmbwmon {

reply::reply(const std::vector<size_t> &_cores, double _result, std::string &_id) : cores(_cores), result(_result), id(_id)
{
}

YAML::Node reply::emit() const
{
	YAML::Node node;
	node["cores"] = cores;
	node["result"] = result;
	node["id"] = id;
	return node;
}

void reply::load(const YAML::Node &node)
{
	fast::load(cores, node["cores"]);
    fast::load(result, node["result"]);
	fast::load(id, node["id"]);
}

}
}
}
}
