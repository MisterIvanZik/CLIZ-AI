/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   events.c                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/22 13:54:31 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/22 13:54:31 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

#include "includes.h"
#include "macros.h"
#include "struct.h"
#include "prototypes.h"

void handleEvents(Struct_t *cliz)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(cliz->window, &event)) {
        if (event.type == sfEvtClosed)
            cliz->isRunning = false;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            cliz->isRunning = false;
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            sfVector2i mousePos = sfMouse_getPositionRenderWindow(cliz->window);
            sfVector2f mousePosF = {mousePos.x, mousePos.y};
            if (sfFloatRect_contains(&cliz->signUpButton.bounds, mousePosF.x, mousePosF.y)) {
                cliz->currentPage = PAGE_SIGN_UP;
            }
            if (sfFloatRect_contains(&cliz->signInButton.bounds, mousePosF.x, mousePosF.y)) {
                cliz->currentPage = PAGE_SIGN_IN;
            }
            if (sfFloatRect_contains(&cliz->chatbotButton.bounds, mousePosF.x, mousePosF.y)) {
                cliz->currentPage = PAGE_CHATBOT;
            }
        }
        if (event.type == sfEvtTextEntered && cliz->currentPage == PAGE_CHATBOT) {
            if (event.text.unicode == 8 && strlen(cliz->chatbox.content) > 0) {
                cliz->chatbox.content[strlen(cliz->chatbox.content) - 1] = '\0';
            } else if (event.text.unicode < 128 && event.text.unicode != 8) {
                size_t len = strlen(cliz->chatbox.content);
                if (len < sizeof(cliz->chatbox.content) - 1) {
                    cliz->chatbox.content[len] = (char)event.text.unicode;
                    cliz->chatbox.content[len + 1] = '\0';
                }
            }
        }
    }
}
