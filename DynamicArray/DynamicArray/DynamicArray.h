#include <iostream>

/*
// 동적배열 (Dynamic Array)
// : 배열이기 때문에 연속적인 메모리를 가지며, 셋팅한 size를 초과할 경우
//   자동으로 더 큰 메모리를 재할당하여 요소를 복사하고 확장한다.
//   중간 요소의 삽입 삭제는 많은 요소를 이동시켜야하므로 성능상 부담이 있지만,
//   연속된 메모리를 사용하여 CPU 캐시 효율이 매우 높다.
// - Low-level operator new/delete 활용 방법
// - serve / resize 차이
// - 동적배열 insert / erase 의 한계
// - 동적배열 삭제를 해결하기위한 erase_unordered
*/

template <typename T>
class DynamicArray
{
private:
	T* data = nullptr;	    // 동적 메모리 할당을 위한 포인터
	size_t size = 0;		// 사용된 메모리의 크기
	size_t capacity = 0;    // 할당된 메모리의 크기

public:
	DynamicArray() {}
	~DynamicArray()
	{
		clear();
		::operator delete(data); // 메모리 해제 
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	
	/*--------------- push, insert, remove, clear ---------------*/
	/// 맨 뒤에 값 삽입
	void push_back(const T& value)
	{
		std::cout << "push_back" << std::endl;
		if (size >= capacity)
		{
			reserve((capacity == 0) ? 1 : capacity * 2);
		}
		data[size++] = value; // 복사 대입 연산자
	}

	/// 마지막 요소 삭제
	void pop_back()
	{
		std::cout << "pop_back" << std::endl;
		if (size > 0)
		{
			data[--size].~T(); // 소멸자 호출
			--size;
		}
	}

	/// index에 요소 삽입
	void insert(size_t index, const T& value)
	{
		std::cout << "insert" << index << std::endl;
		if (index > size)
		{
			throw std::out_of_range("Index out of range");
		}
		if (size >= capacity)
		{
			reserve((capacity == 0) ? 1 : capacity * 2);
		}
		// 한칸씩 뒤로 밀기
		for (size_t i = size; i > index; --i)
		{
			data[i] = data[i - 1]; // 복사 대입 연산자 호출
		}
		data[index] = value; // 복사 대입 연산자 호출
		++size;
	}

	/// index의 요소 삭제
	void erase(size_t index)
	{
		std::cout << "erase" << index << std::endl;
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		data[index].~T(); // 소멸자 호출
		for (size_t i = index; i < size - 1; ++i)
		{
			data[i] = data[i + 1]; // 복사 대입 연산자 호출
		}
		--size;
	}

	/// 모든 요소 제거 (메모리는 유지)
	void clear()
	{
		for (size_t i = 0; i < size; ++i)
		{
			data[i].~T(); // 소멸자 호출
		}
		size = 0;
	}


	/*------------------ get --------------------*/
	/// 공백 상태 반환
	bool empty() const
	{
		return size == 0;
	}

	/// 내부 배열의 전체 용량 반환
	size_t capacity() const
	{
		return capacity;
	}

	/// 현재 요소 개수 반환
	size_t size() const
	{
		return size;
	}

	/// 배열의 첫번째 요소 반환
	T& front()
	{
		if (size == 0)
		{
			throw std::out_of_range("Array is empty");
		}
		return data[0];
	}

	/// 배열의 마지막 요소 반환
	T& back()
	{
		if (size == 0)
		{
			throw std::out_of_range("Array is empty");
		}
		return data[size - 1];
	}

	/// [index] 인덱스의 요소 반환
	T& operator[](size_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	/// at(index) 인덱스의 요소 반한
	const T& at(size_t index) const
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}


	/*------------------ mamory --------------------*/
	/// 용량 확보
	void reserve(size_t newCap)
	{
		if (newCap <= capacity)
			return; // 용량이 충분함

		// 1. 새 메모리 할당 (T 객체 n개 분량만큼)
		T* newData = static_cast<T*>(::operator new(sizeof(T) * newCap));

		// 2. 기존 요소 복사 - placement new 사용
		for (size_t i = 0; i < size; ++i)
		{
			::new (&newData[i]) T(data[i]); // 복사생성자 호출
			data[i].~T(); // 기존 요소 소멸자 호출
		}

		// 3. 기존 메모리 해제
		if (data != nullptr)
			::operator delete(data);

		// 4. 포인터 및 용량 갱신
		data = newData;
		capacity = newCap;
	}

	/// size 변경 (초과하면 기본 값으로 채우기)
	void resize(size_t newSize)
	{
		if (newSize > capacity)
			reserve(newSize); // 메모리 늘림

		if (newSize > size) {
			// 새로운 요소 생성
			for (size_t i = size; i < newSize; ++i)
				::new (&data[i]) T(); // 기본 생성자 호출
		}
		else if (newSize < size) {
			// 남은 요소 소멸자 호출
			for (size_t i = newSize; i < size; ++i)
				data[i].~T();
		}

		size = newSize;
	}

	
	//DynamicArray(const DynamicArray& other);
	//DynamicArray& operator=(const DynamicArray& other);
	//DynamicArray(DynamicArray&& other) noexcept;
	//DynamicArray& operator=(DynamicArray&& other) noexcept;
	//void erase_unordered(size_t index)
	//void shrink_to_fit();
};

