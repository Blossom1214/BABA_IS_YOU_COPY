#include "TileMap.h"
#include "Tile.h"
#include "TileBase.h"
#include "ObjectType.h"
#include "Position.h"
#include "Object.h"
#include <iterator>
#include <algorithm>
using namespace std;
TileMap::TileMap() :_height(0), _width(0), _tileMap(nullptr) //������ ���ÿ� �ʱ�ȭ�ϰ�
{
	LoadMap("../Stage/Stage1.txt"); //���� �迭 �Ҵ�..
	
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
	//���� �Ҹ��ڿ��� ������Ʈ�� �����Ҵ�Ǵ� �������ֱ⶧���� 2�������� ���� �����Ҵ�� Ÿ�� ������Ʈ���� �ϳ��� �����ִ� �۾��� �ؾ���
	delete _tileMap; //�迭������... �迭�� �ƴ�... 2���� ����Ÿ���� �޴�...
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
		cout << "���� ���� ����" << endl;
		return;
	}
	else
	{
		file >> _width >> _height; //���� ����¿��� �Ȱ��� cinó�� ����̰��� ù���� 1 2 ��°�� �ҷ��ͼ� ������
		file.ignore();//������ �� ���� ���� �б����ؼ� ������ ���������� ���۱��� �����ϴ� �Լ��� ������
		

		_tileMap = new vector<vector<TileBase*>>(_height, vector<TileBase*>(_width));
		for (int i = 0; i < _height ; ++i) //�� ���Ǹ�ŭ �ݺ��Ұ��� Ÿ�ϸ��� ��ǥ�� ����ִ°�
		{
			string line;
			getline(file, line);//�ش� ����(��Ʈ��)���� ������ �о ���ڿ��� ������..
			for (int j = 0; j < _width; ++j)
			{
				TileBase* tile = new Tile();
				(*_tileMap)[i][j] = tile;
				if (j < line.length()) //line�� string�����̳ʷ� ���̸� ���������  ���� ������ j��° ���ڸ� ch�� �����ϰ�
				{
					char ch = line[j];
					//TileType type = ConvertCharToTileType(ch); //�ش� ������ ���ڿ� �������� ã���� ��ȯ�ϰ�
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
	const auto& objs = tile->GetObjects(); //�ش���ġ�� Ÿ��
	if (!objs.empty())
	{
		return objs.back()->GetType();//�ش���ġ�� ������Ʈ�������� ���� �����ִ� ������ƮŸ���� �����־����
	}
	return ObjectType::NONE; //������ �ᱹ none�� �Ǹ鼭 �ƹ��͵� ����������..
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
	for (int y = 0; y < _tileMap->size(); ++y) //���� ũ�⸸ŭ
	{
		auto& row = (*_tileMap)[y]; //���ͷ����͸� ��������� �̵�
		for (int x = 0; x < row.size(); ++x) //���� ���̸�ŭ�ݺ�
		{
			const auto* tile = row[x]; //�ش���ġ���ִ� Ÿ��
			if (tile->HasObjectType(target))  //���� ã����� ������ƮŸ���� ���̸� �ش���ġ�� ��ȯ�ϸ��...(���� ���ͷ� �Ǿ��ֱ⿡ �Լ�����Ȯ���ؾ���..)
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

//void TileMap::InitializeMap() //�ʱ�ȭ �׽�Ʈ...
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

