#include "pch.h"
#include "TaskSystem.h"
#include "../Model/Task.h"

void CTaskSystem::Init()
{

}

void CTaskSystem::AddTask(std::shared_ptr<Task> task)
{
	_taskList.push_back(task);
	SendEvent<UpdateGridEvent>();
}
void CTaskSystem::RemoveTask(std::shared_ptr<Task> task)
{
	for (auto iter = _taskList.begin(); iter != _taskList.end(); ++iter)
	{
		if ((*iter)->strName == task->strName)
		{
			_taskList.erase(iter);
			return;
		}
	}
	SendEvent<UpdateGridEvent>();
}

std::shared_ptr<Task> CTaskSystem::GetTask(int idx)
{
	return _taskList[idx];
}

int CTaskSystem::GetTaskCnt()
{
	return _taskList.size();
}

bool CTaskSystem::IsEmpty()
{
	return _taskList.empty();
}