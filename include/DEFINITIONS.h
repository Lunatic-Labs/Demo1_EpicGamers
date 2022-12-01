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

#define SCORING_HYDRANT_FILEPATH "Resources/Textures/invisibleScoringPipe.png"    //Part of score video
#define DOG_FONT_FILEPATH "Resources/Fonts/DogDashNumbers.ttf"                        //Part of score video
#define HIGH_SCORE_FILEPATH "Resources/Highscore.txt"								//Cole #30 Video
#define GAME_OVER_TITLE_FILEPATH "Resources/Textures/GameOverTitle.png"
#define GAME_OVER_BODY_FILEPATH "Resources/Textures/GameOverBody.png"


#define PLAYER_FRAME_1_FILEPATH "Resources/Player/dogRunner 2xFrame1.png"		//Tutorial defined filepaths to each frame of animation separately. Compare methods.
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
#define BONE_FILEPATH "Resources/Textures/bone.png"
#define BONE_MOVEMENT_SPEED 800.0f
#define GROUND_FILEPATH "Resources/Textures/landPlusOne.png"
#define HYDRANT_MOVEMENT_SPEED 400.0f
#define HYDRANT_SPAWN_FREQUENCY 1.7f
#define BONE_MOVEMENT_SPEED 800.0f

#define SFX_JUMP_FILEPATH "Resources/Sound/jump.wav"
#define SFX_LAND_FILEPATH "Resources/Sound/land.wav"
#define SFX_DEATH_FILEPATH "Resources/Sound/death.wav"
#define SFX_COLLECTIBLE_FILEPATH "Resources/Sound/collectible.wav"
#define LEVEL_MUSIC_FILEPATH "Resources/Sound/levelMusic.ogg"

#define PLAYER_ANIMATION_DURATION 1.0f						//Length of the Player animation

#define PLAYER_STATE_STILL 1
#define PLAYER_STATE_FALLING 2
#define	PLAYER_STATE_JUMPING 3

#define GRAVITY 10.0f			//Value to pull player down during Falling state.
#define JUMP_SPEED 375.0f		//Value to jump up by during Jumping state.

#define JUMP_DURATION 1.0f		//Length of jump animation. Tutorial used 0.25f

#define TIME_BEFORE_GAME_OVER_APPEARS 0.4f

#define HYDRANT_MIN_SPAWN_TIME 1.4f
#define HYDRANT_MAX_SPAWN_TIME 1.6f

#define STARTING_SPEED 1.0f				//Starting game speed multiplier. How fast hydrants scroll, player jumps, etc.	
#define INCREMENT_SPEED_BY 0.15f				//Used to gradually increment Speed every TBSI
#define TIME_BEFORE_SPEED_INCREMENT 4.0f		//Time in seconds, TBSI
#define INCREMENT_JUMP_TIME_BY 0.03f			//Used to gradually decrease Jump time every TBSI
#define INCREMENT_JUMP_SPEED_BY 11.25f			//Used to gradually increase Jump Speed (compensating for decreased time) every TBSI
#define INCREMENT_GRAVITY_BY 0.5f				//Used to gradually increase Gravity (countering increased Jump Speed) every TBSI. Approximate number based on (INCREMENT_JUMP_TIME_BY * 15)
#define MAX_SPEED 9.0f					//Max game speed multiplier (should be pretty fast)

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};