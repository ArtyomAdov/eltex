#ifndef DEATH_ANGEL_ERROR_H

#define DEATH_ANGEL_ERROR_H

#define ERROR_ALLOCATION_MEMORY 0b00000001
#define ERROR_OUT_OF_MEMORY 0b00000010

#define CHECK_ERROR_FLAG(error_flag) \
	{                                \
		if(0b0 != error_flag)        \
		{                            \
			return error_flag;       \
		}                            \
	}

#endif