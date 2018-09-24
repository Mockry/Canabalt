#pragma once

// Library Includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>





class AssetManager
{
public:

	// Public Interface / Behaviours

	//Constructer
	AssetManager();


	//Get a texture based on a file name
	static sf::Texture& GetTexture(std::string _fileName);
	//Get a SoundBuffer based on a file name
	//static sf::SoundBuffer& GetSoundBuffer(std::string _fileName);
	//Get a texture based on a file name
	//static sf::Font& GetFont(std::string _fileName);



private:

	//private data for this class

	//A pointer to the class itself
	//For the singletone design pattern
	//The one and only instance of this class
	static AssetManager* s_instance;


	//List of Textures
	std::map<std::string, sf::Texture> m_textures;

	//List of soundbuffers
	std::map<std::string, sf::SoundBuffer> m_soundBuffers;

	//List of Fonts
	std::map<std::string, sf::Font> m_font;


};