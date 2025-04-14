#include <iostream>
using namespace std;

/*
// 동적배열 (Dynamic Array)
//   배열이기 때문에 연속적인 메모리를 가지며, 셋팅한 size를 초과할 경우
//   자동으로 더 큰 메모리를 재할당하여 요소를 복사하고 확장한다.
//   중간 요소의 삽입 삭제는 많은 요소를 이동시켜야하므로 성능상 부담이 있지만,
//   연속된 메모리를 사용하여 CPU 캐시 효율이 매우 높다.

// 1. Low-level operator new/delete 활용 방법 ⭐
//  - C++에서의 가장 저수준 메모리 관리 기술로, 메모리 관리와 인스턴스 생성/소멸을 분리하여 메모리를 재활용한다.
//  - operator new(size_t), operator delete(size_t), new(할당된메모리) 할당할 value
// 2. rserve / resize 차이
// 3. 동적배열 insert / erase 의 한계
// 4. 동적배열 삭제를 해결하기위한 erase_unordered
*/

template <typename T>
class DynamicArray
{
private:
	T* data = nullptr;	    // 동적 메모리 할당을 위한 포인터
	size_t size = 0;		// 현재 사용중인 요소 개수
	size_t capacity = 0;    // 메모리로 확보한 요소 개수

public:
	DynamicArray() {}
	~DynamicArray()
	{
		clear();				 // 객체 소멸
		::operator delete(data); // 메모리 해제
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	/*------------------ mamory --------------------*/
	/// 메모리 확보
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
			data[i].~T();					// 기존 요소 소멸자 호출
		}

		// 3. 기존 메모리 해제
		if (data != nullptr)
			::operator delete(data);

		// 4. 포인터 및 용량 갱신
		data = newData;
		capacity = newCap;
	}

	/// 메모리 용량 변경 (초과하면 기본 값으로 채우기)
	void resize(size_t newSize)
	{
		// 메모리 추가 확보
		if (newSize > capacity)
			reserve(newSize); 
		
		if (newSize > size) {
			// 새로운 요소 생성
			for (size_t i = size; i < newSize; ++i)
				::new (&data[i]) T();
		}	
		else if (newSize < size) {	
			// 남은 요소 소멸자 호출
			for (size_t i = newSize; i < size; ++i)
				data[i].~T();
		}

		size = newSize;
	}
	
	/*--------------- push, insert, remove, clear ---------------*/
	/// 맨 뒤에 값 삽입
	void push_back(const T& value)
	{
		cout << "push_back" << endl;
		if (size >= capacity)
		{
			reserve((capacity == 0) ? 1 : capacity * 2);
		}
		data[size++] = value; // 복사 대입 연산자
	}

	/// 마지막 요소 삭제
	void pop_back()
	{
		cout << "pop_back" << endl;
		if (size > 0)
		{
			data[--size].~T(); // 소멸자 호출
			--size;
		}
	}

	/// index에 요소 삽입
	void insert(size_t index, const T& value)
	{
		cout << "insert" << index << endl;
		if (index > size) throw out_of_range("Index out of range");

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
		cout << "erase" << index << endl;
		if (index >= size) throw out_of_range("Index out of range");

		data[index].~T();		   // 소멸자 호출

		for (size_t i = index; i < size - 1; ++i)
		{
			data[i] = data[i + 1]; // 복사 대입 연산자 호출
		}
		--size;
	}

	/// index의 요소 삭제 (요소의 이동 X)
	/// 순서가 중요하지 않은 배열 목록(게임오브젝트)라면 소멸자 호출 후 끝의 요소로 복사 대입하여 교체
	void erase_unordered(size_t index) {

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
	/// [index] 인덱스의 요소 반환
	T& operator[](size_t index)
	{
		if (index >= size) throw out_of_range("Index out of range");
		return data[index];
	}

	/// at(index) 인덱스의 요소 반한
	const T& at(size_t index) const
	{
		if (index >= size) throw out_of_range("Index out of range");
		return data[index];
	}

	/// 내부 배열의 전체 용량 반환
	size_t getCapacity() const
	{
		return capacity;
	}

	/// 현재 요소 개수 반환
	size_t getSize() const
	{
		return size;
	}

	/// 공백 상태 반환
	bool empty() const
	{
		return size == 0;
	}

	/// 배열의 첫번째 요소 반환
	T& front()
	{
		if (size == 0) throw out_of_range("Array is empty");
		return data[0];
	}

	/// 배열의 마지막 요소 반환
	T& back()
	{
		if (size == 0) throw out_of_range("Array is empty");
		return data[size - 1];
	}


	//DynamicArray(const DynamicArray& other);
	//DynamicArray& operator=(const DynamicArray& other);
	//DynamicArray(DynamicArray&& other) noexcept;
	//DynamicArray& operator=(DynamicArray&& other) noexcept;
	//void shrink_to_fit();
};
