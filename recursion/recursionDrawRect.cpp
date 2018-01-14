#include <iostream>

using namespace std;

//Function prototype
void draw_rect_iter(int);
void draw_rect_recur(int);

void draw_rect_iter(int i)
{
	// iterative solution
	for (; i > 0; i--)
	{
		cout << "**********" << endl;
		cout << "*        *" << endl;
		cout << "**********" << endl;
	}
}

void draw_rect_recur(int i)
{
	// iterative solution
	if (i>0)
	{
		draw_rect_recur(--i);		// the () could also hold (i - 1)
		cout << "**********" << endl;
		cout << "*        *" << endl;
		cout << "**********" << endl << endl;
		// draw_rect_recur(--i); could also be placed here, printing happens here first
	}
}

int main()
{
	cout << "now drawing our iterative rectangle" << endl;
	draw_rect_iter(5);

	cout << "now drawing our recursive rectangle" << endl;
	draw_rect_recur(5);

	cin.get();
	return 0;
}