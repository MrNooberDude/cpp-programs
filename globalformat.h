/*
GlobalFormat Header File
Formatting styles that work mostly everywhere
Also includes color struct
Made by IceandFire04
Free to use; examples at the bottom of this file
*/

#include <string>

struct Color {
	int r;
	int g;
	int b;
};

enum FormattingTypes
{
	NORMAL = 0,
	BOLD,
	DIM,
	ITALIC,
	UNDERLINE,
	INVERT = 7,
	HIDE,
	DOUBLEUNDERLINE = 21,
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	RGBCOLOR, // add arguments 2;r;g;b to the text
	BG_BLACK = 40,
	BG_RED,
	BG_GREEN,
	BG_YELLOW,
	BG_BLUE,
	BG_MAGENTA,
	BG_CYAN,
	BG_WHITE,
	BG_RGBCOLOR, // same as before, add some extra args
	BRIGHTBLACK = 90,
	BRIGHTRED,
	BRIGHTGREEN,
	BRIGHTYELLOW,
	BRIGHTBLUE,
	BRIGHTMAGENTA,
	BRIGHTCYAN,
	BRIGHTWHITE,
	BG_BRIGHTBLACK = 100,
	BG_BRIGHTRED,
	BG_BRIGHTGREEN,
	BG_BRIGHTYELLOW,
	BG_BRIGHTBLUE,
	BG_BRIGHTMAGENTA,
	BG_BRIGHTCYAN,
	BG_BRIGHTWHITE,
	NUM_FORMATTINGTYPES
};

string formatText(string text, int type, bool useColor = false, Color color = {255,255,255})
{
	if (!useColor)
		return "\e[" + to_string(type) + "m" + text + "\e[0m";
	else
		return "\e[" + to_string(type) + ";2;" +
		       to_string(color.r) + ";" + to_string(color.g) + ";" + to_string(color.b) +
		       "m" + text + "\e[0m";
}

void testFormatting()
{
	for (int i = 0; i < NUM_FORMATTINGTYPES; ++i)
	{
		cout << formatText("text!", i) << " (format style " << formatText(to_string(i), BOLD) << ")" << endl;
	}
}

/*
EXAMPLES!

This line makes text bold.
formatText("Bold Text", bold)

This line sets the text to a custom color, and the one below changes the background.
formatText("text!", RGBCOLOR, true, {100,50,255})
formatText("text!", BG_RGBCOLOR, true, {100,50,255})





*/
