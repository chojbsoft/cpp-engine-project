#pragma once
//#include <windows.h>
#include <cmath>
#include <memory>
#include <typeinfo>
#include <iostream>

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <boost/pool/pool.hpp>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;
using Socket = boost::asio::ip::tcp::socket;
using namespace std;

#include "define.h"
#include "Struct.h"
#include "Object.h"
#include "Function.h"
#include "Logger.h"

#pragma comment(lib, "Msimg32.lib")

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;