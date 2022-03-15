# include <stdio.h>
void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_pointer(void)
{
	// 포인터

	// [병민] 101호
	// [여진] 201호
	// [영준] 301호
	// 각 문 앞에 '암호'가 걸려있음
	/*int 병민 = 1; 
	int 여진 = 2;
	int 영준 = 3;

	printf("병민이네 주소 : %d, 암호 : %d\n", &병민, 병민);
	printf("여진이네 주소 : %d, 암호 : %d\n", &여진, 여진);
	printf("영준이네 주소 : %d, 암호 : %d\n", &영준, 영준);*/

	// 미션맨

	// 첫번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
	//int* 미션맨; // 포인터 변수
	//미션맨 = &병민;
	//printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &여진;
	//printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &영준;
	//printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	// 두번째 미션 : 각 암호에 3을 곱해라
	/*미션맨 = &병민;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &여진;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영준;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);*/

	// 스파이
	// 미션맨이 바꾼 암호에서 2를 빼라
	/*int* 스파이 = 미션맨;
	printf("%d, %d", 스파이, 미션맨);
	printf("\n... 스파이가 미션을 수행 중 입니다... \n\n");
	스파이 = &병민;
	*스파이 = *스파이 - 2; // 병민 = 병민 - 2
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &여진;
	*스파이 = *스파이 - 2; 
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &영준;
	*스파이 = *스파이 - 2; 
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);*/

	/*printf("\n병민, 여진, 영준은 집에 오고서 바뀐 암호를 보고 놀람\n\n");

	printf("병민이네 주소 : %d, 암호 : %d\n", &병민, 병민);
	printf("여진이네 주소 : %d, 암호 : %d\n", &여진, 여진);
	printf("영준이네 주소 : %d, 암호 : %d\n", &영준, 영준);*/

	// 참고로, 미션맨이 사는 곳의 주소는 &미션맨으로 확인
	/*printf("미션맨의 주소 : %d\n", &미션맨);
	printf("스파이의 주소 : %d\n", &스파이);*/

	// 배열
	/*int arr[3] = {5, 10, 15};
	int* ptr = arr;
	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
	}

	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;
	for (int i = 0; i < 3; i++)
	{
		//printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
		printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i));
	}
	for (int i = 0; i < 3; i++)
	{
		//printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
		printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i));
	}*/
	// *(arr + i) == arr[i] 똑같은 표현
	// arr = arr 배열의 첫번쨰 값의 주소와 동일 == &arr[0]
	/*printf("arr 자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);
	printf("arr[1]의 주소 : %d\n", &arr[1])
	printf("arr[2]의 주소 : %d\n", &arr[2]);*/

	//printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); //*(arr + 0) 
	//printf("arr[0]의 실제 값 : %d\n", *&arr[0]); //*주소 = 실제값 => *&특정값 == 특정값 
	// *&은 아무것도 없는 것과 같다. &는 주소이며, *은 그 주소에 해당하는 값이기 때문에. 서로 상쇄된다
	//printf("arr[0]의 실제 값 : %d\n", *&*&*&*&*&*&arr[0]);
	//printf("arr[0]의 실제 값 : %d\n", arr[0]);

	// SWAP
	//int a = 10;
	//int b = 20;
	//printf("a의 주소 : %d\n", &a);
	//printf("b의 주소 : %d\n", &b);

	//// a와 b의 값을 바꾼다
	//printf("Swap 함수 전 => a : %d, b : %d\n", a, b);
	//swap(a, b);
	//printf("Swap 함수 후 => a : %d, b : %d\n", a, b); // 출력 값 변화 없음
	//// 값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미

	//// 주소값을 넘기면? 메모리 공간에 있는 주소값을 넘기면..
	//printf("{주소값 전달} swap 함수 전 => a : %d, b : %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("{주소값 전달} swap 함수 후 => a : %d, b : %d\n", a, b);
	
	
	// 배열일 때, arr2 -> 주소
	int arr2[3] = { 10, 20, 30 };
	//changeArray(arr2);
	changeArray(& arr2[0]); //arr2의 값은 arr2의 첫번째 값의 주소와 같다
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	// scanf에서 &num과 같이 &를 사용하는 이유

	return 0;
}

void swap(int a, int b)
{
	printf("<swap 함수 내> a의 주소 : %d\n", &a);
	printf("<swap 함수 내> b의 주소 : %d\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내 => a : %d, b : %d\n", a, b);
}

void swap_addr(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("<주소값 전달> swap 함수 내 => a : %d, b : %d\n", *a, *b);
}

void changeArray(int *ptr) 
{
	ptr[2] = 50;
}