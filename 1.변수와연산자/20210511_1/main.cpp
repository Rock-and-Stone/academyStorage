#include <iostream>

using namespace std;

int main()
{
	//변수란 == 변하는 수다
	//영어로(variable)

	//정수형 변수
	//변수타입			크기				범위
	//int				4Byte		-22억 ~ 21억까지의 범위
	//unsigned int		4Byte		0 ~ 43억까지의 범위
	//long				4Byte		-22억 ~ 21억까지의 범위
	//unsigned long		4Byte		0 ~ 43억까지의 범위
	//short				2Byte		-32768 ~ 32767 범위
	//unsigned short	2Byte		0 ~ 65535 범위

	//실수형 변수 -> 소수점
	//float				4Byte		소수점 6짜리까지의 실수를 담음
	//double			8Byte		소수점 15짜리까지의 실수를 담음

	//문자형 변수
	//char (촤~ X 캐릭터O)1Byte		정수를 담는다(문자)
	//unsigned char		1Byte		양의 정수를 담는다(문자)

	//참,거짓
	//bool				1byte		참(1), 거짓(0)

	//변수 선언시 주의점
	//1. 초기화를 하자 (안하면 쓰레기값이 들어있다)
	//2. 변수명은 중복될수 없다
	//3. 변수명 앞에 숫자는 쓸수없다
	//4. 줴에봐알 알아먹을 수 있게 좀....
	//5. 변수명은 영어로 합시다 

	int elfHP = 100;
	int elfMP = 100;
	float elfSpeed = 3.5f;
	bool isLive = true;

	//1. 헝가리안 표기법
	//아주 예전에 절차지향적 코딩방식이 유행할때
	//선언된 변수의 타입이 헷갈리는 경우 재차 확인을 할때
	//시간 소모 라던지 코드 가독성이 안좋았기 때문에
	//나온 방식이다 int는 n, float은 f, bool은 b 로 약칭을 달았다.
	//예) int number -> int nNumber, float speed -> float fSpeed;

	//2. 카멜식 표기법
	//최근 객체지향적 코딩방식이 유행하면서 코드의 줄 수가
	//상대적으로 짧아지게 되었다.
	//변수명을 정의할때 첫문장은 소문자 그이후에 문장의 앞글자만
	//대문자로 표기해 낙타 혹처럼 볼록볼록 튀어나와보여서 카멜식이라함
	//예) int selectNum;

	return 0;
}