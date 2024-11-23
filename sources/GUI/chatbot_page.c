/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   chatbot_page.c                                            :+:       :+:    :+: :+:    :+:    :+:        */
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

void drawChatbotPage(Struct_t *cliz)
{
    sfRenderWindow_drawSprite(cliz->window, cliz->backgroundSprite_chat, NULL);

    sfText *title = sfText_create();
    sfText_setString(title, "Chatbot");
    sfText_setFont(title, cliz->font);
    sfText_setCharacterSize(title, 30);
    sfText_setFillColor(title, sfBlack);
    sfText_setPosition(title, (sfVector2f){850, 100});
    sfRenderWindow_drawText(cliz->window, title, NULL);
    sfText_destroy(title);
    sfRenderWindow_drawRectangleShape(cliz->window, cliz->chatbox.box, NULL);
    sfText_setString(cliz->chatbox.text, cliz->chatbox.content);
    sfRenderWindow_drawText(cliz->window, cliz->chatbox.text, NULL);
}
