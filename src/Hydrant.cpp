#include "../include/Hydrant.h"

namespace EpicGamers
{
 Hydrant::Hydrant(GameDataRef data) : _data(data)
	{
	}

	void Hydrant::DrawHydrants()
	{
		for (unsigned short int i = 0; i < HydrantSprites.size(); i++)
		{
			this->_data->window.draw(HydrantSprites.at(i));
		}
	} 
}
