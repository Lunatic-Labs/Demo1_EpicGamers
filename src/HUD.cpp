/*
    The HUD controls the onscreen score display, using a custom font.
*/

#include "../include/HUD.h"
#include <string>


namespace EpicGamers
{
    HUD::HUD( GameDataRef data ) : data( data )
    {
        scoreText.setFont( data->assets.GetFont( "Dog Font" ) );
        scoreText.setString( "0" );
        scoreText.setCharacterSize( 128 );
        scoreText.setFillColor( sf::Color(185,246,231));
        scoreText.setOrigin( scoreText.getGlobalBounds( ).width / 2, scoreText.getGlobalBounds( ).height / 2);
        scoreText.setPosition( data->window.getSize( ).x / 2, data->window.getSize( ).y / 10 );
    }

    void HUD::Draw( )
    {
        data->window.draw( scoreText );
    }

    void HUD::UpdateScore( int score )
    {
        scoreText.setString( std::to_string( score ) );
    }
}