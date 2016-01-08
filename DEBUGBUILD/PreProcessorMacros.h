//
//  PreProcessorMacros.h
//  China
//
//  Created by Limon on 16/1/8.
//  Copyright © 2016年 DEBUGBUILD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PreProcessorMacros : NSObject

#ifndef PreProcessorMacros_h
#define PreProcessorMacros_h

extern BOOL const DEBUG_BUILD;

#endif

@end



@implementation PreProcessorMacros

#ifdef DEBUG
BOOL const DEBUG_BUILD = YES;
#else
BOOL const DEBUG_BUILD = NO;
#endif

@end
