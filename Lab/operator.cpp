// TODO
template <typename T>
T& Array<T>::operator[](int idx) {
  if (idx < 0 || idx >= size) {
    throw -1;
  }
  return p[idx];
}
