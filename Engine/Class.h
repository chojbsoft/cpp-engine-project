#pragma once

#include "Object.h"


class Class : public Object
{
	Class() = default;
};


extern map<wstring, Class*> g_mapClass;