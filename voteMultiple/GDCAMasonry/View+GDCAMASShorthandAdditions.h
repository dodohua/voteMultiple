//
//  UIView+MASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "View+GDCAMASAdditions.h"

#ifdef MAS_SHORTHAND

/**
 *	Shorthand view additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface MAS_VIEW (MASShorthandAdditions)

@property (nonatomic, strong, readonly) GDCAMASViewAttribute *left;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *top;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *right;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *bottom;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *leading;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *trailing;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *width;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *height;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *centerX;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *centerY;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *baseline;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *(^attribute)(NSLayoutAttribute attr);

@property (nonatomic, strong, readonly) GDCAMASViewAttribute *firstBaseline;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) GDCAMASViewAttribute *leftMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *rightMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *topMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *bottomMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *leadingMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *trailingMargin;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *centerXWithinMargins;
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *centerYWithinMargins;

#endif

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideLeading NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideTrailing NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideLeft NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideRight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideTop NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideBottom NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideWidth NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideHeight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideCenterX NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *safeAreaLayoutGuideCenterY NS_AVAILABLE_IOS(11.0);

#endif

- (NSArray *)makeConstraints:(void(^)(GDCAMASConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(GDCAMASConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(GDCAMASConstraintMaker *make))block;

@end

#define MAS_ATTR_FORWARD(attr)  \
- (GDCAMASViewAttribute *)attr {    \
    return [self mas_##attr];   \
}

#define MAS_ATTR_FORWARD_AVAILABLE(attr, available)  \
- (GDCAMASViewAttribute *)attr available {    \
    return [self mas_##attr];   \
}

@implementation MAS_VIEW (MASShorthandAdditions)

MAS_ATTR_FORWARD(top);
MAS_ATTR_FORWARD(left);
MAS_ATTR_FORWARD(bottom);
MAS_ATTR_FORWARD(right);
MAS_ATTR_FORWARD(leading);
MAS_ATTR_FORWARD(trailing);
MAS_ATTR_FORWARD(width);
MAS_ATTR_FORWARD(height);
MAS_ATTR_FORWARD(centerX);
MAS_ATTR_FORWARD(centerY);
MAS_ATTR_FORWARD(baseline);

MAS_ATTR_FORWARD(firstBaseline);
MAS_ATTR_FORWARD(lastBaseline);

#if TARGET_OS_IPHONE || TARGET_OS_TV

MAS_ATTR_FORWARD(leftMargin);
MAS_ATTR_FORWARD(rightMargin);
MAS_ATTR_FORWARD(topMargin);
MAS_ATTR_FORWARD(bottomMargin);
MAS_ATTR_FORWARD(leadingMargin);
MAS_ATTR_FORWARD(trailingMargin);
MAS_ATTR_FORWARD(centerXWithinMargins);
MAS_ATTR_FORWARD(centerYWithinMargins);

MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideLeading, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideTrailing, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideLeft, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideRight, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideTop, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideBottom, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideWidth, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideHeight, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideCenterX, NS_AVAILABLE_IOS(11.0));
MAS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideCenterY, NS_AVAILABLE_IOS(11.0));

#endif

- (GDCAMASViewAttribute *(^)(NSLayoutAttribute))attribute {
    return [self mas_attribute];
}

- (NSArray *)makeConstraints:(void(NS_NOESCAPE ^)(GDCAMASConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(NS_NOESCAPE ^)(GDCAMASConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(NS_NOESCAPE ^)(GDCAMASConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
