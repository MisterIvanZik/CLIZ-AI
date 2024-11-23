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

void drawSignUpPage(Struct_t *cliz)
{
    sfText *title = sfText_create();
    sfText_setString(title, "Sign Up");
    sfText_setFont(title, cliz->font);
    sfText_setCharacterSize(title, 30);
    sfText_setFillColor(title, sfBlack);
    sfText_setPosition(title, (sfVector2f){850, 100});
    sfRenderWindow_drawText(cliz->window, title, NULL);
    sfText_destroy(title);

    sfRectangleShape *usernameBox = sfRectangleShape_create();
    sfRectangleShape_setSize(usernameBox, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(usernameBox, (sfVector2f){700, 200});
    sfRectangleShape_setFillColor(usernameBox, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(usernameBox, 2);
    sfRectangleShape_setOutlineColor(usernameBox, sfBlack);
    sfRenderWindow_drawRectangleShape(cliz->window, usernameBox, NULL);
    sfRectangleShape_destroy(usernameBox);

    sfText *usernameText = sfText_create();
    sfText_setString(usernameText, "Username");
    sfText_setFont(usernameText, cliz->font);
    sfText_setCharacterSize(usernameText, 20);
    sfText_setFillColor(usernameText, sfBlack);
    sfText_setPosition(usernameText, (sfVector2f){710, 210});
    sfRenderWindow_drawText(cliz->window, usernameText, NULL);
    sfText_destroy(usernameText);

    sfRectangleShape *emailBox = sfRectangleShape_create();
    sfRectangleShape_setSize(emailBox, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(emailBox, (sfVector2f){700, 300});
    sfRectangleShape_setFillColor(emailBox, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(emailBox, 2);
    sfRectangleShape_setOutlineColor(emailBox, sfBlack);
    sfRenderWindow_drawRectangleShape(cliz->window, emailBox, NULL);
    sfRectangleShape_destroy(emailBox);

    sfText *emailText = sfText_create();
    sfText_setString(emailText, "Email");
    sfText_setFont(emailText, cliz->font);
    sfText_setCharacterSize(emailText, 20);
    sfText_setFillColor(emailText, sfBlack);
    sfText_setPosition(emailText, (sfVector2f){710, 310});
    sfRenderWindow_drawText(cliz->window, emailText, NULL);
    sfText_destroy(emailText);

    sfRectangleShape *passwordBox = sfRectangleShape_create();
    sfRectangleShape_setSize(passwordBox, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(passwordBox, (sfVector2f){700, 400});
    sfRectangleShape_setFillColor(passwordBox, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(passwordBox, 2);
    sfRectangleShape_setOutlineColor(passwordBox, sfBlack);
    sfRenderWindow_drawRectangleShape(cliz->window, passwordBox, NULL);
    sfRectangleShape_destroy(passwordBox);

    sfText *passwordText = sfText_create();
    sfText_setString(passwordText, "Password");
    sfText_setFont(passwordText, cliz->font);
    sfText_setCharacterSize(passwordText, 20);
    sfText_setFillColor(passwordText, sfBlack);
    sfText_setPosition(passwordText, (sfVector2f){710, 410});
    sfRenderWindow_drawText(cliz->window, passwordText, NULL);
    sfText_destroy(passwordText);
}
