

#ifndef GUN_H
#define GUN_H

#include "projectile.h"

typedef enum{
    PLUS_ONE,
    MINUS_ONE,
    HALF,
    DOUBLE,
    SQRT
} GunType;

typedef struct 
{
    GunType type;
    Projectile bullet;
} Gun;


#endif