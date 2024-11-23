/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   animation.c                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/11/16 02:02:07 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/11/16 02:02:07 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"
#include "macros.h"
#include "struct.h"

Animation_t *loadAnimation(char *filename, int frameCount, float frameDuration, int frameColumns, int frameRows)
{
    Animation_t *animation = malloc(sizeof(Animation_t));

    animation->texture = sfTexture_createFromFile(filename, NULL);
    if (!animation->texture) {
        free(animation);
        return NULL;
    }
    animation->frames = malloc(sizeof(sfIntRect) * frameCount);
    animation->frameCount = frameCount;
    animation->frameDuration = frameDuration;
    int frameWidth = sfTexture_getSize(animation->texture).x / frameColumns;
    int frameHeight = sfTexture_getSize(animation->texture).y / frameRows;
    for (int i = 0; i < frameCount; i++) {
        int column = i % frameColumns;
        int row = i / frameColumns;
        animation->frames[i] = (sfIntRect){column * frameWidth, row * frameHeight, frameWidth, frameHeight};
    }
    return animation;
}

void destroyAnimation(Animation_t *animation)
{
    sfTexture_destroy(animation->texture);
    free(animation->frames);
    free(animation);
}

void playAnimation(sfRenderWindow *window, Animation_t *animation)
{
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();
    float elapsedTime = 0.0f;
    int currentFrame = 0;

    sfSprite_setTexture(sprite, animation->texture, sfTrue);
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    int frameWidth = animation->frames[0].width;
    int frameHeight = animation->frames[0].height;
    sfVector2f centeredPosition = {
        (windowSize.x - frameWidth) / 2.0f,
        (windowSize.y - frameHeight) / 2.0f
    };
    while (elapsedTime < animation->frameCount * animation->frameDuration) {
        sfTime time = sfClock_getElapsedTime(clock);
        elapsedTime = sfTime_asSeconds(time);
        currentFrame = (int)(elapsedTime / animation->frameDuration) % animation->frameCount;
        sfSprite_setTextureRect(sprite, animation->frames[currentFrame]);
        sfSprite_setPosition(sprite, centeredPosition);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfClock_destroy(clock);
}