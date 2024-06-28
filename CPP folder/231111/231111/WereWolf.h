#pragma once
#include "Human.h"
#include "Wolf.h"


// 다중 상속.
class WereWolf : public Wolf, public Human
{
public: // show가 울프와 휴먼에서 겹쳐도 상관 없음. why? 순수가상메서드 비어있을 뿐만 아니라 부모에서 받아온 메서드를 재정의 해야하기 때문에
	void Show();

public :
	WereWolf(const char* name);
	~WereWolf() = default;
};

