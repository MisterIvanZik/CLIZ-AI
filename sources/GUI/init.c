/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init.c                                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/22 13:53:17 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/22 13:53:17 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

Struct_t *initGame(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    Struct_t *cliz = malloc(sizeof(Struct_t));

    if (!cliz)
        return NULL;
    cliz->window = sfRenderWindow_create(mode, "CLIZ AI", sfResize | sfClose, NULL);
    if (!cliz->window) {
        free(cliz);
        return NULL;
    }
    cliz->font = sfFont_createFromFile("assets/fonts/font.ttf");
    if (!cliz->font) {
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
        return NULL;
    }
    cliz->textBoxFont = sfFont_createFromFile("assets/fonts/regular.otf");
    if (!cliz->textBoxFont) {
        sfFont_destroy(cliz->font);
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
        return NULL;
    }
    cliz->signUpButton = createButton(
        cliz->font,
        "Sign Up",
        (sfVector2f){750, 150},
        (sfVector2f){150, 50}
    );
    cliz->signInButton = createButton(
        cliz->font,
        "Sign In",
        (sfVector2f){950, 150},
        (sfVector2f){150, 50}
    );
    cliz->chatbotButton = createButton(
        cliz->font,
        "Chatbot",
        (sfVector2f){850, 250},
        (sfVector2f){150, 50}
    );
    cliz->isRunning = true;
    cliz->currentPage = PAGE_HOME;
    cliz->animationPlayed = false;

    Animation_t *animation = loadAnimation("assets/images/intro_one.png", FRAME_COUNT, FRAME_DURATION, FRAME_COLUMNS, FRAME_ROWS);
    if (animation) {
        playAnimation(cliz->window, animation);
        destroyAnimation(animation);
    }
    cliz->animationPlayed = true;
    cliz->backgroundTexture = sfTexture_createFromFile("assets/images/home_page.png", NULL);
    if (!cliz->backgroundTexture) {
        sfFont_destroy(cliz->font);
        sfFont_destroy(cliz->textBoxFont);
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
        return NULL;
    }
    cliz->backgroundSprite = sfSprite_create();
    sfSprite_setTexture(cliz->backgroundSprite, cliz->backgroundTexture, sfTrue);
    cliz->backgroundTexture_chat = sfTexture_createFromFile("assets/images/background_chatbot.jpg", NULL);
    if (!cliz->backgroundTexture_chat) {
        sfFont_destroy(cliz->font);
        sfFont_destroy(cliz->textBoxFont);
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
        return NULL;
    }
    cliz->backgroundSprite_chat = sfSprite_create();
    sfSprite_setTexture(cliz->backgroundSprite_chat, cliz->backgroundTexture_chat, sfTrue);

    cliz->chatbox.box = sfRectangleShape_create();
    sfRectangleShape_setSize(cliz->chatbox.box, (sfVector2f){600, 50});
    sfRectangleShape_setPosition(cliz->chatbox.box, (sfVector2f){660, 900});
    sfRectangleShape_setFillColor(cliz->chatbox.box, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(cliz->chatbox.box, 2);
    sfRectangleShape_setOutlineColor(cliz->chatbox.box, sfBlack);

    cliz->chatbox.text = sfText_create();
    sfText_setFont(cliz->chatbox.text, cliz->textBoxFont);
    sfText_setCharacterSize(cliz->chatbox.text, 20);
    sfText_setFillColor(cliz->chatbox.text, sfBlack);
    sfText_setPosition(cliz->chatbox.text, (sfVector2f){670, 910});
    cliz->chatbox.content = malloc(sizeof(char) * 100);
    if (!cliz->chatbox.content) {
        sfRectangleShape_destroy(cliz->chatbox.box);
        sfText_destroy(cliz->chatbox.text);
        sfFont_destroy(cliz->font);
        sfFont_destroy(cliz->textBoxFont);
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
        return NULL;
    }
    cliz->chatbox.content[0] = '\0';

    return cliz;
}