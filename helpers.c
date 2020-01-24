#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = (float) image[i][j].rgbtRed;
            float originalGreen = (float) image[i][j].rgbtGreen;
            float originalBlue = (float) image[i][j].rgbtBlue;
            int red = (int) round(((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue)));
            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = (int) round(((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue)));
            }
            int green = (int) round(((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue)));
            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (int) round(((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue)));
            }
            int blue = (int) round(((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue)));
            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (int) round(((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue)));
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, half = floor(width / 2); j < half; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original_image[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            void add_colors(int *pixRed, int *pixGreen, int *pixBlue, int *red, int *green, int *blue, int *pixnum);

            int pixnum = 0;
            int red = 0;
            int green = 0;
            int blue = 0;
            if (i-1 >= 0 && j-1 >= 0)
            {
                int pixRed = original_image[i-1][j-1].rgbtRed;
                int pixGreen = original_image[i-1][j-1].rgbtGreen;
                int pixBlue = original_image[i-1][j-1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (i-1 >= 0)
            {
                int pixRed = original_image[i-1][j].rgbtRed;
                int pixGreen = original_image[i-1][j].rgbtGreen;
                int pixBlue = original_image[i-1][j].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (i-1 >= 0 && j+1 < width)
            {
                int pixRed = original_image[i-1][j+1].rgbtRed;
                int pixGreen = original_image[i-1][j+1].rgbtGreen;
                int pixBlue = original_image[i-1][j+1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (j-1 >= 0)
            {
                int pixRed = original_image[i][j-1].rgbtRed;
                int pixGreen = original_image[i][j-1].rgbtGreen;
                int pixBlue = original_image[i][j-1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            int current_pixRed = original_image[i][j].rgbtRed;
            int current_pixGreen = original_image[i][j].rgbtGreen;
            int current_pixBlue = original_image[i][j].rgbtBlue;
            add_colors(&current_pixRed, &current_pixGreen, &current_pixBlue, &red, &green, &blue, &pixnum);
            if (j+1 < width)
            {
                int pixRed = original_image[i][j+1].rgbtRed;
                int pixGreen = original_image[i][j+1].rgbtGreen;
                int pixBlue = original_image[i][j+1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (i+1 < height && j-1 >= 0)
            {
                int pixRed = original_image[i+1][j-1].rgbtRed;
                int pixGreen = original_image[i+1][j-1].rgbtGreen;
                int pixBlue = original_image[i+1][j-1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (i+1 < height)
            {
                int pixRed = original_image[i+1][j].rgbtRed;
                int pixGreen = original_image[i+1][j].rgbtGreen;
                int pixBlue = original_image[i+1][j].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            if (i+1 < height && j+1 < width)
            {
                int pixRed = original_image[i+1][j+1].rgbtRed;
                int pixGreen = original_image[i+1][j+1].rgbtGreen;
                int pixBlue = original_image[i+1][j+1].rgbtBlue;
                add_colors(&pixRed, &pixGreen, &pixBlue, &red, &green, &blue, &pixnum);
            }
            image[i][j].rgbtRed = round(red / pixnum);
            image[i][j].rgbtGreen = round(green / pixnum);
            image[i][j].rgbtBlue = round(blue / pixnum);
        }
    }
    return;
}

void add_colors(int *pixRed, int *pixGreen, int *pixBlue, int *red, int *green, int *blue, int *pixnum)
{
    *red += *pixRed;
    *green += *pixGreen;
    *blue += *pixBlue;
    *pixnum += 1;
}