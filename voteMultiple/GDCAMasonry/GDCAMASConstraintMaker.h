//
//  GDCAMASConstraintMaker.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "GDCAMASConstraint.h"
#import "GDCAMASUtilities.h"

typedef NS_OPTIONS(NSInteger, MASAttribute) {
    MASAttributeLeft = 1 << NSLayoutAttributeLeft,
    MASAttributeRight = 1 << NSLayoutAttributeRight,
    MASAttributeTop = 1 << NSLayoutAttributeTop,
    MASAttributeBottom = 1 << NSLayoutAttributeBottom,
    MASAttributeLeading = 1 << NSLayoutAttributeLeading,
    MASAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    MASAttributeWidth = 1 << NSLayoutAttributeWidth,
    MASAttributeHeight = 1 << NSLayoutAttributeHeight,
    MASAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    MASAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    MASAttributeBaseline = 1 << NSLayoutAttributeBaseline,

    MASAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    MASAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#if TARGET_OS_IPHONE || TARGET_OS_TV
    
    MASAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    MASAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    MASAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    MASAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    MASAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    MASAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    MASAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    MASAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface GDCAMASConstraintMaker : NSObject

/**
 *	The following properties return a new GDCAMASViewConstraint
 *  with the first item set to the makers associated view and the appropriate GDCAMASViewAttribute
 */
@property (nonatomic, strong, readonly) GDCAMASConstraint *left;
@property (nonatomic, strong, readonly) GDCAMASConstraint *top;
@property (nonatomic, strong, readonly) GDCAMASConstraint *right;
@property (nonatomic, strong, readonly) GDCAMASConstraint *bottom;
@property (nonatomic, strong, readonly) GDCAMASConstraint *leading;
@property (nonatomic, strong, readonly) GDCAMASConstraint *trailing;
@property (nonatomic, strong, readonly) GDCAMASConstraint *width;
@property (nonatomic, strong, readonly) GDCAMASConstraint *height;
@property (nonatomic, strong, readonly) GDCAMASConstraint *centerX;
@property (nonatomic, strong, readonly) GDCAMASConstraint *centerY;
@property (nonatomic, strong, readonly) GDCAMASConstraint *baseline;

@property (nonatomic, strong, readonly) GDCAMASConstraint *firstBaseline;
@property (nonatomic, strong, readonly) GDCAMASConstraint *lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) GDCAMASConstraint *leftMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *rightMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *topMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *bottomMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *leadingMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *trailingMargin;
@property (nonatomic, strong, readonly) GDCAMASConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) GDCAMASConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new GDCAMASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  MASAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) GDCAMASConstraint *(^attributes)(MASAttribute attrs);

/**
 *	Creates a GDCAMASCompositeConstraint with type GDCAMASCompositeConstraintTypeEdges
 *  which generates the appropriate GDCAMASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) GDCAMASConstraint *edges;

/**
 *	Creates a GDCAMASCompositeConstraint with type GDCAMASCompositeConstraintTypeSize
 *  which generates the appropriate GDCAMASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) GDCAMASConstraint *size;

/**
 *	Creates a GDCAMASCompositeConstraint with type GDCAMASCompositeConstraintTypeCenter
 *  which generates the appropriate GDCAMASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) GDCAMASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstraint are created with this view as the first item
 *
 *	@return	a new MASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (GDCAMASConstraint * (^)(dispatch_block_t))group;

@end
