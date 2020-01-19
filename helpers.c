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
    int half = round(width / 2);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tmp;
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

    // top left corner
    int average_red = (int) round((original_image[0][0].rgbtRed + original_image[0][1].rgbtRed + original_image[1][0].rgbtRed + original_image[1][1].rgbtRed) / 4);
    int average_green = (int) round((original_image[0][0].rgbtGreen + original_image[0][1].rgbtGreen + original_image[1][0].rgbtGreen + original_image[1][1].rgbtGreen) / 4);
    int average_blue = (int) round((original_image[0][0].rgbtBlue + original_image[0][1].rgbtBlue + original_image[1][0].rgbtBlue + original_image[1][1].rgbtBlue) / 4);
    image[0][0].rgbtRed = average_red;
    image[0][0].rgbtGreen = average_green;
    image[0][0].rgbtBlue = average_blue;

    // top right corner
    average_red = (int) round((original_image[0][width - 2].rgbtRed + original_image[0][width - 1].rgbtRed + original_image[1][width - 2].rgbtRed + original_image[1][width - 1].rgbtRed) / 4);
    average_green = (int) round((original_image[0][width - 2].rgbtGreen + original_image[0][width - 1].rgbtGreen + original_image[1][width - 2].rgbtGreen + original_image[1][width - 1].rgbtGreen) / 4);
    average_blue = (int) round((original_image[0][width - 2].rgbtBlue + original_image[0][width - 1].rgbtBlue + original_image[1][width - 2].rgbtBlue + original_image[1][width - 1].rgbtBlue) / 4);
    image[0][width - 1].rgbtRed = average_red;
    image[0][width - 1].rgbtGreen = average_green;
    image[0][width - 1].rgbtBlue = average_blue;

    // bottom left corner
    average_red = (int) round((original_image[height - 2][0].rgbtRed + original_image[height - 2][1].rgbtRed + original_image[height - 1][0].rgbtRed + original_image[height - 1][1].rgbtRed) / 4);
    average_green = (int) round((original_image[height - 2][0].rgbtGreen + original_image[height - 2][1].rgbtGreen + original_image[height - 1][0].rgbtGreen + original_image[height - 1][1].rgbtGreen) / 4);
    average_blue = (int) round((original_image[height - 2][0].rgbtBlue + original_image[height - 2][1].rgbtBlue + original_image[height - 1][0].rgbtBlue + original_image[height - 1][1].rgbtBlue) / 4);
    image[height - 1][0].rgbtRed = average_red;
    image[height - 1][0].rgbtGreen = average_green;
    image[height - 1][0].rgbtBlue = average_blue;

    // bottom right corner
    average_red = (int) round((original_image[height - 2][width - 2].rgbtRed + original_image[height - 2][width - 1].rgbtRed + original_image[height - 1][width - 2].rgbtRed + original_image[height - 1][width - 1].rgbtRed) / 4);
    average_green = (int) round((original_image[height - 2][width - 2].rgbtGreen + original_image[height - 2][width - 1].rgbtGreen + original_image[height - 1][width - 2].rgbtGreen + original_image[height - 1][width - 1].rgbtGreen) / 4);
    average_blue = (int) round((original_image[height - 2][width - 2].rgbtBlue + original_image[height - 2][width - 1].rgbtBlue + original_image[height - 1][width - 2].rgbtBlue + original_image[height - 1][width - 1].rgbtBlue) / 4);
    image[height - 1][width - 1].rgbtRed = average_red;
    image[height - 1][width - 1].rgbtGreen = average_green;
    image[height - 1][width - 1].rgbtBlue = average_blue;

    for (int i = 0; i < height; i++)
    {
        for (int j  = 0; j < width; j++)
        {
            // middle
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                int red = (int) round((original_image[i-1][j-1].rgbtRed + original_image[i-1][j].rgbtRed + original_image[i-1][j+1].rgbtRed + original_image[i][j-1].rgbtRed + original_image[i][j].rgbtRed + original_image[i][j+1].rgbtRed + original_image[i+1][j-1].rgbtRed + original_image[i+1][j].rgbtRed + original_image[i+1][j+1].rgbtRed) / 9);
                int green = (int) round((original_image[i-1][j-1].rgbtGreen + original_image[i-1][j].rgbtGreen + original_image[i-1][j+1].rgbtGreen + original_image[i][j-1].rgbtGreen + original_image[i][j].rgbtGreen + original_image[i][j+1].rgbtGreen + original_image[i+1][j-1].rgbtGreen + original_image[i+1][j].rgbtGreen + original_image[i+1][j+1].rgbtGreen) / 9);
                int blue = (int) round((original_image[i-1][j-1].rgbtBlue + original_image[i-1][j].rgbtBlue + original_image[i-1][j+1].rgbtBlue + original_image[i][j-1].rgbtBlue + original_image[i][j].rgbtBlue + original_image[i][j+1].rgbtBlue + original_image[i+1][j-1].rgbtBlue + original_image[i+1][j].rgbtBlue + original_image[i+1][j+1].rgbtBlue) / 9);
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
            // top
            else if (i == 0 && j > 0 && j < width - 1)
            {
                int red = (int) round((original_image[i][j-1].rgbtRed + original_image[i][j].rgbtRed + original_image[i][j+1].rgbtRed + original_image[i+1][j-1].rgbtRed + original_image[i+1][j].rgbtRed + original_image[i+1][j+1].rgbtRed) / 6);
                int green = (int) round((original_image[i][j-1].rgbtGreen + original_image[i][j].rgbtGreen + original_image[i][j+1].rgbtGreen + original_image[i+1][j-1].rgbtGreen + original_image[i+1][j].rgbtGreen + original_image[i+1][j+1].rgbtGreen) / 6);
                int blue = (int) round((original_image[i][j-1].rgbtBlue + original_image[i][j].rgbtBlue + original_image[i][j+1].rgbtBlue + original_image[i+1][j-1].rgbtBlue + original_image[i+1][j].rgbtBlue + original_image[i+1][j+1].rgbtBlue) / 6);
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
            // bottom
            else if (i == height - 1 && j > 0 && j < width - 1)
            {
                int red = (int) round((original_image[i-1][j-1].rgbtRed + original_image[i-1][j].rgbtRed + original_image[i-1][j+1].rgbtRed + original_image[i][j-1].rgbtRed + original_image[i][j].rgbtRed + original_image[i][j+1].rgbtRed) / 6);
                int green = (int) round((original_image[i-1][j-1].rgbtGreen + original_image[i-1][j].rgbtGreen + original_image[i-1][j+1].rgbtGreen + original_image[i][j-1].rgbtGreen + original_image[i][j].rgbtGreen + original_image[i][j+1].rgbtGreen) / 6);
                int blue = (int) round((original_image[i-1][j-1].rgbtBlue + original_image[i-1][j].rgbtBlue + original_image[i-1][j+1].rgbtBlue + original_image[i][j-1].rgbtBlue + original_image[i][j].rgbtBlue + original_image[i][j+1].rgbtBlue) / 6);
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
            // left
            else if (j == 0 && i > 0 && i < height - 1)
            {
                int red = (int) round((original_image[i-1][j].rgbtRed + original_image[i-1][j+1].rgbtRed + original_image[i][j].rgbtRed + original_image[i][j+1].rgbtRed + original_image[i+1][j].rgbtRed + original_image[i+1][j+1].rgbtRed) / 6);
                int green = (int) round((original_image[i-1][j].rgbtGreen + original_image[i-1][j+1].rgbtGreen + original_image[i][j].rgbtGreen + original_image[i][j+1].rgbtGreen + original_image[i+1][j].rgbtGreen + original_image[i+1][j+1].rgbtGreen) / 6);
                int blue = (int) round((original_image[i-1][j].rgbtBlue + original_image[i-1][j+1].rgbtBlue + original_image[i][j].rgbtBlue + original_image[i][j+1].rgbtBlue + original_image[i+1][j].rgbtBlue + original_image[i+1][j+1].rgbtBlue) / 6);
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
            // right
            else if (j == width - 1 && i > 0 && i < height - 1)
            {
                int red = (int) round((original_image[i-1][j-1].rgbtRed + original_image[i-1][j].rgbtRed + original_image[i][j-1].rgbtRed + original_image[i][j].rgbtRed + original_image[i+1][j-1].rgbtRed + original_image[i+1][j].rgbtRed) / 6);
                int green = (int) round((original_image[i-1][j-1].rgbtGreen + original_image[i-1][j].rgbtGreen + original_image[i][j-1].rgbtGreen + original_image[i][j].rgbtGreen + original_image[i+1][j-1].rgbtGreen + original_image[i+1][j].rgbtGreen) / 6);
                int blue = (int) round((original_image[i-1][j-1].rgbtBlue + original_image[i-1][j].rgbtBlue + original_image[i][j-1].rgbtBlue + original_image[i][j].rgbtBlue + original_image[i+1][j-1].rgbtBlue + original_image[i+1][j].rgbtBlue) / 6);
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
        }
    }
    return;
}
