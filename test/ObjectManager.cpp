#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Object.h"

ObjectManager * ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}

ObjectManager::~ObjectManager()
{

}


void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());	//위치값이나 함수

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		EnableList->insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectManager::DelObject(Object* _Object, list<Object*>::iterator _Where)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
	{
		iter->second.end() = DisableList->
		
	}
	else
		iter->second.pop_back();
}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	if (iter == EnableList->end())
		return nullptr;

	return &iter->second;
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}