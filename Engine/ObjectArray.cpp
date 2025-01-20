#include "pch.h"
#include "ObjectArray.h"

ObjectArray GObjectArray;

void ObjectArray::Create(const type_info& InTypeInfo, const size_t InSizePerOne)
{
	MapMemoryPool[InTypeInfo.hash_code()].Create(InTypeInfo.name(), InSizePerOne);
}

void* ObjectArray::Malloc(const type_info& InTypeInfo)
{
	return MapMemoryPool[InTypeInfo.hash_code()].Malloc();
}

void ObjectArray::Free(const type_info& InTypeInfo, void* InAddress)
{
	MapMemoryPool[InTypeInfo.hash_code()].Free(InAddress);
}

void ObjectArray::Destroy()
{
	for (auto& Pair : MapMemoryPool)
	{
		Pair.second.Destroy();
	}
	MapMemoryPool.clear();
}

bool ObjectArray::IsExist(const type_info& InTypeInfo)
{
	return MapMemoryPool.find(InTypeInfo.hash_code()) != MapMemoryPool.end();
}

void FMemoryPool::Create(const string_view InTypeName, const size_t InSizePerOne)
{
	if (Pool)
	{
		return;
	}

	TypeName = InTypeName;
	SizePerOne = InSizePerOne;
	Pool = new boost::pool<>(SizePerOne);
}

void* FMemoryPool::Malloc()
{
	void* Address = Pool->malloc();
	return Address;
}

void FMemoryPool::Free(void* InAddress)
{
	Pool->free(InAddress);
}

void FMemoryPool::Destroy()
{
	if (Pool)
	{
		delete Pool;
		Pool = nullptr;
	}
}
