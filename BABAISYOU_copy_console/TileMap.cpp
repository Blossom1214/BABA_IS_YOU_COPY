#include "TileMap.h"
#include "Tile.h"
#include "TileBase.h"
#include "ObjectType.h"
#include "Position.h"
#include "Object.h"
#include <iterator>
#include <algorithm>
using namespace std;
TileMap::TileMap() :_height(0), _width(0), _tileMap(nullptr) //생성과 동시에 초기화하고
{
	LoadMap("../Stage/Stage1.txt"); //동적 배열 할당..
	
}

TileMap::~TileMap()
{
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			delete(*_tileMap)[i][j];
		}
	}
	//이제 소멸자에서 오브젝트가 동적할당되는 현상이있기때문에 2차원백터 내의 동적할당된 타일 오브젝트들을 하나씩 지워주는 작업을 해야해
	delete _tileMap; //배열같지만... 배열이 아님... 2차원 벡터타입을 받는...
	_tileMap = nullptr;
}

TileBase* TileMap::GetTile(const Position& pos)const
{
	
	return  (*_tileMap)[pos.s_y][pos.s_x];
}

void TileMap::SetTile(Position pos, TileBase* tile)
{
	(*_tileMap)[pos.s_y][pos.s_x] = tile;
}

void TileMap::LoadMap(const string& filemap)
{
	ifstream file(filemap);
	if (!file.is_open())
	{	
		cout << "파일 열기 실패" << endl;
		return;
	}
	else
	{
		file >> _width >> _height; //파일 입출력에도 똑같이 cin처럼 사용이가능 첫행의 1 2 번째를 불러와서 저장함
		file.ignore();//파일의 그 다음 행을 읽기위해서 개행을 만날때까지 버퍼까지 진행하는 함수를 실행함
		

		_tileMap = new vector<vector<TileBase*>>(_height, vector<TileBase*>(_width));
		for (int i = 0; i < _height ; ++i) //각 행의만큼 반복할것을 타일맵의 좌표에 집어넣는것
		{
			string line;
			getline(file, line);//해당 파일(스트림)에서 한줄을 읽어서 문자열에 저장함..
			for (int j = 0; j < _width; ++j)
			{
				TileBase* tile = new Tile();
				(*_tileMap)[i][j] = tile;
				if (j < line.length()) //line은 string컨테이너로 길이를 잴수가있음  따라서 라인의 j번째 문자를 ch에 저장하고
				{
					char ch = line[j];
					//TileType type = ConvertCharToTileType(ch); //해당 저장한 문자와 같은것을 찾으면 반환하고
					ObjectType type1 = ConvertCharToObjectType(ch);
					
					Position pos(j, i);
					tile->SetType(TileType::EMPTY);
					if (type1 != ObjectType::NONE)
					{
						Object* obj = new Object(type1, pos);
						tile->AddObject(obj);
					}
					
				}
				
			}
		}
		
	}
	file.close();
}

ObjectType TileMap::GetObjectTile(TileBase* tile) 
{
	const auto& objs = tile->GetObjects(); //해당위치의 타일
	if (!objs.empty())
	{
		return objs.back()->GetType();//해당위치의 오브젝트가있으면 가장 위에있는 오브젝트타입을 보여주어야함
	}
	return ObjectType::NONE; //없으면 결국 none이 되면서 아무것도 보이지않음..
}



//TileType TileMap::ConvertCharToTileType(char ch)
//{
//	switch (ch)
//	{
//	case '.':
//		return TileType::EMPTY;
//	case 'W':
//		return TileType::WALL;
//	case 'B': 
//		return TileType::BABA;
//	case 'F': 
//		return TileType::FLAG;
//	case 'R':
//		return TileType::ROCK;
//	case 'b': 
//		return TileType::TEXT_BABA;
//	case 'r':
//		return TileType::TEXT_ROCK;
//	case 'w':
//		return TileType::TEXT_WIN;
//	case 'y':
//		return TileType::TEXT_YOU;
//	case 'p':
//		return TileType::TEXT_PUSH;
//	case 's':
//		return TileType::TEXT_STOP;
//	case 'i':
//		return TileType::TEXT_IS;
//	case 'f':
//		return TileType::TEXT_FLAG;
//	default: 
//		return TileType::EMPTY;
//	}
//}
ObjectType TileMap::ConvertCharToObjectType(char ch)
{
	switch (ch)
	{
	case '.':
		return ObjectType::NONE;
	case 'W':
		return ObjectType::WALL;
	case 'B':
		return ObjectType::BABA;
	case 'F':
		return ObjectType::FLAG;
	case 'R':
		return ObjectType::ROCK;
	case 'b':
		return ObjectType::TEXT_BABA;
	case 'r': 
		return ObjectType::TEXT_ROCK;
	case 'w': 
		return ObjectType::TEXT_WIN;
	case 'y': 
		return ObjectType::TEXT_YOU;
	case 'p': 
		return ObjectType::TEXT_PUSH;
	case 's':
		return ObjectType::TEXT_STOP;
	case 'i':
		return ObjectType::TEXT_IS;
	case 'f':
		return ObjectType::TEXT_FLAG;
	default:
		return ObjectType::NONE;
	}
}
void TileMap::RenderMap()
{
	for (int i = 0; i < _height; ++i)
	{
 		for (int j = 0; j < _width; ++j)
		{
			(*_tileMap)[i][j]->Render();
			
		}
		cout << endl;
	}

}

Position TileMap::FindObject(ObjectType target)
{
	if (_tileMap == nullptr)
	{
		return Position(-1, -1);
	}
	for (int y = 0; y < _tileMap->size(); ++y) //행의 크기만큼
	{
		auto& row = (*_tileMap)[y]; //이터레이터를 몇번행으로 이동
		for (int x = 0; x < row.size(); ++x) //열의 길이만큼반복
		{
			const auto* tile = row[x]; //해당위치에있는 타일
			if (tile->HasObjectType(target))  //내가 찾고싶은 오브젝트타입이 참이면 해당위치를 반환하면됨...(물론 벡터로 되어있기에 함수에서확인해야함..)
			{
				return Position(x, y);
			}
		}
	}

	return Position(-1, -1);
}
bool TileMap::isInside(const Position& pos) const
{
	return pos.s_x >= 0 && pos.s_x < _width && pos.s_y >= 0 && pos.s_y < _height;
}

//void TileMap::InitializeMap() //초기화 테스트...
//{
//	_width = 5;
//	_height = 5;
//	_tileMap = new std::vector<std::vector<Tile>>(_height, std::vector<Tile>(_width));
//	(*_tileMap)[1][1].SetObject(ObjectType::BABA);
//	(*_tileMap)[1][1].SetType(TileType::BABA);
//	(*_tileMap)[1][2].SetType(TileType::TEXT_BABA);
//	(*_tileMap)[1][3].SetType(TileType::TEXT_IS);
//	(*_tileMap)[1][4].SetType(TileType::TEXT_YOU);
//	(*_tileMap)[2][1].SetType(TileType::WALL);
//	(*_tileMap)[2][2].SetType(TileType::WALL);
//	(*_tileMap)[3][1].SetType(TileType::ROCK);
//	(*_tileMap)[3][2].SetType(TileType::TEXT_IS);
//	(*_tileMap)[3][3].SetType(TileType::TEXT_PUSH);
//	(*_tileMap)[4][1].SetType(TileType::FLAG);
//	(*_tileMap)[4][2].SetType(TileType::TEXT_IS);
//	(*_tileMap)[4][3].SetType(TileType::TEXT_WIN);
//}

