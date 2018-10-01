// --------------------------------------
// Includes
// --------------------------------------
// Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Project includes
#include "AssetManager.h"
#include "Animation.h"
#include"AnimationSystem.h"

int main()
{
	// --------------------------------------
	// Game Setup
	// --------------------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Canabalt",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;


	
	// Testing AssetManager
	AssetManager assets;

	
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));

	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();

	sf::Text testText;
	testText.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testText.setString("Testing!");

	//Test Animation
	AnimationSystem testAnimationSystem;
	testAnimationSystem.SetSprite(testSprite);



	Animation& testAnimation = testAnimationSystem.CreateAnimation("run");
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
	testAnimation.SetLoop(true);
	testAnimation.SetPlayBackSpeed(10.0f);


	Animation& jumpAnimation = testAnimationSystem.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerJump.png"));



	testAnimationSystem.Play("jump");


	// end game setup
	// --------------------------------------


	// --------------------------------------
	// Game Loop
	// --------------------------------------
	while (gameWindow.isOpen())
	{
		// --------------------------------------
		// Input
		// --------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			} // End if (closed)
		} // end event polling loop

		// end input
		// --------------------------------------


		// --------------------------------------
		// Update
		// --------------------------------------
		sf::Time frameTime = gameClock.restart();

		//update our animation
		testAnimationSystem.Update(frameTime);

		// end update
		// --------------------------------------



		// --------------------------------------
		// Draw
		// --------------------------------------

		// Clear the window to a single colour
		gameWindow.clear();

		
		// Draw Everything
		gameWindow.draw(testSprite);
		gameWindow.draw(testText);

		// Display the window contents to the screen
		gameWindow.display();

		// end draw
		// --------------------------------------

	} // end of the game while loop

	// end game loop
	// --------------------------------------

	// exit point for the program
	return 0;

} // end of the main() function
