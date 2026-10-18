#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zcq {
    template<class T>
    class vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        vector()
            :_start(nullptr)
            , _finish(nullptr)
            , _end_of_storage(nullptr) {

        }

        vector(initializer_list<T> il) {
            reserve(il.size());
            for (auto& x : il) {
                push_back(x);
            }

        }

        vector(const vector<T>& v) {
            vector<T> temp(v.begin(), v.end());
            //swap(_start, temp._start);//成员函数可以直接访问同类对象里的私有成员
            //swap(_finish, temp._finish);
            //swap(_end_of_storage, temp._end_of_storage);
            Swap(temp);
        }

        vector(size_t n, const T& val) {
            reserve(n);
            iterator it = _start;
            while (it != _end_of_storage) {
                *it = val;
                ++it;
            }
            _finish = _start + n;
        }

        ~vector() {
           //这里的判断语句并不能解决浅拷贝问题(对象不一样，_start就不是同一个)
            if (_start) {
                delete[] _start;//它们指向的都是同一块内存，所以只需要delete一次就够了
                _start = nullptr;
                _finish = nullptr;
                _end_of_storage = nullptr;
            }
        }
        template<class Inputiterator>
        vector(Inputiterator first, Inputiterator last) {
            Inputiterator fi = first;
            while (fi != last) {
                push_back(*fi);
                ++fi;
            }
        }

        vector<T>& operator= (const vector<T>& v) {
            vector<T> temp(v);
            Swap(temp);
            return *this;
        }

        void Print();

        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        const_iterator begin() const{
            return _start;
        }

        const_iterator end() const{
            return _finish;
        }

        iterator storage_end() {
            return _end_of_storage;
        }

        void Swap(vector<T>& v) {
            swap(_start, v._start);
            swap(_finish, v._finish);
            swap(_end_of_storage, v._end_of_storage);
        }
        
        size_t size() {
            return _finish - _start;
        }

        size_t capacity() {
            return _end_of_storage - _start;
        }

        T& operator[](size_t pos) {
            assert(pos < size());
            return *(_start + pos);//等价于_start[pos]
        }
        const T& operator[](size_t pos)const {
            assert(pos < size());
            return *(_start + pos);
        }

        void reserve(size_t n);
        void resize(size_t n, const T& x);
        void push_back(const T& x);
        void pop_back();
        bool empty();
        void insert(iterator pos, const T& x);
        //涉及迭代器失效问题
        iterator erase(iterator pos);

    private:
        iterator _start;
        iterator _finish;//最后一个元素的下一个位置
        iterator _end_of_storage;//空间大小
    };
    //类外定义每个函数前都要加模板
    template<class T>
    void vector<T>::reserve(size_t n) {
        if (n > capacity()) {
            size_t old_size = size();//注意变量和函数不要同名，会报错
            iterator temp = new T[n];
            for (size_t i = 0; i < old_size; ++i) {
                temp[i] = _start[i];
            }
            delete[] _start;
            _start = temp;
            _finish = _start + old_size;
            _end_of_storage = _start + n;
        }
    }

    template<class T>
    void vector<T>::resize(size_t n, const T& x) {
        if (n > capacity()) {
            reserve(n);
        }
        if (n > size()) {
            while (_finish != _start + n) {//_finish != _end_of_storage错误，n<capacity()时，这个条件会导致resize个数到capacity()个
                *_finish = x;
                ++_finish;
            }
        }
        else {
            _finish = _start + n;
        }
    }

    template<class T>
    void vector<T>::push_back(const T& x) {
        if (size() == capacity()) {
            reserve(capacity() == 0 ? 4 : capacity() * 2);
        }
        *_finish = x;
        ++_finish;
    }

    template<class T>
    bool vector<T>::empty() {
        return _start == _finish;
    }

    template<class T>
    void vector<T>::pop_back() {
        assert(!empty());
        --_finish;
    }

    template<class T>
    void vector<T>::Print() {
        
        for (size_t i = 0; i < size(); ++i) {
            cout << this->operator[](i) << ' ';
        }
    }

    template<class T>
    void vector<T>::insert(iterator pos, const T& x) {
        assert(pos >= _start && pos <= _finish);
        size_t len = pos - _start;
        if (size() == capacity()) {
            reserve(capacity() == 0 ? 4 : capacity() * 2);
        }
        iterator end = _finish;
        pos = _start + len;
        while (end != pos) {
            *end = *(end - 1);
            --end;
        }
        *pos = x;
        ++_finish;
    }


    template<class T>
   typename vector<T>::iterator vector<T>::erase(iterator pos) {
        assert(pos >= _start && pos < _finish);
        iterator it = pos + 1;
        while (it != _finish ) {
            *(it - 1) = *it;
            ++it;
        }
        --_finish;
        return pos;
    }
}
