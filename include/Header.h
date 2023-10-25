#include <iostream>


using namespace std;


template <class T>
class Stack {
    T* begin;
    T* end;
    int size;
public:   Stack() {
    size = 100;
    begin = new T[size];
    end = begin;
}
      Stack(int _n) {
          if (_n < 0) throw invalid_argument("Error");
          size = _n;
          begin = new T[size];
          end = begin;
      }

      Stack(const Stack& s):size(s.size) {
          begin = new T[size]{};
          for (int i = 0; i < size; i++) {
              begin[i] = s.begin[0];
              end = begin + (s.end - s.begin);
          }
      }
      ~Stack() {
          delete[] begin;
      }
      void Push(T el) {
          if (end - begin == size) {
              size = size * 1.3;
              T* tmp = new T[size];
              for (int i = 0; i < (end - begin); i ++ ) {
                  tmp[i] = begin[i];
              }
              end = tmp + (end - begin);
              delete[]begin;
              begin = tmp;
          }
          *end = el;
          end++;
      }
      T top() {
          if (!isEmpty())
              return *(end-1);
          else throw
              out_of_range("...");
      }
      void Pop() {
          if (begin == end) {
              throw - 1;
          }
          else {
              end--; 
          }
      }
      bool isEmpty() {
          return begin == end;
      }
      int Size() {
          return size;
      }
      bool operator ==(const Stack& s) {
          if (s.end - s.begin == end - begin) {
              for (int i = 0; i < end - begin; i++) {
                  if (begin[i] != s.begin[i])
                      return false;
                  else
                      return false;
                  return true;
              }
          }
      }
      friend ostream& operator<<(ostream& out, const Stack& st) {
          for (int i = 0; i < (st.end - st.begin); i++)
              cout << st.begin[i];
          return out;
      }
};