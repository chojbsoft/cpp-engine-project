#pragma once

class Texture;
class ResourceManager
{
	SINGLE(ResourceManager)

public:
	Texture* FindTexture(const wstring& key);
	Texture* Load(const wstring& key, const wstring& relativePath);

private:
	map<wstring, Texture*> mMapTex;

};

