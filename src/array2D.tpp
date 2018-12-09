template <typename T>
Array2D<T>::Array2D(int pwidth, int pheight) : width(pwidth), height(pheight) {
  items.resize(width * height);
}

template <typename T> T &Array2D<T>::operator[](const Vec &index) {
  return items.at(index.x * height + index.y);
}