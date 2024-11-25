/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   gui.c                                                     :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/06 23:36:13 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/06 23:36:13 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

Button_t createButton(sfFont *font, char *text, sfVector2f position, sfVector2f size)
{
    Button_t button;

    button.shape = sfRectangleShape_create();
    sfRectangleShape_setSize(button.shape, size);
    sfRectangleShape_setPosition(button.shape, position);
    sfRectangleShape_setFillColor(button.shape, sfColor_fromRGB(200, 200, 200));
    sfRectangleShape_setOutlineThickness(button.shape, 2);
    sfRectangleShape_setOutlineColor(button.shape, sfBlack);
    button.text = sfText_create();
    sfText_setString(button.text, text);
    sfText_setFont(button.text, font);
    sfText_setCharacterSize(button.text, 20);
    sfText_setFillColor(button.text, sfBlack);
    sfFloatRect textRect = sfText_getGlobalBounds(button.text);
    sfVector2f textPosition = {
        position.x + (size.x - textRect.width) / 2,
        position.y + (size.y - textRect.height) / 2
    };
    sfText_setPosition(button.text, textPosition);
    button.bounds = sfRectangleShape_getGlobalBounds(button.shape);
    return button;
}

void drawHomePage(Struct_t *cliz)
{
    sfRenderWindow_drawSprite(cliz->window, cliz->backgroundSprite, NULL);
    sfRenderWindow_drawRectangleShape(cliz->window, cliz->signUpButton.shape, NULL);
    sfRenderWindow_drawText(cliz->window, cliz->signUpButton.text, NULL);
    sfRenderWindow_drawRectangleShape(cliz->window, cliz->signInButton.shape, NULL);
    sfRenderWindow_drawText(cliz->window, cliz->signInButton.text, NULL);
    sfRenderWindow_drawRectangleShape(cliz->window, cliz->chatbotButton.shape, NULL);
    sfRenderWindow_drawText(cliz->window, cliz->chatbotButton.text, NULL);
}

void drawWindow(Struct_t *cliz)
{
    Animation_t *animation = NULL;
    sfColor beigeColor;

    beigeColor.r = 245;
    beigeColor.g = 245;
    beigeColor.b = 220;
    if (!cliz->animationPlayed) {
        animation = loadAnimation("assets/images/intro_one.png", FRAME_COUNT, FRAME_DURATION, FRAME_COLUMNS, FRAME_ROWS);
        if (animation) {
            playAnimation(cliz->window, animation);
            destroyAnimation(animation);
        }
        cliz->animationPlayed = true;
    } else {
        if (cliz->currentPage == PAGE_HOME) {
            sfRenderWindow_clear(cliz->window, beigeColor);
            drawHomePage(cliz);
        } else {
            switch (cliz->currentPage) {
                case PAGE_SIGN_UP:
                    sfRenderWindow_clear(cliz->window, sfWhite);
                    drawSignUpPage(cliz);
                    break;
                case PAGE_SIGN_IN:
                    sfRenderWindow_clear(cliz->window, sfBlack);
                    break;
                case PAGE_CHATBOT:
                    sfRenderWindow_clear(cliz->window, sfWhite);
                    drawChatbotPage(cliz);
                    break;
                default:
                    sfRenderWindow_clear(cliz->window, sfBlack);
                    break;
            }
        }
    }
    sfRenderWindow_display(cliz->window);
}
