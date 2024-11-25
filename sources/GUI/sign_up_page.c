/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   sign_up_page.c                                            :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/22 13:55:50 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/22 13:55:50 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

void drawTextBox(sfRenderWindow *window, sfFont *font, char *label, sfVector2f position)
{
    sfRectangleShape *box = NULL;
    sfText *text = NULL;

    box = sfRectangleShape_create();
    sfRectangleShape_setSize(box, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(box, position);
    sfRectangleShape_setFillColor(box, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(box, 2);
    sfRectangleShape_setOutlineColor(box, sfBlack);
    sfRenderWindow_drawRectangleShape(window, box, NULL);
    sfRectangleShape_destroy(box);

    text = sfText_create();
    sfText_setString(text, label);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){position.x + 10, position.y + 10});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void drawSignUpPage(Struct_t *cliz)
{
    sfText *title = NULL;

    title = sfText_create();
    sfText_setString(title, "Sign Up");
    sfText_setFont(title, cliz->font);
    sfText_setCharacterSize(title, 30);
    sfText_setFillColor(title, sfBlack);
    sfText_setPosition(title, (sfVector2f){850, 100});
    sfRenderWindow_drawText(cliz->window, title, NULL);
    sfText_destroy(title);
    drawTextBox(cliz->window, cliz->font, "Username", (sfVector2f){700, 200});
    drawTextBox(cliz->window, cliz->font, "Email", (sfVector2f){700, 300});
    drawTextBox(cliz->window, cliz->font, "Password", (sfVector2f){700, 400});
}
