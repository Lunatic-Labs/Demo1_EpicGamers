/*
	This DEFINITIONS file contains lots of important filepaths and variables
	that are referenced throughout the code.
*/

#pragma once

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 2.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/Textures/EpicGamers.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/Textures/background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/Textures/background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/Textures/background.png"

#define GAME_TITLE_FILEPATH "Resources/Textures/DogDashTitle.png"
#define PLAY_BUTTON_FILEPATH "Resources/Textures/PlayButton.png"

#define SCORING_HYDRANT_FILEPATH "Resources/Textures/invisibleScoringPipe.png"
#define DOG_FONT_FILEPATH "Resources/Fonts/DogDashNumbers.ttf"
#define HIGH_SCORE_FILEPATH "Resources/Highscore.txt"
#define GAME_OVER_TITLE_FILEPATH "Resources/Textures/GameOverTitle.png"
#define GAME_OVER_BODY_FILEPATH "Resources/Textures/GameOverBody.png"


#define PLAYER_FRAME_1_FILEPATH "Resources/Player/dogRunner 2xFrame1.png"
#define PLAYER_FRAME_2_FILEPATH "Resources/Player/dogRunner 2xFrame2.png"
#define PLAYER_FRAME_3_FILEPATH "Resources/Player/dogRunner 2xFrame3.png"
#define PLAYER_FRAME_4_FILEPATH "Resources/Player/dogRunner 2xFrame4.png"
#define PLAYER_FRAME_5_FILEPATH "Resources/Player/dogRunner 2xFrame5.png"
#define PLAYER_FRAME_6_FILEPATH "Resources/Player/dogRunner 2xFrame6.png"
#define PLAYER_FRAME_7_FILEPATH "Resources/Player/dogRunner 2xFrame7.png"
#define PLAYER_FRAME_8_FILEPATH "Resources/Player/dogRunner 2xFrame8.png"
#define PLAYER_FRAME_9_FILEPATH "Resources/Player/dogRunner 2xFrame9.png"
#define PLAYER_FRAME_10_FILEPATH "Resources/Player/dogRunner 2xFrame10.png"

#define JUMP_FRAME_1_FILEPATH "Resources/Player/dogRunner 2xJump Frame 1.png"
#define JUMP_FRAME_2_FILEPATH "Resources/Player/dogRunner 2xJump Frame 2.png"
#define JUMP_FRAME_3_FILEPATH "Resources/Player/dogRunner 2xJump Frame 3.png"
#define JUMP_FRAME_4_FILEPATH "Resources/Player/dogRunner 2xJump Frame 4.png"
#define JUMP_FRAME_5_FILEPATH "Resources/Player/dogRunner 2xJump Frame 5.png"
#define JUMP_FRAME_6_FILEPATH "Resources/Player/dogRunner 2xJump Frame 6.png"
#define JUMP_FRAME_7_FILEPATH "Resources/Player/dogRunner 2xJump Frame 7.png"
#define JUMP_FRAME_8_FILEPATH "Resources/Player/dogRunner 2xJump Frame 8.png"
#define JUMP_FRAME_9_FILEPATH "Resources/Player/dogRunner 2xJump Frame 9.png"
#define JUMP_FRAME_10_FILEPATH "Resources/Player/dogRunner 2xJump Frame 10.png"

#define HYDRANT_FILEPATH "Resources/Textures/hydrantWIP1.png"
#define CAT_FILEPATH "Resources/Textures/Cat.png"
#define BONE_FILEPATH "Resources/Textures/bone.png"
#define BONE_MOVEMENT_SPEED 800.0f
#define GROUND_FILEPATH "Resources/Textures/landPlusOne.png"
#define BONE_MOVEMENT_SPEED 800.0f

#define SFX_JUMP_FILEPATH "Resources/Sound/jump.wav"
#define SFX_LAND_FILEPATH "Resources/Sound/land.wav"
#define SFX_DEATH_FILEPATH "Resources/Sound/death.wav"
#define SFX_COLLECTIBLE_FILEPATH "Resources/Sound/collectible.wav"
#define LEVEL_MUSIC_FILEPATH "Resources/Sound/levelMusic.ogg"
#define LEVEL_AMBIENCE_FILEPATH "Resources/Sound/levelAmbience.ogg"


#define PLAYER_ANIMATION_DURATION 1.0f		// length of the Player animation

#define PLAYER_STATE_STILL 1
#define PLAYER_STATE_FALLING 2
#define	PLAYER_STATE_JUMPING 3

#define GRAVITY 30.0f						// strength of player gravity
#define JUMP_SPEED 600.0f					// strength of player jump
#define JUMP_DURATION 1.0f					// length of jump animation. Tutorial used 0.25f

#define TIME_BEFORE_GAME_OVER_APPEARS 0.4f

#define HYDRANT_MOVEMENT_SPEED 400.0f
#define HYDRANT_SPAWN_FREQUENCY 1.7f
#define HYDRANT_MIN_SPAWN_TIME 1.1f
#define HYDRANT_MAX_SPAWN_TIME 1.3f
#define HYDRANT_MULTIPLIER 1.0f				// directly modifies the hydrant spawn times and decreases over time.
#define HYDRANT_MULTIPLIER_INTERVAL 0.012f	// increase the hydrant spawning by this much
#define HYDRANT_MULTIPLIER_LIMIT 0.1f		// prevents the game from becoming impossible (in theory)

#define CAT_MOVEMENT_SPEED 200.0f
#define CAT_SPAWN_FREQUENCY 2.4f
#define CAT_MIN_SPAWN_TIME 2.8f
#define CAT_MAX_SPAWN_TIME 3.6f

#define TIME_BEFORE_SPEED_INCREMENT 1.0f	// time in seconds, TBSI
#define STARTING_SPEED 1.0f					// starting game speed multiplier. How fast hydrants scroll, player jumps, etc.	
#define INCREMENT_SPEED_BY 0.25f			// used to gradually increment Speed every TBSI
#define INCREMENT_JUMP_TIME_BY 0.00f		// used to gradually decrease Jump time every TBSI
#define INCREMENT_JUMP_SPEED_BY 4.0f  		// used to gradually increase Jump Speed (compensating for decreased time) every TBSI
#define INCREMENT_GRAVITY_BY 0.5f			// used to gradually increase Gravity (countering increased Jump Speed) every TBSI. Approximate number based on (INCREMENT_JUMP_TIME_BY * 15)
#define MAX_SPEED 20.0f						// max game speed multiplier (should be pretty fast)


enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};