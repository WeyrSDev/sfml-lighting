/***********************************************************************
     * File       : defines.hpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEFINES
#define __DEFINES



/***********************************************************************
     * List processing macros

***********************************************************************/
#define deleteList(list)      for (; !(list).empty(); delete (list).back(), (list).pop_back())
#define updateList(list)      for (unsigned int i = 0; i < (list).size();) { if (!(list)[i]->update()) {delete (list)[i]; (list).erase((list).begin() + i);} else i++;}



/***********************************************************************
     * Lighting constants

***********************************************************************/
#define LIGHT_MAX_LIGHTLEVEL    100
#define LIGHT_ABSOLUTE          80



/***********************************************************************
     * Map constants

***********************************************************************/
#define TILE_SIZE     16
#define MAP_SIZE_X    50
#define MAP_SIZE_Y    38


#endif
