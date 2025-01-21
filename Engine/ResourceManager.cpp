#include "pch.h"
#include "ResourceManager.h"
#include "PathManager.h"
#include "Texture.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
    map<wstring, Texture*>::iterator iter = mMapTex.begin();
    for (; iter != mMapTex.end(); ++iter)
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
    mMapTex.insert({ key, tex });
    return tex;
}

Texture* ResourceManager::FindTexture(const wstring& key)
{
    map<wstring, Texture*>::iterator iter = mMapTex.find(key);
    if (iter == mMapTex.end())
    {
        return nullptr;
    }
    else
    {
        return iter->second;
    }
}

