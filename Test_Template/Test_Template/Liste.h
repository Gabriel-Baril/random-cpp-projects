#pragma once
template<class T>
class Liste {
public:
	Liste(T obj);
	T get();
private:
	T obj;
};

template<class T>
inline Liste<T>::Liste(T obj) {
	this->obj = obj;
}

template<class T>
inline T Liste<T>::get() {
	return this->obj;
}
