#include "TestLevel.h"

UTestLevel::UTestLevel()
{
	//opening 대사  script
	Script.push_back("한낮의 회색빛 하늘 아래......");
	Script.push_back("이브와 그녀의 부모님은 미술관으로 가고 있었습니다......");
	Script.push_back("'잊은건 없니? 이브'");
	Script.push_back("'맞다, 손수건은 챙겼니?\n        있잖아, 생일선물로 줬던거'");
	Script.push_back("'주머니 안에 잘 챙겨둬야 해? 잃어버리면 안 된다'");

	// 엄마 오른쪽에서 이브쪽 바라본 후 대사
	Script.push_back("자. 도착했네\n......이브는 미술관 처음 와보지?");//엄마 살짝 웃는표정
	Script.push_back("오늘 보러 온 건\n'게르테나'라는 사람의 전시회인데......");//엄마 입벌린 표정
	Script.push_back("그림 말고도 조각이라든가......\n여러 재미있는 작품들이 있는 것 같으니까");//엄마 살짝 웃는표정
	Script.push_back("분명 이브도 재밌게 볼 수 있을 거야");//엄마 활짝 웃는 표정
	//아빠 뒤돌고 대사
	Script.push_back("접수하고 올까?");//아빠 살짝 웃는 표정
	Script.push_back("그래\n그리고 전단지도 받아가자");//엄마 살짝 웃는표정

	//엄마 아빠 걸어나와서 프론트에 나란히 선다.
	//이후에 이브도 엄마 옆으로 가서 나란히 선다.
	//이브가 오른쪽 엄마쪽으로 돌아서고, 엄마도 이브를 돌아 본 후
	Script.push_back("응? 먼저 보고 있겠다고?\n정말, 이브도 참......어쩔 수 없네");//엄마 살짝 당황표정
	Script.push_back("미술관 안에서는 조용히 해야한다??\n알겠지?");//엄마 단호한 표정
	Script.push_back("......뭐, 너라면 걱정 없지만");//엄마 살짝 웃는표정
	Script.push_back("다른 사람들한테 민폐를 끼치지 않도록 주의하렴");//엄마 살짝 웃는표정
	//엄마 앞을 본다. 이브 자유시간

}

UTestLevel::~UTestLevel()
{
}
