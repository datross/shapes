#include "SelectionFactory.h"

using namespace idl;


SelectionFactory & idl::SelectionFactory::getInstance(){
	static SelectionFactory instance;
	return instance;
}

shared_ptr<Selection> idl::SelectionFactory::create(json jSelection) {
	return shared_ptr<Selection>();
}

SelectionFactory::SelectionFactory()
{
}

SelectionFactory::~SelectionFactory()
{
}
