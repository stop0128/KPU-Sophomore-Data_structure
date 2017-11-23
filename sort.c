//#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_SIZE 10000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selecting_sort(int list[], int n)				// 선택 정렬 함수(정렬할 배열, 배열의 최대 크기)
{
	int i, j, least, temp;							

	for(i = 0; i < n - 1; i++)
	{
		least = i;
		for(j = i + 1; j < n; j++)
		{
			if (list[j] < list[least]) least = j;
		}
		SWAP(list[i], list[least], temp);
   }
}

void insertion_sort(int list[], int n)				// 삽입 정렬 함수(정렬할 배열, 배열의 최대 크기)(대부분의 레코드가 이미 정렬되어있는경우 효율적)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = list[i];

		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
      
	}
}

void bubble_sort(int list[], int n)					// 버블 정렬 함수(정렬할 배열, 배열의 최대 크기)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		if (list[j] > list[j + 1])
			SWAP(list[j], list[j + 1], temp);
	}
}

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do{
		do{
			low++;
		}while(low <= right && list[low] < pivot);
		do{
			high--;
		}while(high >= left && list[high] > pivot);
		if(low < high){
			SWAP(list[low], list[high], temp);
		}
	}while(low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){
		int q = partition(list, left, right);
		quick_sort(list, left, q-1);
		quick_sort(list, q+1, right);
	}
}

void file_insert(FILE *file ,int *list, int max)
{
	int i;
	if(file == 0)
	{
		printf("실패 \n");
		return;
	}
	for(i = 0; i<max; i++)
	{
		fprintf(file, " %d", list[i]);
	}
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;      // i 는 정렬된 왼쪽리스트의 인덱스, j는 정렬된 오른쪽리스트의 인덱스, k를 정렬될 리스트에대한 인덱스
	int sorted[10000];
	int sorted2[50000];
	int sorted3[100000];

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]){ 
			sorted[k++] = list[i++];
		}
		else{ 
			sorted[k++] = list[j++];
		}
	}

    if (i > mid){
		for (l = j; l <= right; l++){ 

			sorted[k++] = list[l];
		}
	}
	else{
		for (l = i; l <= mid; l++){ 
			sorted[k++] = list[l];
		}
	}          
	for (l = left; l <= right; l++){ 
		list[l] = sorted[l];
	}

}

void merge_sort(int list[], int left, int right) {
   int mid;
   if (left < right) {
      mid = (left + right) / 2;
      merge_sort(list, left, mid);
      merge_sort(list, mid + 1, right);
      merge(list, left, mid, right);
   }
}

int main() {

	FILE *file11 = fopen("selecting sort-1.txt", "at");
	FILE *file12 = fopen("selecting sort-5.txt", "at");
	FILE *file13 = fopen("selecting sort-10.txt", "at");
	FILE *file21 = fopen("insertion sort-1.txt", "at");
	FILE *file22 = fopen("insertion sort-5.txt", "at");
	FILE *file23 = fopen("insertion sort-10.txt", "at");
	FILE *file31 = fopen("bubble sort-1.txt", "at");
	FILE *file32 = fopen("bubble sort-5.txt", "at");
	FILE *file33 = fopen("bubble sort-10.txt", "at");
	FILE *file41 = fopen("merge sort-1.txt", "at");
	FILE *file42 = fopen("merge sort-5.txt", "at");
	FILE *file43 = fopen("merge sort-10.txt", "at");
	FILE *file51 = fopen("quick sort-1.txt", "at");
	FILE *file52 = fopen("quick sort-5.txt", "at");
	FILE *file53 = fopen("quick sort-10.txt", "at");

	int list1[10000];
	int	list2[50000];
	int list3[100000];
	int n, n2, n3;
	int i;
	int sel = 0, sel2 = 0;
	int z = 0;
	n = MAX_SIZE;
	n2 = MAX_SIZE*5;
	n3 = MAX_SIZE*10;

	for (i = 0; i < n; i++) {
		list1[i] = rand() % n;
	}
	for (i = 0; i < n2; i++) {
		list2[i] = rand() % n2;
	}
	for (i = 0; i < n3; i++) {
		list3[i] = rand() % n3;
	}
	while(1){
   printf("**************\nSelect sort\n1. 선택정렬\n2. 삽입정렬\n3. 버블정렬\n4. 합병정렬\n5. 퀵정렬\n**************\ninsert number : ");
   scanf("%d", &sel);
   switch (sel) {
      case 1 :
		  system("cls");
		  printf("**************\nselecting sort\nSelect data\n1. 10,000\n2. 50,000\n3. 100,000\n**************\ninsert number : ");
		  scanf("%d", &sel2);
		  switch (sel2){
			case 1 :
				selecting_sort(list1, n);
				file_insert(file11, list1, n);
				break;
			case 2 :
				selecting_sort(list2, n2);
				file_insert(file12, list2, n2);
				break;
			case 3 :
				selecting_sort(list3, n3);
				file_insert(file13, list3, n3);
				break;
			default :
				printf("올바른 입력이 아닙니다.");
				break;
		  }
        break;
      case 2 :
		  system("cls");
		  printf("**************\ninsertion sort\nSelect data\n1. 10,000\n2. 50,000\n3. 100,000\n**************\ninsert number : ");
		  scanf("%d", &sel2);
		  switch (sel2){
			case 1 :
				insertion_sort(list1, n);
				file_insert(file21, list1, n);
				break;
			case 2 :
				insertion_sort(list2, n2);
				file_insert(file22, list2, n2);
				break;
			case 3 :
				insertion_sort(list3, n3);
				file_insert(file23, list3, n3);
				break;
			default :
				return printf("올바른 입력이 아닙니다.");
		  }
         break;
      case 3 :
		  system("cls");
		  printf("**************\nbubble sort\nSelect data\n1. 10,000\n2. 50,000\n3. 100,000\n**************\ninsert number : ");
		  scanf("%d", &sel2);
		  switch (sel2){
			case 1 :
				bubble_sort(list1, n);
				file_insert(file31, list1, n);
				break;
			case 2 :
				bubble_sort(list2, n2);
				file_insert(file32, list2, n2);
				break;
			case 3 :
				bubble_sort(list3, n3);
				file_insert(file33, list3, n3);
				break;
			default :
				return printf("올바른 입력이 아닙니다.");
		  }
         break;
      case 4 :
		  system("cls");
		  printf("**************\nmerge sort\nSelect data\n1. 10,000\n2. 50,000\n3. 100,000\n**************\ninsert number : ");
		  scanf("%d", &sel2);
		  switch (sel2){
			case 1 :
				merge_sort(list1, 0, n-1, n);
				file_insert(file41, list1, n);
				break;
			case 2 :
				merge_sort(list2, 0, n2-1, n2);
				file_insert(file42, list2, n2);
				break;
			case 3 :
				merge_sort(list3, 0, n3-1, n3);
				file_insert(file43, list3, n3);
				break;
			default :
				return printf("올바른 입력이 아닙니다.");
		  }
		  break;
	  case 5:
		  system("cls");
		  printf("**************\ninsertion sort\nSelect data\n1. 10,000\n2. 50,000\n3. 100,000\n**************\ninsert number : ");
		  scanf("%d", &sel2);
		  switch (sel2){
			case 1 :
				quick_sort(list1, 0, n-1);
				file_insert(file51, list1, n);
				break;
			case 2 :
				quick_sort(list2, 0, n2-1);
				file_insert(file52, list2, n2);
				break;
			case 3 :
				quick_sort(list3, 0, n3-1);
				file_insert(file53, list3, n3);
				break;
			default :
				return printf("올바른 입력이 아닙니다.");
		  }
		  break;
      default :
         return printf("올바른 입력이 아닙니다.");      
   }}

   
	fclose(file11);
	fclose(file12);
	fclose(file13);
	fclose(file21);
	fclose(file22);
	fclose(file23);
	fclose(file31);
	fclose(file32);
	fclose(file33);
	fclose(file41);
	fclose(file42);
	fclose(file43);
	fclose(file51);
	fclose(file52);
	fclose(file53);

	_getch();
	return 0;
}

