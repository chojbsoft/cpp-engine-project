#pragma once

void CreateObject(shared_ptr<Object> obj, OBJECT_TYPE type);
void DestroyObject(shared_ptr<Object> obj, OBJECT_TYPE type);
void ChangeScene(SCENE_TYPE next);

