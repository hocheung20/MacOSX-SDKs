//
//  ATSDefines.h
//  ATS
//
//  Copyright (c) 2011-2012 Apple Inc. All rights reserved.
//

#ifndef __ATSDEFINES__
#define __ATSDEFINES__

#if defined(BUILDING_ATS)
# define ATS_AVAILABLE_BUT_DEPRECATED_WITH_ADVICE(_mac,_macDep,_deprecationAdvice)
# define ATS_AVAILABLE_BUT_DEPRECATED(_mac,_macDep)
# define ATS_DEPRECATED_IN_MAC_OS_X_VERSION(_macDep) // For types
#elif defined(__has_extension) /* defined(BUILDING_ATS) */
# if __has_extension(attribute_deprecated_with_message)
#  define ATS_AVAILABLE_BUT_DEPRECATED_WITH_ADVICE(_mac,_macDep,_deprecationAdvice) __attribute__((deprecated(_deprecationAdvice)))
# endif /*__has_extension(attribute_deprecated_with_message) */
#endif /* defined(__has_extension)*/ /* defined(BUILDING_ATS) */

#if !defined(ATS_AVAILABLE_BUT_DEPRECATED_WITH_ADVICE)
# include <Availability.h>
# if defined(__MAC_10_8)
#  define ATS_AVAILABLE_BUT_DEPRECATED_WITH_ADVICE(_mac,_macDep,_deprecationAdvice) AVAILABLE_MAC_OS_X_VERSION_##_mac##_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_##_macDep
# else
#  define ATS_AVAILABLE_BUT_DEPRECATED_WITH_ADVICE(_mac,_macDep,_deprecationAdvice) AVAILABLE_MAC_OS_X_VERSION_##_mac##_AND_LATER
# endif
#endif

#if !defined(ATS_AVAILABLE_BUT_DEPRECATED)
# include <Availability.h>
# if defined(__MAC_10_8)
#  define ATS_AVAILABLE_BUT_DEPRECATED(_mac,_macDep) AVAILABLE_MAC_OS_X_VERSION_##_mac##_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_##_macDep
# else
#  define ATS_AVAILABLE_BUT_DEPRECATED(_mac,_macDep) AVAILABLE_MAC_OS_X_VERSION_##_mac##_AND_LATER
# endif
#endif

#if !defined(ATS_DEPRECATED_IN_MAC_OS_X_VERSION)
# define ATS_DEPRECATED_IN_MAC_OS_X_VERSION(_macDep) DEPRECATED_IN_MAC_OS_X_VERSION_##_macDep##_AND_LATER
#endif

#endif //__ATSDEFINES__
