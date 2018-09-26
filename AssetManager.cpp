//Library Includes
#include <assert.h>

//Project Includes
#include "AssetManager.h"

//initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

//Constructor
AssetManager::AssetManager()
	:m_textures()
	, m_soundBuffers()
	, m_font()
{
	// Throw an error and stop execution (in debug mode) if a copy
	// of this class has already been created
	assert(s_instance == nullptr);

	//Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}


sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	// Create and iterator to hold a key and value play
	// ad search for the required key
	//using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" in this case is equivalent to writing
	// std::map<std::string,sf::Texture>::iterator
	// this keyword (auto) can be used in cases where the compiler
	// can figure our the type of a variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//Did we find the texture? (aka was it already loaded?)
	//(iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_textures.end())
	{
		//Yes! we found it
		return keyValuePair->second;
	}
	else
	{
		// No! we didn't find it

		//We need to create the texture

		//Create a new key value pair using the filename
		//the subscript [] operator creates and entry in the map
		// if there is not already one there

		sf::Texture& texture = s_instance->m_textures[_fileName];
		//blank texture has been created
		//now just load it from file using SFML
		texture.loadFromFile(_fileName);

		return texture;
	}

}



sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	auto keyValuePair = s_instance->m_soundBuffers.find(_fileName);

	if (keyValuePair != s_instance->m_soundBuffers.end())
	{
		//we did find it
		return keyValuePair->second;
	}
	else
	{
		//we did not find it
		sf::SoundBuffer& soundBuffer = s_instance->m_soundBuffers[_fileName];
		soundBuffer.loadFromFile(_fileName);
		return soundBuffer;
	}
}