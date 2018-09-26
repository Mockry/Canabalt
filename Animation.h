#pragma once

//Library includes
#include <vector>
#include <SFML/Graphics.hpp>


class Animation
{
public:

	Animation();

	void Update(sf::Time _frameTime);

	void play();
	void Pause();
	void Stop();

	bool IsPLaying();

	void AddFrame(sf::Texture& _newFrame);
	void SetSprite(sf:: Sprite& _sprite);
	void setPlayBackSpeed(float _framesPerSecond);
	void setLoop(bool _loop);





private:

	std::vector<sf::Texture*> m_frames;
	sf::Sprite* m_sprite;
	float m_playBackSpeed;
	bool m_loop;

	bool m_playing;
	sf::Time m_nextFrameChange;
	int m_currentFrame;
};