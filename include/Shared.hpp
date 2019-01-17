
template <typename T>
class SharedPtr
{
public:
	SharedPtr() //по умолчанию
	{
		Set(0);
	}
	SharedPtr(T * ptr) // конструктор параметризирования
	{
		Set(ptr);
	}

	~SharedPtr()
	{
		Delete();
	}

	SharedPtr(const SharedPtr& r) //конструктор копирования 
	{
		Set(r._ptr);
	}

	SharedPtr& operator=(const SharedPtr& r) // оператор присваивания 
	{
		if (*this == &r)
			return this;
		Delete();
		Set(r._ptr);
	}

	operator bool() const //
	{
		return _ptr != 0;
	}

	T& operator *() const
	{
		return *_ptr;
	}

	T* operator->() const
	{
		return _ptr;
	}

	T* get() const //получить эказатель
	{
		return _ptr;
	}

	void reset() 
	{
		Delete();
	}
	
	void reset(T * ptr)
	{
		Delete();
		Set(ptr);
	}
	void swap(SharedPtr& r) //
	{
		T* temp = r._ptr;
		r._ptr = _ptr;
		_ptr = r._ptr;
	}

	size_t use_count() const //количество сылок на объект 
	{
		if (_ptr != 0)
			return _storage[_ptr];
		throw;
	}

private:	
	void Delete()
	{
		if (_ptr != 0)
		{
			--_storage[_ptr];
			if (_storage[_ptr] == 0)
				_storage.erase(_ptr);
		}
		_ptr = 0;
	}

	void Set(T* ptr)
	{
		_ptr = ptr;
		if (ptr != 0)
			++_storage[ptr];
	}

	T *_ptr;
	static std::map<T*, std::atomic_uint> _storage;
};

template <typename T>
std::map<T*, std::atomic_uint> SharedPtr<T>::_storage;
