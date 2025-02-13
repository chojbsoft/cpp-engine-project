#pragma once

struct MemoryPool
{
public:
	~MemoryPool();

public:
	void Create(const string_view typeName, const size_t sizePerOne);
	void* Malloc();
	void Free(void* ptr);
	void Destroy();

private:
	string_view _typeName;
	size_t _size;

	boost::pool<>* _pool = nullptr;
};

class ObjectArray
{
public:
	void Create(const type_info& typeInfo, const size_t size);
	void* Malloc(const type_info& typeInfo);
	void Free(const type_info& typeInfo, void* address);
	void Destroy();
	bool IsExist(const type_info& typeInfo);

private:
	unordered_map<size_t, MemoryPool> _memoryPool;
};

extern ObjectArray _objectArray;


template <class _Ty>
class Allocator
{
public:
	static_assert(!is_const_v<_Ty>, "The C++ Standard forbids containers of const elements "
		"because allocator<const T> is ill-formed.");
	static_assert(!is_function_v<_Ty>, "The C++ Standard forbids allocators for function elements "
		"because of [allocator.requirements].");
	static_assert(!is_reference_v<_Ty>, "The C++ Standard forbids allocators for reference elements "
		"because of [allocator.requirements].");

	using _From_primary = Allocator;

	using value_type = _Ty;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	using propagate_on_container_move_assignment = true_type;
	using is_always_equal _CXX20_DEPRECATE_IS_ALWAYS_EQUAL = true_type;
	
	Allocator(const type_info& typeInfo) noexcept :
		_typeInfo(typeInfo)
	{
	}
	constexpr Allocator(const Allocator&) noexcept = default;
	template <class _Other>
	constexpr Allocator(const Allocator<_Other>& InOther) noexcept :
		_typeInfo(InOther._typeInfo)
	{
	}
	_CONSTEXPR20 ~Allocator() = default;
	_CONSTEXPR20 Allocator& operator=(const Allocator&) = default;


	_Ty* allocate(const size_t count)
	{
		return (_Ty*)_objectArray.Malloc(_typeInfo);
	}

	template <class _Objty, class... _Types>
	void construct(_Objty* const ptr, _Types&&... args)
	{
		new(ptr)_Objty(std::forward<_Types>(args)...);
	}

	template<class U>
	void destroy(U* p)
	{
		p->~U();
	}

	void deallocate(_Ty* const ptr, const size_t count)
	{
		_objectArray.Free(_typeInfo, ptr);
	}

public:
	const type_info& _typeInfo;
};

_EXPORT_STD template <class _Ty, class _Other>
_NODISCARD _CONSTEXPR20 bool operator==(const Allocator<_Ty>&, const Allocator<_Other>&) noexcept
{
	return true;
}
_EXPORT_STD template <class _Ty, class _Other>
_NODISCARD _CONSTEXPR20 bool operator!=(const Allocator<_Ty>& a, const Allocator<_Other>& b) noexcept
{
	return !(a == b);
}

