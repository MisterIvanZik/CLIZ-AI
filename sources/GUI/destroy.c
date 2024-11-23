/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy.c                                                 :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/22 13:56:31 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/22 13:56:31 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

void cleanup(Struct_t *cliz)
{
    if (cliz) {
        sfRectangleShape_destroy(cliz->signUpButton.shape);
        sfText_destroy(cliz->signUpButton.text);
        sfRectangleShape_destroy(cliz->signInButton.shape);
        sfText_destroy(cliz->signInButton.text);
        sfRectangleShape_destroy(cliz->chatbotButton.shape);
        sfText_destroy(cliz->chatbotButton.text);
        sfTexture_destroy(cliz->backgroundTexture);
        sfSprite_destroy(cliz->backgroundSprite);
        sfTexture_destroy(cliz->backgroundTexture_chat);
        sfSprite_destroy(cliz->backgroundSprite_chat);
        sfRectangleShape_destroy(cliz->chatbox.box);
        sfText_destroy(cliz->chatbox.text);
        free(cliz->chatbox.content);
        sfFont_destroy(cliz->font);
        sfFont_destroy(cliz->textBoxFont);
        sfRenderWindow_destroy(cliz->window);
        free(cliz);
    }
}