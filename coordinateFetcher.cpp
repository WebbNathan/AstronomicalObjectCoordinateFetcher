#include <iostream>
#include "AstronomicalObjectsProto.h"
using namespace std;

/* Step zero: catalog preperation and source data (NON SOLAR SYSTEM OBJECTS)

    - Probably the first step should be to load the J2000 data into an object

*/

void setObjectData(AstronomicalObject &newObj, FILE* J200_data);
