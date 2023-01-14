#include "Katren.h"

bool Katren::operator*() const
{
    if (this->getKap() == this->brElem and (this->nizStihova[0] ^ this->nizStihova[brElem - 1]) and (this->nizStihova[1] ^ this->nizStihova[brElem - 2])) return true;
    return false;
}
