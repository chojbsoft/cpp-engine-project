#pragma once

struct MemoryPool
{
public:
	~MemoryPool();

public:
	void Create(const string_view InTypeName, const size_t InSizePerOne);
	void* Malloc();
	void Free(void* InPtr);
	void Destroy();

private:
	string_view mTypeName;
	size_t size;

	boost::pool<>* pool = nullptr;
};

class ObjectArray
{
public:
	void Create(const type_info& InTypeInfo, const size_t InSizePerOne);
	void* Malloc(const type_info& InTypeInfo);
	void Free(const type_info& InTypeInfo, void* InAddress);
	void Destroy();
	bool IsExist(const type_info& InTypeInfo);

private:
	unordered_map<size_t, MemoryPool> mMapMemoryPool;
};

extern ObjectArray GObjectArray;


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
		mTypeInfo(typeInfo)
	{
	}
	constexpr Allocator(const Allocator&) noexcept = default;
	template <class _Other>
	constexpr Allocator(const Allocator<_Other>& InOther) noexcept :
		mTypeInfo(InOther.mTypeInfo)
	{
	}
	_CONSTEXPR20 ~Allocator() = default;
	_CONSTEXPR20 Allocator& operator=(const Allocator&) = default;

	template< class U >
	_CONSTEXPR20 void destroy(U* p)
	{
		p->~U();
	}


	_CONSTEXPR20 void deallocate(_Ty* const _Ptr, const size_t _Count)
	{
		_STL_ASSERT(_Ptr != nullptr || _Count == 0, "null pointer cannot point to a block of non-zero size");
		_STL_ASSERT(_Count == 1, "error");
		// no overflow check on the following multiply; we assume _Allocate did that check
		//_Deallocate<_New_alignof<_Ty>>(_Ptr, sizeof(_Ty) * _Count);

		GObjectArray.Free(mTypeInfo, _Ptr);
	}

	_NODISCARD_RAW_PTR_ALLOC _CONSTEXPR20 __declspec(allocator) _Ty* allocate(_CRT_GUARDOVERFLOW const size_t /*_Count*/)
	{
		static_assert(sizeof(value_type) > 0, "value_type must be complete before calling allocate.");
		_Ty* Pointer = (_Ty*)GObjectArray.Malloc(mTypeInfo);
		return Pointer;
	}

	template <class _Objty, class... _Types>
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS void construct(_Objty* const _Ptr, _Types&&... _Args)
	{
		new(_Ptr)_Objty(std::forward<_Types>(_Args)...);
	}

public:
	const type_info& mTypeInfo;
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

