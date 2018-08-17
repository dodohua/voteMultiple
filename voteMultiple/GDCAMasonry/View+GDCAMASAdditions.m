//
//  UIView+MASAdditions.m
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "View+GDCAMASAdditions.h"
#import <objc/runtime.h>

@implementation MAS_VIEW (MASAdditions)

- (NSArray *)mas_makeConstraints:(void(^)(GDCAMASConstraintMaker *))block {
    self.translatesAutoresizingMaskIntoConstraints = NO;
    GDCAMASConstraintMaker *constraintMaker = [[GDCAMASConstraintMaker alloc] initWithView:self];
    block(constraintMaker);
    return [constraintMaker install];
}

- (NSArray *)mas_updateConstraints:(void(^)(GDCAMASConstraintMaker *))block {
    self.translatesAutoresizingMaskIntoConstraints = NO;
    GDCAMASConstraintMaker *constraintMaker = [[GDCAMASConstraintMaker alloc] initWithView:self];
    constraintMaker.updateExisting = YES;
    block(constraintMaker);
    return [constraintMaker install];
}

- (NSArray *)mas_remakeConstraints:(void(^)(GDCAMASConstraintMaker *make))block {
    self.translatesAutoresizingMaskIntoConstraints = NO;
    GDCAMASConstraintMaker *constraintMaker = [[GDCAMASConstraintMaker alloc] initWithView:self];
    constraintMaker.removeExisting = YES;
    block(constraintMaker);
    return [constraintMaker install];
}

#pragma mark - NSLayoutAttribute properties

- (GDCAMASViewAttribute *)mas_left {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeLeft];
}

- (GDCAMASViewAttribute *)mas_top {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeTop];
}

- (GDCAMASViewAttribute *)mas_right {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeRight];
}

- (GDCAMASViewAttribute *)mas_bottom {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeBottom];
}

- (GDCAMASViewAttribute *)mas_leading {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeLeading];
}

- (GDCAMASViewAttribute *)mas_trailing {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeTrailing];
}

- (GDCAMASViewAttribute *)mas_width {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeWidth];
}

- (GDCAMASViewAttribute *)mas_height {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeHeight];
}

- (GDCAMASViewAttribute *)mas_centerX {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeCenterX];
}

- (GDCAMASViewAttribute *)mas_centerY {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeCenterY];
}

- (GDCAMASViewAttribute *)mas_baseline {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeBaseline];
}

- (GDCAMASViewAttribute *(^)(NSLayoutAttribute))mas_attribute
{
    return ^(NSLayoutAttribute attr) {
        return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:attr];
    };
}

- (GDCAMASViewAttribute *)mas_firstBaseline {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeFirstBaseline];
}
- (GDCAMASViewAttribute *)mas_lastBaseline {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeLastBaseline];
}

#if TARGET_OS_IPHONE || TARGET_OS_TV

- (GDCAMASViewAttribute *)mas_leftMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeLeftMargin];
}

- (GDCAMASViewAttribute *)mas_rightMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeRightMargin];
}

- (GDCAMASViewAttribute *)mas_topMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeTopMargin];
}

- (GDCAMASViewAttribute *)mas_bottomMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeBottomMargin];
}

- (GDCAMASViewAttribute *)mas_leadingMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeLeadingMargin];
}

- (GDCAMASViewAttribute *)mas_trailingMargin {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeTrailingMargin];
}

- (GDCAMASViewAttribute *)mas_centerXWithinMargins {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeCenterXWithinMargins];
}

- (GDCAMASViewAttribute *)mas_centerYWithinMargins {
    return [[GDCAMASViewAttribute alloc] initWithView:self layoutAttribute:NSLayoutAttributeCenterYWithinMargins];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuide {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeNotAnAttribute];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideLeading {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeLeading];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideTrailing {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeTrailing];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideLeft {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeLeft];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideRight {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeRight];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideTop {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeTop];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideBottom {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeBottom];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideWidth {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeWidth];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideHeight {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeHeight];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideCenterX {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeCenterX];
}

- (GDCAMASViewAttribute *)mas_safeAreaLayoutGuideCenterY {
    return [[GDCAMASViewAttribute alloc] initWithView:self item:self.safeAreaLayoutGuide layoutAttribute:NSLayoutAttributeCenterY];
}

#endif

#pragma mark - associated properties

- (id)mas_key {
    return objc_getAssociatedObject(self, @selector(mas_key));
}

- (void)setMas_key:(id)key {
    objc_setAssociatedObject(self, @selector(mas_key), key, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

#pragma mark - heirachy

- (instancetype)mas_closestCommonSuperview:(MAS_VIEW *)view {
    MAS_VIEW *closestCommonSuperview = nil;

    MAS_VIEW *secondViewSuperview = view;
    while (!closestCommonSuperview && secondViewSuperview) {
        MAS_VIEW *firstViewSuperview = self;
        while (!closestCommonSuperview && firstViewSuperview) {
            if (secondViewSuperview == firstViewSuperview) {
                closestCommonSuperview = secondViewSuperview;
            }
            firstViewSuperview = firstViewSuperview.superview;
        }
        secondViewSuperview = secondViewSuperview.superview;
    }
    return closestCommonSuperview;
}

@end
