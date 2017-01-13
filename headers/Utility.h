#ifndef UTILITY_H
#define UTILITY_H

template<class T>
T sign(float a) {
	if(a >= 0)
		return 1;
	else
		return -1;
}

#endif