#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SWITCH,
	ITM_SAVE_GRAPH,
	ITM_LOAD_GRAPH,
	ITM_START_REC,
	ITM_STOP_REC,
	ITM_PLAY_REC,
	ITM_SELECT,
	ITM_CHANGE_DRAWING_CLR,
	ITM_CHANGE_FILL_CLR,
	ITM_MOVE,
	ITM_DELETE,
	ITM_UNDO,
	ITM_REDO,
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE,
	ITM_TRIANGLE,
	ITM_HEXAGON,
	ITM_CIRCLE,
	ITM_BLACK,
	ITM_RED,
	ITM_ORANGE,
	ITM_YELLOW,
	ITM_GREEN,
	ITM_BLUE,
	ITM_sound,
	ITM_move_by_dragging,
	ITM_RESIZE_BY_DRAGGING,
	ITM_CLEARALL,
	
	//TODO: Add more items names here: DONE all the required THE SHAPES, recording icons left.

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_SWITCH_BACK,
	ITM_PICK_BY_TYPE,
	ITM_PICK_BY_CLR,
	ITM_PICK_BY_TYPE_AND_CLR,
	ITM_EXIT_PLAY,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif