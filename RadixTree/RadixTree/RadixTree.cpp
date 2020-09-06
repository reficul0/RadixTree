#include "pch.h"

#include <cassert>
#include <iostream>

#include <unordered_map>
#include <boost/optional.hpp>
#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <boost/variant.hpp>

namespace tree
{
	template<typename Value>
	struct Node
	{
		Value value;
		std::list<Node> children;
	};

	template<typename Value>
	struct Root
	{
		std::list<Node<Value>> children;
	};
}

class RadixTree
{
	tree::Root<std::string> _root;
public:
	
	void add(std::string add_me)
	{
		_add_to_children(std::move(add_me), _root.children);
	}
private:
	void _add_to_children(std::string add_me, std::list<tree::Node<std::string>> &node_children)
	{
		auto const children_end = node_children.end();
		auto child_iter = std::find_if(
			node_children.begin(), children_end,
			[&add_me](decltype(*node_children.begin()) child)
			{
				return !child.value.empty() && add_me[0] == child.value[0];
			}
		);
		if (child_iter != children_end)
		{
			auto &child = *child_iter;
			_add(std::move(add_me)/*.substr(1)*/, child);
		}
		else
			node_children.emplace_back(tree::Node<std::string>{std::move(add_me)});
	};
	void _add(std::string add_me, tree::Node<std::string> &node)
	{
		auto result = node.value.compare(add_me);
		switch (result)
		{
		case 0:
			// todo terminate simbool
			// этот узел содержит в себе это значение
			break;
		case -1://(node.value.size > add_me.size) значит детей нет
		{
			auto value = node.value;
			if (node.value.size() > 1)
			{
				node.value = value[0];
				node.children.emplace_back(tree::Node<std::string>{value.substr(1)});
				_add(add_me.substr(1), node.children.back());
			}
			else
				_add_to_children(add_me.substr(1), node.children);
		} break;
		default:
			assert(false);
		}
		
	}
};

int main()
{
	RadixTree tree;
	tree.add("abs");
	tree.add("absq");
	tree.add("absqs");
	tree.add("assqs");
}