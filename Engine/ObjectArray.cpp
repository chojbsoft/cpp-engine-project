#include "pch.h"
#include "ObjectArray.h"

ObjectArray GObjectArray;

void ObjectArray::Create(const type_info& InTypeInfo, const size_t InSizePerOne)
{
	mMapMemoryPool[InTypeInfo.hash_code()].Create(InTypeInfo.name(), InSizePerOne);
}

void* ObjectArray::Malloc(const type_info& InTypeInfo)
{
	return mMapMemoryPool[InTypeInfo.hash_code()].Malloc();
}

void ObjectArray::Free(const type_info& InTypeInfo, void* InAddress)
{
	mMapMemoryPool[InTypeInfo.hash_code()].Free(InAddress);
}

void ObjectArray::Destroy()
{
	for (auto& Pair : mMapMemoryPool)
	{
		Pair.second.Destroy();
	}
	mMapMemoryPool.clear();
}

bool ObjectArray::IsExist(const type_info& InTypeInfo)
{
	return mMapMemoryPool.find(InTypeInfo.hash_code()) != mMapMemoryPool.end();
}

MemoryPool::~MemoryPool()
{
	delete pool;
}

void MemoryPool::Create(const string_view InTypeName, const size_t InSizePerOne)
{
	if (pool)
	{
		return;
	}

	mTypeName = InTypeName;
	size = InSizePerOne;
	pool = new boost::pool<>(size);
}

void* MemoryPool::Malloc()
{
	void* Address = pool->malloc();
	return Address;
}

void MemoryPool::Free(void* InAddress)
{
	pool->free(InAddress);
}

void MemoryPool::Destroy()
{
	if (pool)
	{
		delete pool;
		pool = nullptr;
	}
}
