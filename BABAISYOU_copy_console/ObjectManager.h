#pragma once
#include <vector>
#include <string>
class TileMap;
class Object;
struct Position;
class ObjectManager
{
public:
	ObjectManager(TileMap* map);
	~ObjectManager();
public:

	std::vector<Object*> GetObjectsWithRule(const std::string& rule);//플레이가능한지 확인
	//움직일수있는지?(push나...stop이런걸 만나면 다르게 동작해야하기때문)
	void ApplyWinCondition();
	
private:
	const TileMap* _Map;
};
//생각해보면 이미 플레이어캐릭터는 앞에위치하고있는 블록의 타입이 밀수있는지 없는지 여부는 이미 판단했음
//이제 그 오브젝트 뒤에가 밀수있는지 없는지 여부를판단해줘야하는것...
//왜냐면 내 앞의 블록으로 나는 이미 이동할거고 그럼 그위치에있던 블록을 그 뒤의 위치로 이동시켜줘야하기때문에
//이동할수있는지 없는지 여부부터 확인을해야함.. 내앞의 블록이 푸시할수있다면 푸시할것임..

//푸시는 결국 nextpos에 있는 정보가 밀수있는 블록이면 try push를 실행해야함
//이때의 예외조건이 필요
//재귀적 호출로 뒤에있는 블록도 밀수있는 블록으로 지정되어있으면 그 블록도 push로 호출해서 밀어야함
//또한 뒤에 outbound이거나 stop블록의 경우에도 블록이 밀려나가는 오류가잇으면안됨...
//규칙이 하나 더있음 푸시와 스탑 둘다있을때의 우선순위는 스탑이 더 우선순위가 빠름...
//반드시 is blocked를 체크하고 그다음 trypush를 호출해줘야함
//현재 아웃바운드 오류체크가 안된거같음...
//이제는 플래그를 먹으면 이겨야하는데
