import turtle
import random

def draw_spiral(t, length, color1, color2):
    """
    Draws a recursive spiral with color blending.

    Args:
        t (turtle.Turtle): The turtle object to draw with.
        length (int): The current length of the spiral segment.
        color1 (tuple): The starting color for the blend as an RGB tuple.
        color2 (tuple): The ending color for the blend as an RGB tuple.
    """
    if length < 5:
        return

    # Blend colors based on recursion depth
    blend_ratio = (length - 5) / (max_length - 5)
    new_color = (
        int(color1[0] * (1 - blend_ratio) + color2[0] * blend_ratio),
        int(color1[1] * (1 - blend_ratio) + color2[1] * blend_ratio),
        int(color1[2] * (1 - blend_ratio) + color2[2] * blend_ratio)
    )

    # Convert the RGB tuple to a string acceptable by pencolor
    t.pencolor(new_color)
    t.forward(length)

    t.right(90)
    draw_spiral(t, length * 0.8, new_color, color2)  # Shorter segment with ending color
    t.left(90)
    draw_spiral(t, length * 0.8, color1, new_color)  # Shorter segment with blended color

# Set up the turtle and colors
t = turtle.Turtle()
t.speed(0)  # Set speed to fastest
screen = turtle.Screen()
screen.bgcolor("black")
max_length = 200
start_color = (255, 0, 0)  # Red
end_color = (0, 0, 255)  # Blue

# Normalize colors for turtle
start_color = tuple(c / 255 for c in start_color)
end_color = tuple(c / 255 for c in end_color)

# Start drawing
t.penup()
t.goto(0, 0)
t.pendown()
draw_spiral(t, max_length, start_color, end_color)

# Keep the window open
turtle.done()