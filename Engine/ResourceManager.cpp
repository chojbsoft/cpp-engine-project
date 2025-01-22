#include "pch.h"
#include "ResourceManager.h"
#include "PathManager.h"
#include "Texture.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
    map<wstring, Texture*>::iterator iter = textureByName.begin();
    for (; iter != textureByName.end(); ++iter)
    {
        delete iter->second;
    }
}

Texture* ResourceManager::Load(const wstring& key, const wstring& relativePath)
{
    Texture* tex = FindTexture(key);
    if (tex)
    {
        return tex;
    }

    wstring filePath = PathManager::GetInst()->GetResourcePath();
    filePath = filePath + relativePath;

    tex = new Texture(key, relativePath);
    tex->Load(filePath);
    textureByName.insert({ key, tex });
    return tex;
}

Texture* ResourceManager::FindTexture(const wstring& key)
{
    map<wstring, Texture*>::iterator iter = textureByName.find(key);
    if (iter == textureByName.end())
    {
        return nullptr;
    }
    else
    {
        return iter->second;
    }
}

