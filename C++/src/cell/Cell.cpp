
class Cell
{
public:
    int length, breadth;
    string name[2];
    RectangleShape element;
    Cell(float x, float y, float len = 20, float bred = 20)
    {
        name[0] = to_string(x);
        name[1] = to_string(y);
        length = len;
        breadth = bred;

        element.setSize(Vector2f(length, breadth));
        element.setOutlineColor(Color::White);
        element.setOutlineThickness(2);
        element.setPosition(x, y);
    }
};
