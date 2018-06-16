#include<cstdlib>
#include"generatew.h"

weapon *genw(int id){

    weapon *ptr;

    switch (id) {
    case 0:
        ptr= new bullet;
        break;
    case 1:
        ptr= new bomb;
        break;
    case 2:
        ptr= new ult;
        break;
     case 3:
        ptr = new boosw;
        break;
    }
    return ptr;

}
