Psuedocode of Bubble sort algorithm:

```
procedure bubbleSort( A : list of sortable items )
   n = length(A)
   repeat
     swapped = false
     for i = 1 to n-1 inclusive do
       /* if this pair is out of order */
       if A[i-1] > A[i] then
         /* swap them and remember something changed */
         swap( A[i-1], A[i] )
         swapped = true
       end if
     end for
   until not swapped
end procedure
```

Optimised so it doesn't have to check the final n-1 time:

```
procedure bubbleSort( A : list of sortable items )
    n = length(A)
    repeat
       swapped = false
       for i = 1 to n-1 inclusive do
          if A[i-1] > A[i] then
             swap(A[i-1], A[i])
             swapped = true
          end if
       end for
       n = n - 1
    until not swapped
end procedure
```


Top down Merge Sort:

```
// Array A[] has the items to sort; array B[] is a work array.
TopDownMergeSort(A[], B[], n)
{
    TopDownSplitMerge(A, 0, n, B);
}

// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
TopDownSplitMerge(A[], iBegin, iEnd, B[])
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
    iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // split / merge left  half
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // split / merge right half
    TopDownMerge(A, iBegin, iMiddle, iEnd, B);  // merge the two half runs
    CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
}

//  Left half is A[iBegin:iMiddle-1].
// Right half is A[iMiddle:iEnd-1   ].
TopDownMerge(A[], iBegin, iMiddle, iEnd, B[])
{
    i = iBegin, j = iMiddle;

    // While there are elements in the left or right runs...
    for (k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    }
}

CopyArray(B[], iBegin, iEnd, A[])
{
    for(k = iBegin; k < iEnd; k++)
        A[k] = B[k];
}
```

Bottom up Merge Sort:

```
// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(A[], B[], n)
{
  // Each 1-element run in A is already "sorted".
  // Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
  for (width = 1; width < n; width = 2 * width)
    {
      // Array A is full of runs of length width.
      for (i = 0; i < n; i = i + 2 * width)
        {
          // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
          // or copy A[i:n-1] to B[] ( if(i+width >= n) )
          BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
      // Now work array B is full of runs of length 2*width.
      // Copy array B to array A for next iteration.
      // A more efficient implementation would swap the roles of A and B.
      CopyArray(B, A, n);
      // Now array A is full of runs of length 2*width.
    }
}

//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
BottomUpMerge(A[], iLeft, iRight, iEnd, B[])
{
    i = iLeft, j = iRight;
    // While there are elements in the left or right runs...
    for (k = iLeft; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    }
}

void CopyArray(B[], A[], n)
{
    for(i = 0; i < n; i++)
        A[i] = B[i];
}
```
