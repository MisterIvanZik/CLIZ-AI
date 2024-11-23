/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   struct.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/06 23:20:54 by ivan                  #+#       #+#    #+#    #+#    #+#            */
/*   Updated: 2024/11/06 23:20:54 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "includes.h"

typedef enum {
    PAGE_HOME,
    PAGE_SIGN_UP,
    PAGE_SIGN_IN,
    PAGE_CHATBOT
} PageType;

typedef struct Button_s{
    sfRectangleShape* shape;
    sfText* text;
    sfFloatRect bounds;
} Button_t;

typedef struct {
    sfRectangleShape *box;
    sfText *text;
    char *content;
} TextBox_t;

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfFont *textBoxFont;
    Button_t signUpButton;
    Button_t signInButton;
    Button_t chatbotButton;
    bool isRunning;
    int currentPage;
    bool animationPlayed;
    sfTexture *backgroundTexture;
    sfSprite *backgroundSprite;
    sfTexture *backgroundTexture_chat;
    sfSprite *backgroundSprite_chat;
    TextBox_t chatbox;
} Struct_t;

typedef struct {
    sfTexture *texture;
    sfIntRect *frames;
    int frameCount;
    float frameDuration;
} Animation_t;

#endif
