#pragma once

#define SCREEN_WIDTH 2048
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/Textures/LUdLogo.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/Textures/background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/Textures/LUlogo.jpg"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/Textures/LUlogo.jpg"

#define GAME_TITLE_FILEPATH "Resources/Textures/dogWIP2.jpg"
#define PLAY_BUTTON_FILEPATH "Resources/Textures/LLBisonNewBig.png"

#define PLAYER_FRAME_1_FILEPATH "Resources/Player/dogRunner Frame 1.png"		//Tutorial defined filepaths to each frame of animation separately. Compare methods.
#define PLAYER_FRAME_2_FILEPATH "Resources/Player/dogRunner Frame 2.png"
#define PLAYER_FRAME_3_FILEPATH "Resources/Player/dogRunner Frame 3.png"
#define PLAYER_FRAME_4_FILEPATH "Resources/Player/dogRunner Frame 4.png"
#define PLAYER_FRAME_5_FILEPATH "Resources/Player/dogRunner Frame 5.png"
#define PLAYER_FRAME_6_FILEPATH "Resources/Player/dogRunner Frame 6.png"
#define PLAYER_FRAME_7_FILEPATH "Resources/Player/dogRunner Frame 7.png"
#define PLAYER_FRAME_8_FILEPATH "Resources/Player/dogRunner Frame 8.png"
#define PLAYER_FRAME_9_FILEPATH "Resources/Player/dogRunner Frame 9.png"
#define PLAYER_FRAME_10_FILEPATH "Resources/Player/dogRunner Frame 10.png"

#define JUMP_FRAME_1_FILEPATH "Resources/Player/dogRunner Jump Frame 1.png"
#define JUMP_FRAME_2_FILEPATH "Resources/Player/dogRunner Jump Frame 2.png"
#define JUMP_FRAME_3_FILEPATH "Resources/Player/dogRunner Jump Frame 3.png"
#define JUMP_FRAME_4_FILEPATH "Resources/Player/dogRunner Jump Frame 4.png"
#define JUMP_FRAME_5_FILEPATH "Resources/Player/dogRunner Jump Frame 5.png"
#define JUMP_FRAME_6_FILEPATH "Resources/Player/dogRunner Jump Frame 6.png"
#define JUMP_FRAME_7_FILEPATH "Resources/Player/dogRunner Jump Frame 7.png"
#define JUMP_FRAME_8_FILEPATH "Resources/Player/dogRunner Jump Frame 8.png"
#define JUMP_FRAME_9_FILEPATH "Resources/Player/dogRunner Jump Frame 9.png"
#define JUMP_FRAME_10_FILEPATH "Resources/Player/dogRunner Jump Frame 10.png"


#define PLAYER_ANIMATION_DURATION 1.0f						//Length of Player Idle animation

#define PLAYER_STATE_STILL 1		//States that the player can be in, based on input.
#define PLAYER_STATE_JUMPING 2		//Jumping, Falling, or neither (Still)
#define PLAYER_STATE_FALLING 3

#define GRAVITY 350.0f				//force applied downwards when FALLING
#define JUMP_SPEED 350.0f			//force applied upwards when JUMPING
#define JUMP_DURATION 0.25f									//Length of Player Jump functionality. Animation is 1.0f

#define HYDRANT_FILEPATH "Resources/Textures/hydrantWIP1.jpg"
