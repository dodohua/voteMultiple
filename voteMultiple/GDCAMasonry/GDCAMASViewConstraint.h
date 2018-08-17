//
//  GDCAMASViewConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "GDCAMASViewAttribute.h"
#import "GDCAMASConstraint.h"
#import "GDCAMASLayoutConstraint.h"
#import "GDCAMASUtilities.h"

/**
 *  A single constraint.
 *  Contains the attributes neccessary for creating a NSLayoutConstraint and adding it to the appropriate view
 */
@interface GDCAMASViewConstraint : GDCAMASConstraint <NSCopying>

/**
 *	First item/view and first attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *firstViewAttribute;

/**
 *	Second item/view and second attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *secondViewAttribute;

/**
 *	initialises the GDCAMASViewConstraint with the first part of the equation
 *
 *	@param	firstViewAttribute	view.mas_left, view.mas_width etc.
 *
 *	@return	a new view constraint
 */
- (id)initWithFirstViewAttribute:(GDCAMASViewAttribute *)firstViewAttribute;

/**
 *  Returns all GDCAMASViewConstraints installed with this view as a first item.
 *
 *  @param  view  A view to retrieve constraints for.
 *
 *  @return An array of GDCAMASViewConstraints.
 */
+ (NSArray *)installedConstraintsForView:(MAS_VIEW *)view;

@end
