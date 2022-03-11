#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

constexpr Point	testpoint= { 300,300 };

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	EmptyFace fjes({ 300,300 }, 100);
	fjes.attach_to(win);
	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	win.wait_for_button();

	//shockedFace ansikt({ 300,300 }, 100);
	//ansikt.attach_to(win);
	//win.wait_for_button();

	ghaspFace gfjes({ 300,300 }, 100);
	gfjes.attach_to(win);
	win.wait_for_button();

	straightFace sfjes(testpoint, 100);
	sfjes.attach_to(win);
	win.wait_for_button();

	winkEye blunk(testpoint, 100);
	blunk.attach_to(win);
	win.wait_for_button();

	sadFace smil(testpoint, 200);
	smil.attach_to(win);
	win.wait_for_button();
	
}
