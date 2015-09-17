void draw_circle ()
{
    int x, y;
    int length = 50;
    float angle = 0.0;
    float angle_stepsize = 0.1;

    // go through all angles from 0 to 2 * PI radians
    while (angle < 2 * PI)
    {
        // calculate x, y from a vector with known length and angle
        x = length * cos (angle);
        y = length * sin (angle);

        putpixel (screen,
            x + SCREEN_W / 2, y + SCREEN_H / 2,
            makecol (255, 255, 255));
        angle += angle_stepsize;
    }
}