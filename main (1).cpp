#include<iostream>
using namespace std;
class BinaryHeap
{
public:
  int csize;
  int msize;
  int *arr;

    BinaryHeap (int msize)
  {
    this->msize = msize;
    csize = 0;
    arr = new int[msize];
  }

  void swap (int *a, int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  int parent (int i)
  {
    return ((i - 1) / 2);
  }
  int rchild (int i)
  {
    return ((2 * i) + 2);
  }
  int lchild (int i)
  {
    return ((2 * i) + 1);
  }

  int getmin ()
  {
    return arr[0];
  }


  void insert (int value)
  {

    if (csize >= msize)
      cout << "Heap overflow!" << endl;
    else
      {
	csize++;
	arr[csize - 1] = value;
	for (int i = csize - 1; i >= 0; i--)
	  {

	    if (arr[i] < arr[parent (i)])
	      {
		swap (arr + i, arr + parent (i));
	      }
	    else
	      continue;
	  }

      }

  }

  void sort (int a)
  {
    if (lchild (a) > csize - 1
	|| (arr[lchild (a)] > arr[a] && arr[rchild (a)] > arr[a]))
      return;

    else if (lchild (a) == csize - 1)
      swap (arr + a, arr + lchild (a));

    else
      {

	if (arr[lchild (a)] < arr[rchild (a)])
	  {
	    swap (arr + a, arr + lchild (a));
	    sort (lchild (a));
	  }
	else
	  {
	    swap (arr + a, arr + rchild (a));
	    sort (rchild (a));
	  }

      }
  }



  void extractmin ()
  {
    swap (arr, arr + (csize - 1));
    csize--;
    sort (0);
  }


  void del (int i)
  {
    swap (arr + i, arr + csize - 1);
    csize--;
    sort (i);
  }


  void decreaseKey (int i, int newval)
  {
    arr[i] = newval;
    sort (parent (i));
  }

  void display ()
  {

    for (int i = 0; i <= csize - 1; i++)
      {
	cout << arr[i] << "->";
      }
    cout << endl;
  }



};



int
main ()
{

  BinaryHeap b1 (30);
  int i = 0;

  while (i < 10)
    {
      b1.insert (i);
      i++;
    }

  b1.display ();

  b1.decreaseKey (2, 2);
  b1.display ();




}