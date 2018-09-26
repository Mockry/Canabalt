#pragma once

//Library includes
#include <vector>
#include <SFML/Graphics.hpp>


class Animation
{
public:

	Animation();

	void Update(sf::Time _frameTime);

	void Play();
	void Pause();
	void Stop();

	bool IsPLaying();

	void AddFrame(sf::Texture& _newFrame);
	void SetSprite(sf:: Sprite& _sprite);
	void SetPlayBackSpeed(float _framesPerSecond);
	void SetLoop(bool _loop);





private:

	std::vector<sf::Texture*> m_frames;
	sf::Sprite* m_sprite;
	float m_playBackSpeed;
	bool m_loop;

	bool m_playing;
	sf::Time m_nextFrameChange;
	int m_currentFrame;
};