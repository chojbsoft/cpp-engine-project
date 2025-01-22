#include "pch.h"
#include "ObjectArray.h"

ObjectArray _objectArray;

void ObjectArray::Create(const type_info& typeInfo, const size_t size)
{
	_memoryPool[typeInfo.hash_code()].Create(typeInfo.name(), size);
}

void* ObjectArray::Malloc(const type_info& typeInfo)
{
	return _memoryPool[typeInfo.hash_code()].Malloc();
}

void ObjectArray::Free(const type_info& typeInfo, void* address)
{
	_memoryPool[typeInfo.hash_code()].Free(address);
}

void ObjectArray::Destroy()
{
	for (auto& Pair : _memoryPool)
	{
		Pair.second.Destroy();
	}
	_memoryPool.clear();
}

bool ObjectArray::IsExist(const type_info& InTypeInfo)
{
	return _memoryPool.find(InTypeInfo.hash_code()) != _memoryPool.end();
}

MemoryPool::~MemoryPool()
{
	delete _pool;
}

void MemoryPool::Create(const string_view typeName, const size_t size)
{
	if (_pool)
	{
		return;
	}

	_typeName = typeName;
	_size = size;
	_pool = new boost::pool<>(_size);
}

void* MemoryPool::Malloc()
{
	void* Address = _pool->malloc();
	return Address;
}

void MemoryPool::Free(void* InAddress)
{
	_pool->free(InAddress);
}

void MemoryPool::Destroy()
{
	if (_pool)
	{
		delete _pool;
		_pool = nullptr;
	}
}
