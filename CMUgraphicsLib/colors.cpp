/* 
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#include "colors.h"

bool operator==(color a, color b) {

  return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

  return !(a == b);
  
}

string to_string(const color& c)
{
	if(c==SNOW)
		return"Snow" ;
	if(c==GHOSTWHITE)
		return"Ghost White" ;
	if(c==WHITESMOKE)
		return"White SMOKE" ;
	if(c==GAINSBORO)
		return"GAINSBORO" ;
	if(c==FLORALWHITE)
		return"Floral White" ;
	if(c==OLDLACE)
		return"OLDLACE" ;
	if(c==LINEN)
		return"LINEN" ;
	if(c==ANTIQUEWHITE)
		return"Antique White" ;
	if(c==PAPAYAWHIP)
		return"PAPAYAWHIP" ;
	if(c==BLANCHEDALMOND)
		return"BLANCHEDALMOND";
	if(c==BISQUE)
		return"Bisque";
	if(c==PEACHPUFF)
		return"PEACHPUFF" ;
	if(c==NAVAJOWHITE)
		return"NAVAJO White" ;
	if(c==MOCCASIN)
		return"MOCCASIN" ;
	if(c==CORNSILK)
		return"CORNSILK" ;
	if(c==IVORY)
		return"IVORY" ;
	if(c==LEMONCHIFFON)
		return"LEMONCHIFFON" ;
	if(c==SEASHELL)
		return"Sea Shell" ;
	if(c==HONEYDEW)
		return"HONEYDEW" ;
	if(c==MINTCREAM)
		return"MINTCREAM" ;
	if(c==AZURE)
		return"Azure" ;
	if(c==ALICEBLUE)
		return"Alice Blue" ;
	if(c==LAVENDER)
		return"Lavender" ;
	if(c==LAVENDERBLUSH)
		return "Lavender BLUSH";
	if(c==MISTYROSE)
		return "Misty Rose";
	if(c==WHITE)
		return "White";
	if(c==BLACK)
		return "Black";
	if(c==DARKSLATEGRAY)
		return "Dark Slate Gray";
	if(c==DIMGRAY)
		return "DIM Gray";
	if(c==SLATEGRAY)
		return "Slate Gray";
	if(c==LIGHTSLATEGRAY)
		return "Light Slate Gray";
	if(c==MIDNIGHTBLUE)
		return "Midnight Blue";
	if(c==GRAY)
		return "Gray";
	if(c==LIGHTGREY)
		return "Light Gray";
	if(c==NAVY)
		return "Navy";
	if(c==NAVYBLUE)
		return "Navy Blue";
	if(c==CORNFLOWERBLUE)
		return "CORNFLOWER Blue";
	if(c==DARKSLATEBLUE)
		return "Dark Slate Blue";
	if(c==SLATEBLUE)
		return "Slate Blue";
	if(c==MEDIUMSLATEBLUE)
		return "Medium Slate Blue";
	if(c==LIGHTSLATEBLUE)
		return "Light Slate Blue";
	if(c==MEDIUMBLUE)
		return "Medium Blue";
	if(c==ROYALBLUE)
		return "ROYAL Blue";
	if(c==BLUE)
		return "Blue";
	if(c==DODGERBLUE)
		return "DODGER Blue";
	if(c==DEEPSKYBLUE)
		return "DEEP Sky Blue";
	if(c==SKYBLUE)
		return "Sky Blue";
	if(c==LIGHTSKYBLUE)
		return "Light Sky Blue";
	if(c==STEELBLUE)
		return "Steel Blue";
	if(c==LIGHTSTEELBLUE)
		return "Light Steel Blue";
	if(c==LIGHTBLUE)
		return"Light  Blue";
	if(c==POWDERBLUE)
		return"Powder Blue";
	if(c==PALETURQUOISE)
		return"PALE Turquoise";
	if(c==DARKTURQUOISE)
		return"Dark Turquoise";
	if(c==MEDIUMTURQUOISE)
		return"Medium Turquoise";
	if(c==TURQUOISE)
		return"Turquoise";
	if(c==CYAN)
		return"Cyan";
	if(c==LIGHTCYAN)
		return"Light Cyan";
	if(c==CADETBLUE)
		return"CADET Blue";
	if(c==MEDIUMAQUAMARINE)
		return"Medium Aquamarine";
	if(c==AQUAMARINE)
		return"Aquamarine";
	if(c==DARKGREEN)
		return"Dark Green";
	if(c==DARKOLIVEGREEN)
		return"Dark Olive Green";
	if(c==DARKSEAGREEN)
		return"Dark Sea Green";
	if(c==SEAGREEN)
		return"Sea Green";
	if(c==MEDIUMSEAGREEN)
		return"Medium Sea Green";
	if(c==LIGHTSEAGREEN)
		return"Light Sea Green";
	if(c==PALEGREEN)
		return"PALE Green";
	if(c==SPRINGGREEN)
		return"Spring Green";
	if(c==LAWNGREEN)
		return"LAWN Green";
	if(c==GREEN)
		return"Green";
	if(c==CHARTREUSE)
		return"CHARTREUSE";
	if(c==MEDIUMSPRINGGREEN)
		return"Medium Spring Green";
	if(c==GREENYELLOW)
		return"Green Yellow";
	if(c==LIMEGREEN)
		return"Lime Green";
	if(c==YELLOWGREEN)
		return"Yellow Green";
	if(c==FORESTGREEN)
		return"Forest Green";
	if(c==OLIVEDRAB)
		return" Olive DRAB";
	if(c==DARKKHAKI)
		return"Dark Khaki";
	if(c==KHAKI)
		return"Khaki";
	if(c==PALEGOLDENROD)
		return"PALE Goldenrod";
	if(c==LIGHTGOLDENRODYELLOW)
		return"Light Goldenrod Yellow";
	if(c==LIGHTYELLOW)
		return"Light Yellow";
	if(c==YELLOW)
		return"Yellow";
	if(c==GOLD)
		return"Gold";
	if(c==LIGHTGOLDENROD)
		return"Light Goldenrod";
	if(c==GOLDENROD)
		return"Goldenrod";
	if(c==DARKGOLDENROD)
		return"Dark Goldenrod";
	if(c==ROSYBROWN)
		return"Rosy Brown";
	if(c==INDIAN)
		return"Indian";
	if(c==INDIANRED)
		return"Indian Red";
	if(c==SADDLEBROWN)
		return"Saddle Brown";
	if(c==SIENNA)
		return"SIENNA";
	if(c==PERU)
		return"PERU";
	if(c==BURLYWOOD)
		return"BURLYWOOD";
	if(c==BEIGE)
		return"BEIGE";
	if(c==WHEAT)
		return"Wheat";
	if(c==SANDYBROWN)
		return"Sandy Brown";
	if(c==TAN)
		return"Tan";
	if(c==CHOCOLATE)
		return"Chocolate";
	if(c==FIREBRICK)
		return"FIREBRICK";
	if(c==BROWN)
		return"Brown";
	if(c==DARKSALMON)
		return"Dark Salmon";
	if(c==SALMON)
		return"Salmon";
	if(c==LIGHTSALMON)
		return"Light Salmon";
	if(c==ORANGE)
		return"Orange";
	if(c==DARKORANGE)
		return"Dark Orange";
	if(c==CORAL)
		return"Coral";
	if(c==LIGHTCORAL)
		return"Light Coral";
	if(c==TOMATO)
		return"Tomato";
	if(c==ORANGERED)
		return"Orange Red";
	if(c==RED)
		return"Red";
	if(c==HOTPINK)
		return"Hot Pink";
	if(c==DEEPPINK)
		return"Deep Pink";
	if(c==PINK)
		return"Pink";
	if(c==LIGHTPINK)
		return"Light Pink";
	if(c==PALEVIOLETRED)
		return"Pale Violet Red";
	if(c==MAROON)
		return"MAROON";
	if(c==MEDIUMVIOLETRED)
		return"Medium Violet Red";
	if(c==VIOLETRED)
		return"Violet Red";
	if(c==MAGENTA)
		return"Magenta";
	if(c==VIOLET)
		return"Violet";
	if(c==PLUM)
		return"Plum";
	if(c==ORCHID)
		return"Orchid";
	if(c==MEDIUMORCHID)
		return"Medium Orchid";
	if(c==DARKORCHID)
		return"Dark Orchid";
	if(c==DARKVIOLET)
		return"Dark Violet";
	if(c==BLUEVIOLET)
		return" Blue Violet";
	if(c==PURPLE)
		return"Purple";
	if(c==MEDIUMPURPLE)
		return"Medium Purple";
	if(c==THISTLE)
		return"THISTLE";
	if(c==DARKGRAY)
		return"Dark Gray";
	if(c==DARKBLUE)
		return"Dark Blue";
	if(c==DARKCYAN)
		return"Dark Cyan";
	if(c==DARKMAGENTA)
		return"Dark Magenta";
	if(c==DARKRED)
		return"Dark Red";
	if(c==LIGHTGREEN)
		return"Light Green";

	return"Unknown color";
}