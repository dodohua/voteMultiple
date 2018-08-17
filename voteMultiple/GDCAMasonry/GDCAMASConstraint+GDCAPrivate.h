//
//  MASConstraint+Private.h
//  Masonry
//
//  Created by Nick Tymchenko on 29/04/14.
//  Copyright (c) 2014 cloudling. All rights reserved.
//

#import "GDCAMASConstraint.h"

@protocol GDCAMASConstraintDelegate;


@interface GDCAMASConstraint ()

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	Usually GDCAMASConstraintMaker but could be a parent MASConstraint
 */
@property (nonatomic, weak) id<GDCAMASConstraintDelegate> delegate;

/**
 *  Based on a provided value type, is equal to calling:
 *  NSNumber - setOffset:
 *  NSValue with CGPoint - setPointOffset:
 *  NSValue with CGSize - setSizeOffset:
 *  NSValue with MASEdgeInsets - setInsets:
 */
- (void)setLayoutConstantWithValue:(NSValue *)value;

@end


@interface GDCAMASConstraint (Abstract)

/**
 *	Sets the constraint relation to given NSLayoutRelation
 *  returns a block which accepts one of the following:
 *    GDCAMASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (GDCAMASConstraint * (^)(id, NSLayoutRelation))equalToWithRelation;

/**
 *	Override to set a custom chaining behaviour
 */
- (GDCAMASConstraint *)addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end


@protocol GDCAMASConstraintDelegate <NSObject>

/**
 *	Notifies the delegate when the constraint needs to be replaced with another constraint. For example
 *  A GDCAMASViewConstraint may turn into a GDCAMASCompositeConstraint when an array is passed to one of the equality blocks
 */
- (void)constraint:(GDCAMASConstraint *)constraint shouldBeReplacedWithConstraint:(GDCAMASConstraint *)replacementConstraint;

- (GDCAMASConstraint *)constraint:(GDCAMASConstraint *)constraint addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end
