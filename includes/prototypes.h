/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   prototypes.h                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/06 23:40:46 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/06 23:40:46 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_
    #include "includes.h"
    #include "struct.h"

Button_t createButton(sfFont *font, char *text, sfVector2f position, sfVector2f size);
Struct_t *initGame(void);
void handleEvents(Struct_t *cliz);
void drawHomePage(Struct_t *cliz);
void drawWindow(Struct_t *cliz);
void cleanup(Struct_t *cliz);
Animation_t *loadAnimation(char *filename, int frameCount, float frameDuration, int frameColumns, int frameRows);
void destroyAnimation(Animation_t *animation);
void playAnimation(sfRenderWindow *window, Animation_t *animation);
void drawSignUpPage(Struct_t *cliz);
void drawChatbotPage(Struct_t *cliz);

#endif
