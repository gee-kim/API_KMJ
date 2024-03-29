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


	// 프론트데스트 대사
	Script.push_back("게르테나전의 전단지가 걸려있다......");
	Script.push_back("게르테나전 말고 다른 전시회의 전단지다......");
	Script.push_back("많은 전단지가 쌓여있다......");
	Script.push_back("다양한 그림의 엽서를 팔고 있다......");

	// 폰보는 초록머리
	Script.push_back("흐음......\n   이게 잡지 같은 거에 자주 실리는 그건가");
	// 머리묶은 아줌마
	Script.push_back("이 작품, 내 눈으로 직접 보고 싶었어!");
	Script.push_back("역시 책에서 보는 거랑은 전혀 다르네......\n   분위기가 정말...... 무슨 소리인지......알지!");
	//갈색머리
	Script.push_back("지상에서 볼 수 있는 심해라......");
	//심해 안내판
	Script.push_back("[ 심해의 ?? ]");
	Script.push_back("사람이 들어가는 게 허락되지 않는 그 세계를\n ? ? 하기 위해 나는 캔버스 안에서 그 세계를 ? ? 했지");
	//파랑 머리
	Script.push_back("왠지 이 바닥 바로 밑에\n   정말로 물고기가 헤엄치고 있는 것 같아......");
	Script.push_back("이런 게 실존하면 지릴 것 같은데......");
	//할머니
	Script.push_back("꽤나 커다란 작품이네......");
	//핑크니트언니
	Script.push_back("뭔가 빨려들어갈 것 같은 느낌이 들어서 조금은 무서울지도......");


	// 장미 뒤에 남자
	Script.push_back("이 작품은 대단하지만\n   좀 더 위쪽에서 내려다 보고 싶네......");
	// 장미 왼쪽 남자
	Script.push_back("이거, 작은 충격으로\n   저 줄기 부분이 부러지거나 하는 건 아니겠지......");
	Script.push_back("만약 그렇게 되면 대체 얼마를 변상해야 하는 걸까......\n   우와-, 무서워라......");

}

UTestLevel::~UTestLevel()
{
}
