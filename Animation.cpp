//project includes
#include "Animation.h"

Animation::Animation()
	:m_frames ()
	,m_sprite (nullptr)
	,m_playBackSpeed (15.0f)
	,m_loop (false)
	,m_playing (false)
	,m_nextFrameChange ()
	,m_currentFrame (0)
{

}


void Animation::Update(sf::Time _frameTime)
{

	//only process animation if it is playing
	if (m_playing)
	{
		//is it time to change to a new frame?
		m_nextFrameChange -= _frameTime;
		if (m_nextFrameChange.asSeconds() <= 0)
		{
			//it's time to change the frame

			//change to the next frame
			++m_currentFrame;

			//did we reach the end?
			if (m_currentFrame >= m_frames.size())
			{
				//we did reach the end

				// should we loop?
				if (m_loop == true)
				{
					//wrap to the beginning
					m_currentFrame = 0;
				}
				else
				{
					//set our frame as the last in the list
					m_currentFrame = m_frames.size() - 1;

					//stop playback
					m_playing = false;
				}
				
				
			}

			//update the sprite texture to match the new frame
			// does our sprite exist
			if (m_sprite)
			{
				m_sprite->setTexture(*m_frames[m_currentFrame]);
			}

			//determine time for next frame change
			// convert frames per second to seconds per frame
			float timeToChange = 1.0f / m_playBackSpeed;
			m_nextFrameChange = sf::seconds(timeToChange);
		}
	}
}

void Animation::Play()
{
	// update our sprite to the current frame immediately
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}

	// only start playing if playback speed is not 0
	// this prevents a divide by 0 error
	if (m_playBackSpeed != 0)
	{
		m_playing = true;

		//determine time for next frame change
		// convert frames per second to seconds per frame
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
	
}

bool Animation::IsPLaying()
{
	return m_playing;
}



void Animation::Pause()
{
	m_playing = false;
}

void Animation::Stop()
{
	m_playing = false;
	m_currentFrame = 0;
}


void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

void Animation::SetPlayBackSpeed(float _framesPerSecond)
{
	m_playBackSpeed = _framesPerSecond;
	//if the playback speed is 0
	// Pause to protect from divide by 0 error
	if (m_playBackSpeed == 0)
		Pause();
}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;
}