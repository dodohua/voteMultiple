//
//  NSArray+MASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "NSArray+GDCAMASAdditions.h"

#ifdef MAS_SHORTHAND

/**
 *	Shorthand array additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface NSArray (MASShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(GDCAMASConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(GDCAMASConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(GDCAMASConstraintMaker *make))block;

@end

@implementation NSArray (MASShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(GDCAMASConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(^)(GDCAMASConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(^)(GDCAMASConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
