#include <stdio.h>
#define SIZE 10
// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right);
void heapSort(int *numbers, int array_size);
void siftDown(int *numbers, int root, int bottom);
void input(int *a);

void result(int *a) ;
int main()
{
  int a[SIZE], a1[SIZE];
  // Заполнение массива случайными числами
  input(a); 
for (int i = 0; i < SIZE; i++) {
          a1[i] = a[i];
      }
  

  quickSort(a, 0, SIZE-1); // вызов функции сортировки
            // Вывод элементов массива после сортировки
  result(a);
   heapSort(a1, SIZE);
    result(a1);
  getchar();
  return 0;
}

void input(int *a) {
      for (int i = 0; i<SIZE; i++)
   scanf("%d", &a[i]);
}

void result(int *a) {
      for (int i = 0; i<SIZE; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void quickSort(int *numbers, int left, int right)
{
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = numbers[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу влево
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}